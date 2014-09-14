class Solution:
    # @param A, a list of integers
    # @return a boolean
    
    def canJump(self, A):
        l = len(A)
        if l == 1 : 
            return True
        last_max_reach = 0
        max_reach = A[0]
        if max_reach >= l-1:
            return True
        for c in xrange(l):
            last_max_reach,max_reach = max_reach,max([i+A[i] for i in xrange(last_max_reach,max_reach+1)])
            if max_reach >= l-1:
                return True
            if last_max_reach >= max_reach:
                return False
        return False
