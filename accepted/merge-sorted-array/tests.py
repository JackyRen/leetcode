import random
random.seed(1)
def tests():
    a = [[5,7],[0,4],[2,0],[1,1]]
    for m,n in a:
        random.seed(1)
        A = sorted([random.randint(1,10000) for i in xrange(m)])
        B = sorted([random.randint(1,10000) for i in xrange(n)])
        A = A+[0]*n
        yield (A,m,B,n)

