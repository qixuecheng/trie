#include "node.h"
#include "encoding.h"
#include "trie.h"
#include <iostream>

int main()
{
  encoding e;

  //std::cout<<a;
  char * r = e.char_to_hex("123");

  //std::cout<<e.prefix_length("123","1");

  node n;
  node *p = &n;
  shortNode short_node("afdsfsdf2", p);
  //short_node.print();

  std::cout<<std::endl;
  char c = '1';
  std::cout<<int(c)<<std::endl;

  trie t;


  valueNode v("value : 123");
  shortNode short_node1("123", &v);

  node* sn= t.insert_node(&short_node1,"","124",&v);
  sn= t.insert_node(&short_node1,"","125",&v);
  sn->print();

  shortNode* s = dynamic_cast<shortNode *>(sn);

  branchNode* b = dynamic_cast<branchNode *>(s->get_val());

  shortNode* s2 = dynamic_cast<shortNode *>(b->get_children(5));

  valueNode* v1  = dynamic_cast<valueNode *>(s2->get_val());

  v1->print();

  std::cout << s2->get_val()->get_type() << std::endl;
  std::string ss = "123";
  //std::cout<<ss.substr(3,3)+ss<<std::endl;

//  shortNode* ss = dynamic_cast<shortNode *>(s->get_val());
//  ss->print();
  //std::cout << ss->get_type() << std::endl;

  return 0;
}
