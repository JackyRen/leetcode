from solution import *

s = Solution()

def tests():
    yield [1,2,3,100,4]
    yield [-1,-2,-3,0,9,8]
    yield [1234,534,567564,1235,1233,1232,2222,2223,1233]


def strList(t):
    return '['+','.join(map(lambda x:str(x),t))+']'

for t in tests():
    print "largest length of {0} is {1}".format(
            strList(t),s.longestConsecutive(t))
