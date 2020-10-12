NOTATION ='0123456789ABCDEF'
def numeral_system(number, base):
    q, r = divmod(number, base)
    n = NOTATION[r]
    return numeral_system(q, base) + n if q else numeral_system

def mult(n):
    mul = 1
    n = list(n)
    while '0' in n:
        n.remove('0')
    for digit in n:
        mul *= int(digit)
    return mul

def solution(N):
    nNumeral = {}
    digitMultiple = {}

    for i in range(2, 10):
        nNumeral[i] = numeral_system(N, i)

    for i in range(2, 10):
        digitMultiple[i] = mult(nNumeral[i])

    digitMultiple = sorted(digitMultiple.items(), key=lambda x:x[1])

    return list(digitMultiple[-1])