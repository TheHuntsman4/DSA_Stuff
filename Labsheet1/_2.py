#flag changes to 1 when a 6 is encountered,
# the checking will then swap all 6s after the first one to 7

def swap(arr):
    flag=0
    i=0
    while(i<len(arr)):
        if(flag==0 and arr[i]==6):
            flag+=1
            i+=1
        elif(flag!=0 and arr[i]==6):
            arr[i]=7
            i+=1
        else:
            i+=1
    return arr



arr=[]
n=int(input())
for i in range(0,n):
    e=int(input())
    arr.append(e)
print(swap(arr))

