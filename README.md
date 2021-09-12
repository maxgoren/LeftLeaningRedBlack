# LeftLeaningRedBlack

This is an (incomplete) C++ implementation of a Left Leaning Red Black Tree
As discussed by Robert Sedgewick in https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf

Implemented So far:
-------------------
```
Insert();
Find();
getMin();
getMax();
traverse(); //in-order
```

test.cpp includes a level-order (breadth first) traversal of the tree, which one can compare to the
in-order traversal for a rough visual gauge of how well balanced the tree is.

TODO:
 -implement delete();
 -modify node for key/value instead of just key
 -use templates to allow for generic types.
 
 (C) Max Goren 2020 MIT License
