//Left Leaning Red Black Tree as discussed in:
//https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
// (c) Max Goren 2020 MIT License
#include "bsttree.h"
using namespace std;

template <typename k_t, typename v_t>
bstree<k_t, v_t>::bstree()
{
  this->root = nullptr;
}

template <typename k_t, typename v_t>
v_t bstree<k_t,v_t>::find(k_t k)
{
  v_t ret = nullptr;
  node* x = root;
  while (x != nullptr)
  {
   if (x->key == k)
   {
     ret = x->val;
     break;
   }
   x = (k < x->key) ? x->l:x->r; 
  }
  return ret;
}

template <typename k_t, typename v_t>
void bstree<k_t, v_t>::insert(node** x, k_t key, v_t val)
{
  if (*x == nullptr)
  {
   // cout<<key<<" inserted\n";
    *x = new node(key);
    (*x)->val = val;
    return;
  }
  if (key < (*x)->key) 
  {
    insert(&(*x)->l, key, val);
  } else {
    insert(&(*x)->r, key, val);
  }
  *x = fixUp(*x);
}

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::fixUp(node* x)
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

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::rotateLeft(node* x)
{
    node* t = x->r;
    x->r = t->l;
    t->l = x;
    t->color = t->l->color;
    t->l->color = Red;
   cout<<"Left Rotation!!\n"; 
   return t;
}

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::rotateRight(node* x)
{
    node* t = x->l;
    x->l = t->r;
    t->r = x;
    t->color = t->r->color;
    t->r->color = Red;
    cout<<"Right Rotation!!\n";
    return t;
}

template <typename k_t, typename v_t>
v_t bstree<k_t,v_t>::getMin()
{
  node* x = root;
  while (x != nullptr) x = x->l;
  return x->val;
}

template <typename k_t, typename v_t>
v_t bstree<k_t,v_t>::getMax()
{
  node* x = root;
  while (x != nullptr) x = x->l;
  return x->val; 
}

template <typename k_t, typename v_t>
void bstree<k_t,v_t>::traverse(node* x)
{
 if (x != nullptr)
 {
   traverse(x->l);
   cout<<x->key<<" ";
   traverse(x->r);
 }
}
