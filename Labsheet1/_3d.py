size=int(input("enter the size of the array"))
arr=[0]*size
for i in range(0,size):
    arr[i]=int(input())
print("starting array traversal")
for i in range(0,size):
    print(arr[i])
