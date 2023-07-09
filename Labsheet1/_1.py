def binsearch(arr,search):
    arr.sort()
    low=0
    flag=0
    high=len(arr)-1
    while(low<=high):
        mid=(low+high)//2
        if arr[mid]==search:
            flag=1
            break
        elif arr[mid]<search:
            low=mid+1
        else:
            high=mid-1
    if flag==1:
        print(f"value found at {mid}")
    else:
        print("value not found")

arr=[]
n=int(input("enter the size of the array"))
print("enter the array ")
for i in range(0,n):
    e=int(input())
    arr.append(e)
search=int(input("enter the element to be searched "))
print(binsearch(arr,search))


