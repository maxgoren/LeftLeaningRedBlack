//Left Leaning Red Black Tree as discussed in:
//https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
// (c) Max Goren 2020 MIT License

#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;
const int itemMIN = -66642069;
const int itemMAX = 66642069;
enum nodecolor { Red = true, black };
class bstree {
  public:
  class node {
     public:
     node* l;
     node* r;
     bool color;
     int key;
     int depth;
     node() { }
     node(int k) : key(k) { l = r = nullptr; color = Red; }
     node(const node&) { }
  };
  node* root;
  bstree();
  void put(node** x, int key);
  node* fixUp(node* x);
  node* rotateLeft(node* x);
  node* rotateRight(node* x);
  inline void flipColor(node*& x) { x->color = !x->color; }
  inline bool isRed(node* x) { return (x == nullptr) ? false:x->color == Red; }
  void traverse(node* x);
};
