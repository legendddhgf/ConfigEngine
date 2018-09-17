/* ****************************************************************
 * Insertion for a btree sample code from
 * https://www.geeksforgeeks.org/b-tree-set-1-insert-2/
 *
 * Algorithm
 *
 * 1) Initialize x as a root.
 * 2) While x is not a leaf:
 *    a) Find child of x that is going to be traversed next. Let child = y.
 *    b) If y is not full, change x to poinit to y.
 *    c) If y is full, split and change x to point to one of the two parts of y.
 *       If k is smaller than mid key in y, then set x as first part of y. Else
 *       second part of y. When we split y, we move a key from y to its parent x.
 * 3) The loop in step 2 stops when x is a leaf. x must have space for 1 extra
 *    key as we have been splitting all nodes in advance. Insert k to x.
 *
 ********************************************************************/

// C++ program for B-Tree insertion

#include<iostream>

using namespace std;

class Node {
   int *keys; // An array of keys
   int t; // Minimum degree
   Node **C; // An array of child pointers
   int n; // Current number of keys
   bool leaf; // Is true when node is leaf. Otherwise false.

   public:
   Node(int _t, bool _leaf); // Constructor

   void insertNonFull(int k); // Node must be non-full when called

   void splitChild(int i, Node *y); // i is index of child array C[].
   // child y must be full when called.

   void traverse();

   Node *search(int k); // returns NULL if k is not present.

   // Make btree friend of this so that it can access private members of the functions here.
   friend class btree;
};

class btree {
   Node *root;
   int t; // min degree
   public: // initialize tree as empty
   btree(int _t) {
      root = NULL;
      t = _t;
   }

   void traverse() {
      if (root != NULL)
         root->traverse();
   }

   Node* search(int k) {
      return (root == NULL) ? NULL : root-> search(k);
   }

   void insert(int k);
};

// Constructor for btreenode class
Node:Node(int t1, bool leaf1) {
        t = t1; // replicate vars
        leaf = leaf1;
        keys = new int[2*t-1]; // allocate memory for max number of possible keys
        C = new Node *[2*t];
        n = 0; // number of keys is zero
     }
