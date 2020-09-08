
import sys
n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

start_idx = arr.index(min(arr))
answer = 9876543210

for i in range(k):
	cnt = 1
	front, end = arr[:start_idx-i], arr[start_idx+k-i:]
	front_cnt = len(front) // (k-1) + (1 if len(front) % (k-1) else 0)
	end_cnt = len(end) // (k-1) + (1 if len(end) % (k-1) else 0)

	answer = min(answer, cnt + front_cnt + end_cnt)
print(answer)


