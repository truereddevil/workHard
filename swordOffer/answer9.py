#!/usr/bin/python

def Fibonacci(n):
	a = [0, 1]
	if n < 2:	return a[n]

	fibNMinusOne = 1
	fibNMinusTwo = 0

	for n in range(2,n+1):
		fibN = fibNMinusTwo + fibNMinusOne

		fibNMinusTwo = fibNMinusOne
		fibNMinusOne = fibN

	return fibN	

def Fibonacci1(n):
	if n <= 0:
		return 0

	if n == 1:
		return 1

	return Fibonacci1(n-1) + Fibonacci1(n-2)

def main():
	print Fibonacci(10)
	
	print Fibonacci1(10)

if __name__ == '__main__':
	main()	