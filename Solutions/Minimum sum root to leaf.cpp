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
bool printPath(node* root, int sum)
{
    if(sum == 0)
        return true;
    if(root == NULL)
        return false;
    bool left = printPath(root->left,sum-root->data);
    bool right = printPath(root->right,sum-root->data);
    if(left || right)
        cout<<root->data<<" ";
    return (left||right);
}
int minRootToLeafSum(node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    int leftSum = INT_MAX;
    int rightSum = INT_MAX;
    if(root->left!=NULL)
        leftSum = minRootToLeafSum(root->left);
    if(root->right!=NULL)
        rightSum = minRootToLeafSum(root->right);
    int sum = min(leftSum,rightSum)+root->data;
//    cout<<root->data<<" ";
//    cout<<sum<<endl;
    return sum;
}
int main()
{
    node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(5);
//    root->left->left = createNode(4);
    root->left->right = createNode(2);
//    root->right->left = createNode(6);
    root->right->right = createNode(1);
//    root->left->left->left = createNode(8);
//    root->left->left->right = createNode(9);
//    root->left->right->right = createNode(11);
//    root->left->left->left->left = createNode(10);
    root->right->right->left = createNode(-1);
//    root->right->right->right = createNode(13);
//    root->right->right->right->right = createNode(14);
//    node* ans = LCA(root, root->left->left->left, root->left->left);
    int minSum = minRootToLeafSum(root);
    cout<<minSum<<"\n";
    printPath(root,minSum);
}
