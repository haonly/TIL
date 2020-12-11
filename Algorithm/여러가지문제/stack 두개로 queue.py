class Stack:
    def __init__(self):
        self.items = []
    
    def push(self, item):
        self.items.append(item)
        
    def pop(self):
        return self.items.pop()
    
    def print_stack(self):
        print(self.items)
    
    def is_empty(self):
        return self.items == []
		
		
class myQueue:
    def __init__(self):
        self.stack1 = Stack()
        self.stack2 = Stack()
    
    def enqueue(self, item):
        self.stack1.push(item)
    
    def dequeue(self):
        if self.stack2.is_empty():
            while self.stack1.is_empty() is False:
                self.stack2.push(self.stack1.pop())
            while self.stack2.is_empty() is False:
                print(self.stack2.pop())
        #return self.stack2.pop()
    
    def print_queue(self):
        self.stack1.print_stack()

		
q = myQueue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.print_queue()
q.dequeue()