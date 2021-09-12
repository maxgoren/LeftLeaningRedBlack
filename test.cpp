//Left Leaning Red Black Tree as discussed in:
//https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
// (c) Max Goren 2020 MIT License
#include <iostream>
#include <queue>
#include "bsttree.h"

/* breadth First Traversal of a tree is analagous
   to level order traversal. it gives a visual idea of
   how well balanced our tree is. */
void bfs(bstree& bst)
{
  bstree::node* curr = bst.root;
  queue<bstree::node*> Q;
  Q.push(curr);
  while(!Q.empty())
  {
   curr = Q.front(); Q.pop();
   cout<<curr->key<<" ";
   if (curr->l != nullptr) Q.push(curr->l);
   if (curr->r != nullptr) Q.push(curr->r);
  }
}

int main()
{
  bstree bst;
  int i;
  for (i = 0; i < 25; i++)
    bst.put(&bst.root, (int)(rand() % (100-i))-1 );
  bst.traverse(bst.root);
  cout<<"\n";
  bfs(bst);
  return 0;
}

