def hash(bucket):
    n=int(input("\n ENTER THE SIZE OF THE TABLE: "))
    for i in range(n): 
        bucket.append([0,""])
       
def display(bucket):
    for i in range(len(bucket)):
        print(f"    {bucket[i][0]}     {bucket[i][1]}")
        
def hash_chainning(bucket):
    num=int(input("ENTER THE NUMBER: "))
    name=(input("ENTER THE NAME: "))
    index=num%len(bucket)
    i=index
    while bucket[index][0]!=0 and bucket[index][0]!=num:
        index=(index+1)%len(bucket)
        if(i==index):
            print("HASH TABLE IS FULL!")
            return
    if(bucket[index][0]==0):
        bucket[index]=[num,name]
        return
        
def search(bucket):
    num = int(input("ENTER THE NUMBER TO SEARCH: "))
    index = num % len(bucket)
    i = index
    while bucket[index][0] != 0:
        if bucket[index][0] == num:
            print(f"RECORD FOUND: {bucket[index][1]}")
            return
        index = (index + 1) % len(bucket)
        if(i == index):
            break
    print("RECORD NOT FOUND!!")

def main():
    bucket=[]
    hash(bucket)
    display(bucket)
    while True:
        hash_chainning(bucket)
        display(bucket)
        choice=input("DO YOU WANT TO CONTINUE: (Y/N)")
        if choice.lower()!='y':
            break
    while True:
        ch=input("DO YOU WANT TO SEARCH AN ELEMENT: (Y/N)")
        if ch.lower()=='y':
            search(bucket)
        else:
            break
main()
