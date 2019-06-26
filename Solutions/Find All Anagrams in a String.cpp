#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
int main()
{
    fastIO
    freopen("input.txt","r",stdin);
    string s,p;
    getline(cin,s);
    getline(cin,p);
    vector<int>freq_s(26,0),freq_p(26,0);
    vector<int>ans;
    for(char ch:p)
        freq_p[ch-'a']++;

    int len_p = p.length(), len_s = s.length();
    if(len_s<len_p)
        for(int x:ans)  cout<<x<<" ";
    int i=0,j=0;
    for(;j<len_p;j++)
        freq_s[s[j]-'a']++;

    --j;
    if(freq_s == freq_p)
        ans.pb(i);
    for(;j<len_s-1;)
    {
        freq_s[s[i]-'a']--;
        i++,j++;
        freq_s[s[j]-'a']++;
        if(freq_s == freq_p)
            ans.pb(i);
    }
    for(int x:ans)
        cout<<x<<" ";
    return 0;
}
