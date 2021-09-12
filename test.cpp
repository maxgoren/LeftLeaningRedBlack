//Left Leaning Red Black Tree as discussed in:
//https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
// (c) Max Goren 2020 MIT License
#include <iostream>
#include <queue>
#include "bsttree.cpp"

/* breadth First Traversal of a tree is analagous
   to level order traversal. it gives a visual idea of
   how well balanced our tree is. */
void bfs(bstree<int, char>& bst)
{
  typedef bstree<int,char>::node tnode;
  tnode* curr = bst.root;
  queue<tnode*> Q;
  Q.push(curr);
  while(!Q.empty())
  {
   curr = Q.front(); Q.pop();
   cout<<"{"<<curr->key<<":"<<curr->val<<"} ";
   if (curr->l != nullptr) Q.push(curr->l);
   if (curr->r != nullptr) Q.push(curr->r);
  }
  cout<<endl;
}

int main()
{
  string yeah = "heymanstopcrampingthestyledawg"; //hows that for a letter rich sentance?
  vector<char> ok;
  for (auto c : yeah)
    ok.push_back(c);

  bstree<int, char> bst;
  int i;
  for (i = 0; i < 25; i++)
    bst.insert(&bst.root, (int)(rand() % (100-i))-1, ok.at(rand() % (ok.size() - 1)) );
  bst.traverse(bst.root);
  cout<<"\n";
  bfs(bst);
  cout<<bst.getMin();
  cout<<endl;
  cout<<bst.getMax();
  cout<<endl;
  return 0;
}

