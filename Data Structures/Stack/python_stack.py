'''
This is my python implementation of a stack.
This stack is a python list.
'''

class stack:
    def __init__(self):
        '''Initializes a Stack.'''

        self._data = []
        self._size = 0
        
    def __len__(self):
        '''Returns the length of the Stack.'''

        return self._size
    
    def __setitem__(self, index, value):
        self._data[index] = value

    def put(self, d):
        '''Append element at the top of the Stack.'''

        self._data.append(d)
        self._size += 1
    
    def __getitem__(self, n):
        '''Gets n'th index of Stack.
        Indexes start at 0.'''

        return self._data[n]

    def pop_up(self):
        '''Pops the last(topmost) element of the Stack'''

        if self._size == 0:
            raise "Cannot pop from empty stack" # Raise error if popping from empty stack.
        
        last_elm = self._data[self._size] #store the last elememt before deleting.
        del self._data[self._size] #Remove(Pop) the last element.
        self._size -= 1

        return last_elm
    
stack1 = stack()
stack1.put(1)
stack1.put(2)
stack1.put(3)
stack1.put(4)
stack1.put(5)
print("Length of the stack: ", len(stack1))
print("Elemnts of the stack:")
for i in stack1:
    print("  |\t", i)

stack1[0] = 2
print(stack1[0])
