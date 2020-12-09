class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class linked_list:
    def __init__(self):
        self.head = Node()

    def append(self, data):
        new_node = Node(data)
        cur = self.head
        while cur.next != None:
            cur = cur.next
        cur.next = new_node

    def length(self):
        cur = self.head
        total = 0
        while cur.next != None:
            total += 1
            cur = cur.next
        return total

    def display(self):
        data = []
        cur_node = self.head
        while cur_node.next != None:
            cur_node = cur_node.next
            data.append(cur_node.data)
        print(elems)

list = linked_list()
list.append(1)
list.append(2)
list.append(3)
list.display()
