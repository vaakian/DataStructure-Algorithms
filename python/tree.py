#BinaryTree
import random
class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def Preorder(root):
    if root == None:
        return
    print(root.value)
    Preorder(root.left)
    Preorder(root.right)
def Insert(root, value):
    if value > root.value:
        if root.left == None:
            node = Node(value)
            root.left = node
        else:
            Insert(root.left, value)
    else:
        if root.right == None:
            node = Node(value)
            root.right = node
        else:
            Insert(root.right, value)
root = Node(1)
for i in range(50):
    Insert(root, random.randrange(1, 1000))
Preorder(root)
