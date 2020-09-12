def solution(arr):
    answer = []
    front = 0
    for idx in range(len(arr)):
        if arr[front] == arr[idx]:
            continue
        else:
            answer.append(arr[front])
            front = idx
    answer.append(arr[front])
    return answer