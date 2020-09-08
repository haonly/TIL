# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import sys
num = int(sys.stdin.readline())
arr = list(set(map(int, sys.stdin.readline().split())))
if len(arr) < 3:
	print("NO")
else:	
	arr.sort()
	new_list = []
	new_list.append(arr[0])
	for i in range(1, 3):
		if new_list[i-1] < arr[i]:
			new_list.append(arr[i])
	if len(new_list) == 3:
		print("YES")
	else: print("NO")