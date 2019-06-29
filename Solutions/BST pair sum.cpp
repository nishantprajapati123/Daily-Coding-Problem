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
bool pairSum(node* root, int sum, unordered_set<int>&st)
{
    if(root == NULL)
        return false;
    if(pairSum(root->left,sum,st))
        return true;
    if(st.find(sum-root->data)!=st.end())
    {
        cout<<root->data<<" "<<sum-root->data<<"\n";
        return true;
    }
    else
        st.insert(root->data);
    return pairSum(root->right,sum,st);

}
int main()
{
    node *root = NULL;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        root = insertBST(root,a);
    }
    int sum;
    cin>>sum;
//    print(root);
    unordered_set<int>st;
    if(!pairSum(root,sum,st));
    return 0;

}
