from itertools import permutations
def primeCount(nums):
    primeList = []
    for n in nums:
        count = 0
        for i in range(2, n):
            if n % 2 == 0:
                count += 1
                break
        if n > 1 and count == 0:
            primeList.append(n)
    return len(primeList)

def solution(numbers):
    numList = []
    for i in range(1, len(numbers)+1):
        per = permutations(numbers, i)
        for n in per:
            tmp_per = "".join(n)
            numList.append(int(tmp_per))
    numList = list(set(numList))
    return primeCount(numList)