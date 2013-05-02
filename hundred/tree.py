#!/usr/bin/python
#coding=utf8


def add(x,y): 
    return x + y

#队列
class Queue:
    def __init__(self, size = 16):
        self.queue = []
        self.size = size
        self.front = 0
        self.rear = 0

    def isEmpty(self):
        return self.rear == 0

    def isFull(self):
        if (self.front - self.rear +1) == self.size:
            return True
        else:
            return False

    def first(self):
        if self.isEmpty():
            raise Exception("QueueIsEmpty")
        else:
            return self.queue[self.front]

    def last(self):
        if self.isEmpty():
            raise Exception("QueueIsEmpty")
        else:
            return self.queue[self.rear]

    def add(self, obj):
        if self.isFull():
            raise Exception("QueueOverFlow")
        else:
            self.queue.append(obj)
            self.rear += 1

    def delete(self):
        if self.isEmpty():
            raise Exception("QueueIsEmpty")
        else:
            self.rear -=1
            return self.queue.pop(0)

    def show(self):
        print(self.queue)

q = Queue(3)
q.add(1)
q.add(2)
q.show()
q.delete()
q.show()

#二叉树
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
    
    def isEmpty(self):
        if self.root is None:
            return True
        else:
            return False
    
    def preOrder(self, r):
        if r.root is not None:
            print(r.root.data)
            if r.root.left is not None:
                self.preOrder(r.root.left)
            if r.root.right is not None:
                self.preOrder(r.root.right)
    
    def inOrder(self, r):
        if r.root is not None:
            if r.root.left is not None:
                self.inOrder(r.root.left)
            print(r.root.data)
            if r.root.right is not None:
                self.inOrder(r.root.right)
    
    def postOrder(self, r):
        if r.root is not None:
            if r.root.left is not None:
                self.postOrder(r.root.left)
            if r.root.right is not None:
                self.postOrder(r.root.right)
            print(r.root.data)

    def Visit(self, r, path):
        print path
        if r.root is not None:
            print(r.root.data)
            path.append(r.root.data)

            if r.root.left is not None:
                self.Visit(r.root.left, path)
                path.pop()
            if r.root.right is not None:
                self.Visit(r.root.right, path)
                path.pop()
            else:
                if reduce(add, path) == 22:
                    print "is a legal route"
                    print path
                # path.pop()

    def levelOrder(self, a):
        q = Queue()
        r = a
        while r is not None:
            print(r.root.data)
            if r.root.left is not None:
                q.add(r.root.left)
            if r.root.right is not None:
                q.add(r.root.right)
            if q.isEmpty():
                print("empty")
                r = None
            else:
                r = q.delete()
            
root = BinaryTree()

ll = BinaryTree()
ll.makeTree(4, None, None)
lr = BinaryTree()
lr.makeTree(7, None, None)
l = BinaryTree()
l.makeTree(5, ll, lr)

r = BinaryTree()
r.makeTree(12, None, None)

root.makeTree(10, l, r)

print("preOrder")
root.preOrder(root)
print("inOrder")
root.inOrder(root)
print("postOrder")
root.postOrder(root)
print("levelOrder")
root.levelOrder(root)

print("New order!")
root.Visit(root, [])