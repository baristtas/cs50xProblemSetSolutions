from cs50 import get_int

height = 0
while height > 8 or height < 1 :
    height = get_int("How many hashes you want baby? It must be an integer between 0 and 9: \n")

for i in range(height):
    for x in range(height - (i + 1)):
        print(" ",end="")
    for y in range(i + 1):
        print("#",end="")
    print("  ",end="")
    for z in range (i + 1):
        print("#",end="")
    print()
