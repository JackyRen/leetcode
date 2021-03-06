class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        left = 0
        lowlevel = 0
        minindex = 0  
        n = len(gas)
        for i in xrange(n):
            left += gas[i] 
            left -= cost[i]
            if (left<lowlevel):
                lowlevel = left
                minindex = (i+1) % n
        if left <0 :
            return -1
        return minindex
        
