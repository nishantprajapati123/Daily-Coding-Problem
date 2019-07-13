#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)    arr[i] = -arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        arr[i] = arr[i]*arr[i];

    for(auto x:arr)
        cout<<x<<" ";
}
