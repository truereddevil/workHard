#!/usr/bin/python

num_list = []
min_list = []

def push(number, num_list, min_list):
	num_list.append(number)

	length = len(min_list)
	num_len = len(num_list)

	if length == 0 and num_len >= 1:
		min_list.append(number)
	elif number <= min_list[length-1]:
		min_list.append(number)
	else:
		pass

def pop(num_list, min_list):
	num_stack_top = num_list[len(num_list) - 1]
	min_stack_top = min_list[len(min_list) - 1]

	if min_stack_top == num_stack_top:
		min_list.pop()
	num_list.pop()

def min(min_list):
	return min_list[len(min_list) - 1]	

def main():
	push(9, num_list, min_list)
	push(8, num_list, min_list)
	push(7, num_list, min_list)

	print num_list
	print min_list
	print min(min_list)

	pop(num_list, min_list)
	print num_list
	print min_list
	print min(min_list)	

if __name__ == '__main__':
	main()