class Student():
    def __init__(self,name,id):
        self.name = name
        self.id = id
    
    def changeID(self,id):
        self.id = id

    def print(self):
        print(f"İsim: {self.name}, ID:{self.id}")

baris = Student("baristtas",11001)
baris.print()
baris.changeID("1001")
baris.print()