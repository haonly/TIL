#random module 쓰기
import random

animals = ['cat', 'dog', 'bird']


print(random.choice(animals))

print(random.sample(animals,2))
#중복없이 2개

print(random.randint(5,10))
#5~10 사이의 숫자 random
