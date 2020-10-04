def solution(d, budget):
    d.sort()
    spend = 0
    for i, item in enumerate(d):
        spend += item
        if spend > budget:
            return i
    return len(d)