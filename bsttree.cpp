//Left Leaning Red Black Tree as discussed in:
//https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
// (c) Max Goren 2020 MIT License
#include "bsttree.h"
using namespace std;

int right_count = 0;
int left_count = 0;

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
    *x = new node(key, val, RED);
    return;
  }
  /* 2-3-4 tree
  if (isRed((*x)->l) && isRed((*x)->r))
      flipColor(*x);
  */
  if (key == (*x)->key)
  {
     (*x)->val = val;
  } 
  else if (key < (*x)->key) 
  {
    insert(&(*x)->l, key, val);
  } else {
    insert(&(*x)->r, key, val);
  }
  *x = fixUp(*x);
  /* 2-3 tree */
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
    x->r    = t->l;
    t->l    = x;
    t->color = t->l->color;
    x->color = RED;
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
    x->color = RED;
    cout<<"Right Rotation!!\n";
    return t;
}

template <typename k_t, typename v_t>
void bstree<k_t,v_t>::flipColor(node*& x)
{
    x->color = !x->color;
    if (x->r != nullptr)
      x->r->color = !x->r->color;
    
    if (x->l != nullptr)
      x->l->color = !x->l->color;
    
    cout<<"Color Flip!!\n";
}

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::moveRedRight(node* x)
{
    flipColor(x);
    if (isRed(x->l->l))
    {
      x = rotateRight(x);
      flipColor(x);
    }
    return x;
}

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::moveRedLeft(node* x)
{
    flipColor(x);
    if (isRed(x->r->l))
    {
      x->r = rotateRight(x->r);
      x = rotateLeft(x);
      flipColor(x);
    }
    return x;
}

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::dMin(node* x)
{
  if (isRed(x->l))
    x = rotateRight(x);

  if (x->r == nullptr)
    return nullptr;

  if (!isRed(x->r) && !isRed(x->r->l))
    x = moveRedRight(x);

   x->l = dMax(x->l);

   return fixUp(x);
}

template <typename k_t, typename v_t>
typename bstree<k_t, v_t>::node* bstree<k_t,v_t>::dMax(node* x)
{
  if (isRed(x->l))
    x = rotateRight(x);

  if (x->r == nullptr)
    return nullptr;

  if (!isRed(x->l) && !isRed(x->l->l))
    x = moveRedLeft(x);

   x->l = dMax(x->l);

   return fixUp(x);
}

template <typename k_t, typename v_t>
void bstree<k_t,v_t>::deleteMin()
{
   root = dMin(root);
   root->color = BLACK;
}

template <typename k_t, typename v_t>
void bstree<k_t,v_t>::deleteMax()
{
   root = dMax(root);
   root->color = BLACK;
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

template <typename k_t, typename v_t>
void bstree<k_t,v_t>::count_right(node* x)
{
 if (x != nullptr && x != root->l)
 {
  right_count++;
  count_right(x->l);
  count_right(x->r);
 }
}
template <typename k_t, typename v_t>
void bstree<k_t,v_t>::count_left(node* x)
{
 if (x != nullptr && x != root->r)
 {
   left_count++;
   count_left(x->l);
   count_right(x->r);
 }
}

template <typename k_t, typename v_t>
void bstree<k_t,v_t>::count_sides()
{
  left_count = 0;
  right_count = 0;
  count_right(root);
  count_left(root);
  cout<<"Nodes on left side: "<<left_count<<"\n";
  cout<<"Nodes on right side: "<<right_count<<"\n";
  left_count = 0;
  right_count = 0;
}
