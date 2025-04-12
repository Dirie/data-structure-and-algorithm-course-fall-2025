# Define a Node class to represent each element in the linked list
class Node:
    def __init__(self, data, next_node=None):
        self.data = data  # The value of the node
        self.next = next_node  # Reference to the next node (default to None)

# Function to construct the linked list
def makelist(data, next_node=None):
    return Node(data, next_node)

# Define an empty list as None (base case for recursion)
emptylist = None

# Construct the linked list from the array A = [4, 5, 1, 2, 9]
linked_list = makelist(4, makelist(5, makelist(1, makelist(2, makelist(9, emptylist)))))

# Function to print the linked list
def print_linked_list(node):
    while node:
        print(node.data, end=" -> ")
        node = node.next
    print("None")  # To represent the end of the list

# Output the constructed linked list
print_linked_list(linked_list)
