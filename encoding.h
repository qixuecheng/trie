#ifndef ENCODING_H
#define ENCODING_H
#include <stdio.h>
#include <string.h>
#include <iostream>


class encoding
{
  public:
    encoding();
    char* char_to_hex(const char* key);
    char* hex_to_char(const char* key);
    char* hex_to_compact(const char* key);
    static int prefix_length(const char* key, const char *key_);
    bool has_term(const char* key);

};

#endif // ENCODING_H
