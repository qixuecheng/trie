#include "trie.h"

trie::trie()
{

}

int trie::update(char* key, char* value)
{

  return 200;
}
int get(char* key){
  return 200;
}

node* trie::insert_node(node* n, char* prefix, char* key, node* value)
{
  //返回根节点
  if(NULL == n)
  {
     shortNode *sn = new shortNode(key, value);
     return sn;
  }
  //替换叶子节点的value
  if(strlen(key) == 0)
  {
    return value;
  }

  switch (n->get_type())
  {
  case NODE_TYPE::SHORT_NODE:{
    shortNode* s = dynamic_cast<shortNode *>(n);
    uint64_t matchlen = encoding::prefix_length(key, s->get_key());
    std::cout<<"matchlen " <<matchlen <<std::endl;
    //如果两个叶子节点的值相同，则只更新value的值
    if(matchlen == strlen(s->get_key()))
    {
     std::string str_prefix = prefix;
     std::string str_key = key;
     //更新叶子节点
     node* temp = insert_node(s->get_val(), (char*)(str_prefix + str_key.substr(0, matchlen)).c_str(), (char*)(str_key.substr(matchlen, strlen(key))).c_str(), value);

     shortNode *sn = new shortNode(s->get_key(), temp);

     std::cout<<temp->get_type()<<std::endl;
     std::cout<<"ADD SHORT_NODE 1"<<std::endl;
     return sn;
    }
    //否则，提取相同前缀，加上拓展节点和分支节点
    else
    {
      std::cout<<"ADD branchNode 1"<<std::endl;
      branchNode *b = new branchNode();
      std::string str_prefix = prefix;
      //更新插入的叶子节点
      std::string str_key = key;
      node* n1 = insert_node(NULL, (char*)(str_prefix + str_key.substr(0,matchlen+1)).c_str(), (char*)str_key.substr(matchlen+1, strlen(key)).c_str(), value);
      b->set_children(n1, key[matchlen]%16);
      //更新之前的叶子节点
      std::string str_n_key = s->get_key();
      node* n2 = insert_node(NULL, (char*)(str_prefix + str_n_key.substr(0,matchlen+1)).c_str(), (char*)str_n_key.substr(matchlen+1, strlen(s->get_key())).c_str(), value);
      b->set_children(n2, s->get_key()[matchlen]%16);
      std::cout<<"ADD branchNode 2"<<std::endl;

      //返回分支节点
      if(matchlen == 0)
      {
        return b;
      }
      //返回拓展节点
      shortNode* sn = new shortNode((char*)str_key.substr(0,matchlen).c_str(), b);
      return sn;
    }
  }
    break;
  case NODE_TYPE::BRANCH_NODE:
  {
    shortNode n1(prefix, value);
    branchNode* b = dynamic_cast<branchNode *>(n);
    node* temp;
    std::string str_prefix = prefix + key[0];
    std::string str_key = key;
    str_key = str_key.substr(1,strlen(key));

    temp = insert_node(b->get_children(key[0]), (char*)str_prefix.c_str(), (char*)str_key.c_str(), value);
    return temp;
  }
    break;
  default:

    break;

  }


}

node* trie::get_node(node* n, char* key, uint64_t pos)
{

  switch (n->get_type()) {

  case NODE_TYPE::SHORT_NODE:{
    shortNode* s = dynamic_cast<shortNode *>(n);
    //if prefix of key is not the same with the n's, return error
    std::string str_key = s->get_key();

    if(strlen(key) - pos < strlen(s->get_key()) || strcmp(key,str_key.substr(pos, pos+strlen(s->get_key())).c_str())){
      return NULL;
    }



  }

    break;
  case NODE_TYPE::BRANCH_NODE:{

  }

    break;
  case NODE_TYPE::VALUE_NODE:{

  }
    break;
  default:
  {}
    break;
  }








  return null;




}

int trie::delete_node()
{

}




