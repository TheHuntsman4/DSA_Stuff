class Array:
    def __init__(self):
        self.arr = []

    def create(self, n):
        self.arr = [0] * n
        print(f"Array of size {n} created.")

    def insert_start(self, val):
        self.arr = [val] + self.arr
        print(f"{val} inserted at start.")

    def insert_end(self, val):
        self.arr.append(val)
        print(f"{val} inserted at end.")

    def insert_index(self, index, val):
        self.arr.insert(index, val)
        print(f"{val} inserted at index {index}.")

    def insert_value(self, val):
        try:
            index = self.arr.index(val)
            print(f"{val} already exists at index {index}.")
        except ValueError:
            self.arr.append(val)
            print(f"{val} inserted based on value.")

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

    def traverse(self):
        print("Array elements:")
        for val in self.arr:
            print(val)

    def search_by_value(self, val):
        try:
            index = self.arr.index(val)
            print(f"{val} found at index {index}.")
        except ValueError:
            print(f"{val} not found in array.")

    def search_by_index(self, index):
        try:
            val = self.arr[index]
            print(f"Value at index {index} is {val}.")
        except IndexError:
            print(f"Index {index} is out of range.")

if __name__ == "__main__":
    arr = Array()
    arr.create(5)
    arr.insert_start(10)
    arr.insert_end(20)
    arr.insert_index(2, 30)
    arr.insert_value(40)
    arr.insert_value(20)
    arr.delete_start()
    arr.delete_end()
    arr.delete_index(1)
    arr.delete_value(30)
    arr.delete_value(50)
    arr.traverse()
    arr.search_by_value(40)
    arr.search_by_index(2)
    arr.search_by_index(5)