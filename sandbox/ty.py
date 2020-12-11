from cs50 import get_int, get_float,get_string
from sys import argv

a = 0
if len(argv) >= 2:
    print(argv[1])

##########################

x = 5
y = 4
print(f"x:{x}\ny:{y}")
x, y = y , x
print(f"x:{x}\ny:{y}")

###########################
numbers = []
while True:
    number = get_int("Number: ")

    if number != NUMBER:
        break

    numbers.append(number)
    
for number in numbers:
    print(number)