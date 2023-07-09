class Array:
    def __init__(self):
        self.arr=[]
    def create(self,size):
        self.arr=[0]*size
        print(f"array of size {size} created")
    def insert_start(self,value):
        self.arr[0]=value
    def insert_end(self,value):
        self.arr[-1]=value
    def insert_index(self,value,index):
        self.arr[index]=value
    def insert_value(self, val):
        try:
            index = self.arr.index(val)
            print(f"{val} already exists at index {index}.")
        except ValueError:
            self.arr.append(val)
            print(f"{val} inserted based on value.")
        
    def __str__(self):
        return str(self.arr)

if __name__=="__main__":
    arr=Array()
    arr.create(5)
    print(arr)
    arr.insert_start(4)
    print(arr)
    arr.insert_end(4)
    print(arr)
    arr.insert_index(3,3)
    print(arr)
    arr.insert_value(5)
    print(arr)