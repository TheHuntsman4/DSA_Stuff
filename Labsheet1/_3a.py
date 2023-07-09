class Array:
    def __init__(self):
        self.arr=[]
    def create(self,size):
        self.arr=[0]*size
        print(f"array of size {size} created")

        
    def __str__(self):
        return str(self.arr)

if __name__=="__main__":
    arr=Array()
    arr.create(5)
    print(arr)
