//Left Leaning Red Black Tree as discussed in:
//https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
// (c) Max Goren 2020 MIT License
#include "bsttree.h"
using namespace std;
int dep = 0; //sue me ;)
bstree::bstree()
{
  this->root = nullptr;
}

void bstree::put(node** x, int key)
{
  dep++;
  if (*x == nullptr)
  {
   // cout<<key<<" inserted\n";
    *x = new node(key);
    (*x)->depth = dep;
    return;
  }
  if (key < (*x)->key) 
  {
    put(&(*x)->l, key);
  } else {
    put(&(*x)->r, key);
  }
  *x = fixUp(*x);
  dep = 0;
}

bstree::node* bstree::fixUp(node* x)
{
    if (isRed(x->r))
    {
      x = rotateLeft(x);
    }
    if (isRed(x->l) && isRed(x->l->l))
    {
      x = rotateRight(x);
    }
    if (isRed(x->l) && isRed(x->r))
      flipColor(x);
    return x;
}

bstree::node* bstree::rotateLeft(node* x)
{
    node* t = x->r;
    x->r = t->l;
    t->l = x;
    t->color = t->l->color;
    t->l->color = Red;
   cout<<"Left Rotation!!\n"; 
   return t;
}

bstree::node* bstree::rotateRight(node* x)
{
    node* t = x->l;
    x->l = t->r;
    t->r = x;
    t->color = t->r->color;
    t->r->color = Red;
    cout<<"Right Rotation!!\n";
    return t;
}

void bstree::traverse(node* x)
{
 if (x != nullptr)
 {
   traverse(x->l);
   cout<<x->key<<" ";
   traverse(x->r);
 }
}
