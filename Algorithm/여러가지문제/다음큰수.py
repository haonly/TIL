
def solution(n):
    two_count = bin(n).count('1')
    for num in range(n+1, 1000001):
        num_two = bin(num).count('1')
        if num_two == two_count:
            return num