#!/usr/bin/python

def NumberOf1(n):
	count = 0

	while n:
		if n & 1:
			count += 1

		n = n >> 1

	return count

def NunberOf1A(n):
	count = 0

	while n:
		count += 1
		n = (n-1) & n

	return count

# different from c, it won't stop correctly
def NumberOf1B(n):
	count = 0

	flag = 1

	while flag:
		if n & flag:
			count += 1

		flag = flag << 1

	return count

def main():
	number = 9
	print NumberOf1(number)

	print NunberOf1A(number)

	print NumberOf1B(number)	

if __name__ == '__main__':
	main()
