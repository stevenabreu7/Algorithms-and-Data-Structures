from graph import *

def getOutgoingNodes(graph, start):
    out = graph.outgoing(start)
    res = []
    if out == None:
        return None
    for e in out:
        (n,w) = e
        res.append(n)
    return res

def bfs(graph, start):
    res = []
    needToVisit = [start]
    while not len(needToVisit) == 0:
        n = needToVisit.pop(0)
        res.append(n)
        out = getOutgoingNodes(graph, n)
        for e in out:
            if not (e in res) and not (e in needToVisit):
                needToVisit.append(e)
    return res

def test(i):
    g = makeGraph()
    return bfs(g,i)

assert test(14) == [14, 1, 12, 53, 4, 22, 2, 17, 3, 5, 7]
assert test(1) == [1]
assert test(2) == [2, 4, 1, 17, 3, 5, 7]
assert test(17) == [17, 3, 4, 5, 2, 7, 1]
