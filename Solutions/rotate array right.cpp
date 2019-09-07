#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>&nums, int k)
{
    int n = nums.size();
    int sz = n;
    int j = k % n;
    int beg = 0;
    int rem = nums[beg];
    while(n-- > 0)
    {
        int temp = nums[j];
        nums[j] = rem;
        rem = temp;

        //for breaking symmetric
        if(j == beg)
        {
            beg = (beg+1)%sz;
            rem = nums[beg];
            j++;
        }

        j = (j + k)%sz;
    }
}
int main()
{
    int n, k;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    cin>>k;
    rotate(A,k);
    for(int x:A)
        cout<<x<<" ";
}
