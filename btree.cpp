#include<iostream>

using namespace std;

/****************************************************************************
 * From https://www.geeksforgeeks.org/b-tree-set-1-introduction-2/
 * The purpose of this sample code is for the testing and understanding of
 * the material solely.
 ****************************************************************************/

class Node {
   int *keys;
   int t; // Min degree
   int n; // Current number of keys
   bool leaf; // True when node is leaf. Otherwise false.


   public: // Make public
   Node(int _t, bool _leaf); // underscore is a naming convention?
   void traverse();
   Node *search(int k); // type node, returns NULL if ke is not present
   friend class tree;
};

class BTree {
   Node *root; // Pointer to root node
   int t;
   public:
   BTree(int _t) { // constructor class
      root = NULL;
      t = _t;
      void traverse() {
         if (root != NULL)
            root->traverse();
      }
      Node* search(int k) {
         return (root == NULL) ? NULL : root->search(k);
      }
   }
};

// Constructor for BTreeNode class
Node::Node(int _t, bool _leaf) {
   // Copy the given minimum degree and leaf property
   t = _t;
   leaf = _leaf;
   // Allocate memory for maximum number of possible keys and child pointers
   keys = new int[2*t-1];
   C = new Node *[2*t];
   // Initialize the number of keys as 0
   n = 0;
}

void Node::traverse() { // There are n keys and n+1 children, traverse through n keys and first n
   // and first n children
   int i;
   for (i = 0; i < n; i++) {
      if (leaf = false) {
         C[i]->traverse();
      }
      cout << " " << keys[i];
   }
   // Print the subtree rooted with last child
   if (leaf == false)
      C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
Node *Node::search(int k) {
   int i = 0;
   while (i < n && k > keys[i]) { // Find the first key greater than or equal to k
      i++;
   }
   if (keys[i] == k) {
      return this; // break from function
   }
   if (leaf == true) {
      return NULL;
   }
   return C[i]->search(k);
}
