#include <string.h>

#include <iostream>

#include "array.h"

using namespace std;

void TESTN(size_t n) { cout << "Test " << n << endl; }

void FAIL() {
  cout << "Failure" << endl;
  exit(0);
}

void PASS() { cout << "Test Passed" << endl; }

void TEST(bool q) {
  if (!q)
    FAIL();
}

void test0() {
  TESTN(0);
  cout << "Creation" << endl;

  Array arr1(5);
  Array *arr2 = new Array(5);
  delete arr2;

  PASS();
}

void test1() {
  TESTN(1);
  cout << "Member equality and set" << endl;

  Array arr(5);
  Object o1;
  Object o2;
  Object o3;

  arr.set(0, &o1);
  arr.set(1, &o2);
  arr.set(2, &o3);
  arr.set(3, &o1);
  arr.set(4, &o2);

  TEST(!arr.get(0)->equals(arr.get(1)));
  TEST(!arr.get(0)->equals(arr.get(4)));
  TEST(arr.get(0)->equals(arr.get(3)));

  PASS();
}

void test2() {
  TESTN(2);
  cout << "nullptrs and replacement" << endl;

  Array arr(3);
  Object o1;
  Object o2;
  Object o3;

  TEST(arr.count() == 0);

  arr.set(0, &o1);
  arr.set(1, &o2);

  TEST(arr.get(2) == nullptr);
  TEST(arr.count() == 2);

  arr.remove(1);

  TEST(arr.get(1) == nullptr);
  TEST(arr.get(0)->equals(&o1));
  TEST(arr.count() == 1);

  arr.set(0, &o2);

  TEST(arr.get(0)->equals(&o2));
  TEST(arr.count() == 1);

  arr.set(0, nullptr);

  TEST(arr.get(0) == nullptr);
  TEST(arr.get(1) == nullptr);
  TEST(arr.get(2) == nullptr);
  TEST(arr.count() == 0);

  PASS();
}

void test3() {
  TESTN(3);
  cout << "Identity" << endl;

  Array arr1(5);
  Array arr2(5);

  TEST(arr1.equals(arr2));
  TEST(arr2.equals(arr1));

  Object o1;
  Object o2;
  Object o3;

  arr1.set(0, &o1);
  arr2.set(0, &o1);

  TEST(arr1.equals(arr2));
  TEST(arr2.equals(arr1));

  arr2.set(1, &o2);

  TEST(!arr1.equals(arr2));
  TEST(!arr2.equals(arr1));

  TEST(!arr1.equals(o1));
  TEST(!arr2.equals(o1));

  PASS();
}

void test4() {
  TESTN(4);
  cout << "String arrays" << endl;

  StringArray arr(5);
  String s1("Hello");
  String s2("World");
  String *s3 = new String("FooBar");

  TEST(arr.count() == 0);
  TEST(strcmp(arr.to_string(), "") == 0);

  arr.set(0, &s1);
  arr.set(1, &s2);
  arr.set(2, s3);

  TEST(arr.count() == 3);
  TEST(strcmp(arr.to_string(), "Hello, World, FooBar") == 0);

  arr.remove(1);

  TEST(arr.count() == 2);
  TEST(strcmp(arr.to_string(), "Hello, FooBar") == 0);

  PASS();
}

void test5() {
  TESTN(5);
  cout << "Integer arrays" << endl;

  IntArray arr(5);
  int i1 = 1;
  int i2 = 5;
  int i3 = 7;
  int i4 = 5;

  TEST(arr.count() == 0);
  TEST(strcmp(arr.to_string(), "") == 0);

  arr.set(0, i1);
  arr.set(1, i2);
  arr.set(2, i3);

  TEST(arr.count() == 3);
  TEST(strcmp(arr.to_string(), "1, 5, 7") == 0);
  TEST(arr.get(0) != arr.get(1));

  arr.remove(1);

  TEST(arr.count() == 2);
  TEST(strcmp(arr.to_string(), "1, 7") == 0);

  arr.set(3, i4);

  TEST(arr.get(1) == arr.get(3));

  PASS();
}

void test6() {
  TESTN(6);
  cout << "Floating point arrays" << endl;

  FloatArray arr(5);
  float f1 = 1.5f;
  float f2 = 5.7f;
  float f3 = 7.0f;
  float f4 = 5.7f;

  TEST(arr.count() == 0);
  TEST(strcmp(arr.to_string(), "") == 0);

  arr.set(0, f1);
  arr.set(1, f2);
  arr.set(2, f3);

  TEST(arr.count() == 3);
  TEST(strcmp(arr.to_string(), "1.5, 5.7, 7") == 0);
  TEST(arr.get(0) != arr.get(1));

  arr.remove(1);

  TEST(arr.count() == 2);
  TEST(strcmp(arr.to_string(), "1.5, 7") == 0);

  arr.set(3, f4);

  TEST(arr.get(1) == arr.get(3)); // should be ok without epsilon

  PASS();
}

void test7() {
  TESTN(7);
  cout << "Boolean arrays" << endl;

  BoolArray arr(5);
  bool b1 = true;
  bool b2 = false;
  bool b3 = true;

  TEST(arr.count() == 0);
  TEST(strcmp(arr.to_string(), "") == 0);

  arr.set(0, b1);
  arr.set(1, b2);
  arr.set(2, b3);

  TEST(arr.count() == 3);
  TEST(strcmp(arr.to_string(), "true, false, true") == 0);
  TEST(arr.get(0) != arr.get(1));
  TEST(arr.get(0) == arr.get(2));

  arr.remove(1);

  TEST(arr.count() == 2);
  TEST(strcmp(arr.to_string(), "true, true") == 0);

  PASS();
}

void testAll() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
}

int main() {
  testAll();
  return 0;
}
