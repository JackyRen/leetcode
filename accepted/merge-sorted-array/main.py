from solution import *
from libs import *
from tests import *

s = Solution()

for test_no,t in enumerate(tests()):
    print "No.{0} testcase: {1}".format(test_no,t)
    A,m,B,n = t
    s.merge(A,m,B,n)
    print A
