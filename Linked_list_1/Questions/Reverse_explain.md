# Explanation

If the current node is not NULL, the function makes a recursive call to Reverse with the next node as input. This means that the function will continue to call itself recursively until it reaches the end of the linked list, which is the node whose next pointer is NULL.

Once the end of the linked list is reached, the function starts printing the data of each node in reverse order. This is done by printing the data of the current node (head->data) after the recursive call to Reverse returns.

For example, if the input linked list is 1->2->3, the function will make the following recursive calls:

Reverse(1) -> Reverse(2) -> Reverse(3) -> Reverse(NULL)

When Reverse(NULL) is called, the function immediately returns, since there are no more nodes to process.Now as return is executed,the cout line in Reverse(3). Now the function has ended and we go to previous recursive call.
Once one cout line is executed in one recursive call *(Suppose Reverse(3))*. The function has ended so we go to the previous recursive call *(Reverse (2))* and the cout line over there is executed.  

Then, the function starts printing the data of each node in reverse order:

3 2 1
