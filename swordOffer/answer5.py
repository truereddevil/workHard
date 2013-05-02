#!/usr/bin/python

class LinkListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkList:
    def __init__(self):
        self.head = None

    def insert(self, value): 
        new_node = LinkListNode(value)

        if self.head == None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next != None:
                   temp = temp.next
            temp.next = new_node
            
    def reverse_print(self):  
        stack = []
        temp = self.head
        while temp != None:
            stack.append(temp.data)
            temp = temp.next

        while len(stack) != 0:
            print stack.pop()    

    def print_linklist(self):
        temp = self.head
        while temp != None:
            print temp.data
            temp = temp.next

def main():
    h = LinkList()

    h.insert(10)
    h.insert(20)
    h.insert(30)
    h.insert(40)
    h.print_linklist()
    

    h.reverse_print()

if __name__ == '__main__':
    main()        