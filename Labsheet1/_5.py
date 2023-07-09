arr=[]
n=int(input())
for i in range(0,n):
    e=int(input())
    arr.append(e)
print("lenght of the editted array is",end=" ")
print(len(set(arr)))
print("the array is ", list(set(arr)))
