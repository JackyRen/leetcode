# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def DFS(self,x,prefix):
        if x == None:
            return 
        if x.left == None and x.right == None:
            self.sum += prefix*10 + x.val
            return
        self.DFS(x.left,prefix*10+x.val)
        self.DFS(x.right,prefix*10+x.val)
        
    def sumNumbers(self, root):
        self.sum = 0
        self.DFS(root,0)
        return self.sum
        