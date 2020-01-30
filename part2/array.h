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
  Array(Object *values);

  // Arrays do not take ownership so that delete is not called on objects that
  // were not created with new.
  virtual ~Array();

  // Returns the number of non-nullptr elements. Not necessarily sequential.
  size_t count();
  // Gets the element at the specified index
  Object *get(size_t idx);
  // Sets the element at the specified index to object o and takes ownership
  // of o.
  void set(size_t idx, Object *o);
  // Appends the element to the end of the array. The end of the array is
  // defined as the element following the last non-null element.
  void push_back(Object *o);
  // Appends all non-null elements of given array to the end of this array. The
  // end of the array is defined as the element following the last non-null
  // element.
  void push_back_all(Array *o);
  // Removes and returns the element at the given index.
  // exit(1) on error.
  Object *remove(size_t idx);
};

class StringArray : public Array {
public:
  StringArray();
  StringArray(size_t capacity);
  StringArray(String *values);
  ~StringArray();

  size_t count();
  String *get(size_t idx);
  void set(size_t idx, String *o);
  void push_back(String *o);
  void push_back_all(StringArray *o);
  String *remove(size_t idx);

  // Returns a character array representation of this array's data.
  char *to_string(); // exit(1) on error
};

// you may inherit from Array
class IntArray : public Object {
public:
  IntArray();
  IntArray(size_t capacity);
  IntArray(int *values);
  ~IntArray();

  size_t count();
  int get(size_t idx);
  int set(size_t idx, int o);
  int push_back(int o);
  void push_back_all(IntArray *o);
  int remove(size_t idx); // exit(1) on error

  // Returns a character array representation of this array's data.
  char *to_string();
};

// you may inherit from Array
class FloatArray : public Object {
public:
  FloatArray();
  FloatArray(size_t capacity);
  FloatArray(float *values);
  ~FloatArray();

  size_t count();
  float get(size_t idx);
  float set(size_t idx, float o);
  float push_back(float o);
  void push_back_all(FloatArray *o);
  float remove(size_t idx); // exit(1) on error

  // Returns a character array representation of this array's data.
  char *to_string();
};

// you may inherit from Array
class BoolArray : public Object {
public:
  BoolArray();
  BoolArray(size_t capacity);
  BoolArray(bool *values);
  ~BoolArray();

  size_t count();
  bool get(size_t idx);
  bool set(size_t idx, bool o);
  bool push_back(bool o);
  void push_back_all(BoolArray *o);
  bool remove(size_t idx); // exit(1) on error

  // Returns a character array representation of this array's data.
  char *to_string();
};
