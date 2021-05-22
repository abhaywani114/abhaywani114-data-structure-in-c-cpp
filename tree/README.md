#### What is a tree data structure? ####
A tree data structure is a non-linear structure in which data is organized in hierarchical order. It is a recursive data structure.

#### What is a linear and non-linear data structure? ####
*Linear Data Structure:* A linear data structure is a data structure in which data is stored linearly. Eg: Array, linked list, queue, etc
*Non-Linear Data Structure:* A non-linear data structure is a data structure in which data is stored non-linearly. Eg: Tree etc.

#### Terms associated with tree data structure ####
The topmost element of a tree is called *root*
- The interconnected nodes are called *children* while the preceding is called a *parent node*
- Children of the same node are called siblings.
- Node with 0 children is called a leaf node.
- Length of the path from the root node to x node, or, no of edges in the path from the root node to x node can be called *depth of x*
- No of the edges in the longest path from x node to a leaf node is called as *height of x*.
- The height of the root node is called the height of the tree.

#### What is a binary tree? ####
A tree in which there can be at most only 2 roots.

- Strict BT: In a BT it can either have 2 or 0 children.
- Complete BT: All levels of the tree are filled except the last level.
- Max no of nodes at level i = *2^i*
- Maximum no of nodes with height h = *2 ^(h + 1) -1*
- Height of complete BT =  *floor(log2(n))*
#### What is a balanced binary tree? ####
A balanced binary tree, also referred to as a height-balanced binary tree, is defined as a binary tree in which the height of the left and right subtree of any node differs by not more than 1. (Source: programiz)

#### What is a binary search tree? ####
A binary tree in which for each node values of the node in left is lesser than the nodes at right is called a binary search tree.

#### Implementation of BT ####
a) By creating nodes
b) By using arrays.
For arrays, if i is the index, then: 
- left-child-node = *2i +1*
- right-child-node = *2i + 2*

## Programs ###
- **Binary tree.cpp** demonstrating an *binary search tree* implementation as using **linked list** in C++.
- **binary_tree_find_min_max.c** demonstrating an *binary search tree* implementation as using **linked list** in C with the min/max algorithm.
