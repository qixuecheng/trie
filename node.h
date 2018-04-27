#ifndef NODE_H
#define NODE_H
#include <iostream>
#include<stdio.h>
#include<string.h>


enum NODE_TYPE
{
  SHORT_NODE=0,
  BRANCH_NODE,
  VALUE_NODE
};
class node
{
  private:
    NODE_TYPE type;
  public:
    node();
    ~node(){}
    node(NODE_TYPE type) : type(type){}
    virtual void print(){}
    inline NODE_TYPE get_type()
    {
      return this->type;
    }


};

/**
 * @brief shortNode can be leaf node or extension node, so val points to shortNode or branchNode
 */
class shortNode : public node
{
  public:
    shortNode() : node(NODE_TYPE::SHORT_NODE) {}
    ~shortNode(){}
    shortNode(char* key, node* val) : node(NODE_TYPE::SHORT_NODE), key(key), val(val) {}
    inline char* get_key() const
    {
      return key;
    }
    inline int set_val(node* val){
      this->val = val;
      return 200;
    }
    inline node* get_val(){
     return val;
    }
    inline void print()
    {
      std::cout << key << std::endl;
    }


  private:
    char* key;
    node* val;

};

/**
 * @brief branchNode is branch node
 */
class branchNode : public node
{
  public:
    branchNode() : node(NODE_TYPE::BRANCH_NODE){}
    ~branchNode(){}
    inline int set_children(node* n, int index)
    {
      if(index > 16)
      {
        return 201;
      }
      else
      {
        this->children[index] = n;
        return 200;
      }
    }
    inline node* get_children(int index)
    {
      if(index > 16)
      {
        return nullptr;
      }
      else
      {
        return this->children[index];
      }
    }
    inline void print()
    {

    }

  private:
     node* children[17];
};

/**
 * @brief valueNode contains value of leaf node
 */
class valueNode : public node
{
  public:
    valueNode() : node(NODE_TYPE::VALUE_NODE) {}
    valueNode(char* value) : node(NODE_TYPE::VALUE_NODE), value(value) {}
    ~valueNode(){}
    inline void print()
    {
      std::cout << value << std::endl;
    }
  private:
    char* value;

};
#endif // NODE_H
