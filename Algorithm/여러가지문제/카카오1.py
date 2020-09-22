allowing = []
allowing.append(ord('-')) #45
allowing.append(ord('_')) #95
allowing.append(ord('.')) #46
for i in range(48, 58):
    allowing.append(i)
for i in range(97, 123):
    allowing.append(i)

def make_id(new_id):
    new_id = new_id.lower()
    print(new_id)
    
    ch_ord = [ch for ch in new_id]
    chList = []
    for i, ch in enumerate(ch_ord):
        if ord(ch) in allowing:
            chList.append(ch)
    print("2", "".join(chList))
     

    i = 0
    for ch in chList:
        if i == len(chList)-1:
            break
        if chList[i] == '.' and chList[i+1] == '.':
            del chList[i]
            continue
        i += 1
        
    print("3", "".join(chList))

        
    if chList and chList[0] == '.':
        del chList[0]
    if chList and chList[-1] == '.':
        del chList[-1]
        
    
    print("4", chList)
    
    if not chList:
        chList = ['a']
        
    if len(chList) >= 16:
        chList = chList[0:15]
    print("6:", chList)
    
    if chList[-1] == '.':
        chList = chList[0:-1]
    while len(chList) < 3:
        chList.append(chList[-1])
        
    new_id = "".join(chList)
    return new_id

make_id(new_id)