t = int(input())

while t > 0:
	t -= 1
	stack = [];
	s = input()
	ans = 1
	for c in s:
		if c == '{' or c == '[' or c == '(':
			stack.append(c);
		elif c == ']':
			if len(stack) == 0 or stack[-1] != '[':
				ans = 0
			else:
				stack.pop()
		elif c == ')':
			if len(stack) == 0 or stack[-1] != '(':
				ans = 0
			else:
				stack.pop()
		elif c == '}':
			if len(stack) == 0 or stack[-1] != '{':
				ans = 0
			else:
				stack.pop()
		
	if ans and len(stack) == 0:
		print("S")
	else:
		print("N")



	
