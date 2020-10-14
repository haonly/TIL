def solution(n):
    answer = ''
    nums = ['4', '1', '2']
    while n != 0:
        n, a = divmod(n, 3)
        answer = nums[int(a)] + answer
        if a == 0:
            n -= 1
    return answer