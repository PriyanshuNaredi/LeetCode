# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return self.postorder(root)
    
    def postorder(self, root):
        if root is None:
            return []
        return self.postorder(root.left) + self.postorder(root.right) + [root.val]