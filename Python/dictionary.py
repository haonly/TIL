my_dict = {0: 1, 1: -2, 2: 3.34}
print(my_dict)

my_dict[3] = 5
print(my_dict)
#새로운 key에 새로운 value 추가



print(my_dict.get(3))
my_dict[3] = 6
print(my_dict.get(3))
#key를 이용해 대응하는 value를 바꿀 수도 가져올 수도 있음



del my_dict[3]
print(my_dict)
#key, value 지우기
