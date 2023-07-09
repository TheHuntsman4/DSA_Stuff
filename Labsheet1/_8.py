def occ_count(arr, x):
    count = 0
    for e in arr:
        if e == x:
            count += 1
    return count

def major(arr, x):
    count = occ_count(arr, x)
    if count > len(arr) // 2:
        return f"{x} appears {count} times in the array."
    else:
        return f"{x} does not appear more than n/2 times in the array."

arr=[]
n = int(input("enter the size of array "))
value=int(input("enter the value to be searched "))
for i in range(0,n):
    e=int(input())
    arr.append(e)
print(major(arr,value))
