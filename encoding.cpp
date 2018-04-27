#include "encoding.h"

encoding::encoding()
{

}

char* encoding::char_to_hex(const char* key)
{
  int length = strlen(key)*2+1;
  char *res = (char*) malloc(length * sizeof(char));

  for(int i = 0; i < strlen(key); ++i)
  {
    res[i*2] = key[i]/16 ;
    res[i*2+1] = key[i]%16;
  }
  res[length-1] = 16;

  return res;

}

char* encoding::hex_to_char(const char* key)
{

}

char* encoding::hex_to_compact(const char* key)
{



}

int encoding::prefix_length(const char *key, const char *key_)
{

  int length = strlen(key);
  if(strlen(key_) < length)
  {
    length = strlen(key_);
  }
  int i = 0;
  for(;i < length; ++i)
  {
     if(key[i] != key_[i])
       break;
  }
  return i;
}

bool encoding::has_term(const char *key)
{
  return strlen(key) && key[strlen(key)-1] == 16;
}








