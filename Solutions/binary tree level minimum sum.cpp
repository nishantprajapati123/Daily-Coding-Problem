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
int minLevel(node *root)
{
    int ans = INT_MAX;
    queue<node*>que;
    if(root == NULL)
        cout<<"Tree is empty\n";
    else
    {
        que.push(root);
        while(!que.empty())
        {
            int sum = 0;
            int n = que.size();
            while(n--)
            {
                node *tmp = que.front();
                que.pop();
                sum+=tmp->data;
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
            }
            ans = min(ans,sum);
        }
    }
    return ans;
}
int main()
{
//    node *root = NULL;
    node *root = createNode(1);
    root->left = createNode(-2);
    root->right = createNode(-3);
    root->left->left = createNode(4);
    root->left->right = createNode(-3);
    root->right->left = createNode(2);
    root->right->right = createNode(-1);
    cout<<minLevel(root);
}

