/* left leaning red black tree
*
*   from Robert Sedgewicks october 2008 presentation
*   conforms directly to a 2-3 tree (his earlier work was based on 2-3-4 trees)
*
*   Seems to create far better balanced trees than version 1.
*/
#include <iostream>
#include <queue>
#include <random>
using namespace std;

class RBTree {
    private:
    static const bool red = true;
    static const bool black = false;
    class node {
        public:
        int key;
        bool color;
        node *left;
        node *right;
        node(int k, bool c) : key(k), color(c), right(nullptr), left(nullptr) { }
        node() : key(0), color(red), right(nullptr), left(nullptr) { }
    };
    node* root;
    node* put(node* x, int k);
    node* rotateLeft(node* h);
    node* rotateRight(node* h);
    node* colorFlip(node *x);
    bool isRed(node* x);
    public:
    RBTree();
    void insert(int k) { root = put(root, k); }
    node* rootNode() { return root; }
    void countNode(node *x);
    int min();
    int max();
};

RBTree::RBTree()
{
    root = nullptr;
}

bool RBTree::isRed(node* x)
{
    if (x == nullptr) return false;
    else return (x->color == red);
}

RBTree::node* RBTree::put(node* x, int k)
{
    if (x == nullptr)
       return new node(k, red);

    if (k < x->key)
        x->left = put(x->left, k);
    else
        x->right = put(x->right, k);

    if (isRed(x->right))
      x = rotateLeft(x);

    if (isRed(x->left) && isRed(x->left->left))
      x = rotateRight(x);

    if (isRed(x->left) && isRed(x->right))
      x = colorFlip(x);

    return x;
}

RBTree::node* RBTree::rotateLeft(node* h)
{
    node* x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = x->left->color;
    x->left->color = red;
    return x;
}

RBTree::node* RBTree::rotateRight(node* h)
{
    node* x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = x->right->color;
    x->right->color = red;
    return x;
}

RBTree::node* RBTree::colorFlip(node* x)
{
    x->color = !x->color;
    x->left->color = !x->left->color;
    x->right->color = !x->right->color;
    return x;
}

int RBTree::min()
{
    node* x = root;
    while (x->left != nullptr) x = x->left;
    if (x == nullptr) return -666;
    return x->key;
}

int RBTree::max()
{
    node* x = root;
    while (x->right != nullptr) x = x->right;
    if (x == nullptr) return -666;
    return x->key;
}

void RBTree::countNode(node* start_node)
{
    int node_count = 0;
    std::queue<node*> fq;
    fq.push(start_node);
    while (!fq.empty())
    {
        node* curr = fq.front();
        fq.pop();
        if (curr != nullptr)
        {
            node_count++;
            cout<<curr->key<<" ";
            fq.push(curr->right);
            fq.push(curr->left);
        }
    }
    cout<<"\nNode count: "<<node_count<<"\n";
    cout<<"\n";
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(15, 75);
    RBTree myRBT;
    //myRBT.insert(30);
    for (int i = 0; i < 100; i++)
    {
      int p = dist(gen);
      cout<<"inserting "<<p<<"\n";
      myRBT.insert(p);
    }
    cout<<"Root Node: "<<myRBT.rootNode()->key<<"\n";
    cout<<"Left Side: ";
    myRBT.countNode(myRBT.rootNode()->left);
    cout<<"Right Side: ";
    myRBT.countNode(myRBT.rootNode()->right);
    cout<<"Min: "<<myRBT.min()<<"\n";
    cout<<"Max: "<<myRBT.max()<<"\n";
}