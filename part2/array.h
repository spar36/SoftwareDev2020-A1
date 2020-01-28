#pragma once
#include "object.h"
#include "string.h"

/***
 * Object wrapper for a raw array.
 * authors: white.eva, mawrey.d
 */
class Array : public Object
{
public:
  // Array members are initialized to nullptr.
  Array(size_t capacity);
  // Array takes ownership of objects, i.e. calls delete on members.
  virtual ~Array();

  // Returns the number of non-nullptr elements. Not necessarily sequential.
  size_t count();
  // Gets the element at the specified index. exit(1) on error.
  Object *get(size_t idx);
  // Sets the element at the specified index to object o and takes ownership of
  // o. Return o on success, exit(1) on error
  Object *set(size_t idx, Object *o);
  // Removes and returns the element at the given index. exit(1) on
  // error.
  Object *remove(size_t idx);

  // Returns a character array representation of this array's data.
  char *to_string();
  // Comparision operator.
  bool equals(Object *o);
  bool equals(Object &o);
  // Identifiable hash.
  size_t hash();

  // The array that will contain the elements.
  Object *arr;
  // The maximum capacity of the array.
  size_t cap;
};

class StringArray : public Array
{
public:
  StringArray(size_t capacity);
  ~StringArray();

  String *get(size_t idx);            // exit(1) on error
  String *set(size_t idx, String *o); // exit(1) on error
  String *remove(size_t idx);         // exit(1) on error
};

class IntArray : public Array
{
public:
  IntArray(size_t capacity);
  ~IntArray();

  int *get(size_t idx);         // exit(1) on error
  int *set(size_t idx, int *o); // exit(1) on error
  int *remove(size_t idx);      // exit(1) on error
};
class FloatArray : public Array
{
public:
  FloatArray(size_t capacity);
  ~FloatArray();

  float *get(size_t idx);           // exit(1) on error
  float *set(size_t idx, float *o); // exit(1) on error
  float *remove(size_t idx);        // exit(1) on error
};
class BoolArray : public Array
{
public:
  BoolArray(size_t capacity);
  ~BoolArray();

  bool *get(size_t idx);          // exit(1) on error
  bool *set(size_t idx, bool *o); // exit(1) on error
  bool *remove(size_t idx);       // exit(1) on error
};