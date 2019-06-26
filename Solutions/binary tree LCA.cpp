#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
};

node* createNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    return new_node;
}
node* LCA(node *root, node *p, node *q)
{
    if(root == NULL)
        return NULL;
    if(root == p || root == q)
        return root;
    node* left = LCA(root->left,p,q);
    node* right = LCA(root->right,p,q);

    if(left!=NULL && right!=NULL)
        return root;
    else
        return (left!=NULL?left:right);
}
int main()
{
    node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->right = createNode(11);
    root->left->left->left->left = createNode(10);
    root->right->right->left = createNode(12);
    root->right->right->right = createNode(13);
    root->right->right->right->right = createNode(14);
    node* ans = LCA(root, root->left->left->left, root->left->left);
    cout<<ans->data;
}
