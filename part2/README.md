We went with a basic C style array. It is fixed length and 
provides basic get and set methods. There are versions that
stores a basic object as well as an array that stores strings.

Our design for object is also fairly basic. It provides
a to_string methods as well as default equals and hash methods
for other objects to inherit or overload.

We also have a String class that inherits from object. It is
an immutable string. It has a comapre method and a concat method
that return a new string.