
def solution(progresses, speeds):
    answer = []
    depDay = []
    
    for task, speed in zip(progresses, speeds):
        d, m = divmod(100 - task, speed)
        if m != 0:
            d += 1
        depDay.append(d)
    front = 0
    for idx in range(len(depDay)):
        if depDay[front] < depDay[idx]:
            answer.append(idx-front)
            front = idx
    answer.append(len(depDay) - front)
    return answer