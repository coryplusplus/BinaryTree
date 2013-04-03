#include <iostream>
#include <queue>
using namespace std;


class Node{
public:

Node()
{
    value = 0;
    pLeft = NULL;
    pRight = NULL;
}

Node(const int& valueRef)
{
    value = valueRef;
    pLeft = NULL;
    pRight = NULL;
}
Node(Node *left, Node *right, const int& valueRef)
{
    pLeft = left;
    pRight = right;
    value = valueRef;

}

~Node()
{
    delete pLeft;
    delete pRight;
}

void setLeft(Node* leftNode)
{
    pLeft = leftNode;    
}

Node* getLeft()
{
    return pLeft;
}

Node* getRight()
{
    return pRight;
}

void setRight(Node* rightNode)
{
    pRight = rightNode;
}

void setValue(const int& valueRef)
{
    value = valueRef;
}

int getValue()
{
    return value;
}

private:
int value;
Node *pLeft;
Node *pRight;
};


class BinaryTree {
public:

BinaryTree()
{
    root = NULL;
}

~BinaryTree()
{
    delete root;
}

bool DFS(Node *rootNode, const int& searchValue)
{
    if(rootNode!=NULL)
    {
        if(rootNode->getValue() == searchValue)
        {
            return true;
        }
        if(rootNode->getLeft() != NULL)
        {
            cout<<rootNode->getLeft()->getValue();
            if(rootNode->getLeft()->getValue() == searchValue)
            {
                return true;
            }
            else
            {
                DFS(rootNode->getLeft(), searchValue);
            }
        }
        if(rootNode->getRight() != NULL)
        {
            cout<<rootNode->getRight()->getValue();
            if(rootNode->getRight()->getValue() == searchValue)
            {
                return true;
            }
            else
            {
                DFS(rootNode->getRight(), searchValue);
            }
        }

    return false;
    }
        
}

bool BFS(Node *node, const int &searchValue)
{
    if (node == NULL) return false;

    queue<Node*> q;
    q.push(node);

    while (!q.empty())
    {
        Node* tmp = q.front();
        q.pop();
        cout<<tmp->getValue();
        if (tmp->getValue() == searchValue)
            return true;
        else
        {
            if(tmp->getLeft() != NULL)
                q.push(tmp->getLeft());
            if(tmp->getRight() != NULL)
                q.push(tmp->getRight());
        }
    }
    return false;
}


void setRoot(Node* rootNode)
{
    root = rootNode;
}

Node * getRoot()
{
    return root;
}

private:
Node *root;
};


int main()
{
    BinaryTree tree;
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    Node *d = new Node(5);
    Node *e = new Node(6);
    Node *f = new Node(7);
    Node *g = new Node(8); 
    Node *h = new Node(9);
    Node *i = new Node(10);
    Node *root = new Node(a,c,1);
    a->setLeft(b);
    a->setRight(h);
    h->setLeft(i);
    c->setLeft(d);
    c->setRight(e);
    e->setLeft(f);
    e->setRight(g);

    tree.setRoot(root);
    bool found = false;
    found = tree.BFS(tree.getRoot(), 99);
    cout<<endl;
    found = tree.DFS(tree.getRoot(), 99);
    cout<<endl;
    return 0;
}
