# Linked list

**Description:**
In computer science, a linked list is a linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. [read more](https://en.wikipedia.org/wiki/Linked_list)

**General manipulation:**
* Partition List: https://leetcode.com/problems/partition-list/
    <details><summary>Solution</summary><p>

       We introduce two new pointers low and high that are pointing to the
       dummy node. While iterating through the original list we keep
       updating these two pointers based on the comparison result between
       current list node and target value.
       When iteration is completed we need to connect low and high list.
 
</p></details>

* Merge two sorted list: https://leetcode.com/problems/merge-two-sorted-lists/
    <details><summary>Solution</summary><p>

       We introduce new pointer ptr that is pointing to the dummy node.
       While iterating through the input lists we keep updating
       introduced pointer based on the comparison result between
       node values of two input lists.
       When iteration is completed and if one of the lists is not
       empty we should connect introduced list with the not empty list.
 
</p></details>

* Merge K sorted list: https://leetcode.com/problems/merge-k-sorted-lists/
    <details><summary>Solution</summary><p>

       Solution is based on a priority queue. pq is created with the custom
       comparison operator that we compare between values of two nodes.
       Firstly, we will iterate thoroug the input lists and push the first
       nodes from each list to the pq.
       Then we will create a result list that will point to the dummy node.
       While pq is not empty we will keep removing elements from pq and
       insert it to the result list. If next pointer of the removed node is
       not pointed to the nullptr we will insert it to the pq.
 
</p></details>

* Copy List with Random Pointer: https://leetcode.com/problems/copy-list-with-random-pointer/
    <details><summary>Solution</summary><p>

       Firstly we create an unordered_map which will map orogonal list node pointer
       to the its deep copy. Also, we introduce new list node pointer that will
       point to the dummy node. 
       While iterating thorugh the original list:
       1. We will check if the node already exist in the map, if so we will use
          that saved pointer as a next pointer in our result list.
       2. If the element doesn't exist in the map we will create a new node, save
          it in the map and use it as a next pointer in out result list.
       3. Then if random pointer is not equal to the nullptr, then we need to:
          *  Check if the random pointer already exist in the map, if so we will use
             that saved pointer as a next random pointer in our result list.
          *  If the element doesn't exist in the map we will create a new node, save
          it in the map and use it as a next random pointer in out result list.

</p></details>

* Add two numbers: https://leetcode.com/problems/add-two-numbers/
    <details><summary>Solution</summary><p>

       We create a new list node pointer that will point to the dummy node.
       While iterating through the input lists we will try to get the values
       from two nodes.
       Then we calculate the sum of these node values consider carry result
       from previous operation.
       We will create a new node with the sum value mod 10. And continue
       iterating while ar least one node is not eqaul to nullptr.
       
</p></details>

* Add Two Numbers II: https://leetcode.com/problems/add-two-numbers-ii/
    <details><summary>Solution</summary><p>

       This solution is mostly base on a previous solution, but we also
       need tor everse the result list before returning it to the caller.
       
</p></details>

**Reverse linked list problem:**
* Reverse linked list: https://leetcode.com/problems/reverse-linked-list/
* Reverse Linked List II: https://leetcode.com/problems/reverse-linked-list-ii/
* Reverse Nodes in K Groups: https://leetcode.com/problems/reverse-nodes-in-k-group/

**All in one problems:**
* Reorder list: https://leetcode.com/problems/reorder-list/

**Fast and slow pointers:**
* Middle of linked lsit: https://leetcode.com/problems/middle-of-the-linked-list/
* Linked List Cycle: https://leetcode.com/problems/linked-list-cycle/

**Two pointers technique:**
* Remove Nth Node from End of the List: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
* Swapping Nodes in a Linked List: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

**Design problem:**
* Design Linked List: https://leetcode.com/problems/design-linked-list/submissions/
