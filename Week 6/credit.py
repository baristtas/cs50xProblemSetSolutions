from cs50 import get_int
import math
import pdb

cardNumber = get_int("Please type your card number\n")
cardNumber = list(str(cardNumber)) #pushes credit card numbers to an array

mlcedCN = [] #will keep other numbers that wasnt multiplied by two.
mn = []      #same as mlcedCN but it keeps numbers character by character. like mlced =[12] => mn=[1,2]
otherNumbSum = 0

for i in range((len(cardNumber) - 1),0,-2):
    mlcedCN.append(2 * int(cardNumber[int(i)-1]))
    otherNumbSum = otherNumbSum + int(cardNumber[i]) #keeps sum of underlined numbers. (before multiplied)

for i in range((len(mlcedCN))): #function below this separates digits
    if (mlcedCN[i] >= 10):
        mn.append((math.trunc(int(mlcedCN[i]) / 10)))
        mn.append(int(mlcedCN[i]) % 10)
    else:
        mn.append(mlcedCN[i])

x = 0 #x will keep sum of numbers in mn
for i in range(len(mn)):
    x = x + int(mn[i])

y = x + otherNumbSum 

if bool(int(cardNumber[0]) == 4):
    print("VISA")
    exit()

elif(bool(int(cardNumber[0]) == 5) and (int(cardNumber[1]) in range(1,6))):
    print("MASTERCARD")
    exit()

elif (int(cardNumber[0]) == 3) and ((int(cardNumber[1]) == 4) or (int(cardNumber[1]) == 7)):
    print("AMEX")
    exit()

if ((y % 10) != 0):
    print(f"INVALID") 
    exit()