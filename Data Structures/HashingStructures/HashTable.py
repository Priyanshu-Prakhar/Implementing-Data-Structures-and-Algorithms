class HashTable:
    def __init__(self, size:int):
        """Initializes a HashTable object of size 10"""
        self.array = [[] for _ in range(size)]
        self.size = size

    def hash(self, key:int):
        hashed = key % self.size
        return hashed

    def printarr(self):
        print(self.array, "\n")
    
    def insert(self, key:int, value:any):
        """Inserts element at appropriate index using hash function"""
        index = self.hash(key)
        print("Insert hash: ", index)
        self.array[index].append((key, value))


    def search(self, key:int):
        """Searches for a specific element using the key"""
        index = self.hash(key)
        print("Search hash: ", index)
        for (a,b) in self.array[index]:
            if a == key:
                return (a,b)

    def delete(self, key:int):
        index = self.hash(key)
        bucket = self.array[index]
        for i in range(len(bucket)):
                    if bucket[i][0] == key:
                        del bucket[i]

a = HashTable(20)
a.printarr()

a.insert(55, "Banana")
a.printarr()
a.insert(54, "Mango")
a.printarr()
a.insert(24, "Pineapple")
a.printarr()
a.delete(24)
a.printarr()

print(a.search(54), "\n")
print(a.search(24), "\n")
