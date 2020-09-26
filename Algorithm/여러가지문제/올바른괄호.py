def solution(s):
    answer = True
    
    cnt = 0
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    if s[0] == ')':
        return False
    for ch in s:
        if cnt == 0 and ch == ')':
            return False
        if ch == '(':
            cnt += 1
        if ch == ')':
            cnt -= 1
    if cnt != 0:
        return False

    return True