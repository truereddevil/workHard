
# Stack example: expression evaluation in p52

def GetTop(li):
	return li(len(li) - 1)

def EvaluateExpression():
	OPTR = []
	OPTR.append("#")
	OPND = []
	c = raw_input()
	while c != "#" or GetTop(OPTR) != "#"