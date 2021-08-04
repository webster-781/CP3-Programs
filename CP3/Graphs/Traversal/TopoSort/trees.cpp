#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#define n Node
Node* connect(Node* root) {
    vector<Node*> l1;
    if(root!=nullptr)
        l1.push_back(root);
    
    while(l1.size()>0)
    {
        vector<Node*> l2;
        for(int i=0; i<l1.size()-1;i++)
        {
            if(l1.at(i)!=nullptr)
                l1.at(i)->next = l1.at(i+1);
        }
            
        for(Node* node : l1)
        {
            if(node!=nullptr && node->left!=nullptr);
                l2.push_back(node->left);
            if(node!=nullptr && node->right!=nullptr)
                l2.push_back(node->right);
        }
        l1= l2;
    }
    return root;
}
int main()
{
    n* n2 =new Node(2);
    n* n3 =new Node(3);
    n* n1 = new Node(1,n2,n3,NULL);
    auto t = connect(n1);
    return 0;
}