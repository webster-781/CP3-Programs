from random import randint as r

for _ in range(100):
    print("9 0.",end = "")
    x = [r(0,9) for _ in range(9)]
    for y in x:
        print(y,end="")
    print(" ");
