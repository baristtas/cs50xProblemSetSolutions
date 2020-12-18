import sys
from cs50 import get_string

if len(sys.argv) != 2:
    print("Usage: python3 caesar.py <integer>")
    sys.exit(1)

k = int(sys.argv[1]) #We will add the k number to the ascii number of the character we want to encrypt.

message = get_string("Type your message: ")

theList = []
for i in range(len(message)):
    theList.append(int(ord(message[i]))) #im sure there is more "pythonic" version of this 3 line XD

for i in range(len(theList)):
    if theList[i] > 64 and theList[i] < 91:
        theList[i] = (((theList[i] + k - 65) %26) + 65)
    elif theList[i] > 96 and theList[i] < 123:
        theList[i] = (((theList[i] + k - 97) %26) + 97)

ciphertext = "".join(map(chr,theList))
print(ciphertext)