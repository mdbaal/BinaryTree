# C++ BinaryTree
#### The Main.cpp runs a demo / test, to show the tree functionality.
### Tree functionality

- Making a new tree can be done in 2 ways, BinTree tree = BinTree(*value of first node*) or BinTree tree = BinTree().
- Adding a node is done via tree.addnode(*double*) or tree.addNode(*node pointer*).
- Removing a node uses the same input as the addNode function, only it removes the node from the tree.
- Checking the tree size can be done via size().
- You can also put the tree in to a array/vector by using the toVector() method.
- There are several ways of finding or checking for a node:
 1. findMin() & findMax(), these return the minimum and maximum values of the tree.
 2. findMinNode() & findMaxNode(), these return the adres of the minimum and maximum values of the tree.
 3. findNode(*value*), this returns the adres of the input value.
 4. contains(*value*), return a bool if it the tree contains the input value or not.
