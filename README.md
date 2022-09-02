# 0x1D. C - Binary trees

## Resources

- [Binary tree](https://en.wikipedia.org/wiki/Binary_tree) (note the first line: `Not to be confused with B-tree`.)
- [Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)
- [Tree Traversal](https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm)
- [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- [Data structures: Binary Tree](https://www.youtube.com/watch?v=H5JubkIy_p8)

---

## More Info

### Data structures

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

### Basic Binary Tree

```text
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Binary Search Tree

```text
typedef struct binary_tree_s bst_t;
```

### AVL Tree

```text
typedef struct binary_tree_s avl_t;
```

### Max Binary Heap

```text
typedef struct binary_tree_s heap_t;
```

**Note**: For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.

### Print function

To match the examples in the tasks, you are given [this function](https://github.com/holbertonschool/0x1C.c)
This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction

---

## Tasks

### 0. New node

### 1. Insert left

### 2. Insert right

### 3. Delete

### 4. Is leaf

### 5. Is root

### 6. Pre-order traversal

### 7. In-order traversal

### 8. Post-order traversal

### 9. Height

### 10. Depth

### 11. Size

### 12. Leaves

### 13. Nodes

### 14. Balance factor

### 15. Is full

### 16. Is perfect

### 17. Sibling

### 18. Uncle
