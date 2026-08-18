# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        self.s = ""
        def dfs(root):
            if not root:
                self.s += "N,"
                return
            self.s = self.s + str(root.val) + ","
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return self.s
        

    def deserialize(self, data):
        info = data.split(",")
        self.i = 0 
        
        def dfs():
            if info[self.i] == "N":
                self.i += 1
                return None
            
            node = TreeNode(int(info[self.i]))
            self.i += 1
            node.left = dfs()
            node.right = dfs()
            return node

        return dfs()
                

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))