#include<bits/stdc++.h>
using namespace std;

string IsPalindrome(string s)
{
    int n = s.length();
    vector<int>freq(26,0);
    for(char ch:s)
        freq[ch-'a']++;
    int odd=0;
    for(int x:freq)
    {
        if(x&1)  odd++;
    }
    if(odd == 1 || odd == 0)
        return "Yes";
    else
        return "No";
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        cout<<IsPalindrome(s)<<"\n";
    }
    return 0;
}
