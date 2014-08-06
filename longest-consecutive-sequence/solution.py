class ListBasedHashSet:
    def __init__(self,bins):
        self.__data = [ [] for i in xrange(bins) ]
        self.__counts = 0
        self.__bins = bins
        
    def push(self,x):
        self.__data[x%self.__bins].append(x)
        self.__counts = self.__counts+1
        
    def empty(self,p):
        return len(self.__data[p])==0
    
    def startPoints(self,share):
        p = 0;
        while True:
            if (self.__counts <=0 or self.__counts <= share["maxLength"]):
                #no number or no need to continue
                return;
                
            if (len(self.__data[p])>0):
                yield p
            p=(p+1) % self.__bins;
            
    def pop(self,p):
        self.__counts-=1
        return self.__data[p].pop()
        
    def exist(self,x):
        #TODO: this may be slow
        return x in self.__data[x%self.__bins]
    def remove(self,x):
        self.__data[x%self.__bins].remove(x)
        
    def tryRemove(self,x):
        try:
            self.remove(x)
            self.__counts-=1
            return True
        except ValueError:
            return False
        
        
class Solution:
    # @param num, a list of integer
    # @return an integer
    # hash based search
    def longestConsecutive(self, num):
        bins = len(num)
        lbhs = ListBasedHashSet(bins)
        
        for x in num:
            lbhs.push(x)
        
        
        def searchLink(lbhs,number,direct):
            c = 0
            while lbhs.tryRemove(number):
                c=c+1
                number=number+direct
            return c;
            
        share = {"maxLength":0}
        for p in lbhs.startPoints(share) :
            curNumber = lbhs.pop(p)
            ret = searchLink(lbhs,curNumber+1,1)+searchLink(lbhs,curNumber-1,-1)+1;
            if ret > share["maxLength"]:
                share["maxLength"] = ret
                
        return share["maxLength"]
           
