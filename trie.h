#ifndef TRIE_H
#define TRIE_H
#include "node.h"
#include "encoding.h"

class trie
{
  public:
    trie();
    int update(char* key, char* value);
    int get(char* key);
    node* get_node(node* n, char* key, uint64_t pos);
    node* insert_node(node* n, char* prefix, char* key, node* value);
    int delete_node();
    void print();

  private:
    shortNode* root;

};

#endif // TRIE_H
