input_string = input("Enter the array separated by commas: ")
input_list = input_string.split(",")
arrA = [int(num) for num in input_list]

input_string = input("Enter the next array separated by commas: ")
input_list = input_string.split(",")
arrB = [int(num) for num in input_list]

# sorting arrays 
arrA.sort()
arrB.sort()
# storing lengths for slicing 
p = len(arrA)
q = len(arrB)
# appending first array second, and then sorting 
arrA += arrB  
arrA.sort()
# slicing arrays according to the respective lengths of the original
print("Sorted Arrays:")
print("A:", arrA[:p])
print("B:", arrA[p:])
