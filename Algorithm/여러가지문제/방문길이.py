def solution(dirs):
    answer = 0
    x, y = 0, 0
    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    d = {'U': 0, 'D': 1, 'L': 2, 'R': 3}
    
    visited = set()
    for dir in dirs:
        i = d[dir]
        nx, ny = x + dx[i], y + dy[i]
        if nx < -5 or nx > 5 or ny < -5 or ny > 5:
            continue
        if (x, y, nx, ny) not in visited:
            visited.add((x, y, nx, ny))
            visited.add((nx, ny, x, y))
            answer += 1
        x, y = nx, ny
    return answer