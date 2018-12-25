#include <stdint.h>
#include <string.h>
#include <string>

#define DEFAULTMAXKEYS (4)

using namespace std;

typedef struct BTNode {
  // size max_keys + 1
  struct BTNode **children; // yes, an array of pointers to BTNode children
  // size max_keys
  string *key;
  // size max_keys
  string *value;
  // size max_keys
  uint64_t *hash_key;
  uint64_t max_keys;
  BTNode(uint64_t max_keys);
  ~BTNode();
} BTNode;

typedef struct BTree {
  BTNode *root;
  uint64_t size;
  uint64_t max_keys;
  // depth?
  uint64_t BTHash(string key, uint64_t salt);
  BTree(uint64_t max_keys);
  ~BTree();
  void clear(BTNode *cur_node);
  string lookup(string key, BTNode *cur_node);
  void insert(string key, string value, BTNode *cur_node);
} BTree;
