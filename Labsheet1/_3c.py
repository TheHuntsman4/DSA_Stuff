class Array:
    def __init__(self):
        self.arr=[]
    def create(self,size):
        self.arr=[0]*size
        print(f"array of size {size} created")
    def delete_start(self):
        self.arr = self.arr[1:]
        print("Deleted first element.")

    def delete_end(self):
        self.arr = self.arr[:-1]
        print("Deleted last element.")

    def delete_index(self, index):
        del self.arr[index]
        print(f"Deleted element at index {index}.")

    def delete_value(self, val):
        try:
            index = self.arr.index(val)
            del self.arr[index]
            print(f"{val} deleted based on value at index {index}.")
        except ValueError:
            print(f"{val} not found in array.")
        
    def __str__(self):
        return str(self.arr)

if __name__=="__main__":
    arr=Array()
    arr.create(5)
    print(arr)
    arr.delete_start()
    arr.delete_end()
    arr.delete_index(1)
    arr.delete_value(30)
    arr.delete_value(50)