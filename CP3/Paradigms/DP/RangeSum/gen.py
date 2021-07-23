from random import randint as r
k = 18
i = 75
print(k)
for _ in range(k):
    print(i)
    for _ in range(i):
        for _ in range(i):
            x = r(-100,100)
            print(x,end=" ")
        print(" ")
