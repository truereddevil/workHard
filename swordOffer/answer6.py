#!/usr/bin/python

# Binary Tree
class BinaryTreeNode:

    def __init__(self, data, left, right):
        self.left = left
        self.data = data
        self.right = right

class BinaryTree:
    def __init__(self):
        self.root = None
    
    def makeTree(self, data, left, right):
        self.root = BinaryTreeNode(data, left, right)
        #left.root = right.root = None
        return self.root
    
    def isEmpty(self):
        if self.root is None:
            return True
        else:
            return False
    
    def rebuildTree(self, pre_list, in_list):
        l_tree = None
        r_tree = None
        if len(pre_list) > 0:
            print pre_list, in_list
            index = self.find_in_list(pre_list[0], in_list)

            if index != 0:    
                print pre_list[1:index+1], in_list[0:index]
                l_tree = self.rebuildTree(pre_list[1:index+1], in_list[0:index])
            if index != len(pre_list):
                print pre_list[index+1:], in_list[index+1:]                     
                r_tree = self.rebuildTree(pre_list[index+2:], in_list[index+2:])

            return self.makeTree(pre_list[0], l_tree, r_tree)

    def find_in_list(self, number, in_list):
        print in_list, 
        print "  ", str(number)
        return in_list.index(number)        

    def preOrder(self, r):
        if r.root is not None:
            print(r.root.data)
            if r.root.left is not None:
                self.preOrder(r.root.left)
            if r.root.right is not None:
                self.preOrder(r.root.right)

def main():
    pre_list = [1, 2, 4, 7, 3, 5, 6, 8]
    in_list = [4, 7, 2, 1, 5, 3, 8, 6]

    test_tree = BinaryTree()
    test_tree.rebuildTree(pre_list, in_list)

    test_tree.preOrder(test_tree)

if __name__ == '__main__':
    main()