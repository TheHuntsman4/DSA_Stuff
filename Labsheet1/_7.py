def popper(arr, value):
    for i in range(len(arr)-1,-1,-1):
        if arr[i]==value:
            arr.pop(i)
    return(len(arr))

arr=[]
n = int(input("enter the size of array "))
value=int(input("enter the value to be removed "))
for i in range(0,n):
    e=int(input())
    arr.append(e)
print("new length is ",popper(arr,value))
