def solution(N, stages):
    rate=[]
    answer = []

    for i in range(1,N+1) :   
        stagePeople=0  
        stageWaiting=0  
        for stage in stages :
            if i==stage :
                stagePeople += 1     
            if stage >= i :
                stageWaiting += 1    
        if stageWaiting == 0 :
            rate.append([i,0])   
        else :
            rate.append([i,stagePeople/stageWaiting])

    rate.sort(key=lambda x:x[1],reverse=True)
    
    for i in rate :
        answer.append(i[0])
        
    return answer