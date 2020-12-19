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
    print(bannedText)
    
    



if __name__ == "__main__":
    main()