#!/usr/bin/python

# use two queues to implement a stack
class MyStack(object):
	"""docstring for MyStack"""
	def __init__(self, arg):
		super(MyStack, self).__init__()
		self.arg = arg
		self.queue1 = []
		self.queue2 = []

	def pop_ele(self):
		
		
	def push_ele(self):
		

	def printStack(self):
		print self.queue1
		print self.queue2

def main():
	test = MyStack("test")
	test.push_ele(1)
	test.push_ele(2)
	test.push_ele(3)
	test.push_ele(4)

	test.printStack()

	test.pop_ele()
	test.pop_ele()
	test.pop_ele()
	test.printStack()

if __name__ == '__main__':
	main()		