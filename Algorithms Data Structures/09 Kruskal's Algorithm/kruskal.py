from graph import *

dic = {}
rank = {}

def make_set(node):
    dic[node] = node
    rank[node] = 0

def find(node):
    if not dic[node] == node:
        dic[node] = find(dic[node])
    return dic[node]

def union(node1, node2):
    root1 = find(node1)
    root2 = find(node2)
    if not root1 == root2:
        if rank[root1] < rank[root2]:
            dic[root1] = root2
        else:
            dic[root2] = root1
    if rank[root1] == rank[root2]:
        rank[root2] += 1

def kruskal(graph):
    # get all nodes and initialize dictionary
    nodes = graph.allNodes()
    for node in nodes:
        make_set(node)
    sot = set()
    edges = graph.allEdges()
    # sort with bubblesort by increasing weight
    sortd = False
    while not sortd:
        sortd = True
        for i in range(len(edges)-1):
            x1,y1,w1 = edges[i]
            x2,y2,w2 = edges[i+1]
            if not (w1 <= w2):
                sortd = False
                edges[i], edges[i+1] = edges[i+1], edges[i]
    # add edges to set
    for edge in edges:
        node1, node2, weight = edge
        if find(node1) != find(node2):
            union(node1, node2)
            sot.add(edge)
    # return set represented as list
    return list(sot)

graph = makeUndirectedGraph()
kru = kruskal(graph)
res = [(14, 53, 1), (1, 14, 1), (1, 4, 1), (3, 7, 1), (2, 5, 1), (12, 22, 1),
        (3, 17, 1), (2, 4, 1), (4, 12, 1), (2, 3, 1)]
assert res == kru

graph = makeOtherUndirectedGraph()
kru = kruskal(graph)
res = [(1, 3, 5), (3, 4, 5), (4, 5, 15), (2, 4, 7), (0, 1, 10)]
assert res == kru
