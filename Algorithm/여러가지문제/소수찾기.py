from itertools import permutations
def primeCount(nums):
    primeCount = 0
    for n in nums:
        count = 0
        for i in range(2, n):
            if n % i == 0:
                count += 1
                break
        if n > 1 and count == 0:
            primeCount += 1 
    return primeCount

def solution(numbers):
    numList = []
    for i in range(1, len(numbers)+1):
        per = permutations(numbers, i)
        for n in per:
            tmp_per = "".join(n)
            numList.append(int(tmp_per))
    numList = sorted(list(set(numList)))
    print(numList)
    return primeCount(numList)