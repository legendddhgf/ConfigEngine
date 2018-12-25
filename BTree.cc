#include "BTree.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xxhash.h>

BTNode::BTNode(uint64_t max_keys) {
  this->max_keys = max_keys;
  children = NULL;
  key = (string *) calloc(max_keys, sizeof(string));
  value = (string *) calloc(max_keys, sizeof(string));
  hash_key = (uint64_t *) calloc(max_keys, sizeof(int));
}

BTNode::~BTNode() {
  if (children) free(children);
  free(key);
  free(value);
  free(hash_key);
}

uint64_t BTree::BTHash(string key, uint64_t salt) {
  return ((uint64_t) XXH64(key.c_str(), strlen(key.c_str()), salt) &
      ((uint64_t) ~0));
}

void BTree::clear(BTNode *cur_node = NULL) {
  // Initial condition
  if (cur_node == NULL) {
    cur_node = root;
  }
  if (cur_node->children) {
    for (uint64_t child_iter = 0; child_iter <= max_keys; child_iter++) {
      if (!cur_node->children[child_iter]) break;
      clear(cur_node->children[child_iter]);
    }
  }
  delete cur_node;
}

BTree::BTree(uint64_t max_keys = DEFAULTMAXKEYS) {
  root = NULL;
  size = 0;
  this->max_keys = max_keys;
}

BTree::~BTree() {
  clear();
}

// Assumes that you can't insert empty strings
string BTree::lookup(string key, BTNode *cur_node = NULL) {
  uint64_t hash_key = BTHash(key, 0);
  // Initial condition
  if (cur_node == NULL) {
    cur_node = root;
  }
  for (uint64_t child_iter = 0; child_iter < max_keys; child_iter++) {
    if (hash_key == cur_node->hash_key[child_iter]) {
      return cur_node->value[child_iter];
    } else if (hash_key > cur_node->hash_key[child_iter]) {
      continue;
    }
    // it must be in this range, check the appropriate child node!
    if (!cur_node->children || !cur_node->children[child_iter]) return "";
    return lookup(key, cur_node->children[child_iter]);
  }
  if (!cur_node->children || !cur_node->children[max_keys]) return "";
  return lookup(key, cur_node->children[max_keys]);
}

void BTree::insert(string key, string value, BTNode *cur_node = NULL) {
  // Initial condition
  if (cur_node == NULL) {
    cur_node = root;
  }
  uint64_t hash_key = BTHash(key, 0);
  if (!root) {
    root = new BTNode(max_keys);
    cur_node = root;
  }
  // It's a full leaf node, time for split
  if (!cur_node->children && cur_node->hash_key[max_keys - 1] != 0) {
    // Can't directly split root, have to make new root and re-assign current
    if (cur_node == root) {
      root = new BTNode(max_keys);
      root->children = (BTNode **) calloc(max_keys + 1, sizeof(BTNode *));
      root->children[0] = cur_node;
    }
    // TODO: do the split
    // use middle of sorted vector of hashes?
  }
  for (uint64_t child_iter = 0; child_iter < max_keys; child_iter++) {
    if ((cur_node->hash_key[child_iter] == 0 && cur_node->children) ||
        hash_key < cur_node->hash_key[child_iter]) {
      if (cur_node->children && cur_node->children[child_iter]) {
        insert(key, value, cur_node->children[child_iter]);
        return; // completed insertion in a lower node
      }
      // This is a leaf node, so you can insert directly

      // shift keys from child_iter onwards, one to the right
      // FIXME: consider making a function for this
      for (uint64_t shift_iter = max_keys - 2; shift_iter >= child_iter;
          shift_iter--) {
        cur_node->key[shift_iter + 1] = cur_node->key[shift_iter];
        cur_node->value[shift_iter + 1] = cur_node->value[shift_iter];
        cur_node->hash_key[shift_iter + 1] = cur_node->hash_key[shift_iter];
      }
      cur_node->key[child_iter] = key;
      cur_node->value[child_iter] = value;
      cur_node->hash_key[child_iter] = hash_key;
      return;
    }
  }
  // recur to last child (all other cases assumed to be covered by this point)
  insert(key, value, cur_node->children[max_keys]);
}
