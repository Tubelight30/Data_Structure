# Explanation

## Node *takeInput()

> - Node *takeInput() is a function declaration in C++, which indicates that the function named takeInput() returns a pointer to a Node object.
>
> - The \* before the function name indicates that the function returns a pointer to an object of the Node class. So the return type of this function is a pointer to a Node object, which is represented by the syntax Node \*.

We define a function takeInput() that takes input from the user to create a linked list and returns the head of the linked list.

The function takes integer input from the user using cin>>data. The integer input is stored in the variable data.

Initially, the head pointer is set to NULL, indicating an empty linked list.

The while loop continues until the user enters -1, which indicates the end of the linked list. When the user enters -1, loop will end and all elements stored till now will be added to the linked list

Only problem is that we cannot enter -1 as an element but we can fix that later

Within the loop, a new node is created using the new operator, and the value of data is passed as an argument to the constructor of the Node class to initialize the data of the new node.

If the head is NULL, the new node is assigned as the head of the linked list.

The else statement is executed when the head pointer is not NULL. This means that there is already at least one node in the linked list.
Then, a temporary pointer named temp is initialized to point to the first node of the linked list, which is pointed to by the head pointer.

The while loop is used to traverse through the linked list until the last node is reached. This is done by checking if the next pointer of the current node pointed to by temp is NULL. If it is not NULL, the temp pointer is updated to point to the next node in the linked list.

Once the last node is reached, the next pointer of the last node is updated to point to the new node, effectively adding the new node to the end of the linked list.

We can implement tail feature as i have done to improve our code and bring down time complexity from O(n^2) to O(n).
