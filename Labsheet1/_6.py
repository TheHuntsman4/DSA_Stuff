def sumfind(nums, target):
    for i in range(0,len(nums)):
        for j in range(i+1,len(nums)):
            if nums[i]+nums[j]==target:
                return[i,j]
    return []

arr=[]
n=int(input("enter the length of the array "))
target=int(input("enter the target value"))
for i in range(0,n):
    e=int(input())
    arr.append(e)
print(sumfind(arr,target))