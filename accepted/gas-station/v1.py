class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        n = len(gas)
        gas = gas + gas[:-1]
        cost = cost + cost[:-1]
        delta = [ gas[i] - cost[i] for i in xrange(len(gas))]
        start = -1
        tank = 0
        for i in xrange(len(gas)):
            if tank + delta[i] >= 0:
                tank += delta[i]
                if i-start >= n:
                    return start+1
            elif delta[i] >=0:
                tank = delta[i]
                start = i-1;
            else:
                tank = 0
                start = i
        return -1