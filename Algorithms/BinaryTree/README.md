# Binary Tree

**Description:**

A binary tree (BT) is a tree data structure in which each node has at most two children,
which are referred to as the left child and the right child. [read more](https://en.wikipedia.org/wiki/Binary_tree)

A binary search tree (BST), also called an ordered or sorted binary tree,
is a rooted binary tree whose internal nodes each store a key greater than all
the keys in the node's left subtree and less than those in its right subtree.

Ancestor: any node from the root to node x.

Successor (the node stay ahead of given node: left-most node of right subtree or successor is an ancestor.

Predecessor (the node stay behind of given node): right-most node of left subtree or successor is an ancestor.

## Tree traversals problems
<details><summary>Inorder traversal: https://leetcode.com/problems/binary-tree-inorder-traversal/</summary><p>

        Inorder traversal can be implemented using recursive or iterative algorithm.
        During the in-order traversal algorithm, the left subtree is explored first,
        followed by root, and finally nodes on the right subtree. 
 
</p></details>

<details><summary>Preorder traversal: https://leetcode.com/problems/binary-tree-preorder-traversal/</summary><p>

        Preorder traversal can be implemented using recursive or iterative algorithm.
        During the pre-order traversal algorithm, the root node is visited first,
        followed by left sub-tree, and finally nodes on the right subtree. 
 
</p></details>

<details><summary>Postorder traversal: https://leetcode.com/problems/binary-tree-postorder-traversal/</summary><p>

        Postorder traversal can be implemented using recursive or iterative algorithm.
        During the postorder traversal algorithm, the left subtree is explored first,
        followed by the right subtree, and finally root node.
 
</p></details>

<details><summary>Level order traversal: https://leetcode.com/problems/binary-tree-level-order-traversal/</summary><p>

        Level order traversal can be implemented using recursive or iterative algorithm.
        We should visit each nodes level by level. This means that we can use BFS algorithm
        to solve it using iterative approach.
        In order to solve it using recursive approach we should push new empty vector into the result
        vector, if the vector size is equal to the current level. Then we just need in insert the node
        element into the current level index of result vector: res[l].push_back(r->val).
 
</p></details>

<details><summary>Zigzag order traversal: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/</summary><p>

       We can use the same approach as for level order traversal, but we should
       reverse the nodes in the temp vector depends on the result vector size (BFS).
       Example: if (res.size() % 2 != 0) reverse(temp.begin(), temp.end());
       Or we can detect an insert position to the temo vector depends on the current
       level value (DFS).
       Example: res[level].insert(level % 2 != 0
                              ? res[level].begin()
                              : res[level].end(), root->val);
 
</p></details>

<details><summary>Vertical order traversal: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/</summary><p>

       We can solve this problem by applying DFS on the original tree and construct the
       unordered map with the coordinates of each node in the tree. Then we can traverse
       through this map, sort element inside the map, and insert them into result vector.
 
</p></details>

* Morris traversal: https://leetcode.com/problems/binary-tree-inorder-traversal/
* Binary Tree Right Side View: https://leetcode.com/problems/binary-tree-right-side-view/
* Boundary of Binary Tree: https://leetcode.com/problems/boundary-of-binary-tree/

## General problems
* Depth ob binary tree: https://leetcode.com/problems/maximum-depth-of-binary-tree/
* Diameter of Binary Tree: https://leetcode.com/problems/diameter-of-binary-tree/
* Invert binary tree: https://leetcode.com/problems/invert-binary-tree/
* Balanced Binary Tree: https://leetcode.com/problems/balanced-binary-tree/
* Symmetric Tree: https://leetcode.com/problems/symmetric-tree/
* Subtree of Another Tree: https://leetcode.com/problems/subtree-of-another-tree/
* Insert into a Binary Search Tree: https://leetcode.com/problems/insert-into-a-binary-search-tree/
* Delete Node in a BST: https://leetcode.com/problems/delete-node-in-a-bst/
* Closest Binary Search Tree Value: https://leetcode.com/problems/closest-binary-search-tree-value/

## Medimum problems
* Validate Binary Search Tree: https://leetcode.com/problems/validate-binary-search-tree/
* Balance a Binary Search Tree: https://leetcode.com/problems/balance-a-binary-search-tree/
* Flip Equivalent Binary Trees: https://leetcode.com/problems/flip-equivalent-binary-trees/
* Lowest Common Ancestor of a Binary Tree: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

## Harder problems
* Binary Tree Maximum Path Sum: https://leetcode.com/problems/binary-tree-maximum-path-sum/
* Serialize and desirialize BST: https://leetcode.com/problems/serialize-and-deserialize-bst/
* Count Complete Tree Nodes: https://leetcode.com/problems/count-complete-tree-nodes/

## Trie problems
* Implement Trie (Prefix Tree): https://leetcode.com/problems/implement-trie-prefix-tree/
* Design Add and Search Words Data Structure: https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/
* Design Search Autocomplete System: https://leetcode.com/problems/design-search-autocomplete-system/submissions/
* Stream of Characters: https://leetcode.com/problems/stream-of-characters/
* Word Search II: https://leetcode.com/problems/word-search-ii/
