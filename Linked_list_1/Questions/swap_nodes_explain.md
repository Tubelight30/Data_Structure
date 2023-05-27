# Explanation

    The function takes a pointer to the head of the linked list as input and returns a pointer to the new head of the modified linked list.

    A temporary pointer temp is created and set to the head of the linked list.

    A dummy node is created using the Node constructor, with its next pointer set to the head. This dummy node helps in handling the case where the head of the original linked list needs to be swapped.

    Two more pointers, prev and curr, are created and set to the dummy node and the head node, respectively. prev keeps track of the previous node in the original linked list, while curr points to the first node in the current pair that needs to be swapped.

    The main while loop continues as long as curr is not NULL and curr->next (the second node in the pair) is not NULL. This ensures that there are at least two nodes remaining in the linked list.

    Inside the loop, two additional pointers are created: nxtPair and second. nxtPair points to the node that the second node of the pair is currently pointing to (the node after the pair), while second points to the second node of the current pair.

    The swapping process involves modifying the next pointers of the involved nodes. First, second->next is set to curr, effectively reversing the order of the pair. Then, curr->next is set to nxtPair to maintain the connection with the next pair. Finally, prev->next is set to second, ensuring that the previous node (if any) now points to the new first node of the swapped pair.

    After the swapping process, the prev and curr pointers are updated to move to the next pair of nodes. prev is set to curr, and curr is set to nxtPair (the node after the current pair).

    Once the while loop completes, the swapping process for all pairs is finished, and the modified linked list can be obtained by accessing dummy->next. This pointer points to the new head of the linked list.

    The modified linked list is then printed using the print function.
>Use a code visualizer to gain much more clarity.
