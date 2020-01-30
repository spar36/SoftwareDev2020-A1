#pragma once
#include "object.h"
#include "string.h"

/***
 * Object wrapper for a raw array.
 * authors: white.eva, mawrey.d
 */
class Array : public Object {
public:
  // Array is initialized as empty
  Array();
  // Array members are initialized to nullptr.
  Array(size_t capacity);
  // Array members are initialized to the corresponding values passed in
  Array(Object* values);

  // Array takes ownership of objects, i.e. calls delete on members.
  virtual ~Array();

  // Returns the number of non-nullptr elements. Not necessarily sequential.
  size_t count();
  // Gets the element at the specified index
  Object *get(size_t idx);
  // Sets the element at the specified index to object o and takes ownership
  // of o. Returns o.
  Object *set(size_t idx, Object *o);
  // Appends the element to the end of the array. The end of the array is
  // defined as the element following the last non-null element.
  Object *push_back(Object *o);
  // Removes and returns the element at the given index.
  // exit(1) on error.
  Object *remove(size_t idx);

  // Returns a character array representation of this array's data.
  char *to_string();
  // Comparision operator.
  bool equals(Object *o);
  bool equals(Object &o);
  // Identifiable hash.
  size_t hash();
};

class StringArray : public Array {
public:
  StringArray();
  StringArray(size_t capacity);
  StringArray(String* values);
  ~StringArray();

  String *get(size_t idx);
  String *set(size_t idx, String *o);
  String *push_back(String *o);
  String *remove(size_t idx);         // exit(1) on error
};

class IntArray : public Array {
public:
  IntArray();
  IntArray(size_t capacity);
  IntArray(int* values);
  ~IntArray();

  int get(size_t idx);
  int set(size_t idx, int o);
  int push_back(int o);
  int remove(size_t idx);      // exit(1) on error
};

class FloatArray : public Array {
public:
  FloatArray();
  FloatArray(size_t capacity);
  FloatArray(float* values);
  ~FloatArray();

  float get(size_t idx);
  float set(size_t idx, float o);
  float push_back(float o);
  float remove(size_t idx);        // exit(1) on error
};

class BoolArray : public Array {
public:
  BoolArray();
  BoolArray(size_t capacity);
  BoolArray(bool* values);
  ~BoolArray();

  bool get(size_t idx);
  bool set(size_t idx, bool o);
  bool push_back(bool o);
  bool remove(size_t idx);       // exit(1) on error
};
