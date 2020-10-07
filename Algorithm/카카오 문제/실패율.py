def solution(N, stages):
    answer = []
    stageList = [0 for _ in range(1, N+1)]
    users = len(stages)
    
    dic = {}
    for stage in stages:
        if stage not in dic:
            dic[stage] = 1
        elif stage in dic:
            dic[stage] += 1
            
    dic = sorted(dic.items())
    
    failRate = {}
    for key, getsu in dic:
        
    
    return answer