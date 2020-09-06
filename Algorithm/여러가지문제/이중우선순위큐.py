import heapq
def solution(operations):
    answer = []
    heapq.heapify(answer)
    for operation in operations:
        order, data = operation.split()
        if order == 'I':
            heapq.heappush(answer, int(data))
        if order == 'D' and answer:
            if data == '1':
                answer.remove(max(answer))
            if data == '-1':
                heapq.heappop(answer)
    if not answer:
        return [0, 0]
    return [max(answer), min(answer)]