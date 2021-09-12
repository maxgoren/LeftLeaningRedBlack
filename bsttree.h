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

template <typename k_t, typename v_t>
class bstree {
  public:
  class node {
     public:
     node* l;
     node* r;
     bool color;
     k_t key;
     v_t val;
     node() { }
     node(int k) : key(k) { l = r = nullptr; color = Red; }
     node(const node&) { }
  };
  node* root;
  int left_count;
  int right_count;
  bstree();
  void insert(node** x, k_t key, v_t val);
  node* fixUp(node* x);
  node* rotateLeft(node* x);
  node* rotateRight(node* x);
  v_t getMin();
  v_t getMax();
  v_t find(k_t k);
  void flipColor(node*& x);// { x->color = !x->color; }
  inline bool isRed(node* x) { return (x == nullptr) ? false:x->color == Red; }
  void traverse(node* x);
  void count_right(node* x);
  void count_left(node* x);
  void count_sides();
};
