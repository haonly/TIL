from collections import deque
def checkLeft(num):
    possible = ['1', '4', '7', '2', '5', '8', '0']
    if num in possible:
        return True
    return False
def checkRight(num):
    possible = ['2', '5', '8', '0', '3', '6', '9']
    if num in possible:
        return True
    return False

def solution(numbers, hand):
    answer = ''
    numbers = deque(numbers)

    pads = {'1': (0, 0), '2': (0, 1), '3': (0, 2),
            '4': (1, 0), '5': (1, 1), '6': (1, 2),
            '7': (2, 0), '8': (2, 1), '9': (2, 2),
            '*': (3, 0), '0': (3, 1), '#': (3, 2)}
    
    left = pads['*']
    right = pads['#']
    for num in numbers:
        num = str(num)
        if checkLeft(num) and not checkRight(num):
            answer  += 'L'
            left = pads[num]
        elif not checkLeft(num) and checkRight(num):
            answer += 'R'
            right = pads[num]
        elif checkLeft(num) and checkRight(num): 
            leftDist = abs(pads[num][0] - left[0]) + abs(pads[num][1] - left[1])
            rightDist = abs(pads[num][0] - right[0]) + abs(pads[num][1] - right[1])
            if leftDist < rightDist:
                answer += 'L'
                left = pads[num]
            elif rightDist < leftDist:
                answer += 'R'
                right = pads[num]
            elif rightDist == leftDist:
                if hand == 'right':
                    answer += 'R'
                    right = pads[num]
                if hand == 'left':
                    answer += 'L'
                    left = pads[num]
    return answer