from collections import deque
def solution(skill, skill_trees):
    answer = 0
    for item in skill_trees:
        dq = deque(skill)
        for s in item:
            if s in skill:
                if s != dq.popleft():
                    break
        else:
            answer += 1
                
    return answer