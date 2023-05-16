# General Approaches

To solve this problem we can use multiple methods.
>-Method 1: we can start from head and go to last node and compare them
>then go to next of head and from starting travel to the second last element and compare them
>But this approach Time complexity O(n^2). as we have to travel from starting everytime and then compare.
>
>-Method 2:Create a copy of the linked list and then reverse it and then compare the two linked lists
>We can also put the original linked list in an array and then do comparing operations on the array.(This is not a bad approach but still we can optimise it.)
>Both these approach have time complexity O(n) but space complexity is O(n) as we are creating addtional data structure.
>
>-Method 3:By splitting linked list into two halves and reversing the second half and comparing it with first half.
>Space complexity is obviously O(1) as no new data structure. The time complexity to find mid point is O(n/2), the complexity to reverse second half is O(n/2) and comparing them also has O(n/2)
>so FINAL O(n/2)+O(n/2)O(n/2)=O(n/2).

## Diving into Approach 3
