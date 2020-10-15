def solution(s, n):
    answer = ''
    changed = []
    for ch in s:
        tmp = ord(ch)
        if tmp == 32:
            changed.append(' ')
        elif tmp <= 90 and tmp+n > 90:
            changed.append(chr(tmp+n-26))
        elif tmp >= 97 and tmp <= 122 and tmp+n > 122:
            changed.append(chr(tmp+n-26))
        else:
            changed.append(chr(tmp+n))
    answer = ''.join(changed)
    return answer