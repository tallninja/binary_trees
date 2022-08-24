# 0x1D. C - Binary trees

# General
* What is a binary tree
* What is the difference between a binary tree and a Binary Search Tree
* What is the possible gain in terms of time complexity compared to linked lists
* What are the depth, the height, the size of a binary tree
* What are the different traversal methods to go through a binary tree
* What is a complete, a full, a perfect, a balanced binary tree

# Data structures
# Basic Binary Tree

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

# Binary Search Tree
    typedef struct binary_tree_s bst_t;
# AVL Tree
    typedef struct binary_tree_s avl_t;
# Max Binary Heap
    typedef struct binary_tree_s heap_t;

# Tasks

## 0. New node
Write a function that creates a binary tree node

* Prototype: binary_tree_t `*binary_tree_node(binary_tree_t *parent, int value);`
* Where `parent` is a pointer to the parent node of the node to create
* And `value` is the value to put in the new node
* When created, a node does not have any child
* Your function must return a pointer to the new node, or `NULL` on failure

## 1. Insert left
function that inserts a node as the left-child of another node

* Prototype: binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
* Where `parent` is a pointer to the node to insert the left-child in
* And `value` is the value to store in the new node
* Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
* If parent already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the     new node.
```
alex@/tmp/binary_trees$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root->right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
alex@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)                                            
alex@/tmp/binary_trees$
```
## Repo:

* GitHub repository: binary_trees
* File: [1-binary_tree_insert_left.c]

## 2. Insert right
Write a function that inserts a node as the right-child of another node

* Prototype: binary_tree_t `*binary_tree_insert_right(binary_tree_t *parent, int value);`
* Where `parent` is a pointer to the node to insert the right-child in
* And `value` is the value to store in the new node
* Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
* If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.
```
alex@/tmp/binary_trees$ cat 2-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
alex@/tmp/binary_trees$ ./2-right 
  .--(098)--.
(012)     (402)

  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
alex@/tmp/binary_trees$
```
## Repo:

* GitHub repository: binary_trees
* File: `2-binary_tree_insert_right.c`

<div data-role="task1470" data-position="4">
              <div class=" clearfix gap" id="task-1470">
<span id="user_id" data-id="1283"></span>
<h4 class="task">
3. Delete
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that deletes an entire binary tree</p>

<ul>
<li>Prototype: <code>void binary_tree_delete(binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to delete</li>
<li>If <code>tree</code> is <code>NULL</code>, do nothing</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 3-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
alex@/tmp/binary_trees$ valgrind ./3-del
==13264== Memcheck, a memory error detector
==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==13264== Command: ./3-del
==13264== 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
==13264== 
==13264== HEAP SUMMARY:
==13264==     in use at exit: 0 bytes in 0 blocks
==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
==13264== 
==13264== All heap blocks were freed -- no leaks are possible
==13264== 
==13264== For counts of detected and suppressed errors, rerun with: -v
==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>


  <!-- Task URLs -->

  <!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>3-binary_tree_delete.c</code></li>
</ul>

</div>
</div>

<div data-role="task1471" data-position="5">
              <div class=" clearfix gap" id="task-1471">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
4. Is leaf
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>


<!-- Task Body -->
<p>Write a function that checks if a node is a leaf</p>

<ul>
<li>Prototype: <code>int binary_tree_is_leaf(const binary_tree_t *node);</code></li>
<li>Where <code>node</code> is a pointer to the node to check</li>
<li>Your function must return <code>1</code> if <code>node</code> is a leaf, otherwise <code>0</code></li>
<li>If <code>node</code> is <code>NULL</code>, return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 4-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_leaf(root);
    printf("Is %d a leaf: %d\n", root-&gt;n, ret);
    ret = binary_tree_is_leaf(root-&gt;right);
    printf("Is %d a leaf: %d\n", root-&gt;right-&gt;n, ret);
    ret = binary_tree_is_leaf(root-&gt;right-&gt;right);
    printf("Is %d a leaf: %d\n", root-&gt;right-&gt;right-&gt;n, ret);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
alex@/tmp/binary_trees$ ./4-leaf 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a leaf: 0
Is 128 a leaf: 0
Is 402 a leaf: 1
alex@/tmp/binary_trees$
</code></pre>


  <!-- Task URLs -->

  <!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>4-binary_tree_is_leaf.c</code></li>
</ul>

</div>

</div>


<h4 class="task">
5. Is root
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>


<!-- Task Body -->
<p>Write a function that checks if a given node is a root</p>

<ul>
<li>Prototype: <code>int binary_tree_is_root(const binary_tree_t *node);</code></li>
<li>Where <code>node</code> is a pointer to the node to check</li>
<li>Your function must return <code>1</code> if <code>node</code> is a root, otherwise <code>0</code></li>
<li>If <code>node</code> is <code>NULL</code>, return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 5-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_root(root);
    printf("Is %d a root: %d\n", root-&gt;n, ret);
    ret = binary_tree_is_root(root-&gt;right);
    printf("Is %d a root: %d\n", root-&gt;right-&gt;n, ret);
    ret = binary_tree_is_root(root-&gt;right-&gt;right);
    printf("Is %d a root: %d\n", root-&gt;right-&gt;right-&gt;n, ret);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
alex@/tmp/binary_trees$ ./5-root 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a root: 1
Is 128 a root: 0
Is 402 a root: 0
alex@/tmp/binary_trees$
</code></pre>


  <!-- Task URLs -->

  <!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>5-binary_tree_is_root.c</code></li>
</ul>

</div>

</div>

<div data-role="task1473" data-position="7">
              <div class=" clearfix gap" id="task-1473">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
6. Pre-order traversal
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that goes through a binary tree using pre-order traversal</p>

<ul>
<li>Prototype: <code>void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to traverse</li>
<li>And <code>func</code> is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.</li>
<li>If <code>tree</code> or <code>func</code> is <code>NULL</code>, do nothing</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 6-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_preorder(root, &amp;print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
alex@/tmp/binary_trees$ ./6-pre
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
6
56
402
256
512
alex@/tmp/binary_trees$
</code></pre>


 <!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>6-binary_tree_preorder.c</code></li>
</ul>

</div>

</div>

<div data-role="task1474" data-position="8">
              <div class=" clearfix gap" id="task-1474">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
7. In-order traversal
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that goes through a binary tree using in-order traversal</p>

<ul>
<li>Prototype: <code>void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to traverse</li>
<li>And <code>func</code> is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.</li>
<li>If <code>tree</code> or <code>func</code> is <code>NULL</code>, do nothing</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 7-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_inorder(root, &amp;print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
alex@/tmp/binary_trees$ ./7-in
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
12
56
98
256
402
512
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>7-binary_tree_inorder.c</code></li>
</ul>

</div>
</div>

<div data-role="task1475" data-position="9">
              <div class=" clearfix gap" id="task-1475">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
8. Post-order traversal
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that goes through a binary tree using post-order traversal</p>

<ul>
<li>Prototype: <code>void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to traverse</li>
<li>And <code>func</code> is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.</li>
<li>If <code>tree</code> or <code>func</code> is <code>NULL</code>, do nothing</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 8-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_postorder(root, &amp;print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
alex@/tmp/binary_trees$ ./8-post
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
56
12
256
512
402
98
alex@/tmp/binary_trees$
</code></pre>

  <!-- Task URLs -->

  <!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>8-binary_tree_postorder.c</code></li>
</ul>

</div>

</div>

<div data-role="task1476" data-position="10">
              <div class=" clearfix gap" id="task-1476">
<span id="user_id" data-id="1283"></span>
<h4 class="task">
9. Height
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that measures the height of a binary tree</p>

<ul>
<li>Prototype: <code>size_t binary_tree_height(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to measure the height.</li>
<li>If <code>tree</code> is <code>NULL</code>, your function must return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 9-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root-&gt;n, height);
    height = binary_tree_height(root-&gt;right);
    printf("Height from %d: %lu\n", root-&gt;right-&gt;n, height);
    height = binary_tree_height(root-&gt;left-&gt;right);
    printf("Height from %d: %lu\n", root-&gt;left-&gt;right-&gt;n, height);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
alex@/tmp/binary_trees$ ./9-height 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Height from 98: 2
Height from 128: 1
Height from 54: 0
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
  <li>File: <code>9-binary_tree_height.c</code></li>
</ul>

</div>
</div>

<div data-role="task1477" data-position="11">
              <div class=" clearfix gap" id="task-1477">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
10. Depth
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that measures the depth of a node in a binary tree</p>

<ul>
<li>Prototype: <code>size_t binary_tree_depth(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the node to measure the depth</li>
<li>If <code>tree</code> is <code>NULL</code>, your function must return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 10-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root-&gt;n, depth);
    depth = binary_tree_depth(root-&gt;right);
    printf("Depth of %d: %lu\n", root-&gt;right-&gt;n, depth);
    depth = binary_tree_depth(root-&gt;left-&gt;right);
    printf("Depth of %d: %lu\n", root-&gt;left-&gt;right-&gt;n, depth);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
alex@/tmp/binary_trees$ ./10-depth 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Depth of 98: 0
Depth of 128: 1
Depth of 54: 2
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>10-binary_tree_depth.c</code></li>
</ul>

</div>

</div>

<div data-role="task1478" data-position="12">
              <div class=" clearfix gap" id="task-1478">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
11. Size
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that measures the size of a binary tree</p>

<ul>
<li>Prototype: <code>size_t binary_tree_size(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to measure the size</li>
<li>If <code>tree</code> is <code>NULL</code>, the function must return 0</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 11-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t size;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size of %d: %lu\n", root-&gt;n, size);
    size = binary_tree_size(root-&gt;right);
    printf("Size of %d: %lu\n", root-&gt;right-&gt;n, size);
    size = binary_tree_size(root-&gt;left-&gt;right);
    printf("Size of %d: %lu\n", root-&gt;left-&gt;right-&gt;n, size);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size
alex@/tmp/binary_trees$ ./11-size 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Size of 98: 5
Size of 128: 2
Size of 54: 1
alex@/tmp/binary_trees$
</code></pre>

<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>11-binary_tree_size.c</code></li>
</ul>

</div>

</div>

<div data-role="task1479" data-position="13">
              <div class=" clearfix gap" id="task-1479">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
12. Leaves
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that counts the leaves in a binary tree</p>

<ul>
<li>Prototype: <code>size_t binary_tree_leaves(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to count the number of leaves</li>
<li>If <code>tree</code> is <code>NULL</code>, the function must return 0</li>
<li>A <code>NULL</code> pointer is not a leaf</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 12-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t leaves;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves in %d: %lu\n", root-&gt;n, leaves);
    leaves = binary_tree_leaves(root-&gt;right);
    printf("Leaves in %d: %lu\n", root-&gt;right-&gt;n, leaves);
    leaves = binary_tree_leaves(root-&gt;left-&gt;right);
    printf("Leaves in %d: %lu\n", root-&gt;left-&gt;right-&gt;n, leaves);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves
alex@/tmp/binary_trees$ ./12-leaves 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Leaves in 98: 2
Leaves in 128: 1
Leaves in 54: 1
alex@/tmp/binary_trees$
</code></pre>

<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>12-binary_tree_leaves.c</code></li>
</ul>

</div>

</div>

<div data-role="task1480" data-position="14">
              <div class=" clearfix gap" id="task-1480">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
13. Nodes
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that counts the nodes with at least 1 child in a binary tree</p>

<ul>
<li>Prototype: <code>size_t binary_tree_nodes(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to count the number of nodes</li>
<li>If <code>tree</code> is <code>NULL</code>, the function must return 0</li>
<li>A <code>NULL</code> pointer is not a node</li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 13-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t nodes;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    nodes = binary_tree_nodes(root);
    printf("Nodes in %d: %lu\n", root-&gt;n, nodes);
    nodes = binary_tree_nodes(root-&gt;right);
    printf("Nodes in %d: %lu\n", root-&gt;right-&gt;n, nodes);
    nodes = binary_tree_nodes(root-&gt;left-&gt;right);
    printf("Nodes in %d: %lu\n", root-&gt;left-&gt;right-&gt;n, nodes);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes
alex@/tmp/binary_trees$ ./13-nodes
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Nodes in 98: 3
Nodes in 128: 1
Nodes in 54: 0
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>13-binary_tree_nodes.c</code></li>
</ul>

</div>

</div>

<div data-role="task1481" data-position="15">
              <div class=" clearfix gap" id="task-1481">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
14. Balance factor
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>


<!-- Task Body -->
<p>Write a function that measures the balance factor of a binary tree</p>

<ul>
<li>Prototype: <code>int binary_tree_balance(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to measure the balance factor</li>
<li>If <code>tree</code> is <code>NULL</code>, return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 14-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int balance;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root-&gt;left, 50);
    binary_tree_insert_left(root-&gt;left-&gt;left, 10);
    binary_tree_insert_left(root-&gt;left-&gt;left-&gt;left, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root-&gt;n, balance);
    balance = binary_tree_balance(root-&gt;right);
    printf("Balance of %d: %+d\n", root-&gt;right-&gt;n, balance);
    balance = binary_tree_balance(root-&gt;left-&gt;left-&gt;right);
    printf("Balance of %d: %+d\n", root-&gt;left-&gt;left-&gt;right-&gt;n, balance);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 14-binary_tree_balance.c 14-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance
alex@/tmp/binary_trees$ ./14-balance
                      .-------(098)--.
            .-------(045)--.       (128)--.
       .--(012)--.       (050)          (402)
  .--(010)     (054)
(008)
Balance of 98: +2
Balance of 128: -1
Balance of 54: +0
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>14-binary_tree_balance.c</code></li>
</ul>

</div>

</div>

<div data-role="task1482" data-position="16">
              <div class=" clearfix gap" id="task-1482">
<span id="user_id" data-id="1283"></span>


<h4 class="task">
15. Is full
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that checks if a binary tree is full</p>

<ul>
<li>Prototype: <code>int binary_tree_is_full(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to check</li>
<li>If <code>tree</code> is <code>NULL</code>, your function must return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 15-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int full;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    binary_tree_print(root);

    full = binary_tree_is_full(root);
    printf("Is %d full: %d\n", root-&gt;n, full);
    full = binary_tree_is_full(root-&gt;left);
    printf("Is %d full: %d\n", root-&gt;left-&gt;n, full);
    full = binary_tree_is_full(root-&gt;right);
    printf("Is %d full: %d\n", root-&gt;right-&gt;n, full);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 15-binary_tree_is_full.c 15-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full
alex@/tmp/binary_trees$ ./15-full
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 full: 0
Is 12 full: 1
Is 128 full: 0
alex@/tmp/binary_trees$
</code></pre>

<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>15-binary_tree_is_full.c</code></li>
</ul>

</div>
</div>

<div data-role="task1483" data-position="17">
              <div class=" clearfix gap" id="task-1483">
<span id="user_id" data-id="1283"></span>
<h4 class="task">
16. Is perfect
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that checks if a binary tree is perfect</p>

<ul>
<li>Prototype: <code>int binary_tree_is_perfect(const binary_tree_t *tree);</code></li>
<li>Where <code>tree</code> is a pointer to the root node of the tree to check</li>
<li>If <code>tree</code> is <code>NULL</code>, your function must return <code>0</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 16-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int perfect;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 10);

    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n\n", perfect);

    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 10);
    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n\n", perfect);

    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 10);
    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n", perfect);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 16-binary_tree_is_perfect.c 16-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect
alex@/tmp/binary_trees$ ./16-perfect 
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (010)     (402)
Perfect: 1

       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (010)       .--(402)
                              (010)
Perfect: 0

       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (010)       .--(402)--.
                              (010)     (010)
Perfect: 0
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>16-binary_tree_is_perfect.c</code></li>
</ul>

</div>
</div>

<div data-role="task1558" data-position="18">
              <div class=" clearfix gap" id="task-1558">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
17. Sibling
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that finds the sibling of a node</p>

<ul>
<li>Prototype: <code>binary_tree_t *binary_tree_sibling(binary_tree_t *node);</code></li>
<li>Where <code>node</code> is a pointer to the node to find the sibling</li>
<li>Your function must return a pointer to the sibling node</li>
<li>If <code>node</code> is <code>NULL</code> or the parent is <code>NULL</code>, return <code>NULL</code></li>
<li>If <code>node</code> has no sibling, return <code>NULL</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 17-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *sibling;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 110);
    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 200);
    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 512);

    binary_tree_print(root);
    sibling = binary_tree_sibling(root-&gt;left);
    printf("Sibling of %d: %d\n", root-&gt;left-&gt;n, sibling-&gt;n);
    sibling = binary_tree_sibling(root-&gt;right-&gt;left);
    printf("Sibling of %d: %d\n", root-&gt;right-&gt;left-&gt;n, sibling-&gt;n);
    sibling = binary_tree_sibling(root-&gt;left-&gt;right);
    printf("Sibling of %d: %d\n", root-&gt;left-&gt;right-&gt;n, sibling-&gt;n);
    sibling = binary_tree_sibling(root);
    printf("Sibling of %d: %p\n", root-&gt;n, (void *)sibling);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling
alex@/tmp/binary_trees$ ./17-sibling
       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (110)       .--(402)--.
                              (200)     (512)
Sibling of 12: 128
Sibling of 110: 402
Sibling of 54: 10
Sibling of 98: (nil)
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>17-binary_tree_sibling.c</code></li>
</ul>

</div>
</div>

<div data-role="task1559" data-position="19">
              <div class=" clearfix gap" id="task-1559">
<span id="user_id" data-id="1283"></span>

<h4 class="task">
18. Uncle
  <span class="alert alert-warning mandatory-optional">
	mandatory
  </span>
</h4>

<!-- Task Body -->
<p>Write a function that finds the uncle of a node</p>

<ul>
<li>Prototype: <code>binary_tree_t *binary_tree_uncle(binary_tree_t *node);</code></li>
<li>Where <code>node</code> is a pointer to the node to find the uncle</li>
<li>Your function must return a pointer to the uncle node</li>
<li>If <code>node</code> is <code>NULL</code>, return <code>NULL</code></li>
<li>If <code>node</code> has no uncle, return <code>NULL</code></li>
</ul>

<pre><code>alex@/tmp/binary_trees$ cat 18-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 110);
    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 200);
    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 512);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root-&gt;right-&gt;left);
    printf("Uncle of %d: %d\n", root-&gt;right-&gt;left-&gt;n, uncle-&gt;n);
    uncle = binary_tree_uncle(root-&gt;left-&gt;right);
    printf("Uncle of %d: %d\n", root-&gt;left-&gt;right-&gt;n, uncle-&gt;n);
    uncle = binary_tree_uncle(root-&gt;left);
    printf("Uncle of %d: %p\n", root-&gt;left-&gt;n, (void *)uncle);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle
alex@/tmp/binary_trees$ ./18-uncle
       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (110)       .--(402)--.
                              (200)     (512)
Uncle of 110: 12
Uncle of 54: 128
Uncle of 12: (nil)
alex@/tmp/binary_trees$
</code></pre>


<!-- Task URLs -->

<!-- Github information -->
<p class="sm-gap"><strong>Repo:</strong></p>
<ul>
  <li>GitHub repository: <code>binary_trees</code></li>
	<li>File: <code>18-binary_tree_uncle.c</code></li>
</ul>
</div>
</div>
