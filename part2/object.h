#pragma once
#include <stdlib.h>

class Object {
public:
  Object();
  virtual ~Object();

  virtual char *to_string();
  virtual bool equals(Object *o);
  virtual bool equals(Object &o);
  virtual size_t hash();
};