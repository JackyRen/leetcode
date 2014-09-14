class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        A[n:m+n] = A[:m]
        i = n
        j = 0
        p = 0
        bl = len(B)
        while i < m+n and j < bl:
            if A[i] < B[j]:
                A[p] = A[i]
                i+=1
            else:
                A[p] = B[j]
                j+=1
            p += 1
        while i < m+n:
            A[p] = A[i]
            i+=1
            p+=1
        while j < bl:
            A[p] = B[j]
            j+=1
            p+=1
        
                
            
        
