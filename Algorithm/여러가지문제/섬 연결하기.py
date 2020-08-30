def solution(n, costs):
    answer = 0
    
    costs.sort(key=lambda x:x[2])
    visited = [0]*n
    visited[0] = 1
    
    while sum(visited) != n:
        for item in costs:
            first, second, cost = item
            if visited[first] or visited[second]:
                if visited[first] and visited[second]:
                    continue
                else:
                    visited[first] = 1
                    visited[second] = 1
                    answer += cost
                    break
    return answer