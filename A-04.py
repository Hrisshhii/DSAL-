class Sets:
    def __init__(self):
        self.setA = []
        self.setB = []

    def getSet(self, set_choice):
        if set_choice == 1:
            return self.setA
        elif set_choice == 2:
            return self.setB

    def insert(self, set_choice, a):
        if a not in self.getSet(set_choice):
            self.getSet(set_choice).append(a)

    def remove(self, set_choice, a):
        if a in self.getSet(set_choice):
            self.getSet(set_choice).remove(a)
        else:
            print("ELEMENT DOES NOT EXIST!!")

    def contains(self, set_choice):
        ele = int(input("ENTER THE NUMBER TO BE SEARCHED: "))
        if ele not in self.getSet(set_choice):
            print("ELEMENT DOES NOT EXIST!!!")
        else:
            count = 0
            for i in self.getSet(set_choice):
                if i == ele:
                    print(f"ELEMENT FOUND AT INDEX: {count}")
                count += 1

    def size(self, set_choice):
        count = 0
        for _ in self.getSet(set_choice):
            count += 1
        print(f"SET HAS {count} ELEMENTS")

    def intersection(self):
        result = []
        for i in self.setA:
            if i in self.setB:
                result.append(i)
        print(f"RESULT SET (INTERSECTION): {result}")

    def difference(self):
        result = []
        for i in self.setA:
            if i not in self.setB:
                result.append(i)
        for j in self.setB:
            if j not in self.setA:
                result.append(j)
        print(f"RESULT SET (DIFFERENCE): {result}")

    def union(self):
        result = []
        for i in self.setA:
            result.append(i)
        for j in self.setB:
            if j not in self.setA:
                result.append(j)
        print(f"RESULT SET (UNION): {result}")

    def subset(self):
        temp = []
        for i in self.setB:
            if i in self.setA:
                temp.append(i)
        if len(self.setB) == len(temp):
            print("SET B IS A SUBSET OF SET A")
        else:
            print("SET B IS NOT A SUBSET OF SET A")

    def display(self, set_choice):
        newSet = self.getSet(set_choice)
        iterator=iter(newSet)
        for i in iterator:
            print(i)


def main():
    operator = Sets()
    while True:
        print("""***********MENU************
                1.ADD
                2.REMOVE
                3.DISPLAY
                4.INTERSECTION
                5.UNION
                6.DIFFERENCE
                7.SIZE OF SET
                8.CHECK IF SUBSET
                9.SEARCH ELEMENT
                10.EXIT""")
        choice = int(input("ENTER YOUR CHOICE: "))
        
        if choice == 1:
            ele = int(input("ENTER ELEMENT TO BE ENTERED: "))
            setChoice = int(input("WHAT SET TO ENTER THE ELEMENT (1 for A, 2 for B): "))
            operator.insert(setChoice, ele)
        
        elif choice == 2:
            ele = int(input("ENTER ELEMENT TO BE REMOVED: "))
            setChoice = int(input("FROM WHICH SET TO REMOVE (1 for A, 2 for B): "))
            operator.remove(setChoice, ele)
        
        elif choice == 3:
            setChoice = int(input("SET TO BE DISPLAYED (1 for A, 2 for B): "))
            operator.display(setChoice)
        
        elif choice == 4:
            operator.intersection()
        
        elif choice == 5:
            operator.union()
        
        elif choice == 6:
            operator.difference()
        
        elif choice == 7:
            setChoice = int(input("1.SET A, 2.SET B: "))
            operator.size(setChoice)
        
        elif choice == 8:
            operator.subset()
        
        elif choice == 9:
            setChoice = int(input("1.SET A, 2.SET B: "))
            operator.contains(setChoice)
        
        elif choice == 10:
            break
        
        else:
            print("INVALID CHOICE!!")

main()

