N = int(input())
expression = input()
ans = -2 ** 31
 
if N == 1:
    print(max(ans, int(expression)))
    exit()

symbols = ["+", "-", "*"]
 
    
def add_bracket(idx, expList):
    global ans
    if idx == N:    
        for i, oper in enumerate(expList):
            if len(oper) == 3:
                expList[i] = str(eval(oper))
        result = expList[0]
        for step in range(1, len(expList), 2):
            result = eval(str(result)+expList[step]+expList[step+1])
 
        if ans < result:
            ans = result
        return
 
 
    expList.append(expression[idx])
    add_bracket(idx + 1, expList)
    del expList[-1]
 
    if expList[-1] in symbols and idx + 3 <= N:
        expList.append(expression[idx:idx+3])
        add_bracket(idx + 3, expList)
        del expList[-1]
 
 
add_bracket(1, [expression[0]])
print(ans)