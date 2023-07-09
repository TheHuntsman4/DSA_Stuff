arr=[]
n=int(input("enter the length "))
position=int(input("enter position to operate on "))
arrs = input("Enter the array :")
arrs = arrs.split()
arr = [int(x) for x in arrs]
arr = arr[:n:]
new=arr[:position]
arr[:position]=[]
arr+=new
print(arr)

