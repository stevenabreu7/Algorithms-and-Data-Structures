def counting_sort(A):
    C = [0] * (max(A)+1)
    B = [""] * len(A)
    for index in xrange(len(A)):
        C[A[index]]+=1
    for index in xrange(1, len(C)):
        C[index]+=C[index-1]
    for index in xrange(len(A)-1, -1, -1):
        B[C[A[index]]-1]=A[index]
        print(index)
        print(A,C,B)
        print(A[index], C[A[index]], B[C[A[index]]-1])
        print
        C[A[index]]-=1
    return B

print(counting_sort([1,6,3,2,6,8,3,1]))
