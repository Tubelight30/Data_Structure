# Queues

Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front.

>For inserting: enqueue function
>To access the front element: front function
>To delete: dequeue function(deletes the front element)
>For size: size function(returns the no. of elements in the queue)
>To check if empty: isEmpty function
>For capacity: capacity variable(returns the capacity of the queue)

We have to maintain two variables nextIndex and firstIndex. nextIndex will tell us where we have to insert the next element and firstIndex will tell us where the first element is present in the queue.

When queue is empty nextIndex will be 0 and firstIndex will be -1.

Suppose we have a queue of size 5 and we have inserted 3 elements in it. now nextIndex will be 3 and firstIndex will be 0. eg: 1 2 3 - -.
Now we dequeue one element. now nextIndex will be 3 and firstIndex will be 1.
This does not mean that 1 is deleted from the queue. it is still present in the queue but we can't access it. eg: - 2 3 - -. basically it is now garbage and we can't access it. the front element is 2 now.

>this is not a good way to implement a queue. we can't use the space which is left after deleting the elements. so we can use circular array to implement the queue.

Size can be determined by subtracting nextIndex from firstIndex.

Suppose we have a queue of size 5 and we have inserted 5 elements in it and then we dequeue 2 elements.eg: - - 3 4 5. **nextIndex** is 5 now and **firstIndex** is 2.

> - Now if we want to insert an element in the queue we can't do it because nextIndex is 5 and the size of the queue is 5. so we can't insert any element in the queue. But beginning of the queue is empty. so either we can shift the elements to the left or we can use circular array.
> - Shift the elements to the left is not a good idea because it will take O(n) time. so we can use circular array.
> - Means we want to add an element so we will add it at the first position **nextIndex should be 0 instead of 5** and **firstIndex** is 2. Now we add 6 eg: 6 - 3 4 5.**nextIndex** is 1 and **firstIndex** is 2.
If we call Front function then we will get 3.
> - Now if we do dequeue then we will get 3. eg: 6 - - 4 5. **nextIndex** is 1 and **firstIndex** is 3.
queue is basically still 4 5 6. by using circular array we can use the space which is left after deleting the elements.

Suppose our queue is 30 40 - 10 20. nextIndex is 2 and firstIndex is 3.

> - To find the size we can do nextIndex - firstIndex. but it will give us -1. so we can just maintain a variable size and do size++ when enqueue and size-- when dequeue.
> - Now if we insert 50 queue will be 30 40 50 10 20. nextIndex is 3 and firstIndex is 3.
> - Now if we want to insert 60 we can't do it because the queue is full and there are no empty spaces.
We call size function and we get no. of elements in queue. If size is equal to capacity then we can't insert any element in the queue. If not then we can insert the element in the queue as there is space in the queue.

## Using Header File

> we write basic code of queue and save it with .h extension. then we can use it in our main program by using #include "queue.h" and then we can use it in our main program. Basically we can use it as a library.

```cpp
