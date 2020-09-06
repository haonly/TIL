import heapq
def solution(A, B):
    answer = 0
    if min(A) > max(B):
        return 0
    A.sort(reverse=True)
    B = [-i for i in B]
    heapq.heapify(B)
    for item in A:
        if item >= abs(B[0]):
            continue
        else:
            answer += 1
            heapq.heappop(B)
    return answer