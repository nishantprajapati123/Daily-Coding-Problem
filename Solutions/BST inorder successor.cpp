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
void print(node* root)
{
    if (root ==NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
node* insertBST(node* root, int data)
{
    if(root == NULL)
        root = createNode(data);
    else if(data <= root->data)
        root->left = insertBST(root->left,data);
    else
        root->right = insertBST(root->right,data);
    return root;
}
int inorderSuccessor(node* root, node* n)
{
    int succ;
    if(n->right!=NULL)
    {
        node *temp = n->right;
        while(temp!=NULL)
        {
            succ = temp->data;
            temp = temp->left;
        }
    }
    else if (n->right == NULL)
    {
        node *temp = root;
        while(temp!=NULL)
        {
            if(n->data < temp->data)
            {
                succ = temp->data;
                temp = temp->left;
            }
            else if (n->data > temp->data)
                temp = temp->right;
            else
                break;
        }
    }
    return succ;
}
int main()
{
    node *root = NULL,*temp;
    root = insertBST(root, 20);
  root = insertBST(root, 8);
  root = insertBST(root, 22);
  root = insertBST(root, 4);
  root = insertBST(root, 12);
  root = insertBST(root, 10);
  root = insertBST(root, 14);
  temp = root->left->right;
    cout<<inorderSuccessor(root,temp);
    return 0;

}
