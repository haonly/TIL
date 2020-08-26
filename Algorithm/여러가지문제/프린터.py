from collections import deque
def solution(priorities, location):
    answer = 0
    d = deque([(p, i) for i, p in enumerate(priorities)])

    while len(d):
        item = d.popleft()
        if d and max(d)[0] > item[0]:
            d.append(item)
        else:
            answer += 1
            if item[1] == location:
                return answer
    return 0