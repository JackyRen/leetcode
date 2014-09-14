from solution import *
from libs import *
from tests import *

s = Solution()

for test_no,t in enumerate(tests()):
    print "No.{0} testcase: __{1}__".format(test_no,t)
    print "\t__{}__".format(s.reverseWords(t))
