#pragma once
#include "object.h"

class String : public Object {
public:
  String(const char *s); // Copy the char*
  String(char *s); // Copy the char*
  String(char &s); // Copy the char*
  ~String();

  String *concat(String *s);
  String *concat(String &s);
  int compare();
  size_t get_length();

  char *to_string();
  bool equals(Object *o);
  bool equals(Object &o);
  size_t hash();
};