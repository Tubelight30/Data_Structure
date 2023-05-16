# Explanation

This is a recursive function that inserts a new node with the given data at a specified index in a linked list. The function takes three arguments: a pointer to the head of the linked list, an integer data, and an integer index i.

The function first checks if the head pointer is NULL. If it is, it returns NULL, indicating that the linked list is empty and the new node cannot be inserted.

If the index i is 0, the function creates a new node with the given data and sets its next pointer to the current head of the linked list. It then sets the head pointer to the new node and returns it, which becomes the new head of the linked list.

If the index i is 1, the function creates a new node with the given data and inserts it after the current head of the linked list. It then returns the pointer to the current head of the linked list, which remains the head of the linked list.

If the index i is greater than 1, the function recursively calls itself with the next node in the linked list and decrements the index i by 1. This continues until the index i reaches 1, at which point the function creates a new node with the given data and inserts it after the current node. It then returns the pointer to the current node, which remains in its original position in the linked list.

Finally, the function returns the pointer to the head of the linked list, which may have changed if a new node was inserted at the beginning of the linked list.

## the line Node* curr = insert_recursively(head->next,data,i-1)

The line Node* curr = insert_recursively(head->next,data,i-1) is used to recursively traverse the linked list until the desired index is reached.

When the index i is greater than 1, the function recursively calls itself with the next node in the linked list, which is head->next. This means that the function is called on the rest of the linked list, starting from the second node.

The returned value from the recursive call is stored in the curr pointer. This is done because the function needs to return the head pointer of the linked list, which may have changed if a new node was inserted at the beginning of the linked list.

After the recursive call returns, the function simply returns the original head pointer, which remains unchanged if the index i is greater than 1. If the index i is 0 or 1, the head pointer may have changed, and the new head pointer is returned instead.

## Why we return head at end

The reason we return head at the end of the function instead of curr is because the curr pointer is used only for traversing the linked list recursively and inserting the new node at the desired index.

However, the head pointer of the linked list may have changed if the new node was inserted at the beginning of the linked list. Therefore, we need to return the updated head pointer to the calling function.

If the new node was inserted at the beginning of the linked list, the head pointer would have been updated in the function, and we need to return the new head pointer. If the new node was inserted at any other position in the linked list,the head pointer would remain unchanged, and we can simply return the original head pointer.

Therefore, we return head at the end of the function to ensure that the calling function receives the correct head pointer of the linked list, whether it has been updated or not.

## Note for future me

The recursion is pretty straighforward. use code visualizer if not getting it.
