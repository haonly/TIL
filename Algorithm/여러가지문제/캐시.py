def solution(cacheSize, cities):
    if cacheSize == 0:
        answer = 5*len(cities)
    else:
        cache, answer = [], 0
        for city in cities:
            city = city.lower()
            if city in cache:
                answer += 1
                cache.remove(city)
            else:
                answer += 5
            cache.append(city)
            cache = cache[-cacheSize:]
    return answer