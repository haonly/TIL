from itertools import cycle
def solution(answers):
    winner = []
    
    case1 = [1,2,3,4,5]
    case2 = [2,1,2,3,2,4,2,5]
    case3 = [3,3,1,1,2,2,4,4,5,5]
    solved = [0, 0, 0]
    
    for solve1, solve2, solve3, answer in zip(cycle(case1), cycle(case2), cycle(case3), answers):
        if solve1 == answer: solved[0] += 1
        if solve2 == answer: solved[1] += 1
        if solve3 == answer: solved[2] += 1
        
    for i, solve in enumerate(solved):
        if solve == max(solved):
            winner.append(i+1)
    return winner