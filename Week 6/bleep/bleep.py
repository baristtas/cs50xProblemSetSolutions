from cs50 import get_string
import sys

def argValidator():
    if len(sys.argv) != 2:
        print("Usage: python3 bleep.py dictionary.txt")
        sys.exit(1)    

def main():
    argValidator()
    filename = str(sys.argv[1])
    with open(filename) as f:
        bannedText = f.read().splitlines()
    
    inMessage = (get_string("Type your message: ")).split()

    for i in range(len(inMessage)):
        for j in range(len(bannedText)):
            if (inMessage[i]).lower() == (bannedText[j]).lower():
                inMessage[i] = "*" * len(inMessage[i])
    outMessage = ' '.join([str(i) for i in inMessage]) 
    print(outMessage)

if __name__ == "__main__":
    main()