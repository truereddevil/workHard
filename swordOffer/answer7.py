#!/usr/bin/python

# use two stacks to implement a queue
class MyQueue(object):
	"""docstring for MyQueue"""
	def __init__(self, arg):
		super(MyQueue, self).__init__()
		self.arg = arg
		self.stack1 = []
		self.stack2 = []

	def appendTail(self, number):
		self.stack1.append(number)

	def deleteHead(self):
		if len(self.stack2) > 0:
			print self.stack2.pop()
		else:
			while len(self.stack1) > 0:
				self.stack2.append(self.stack1.pop())
			print self.stack2.pop()	

	def printQueue(self):
		print self.stack1
		print self.stack2	

def main():
	test = MyQueue("test")

	test.appendTail(1)
	test.appendTail(2)
	test.appendTail(3)
	test.appendTail(4)

	test.deleteHead()
	test.deleteHead()	

	test.printQueue()

if __name__ == '__main__':
	main()