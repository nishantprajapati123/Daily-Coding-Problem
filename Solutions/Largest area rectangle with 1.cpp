#include<bits/stdc++.h>
using namespace std;
int maxRectangleHistogram(vector<int>hist)
{
    int n = hist.size();
    stack<int>s;
    int i = 0,maxArea = INT_MIN;
    int area=0;
    while(i<n)
    {
        if(s.empty() || hist[s.top()]<hist[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            int temp_i = s.top();
            s.pop();
            if(!s.empty())
                area = hist[temp_i]*(i-s.top()-1);
            else
                area = hist[temp_i]*i;
            maxArea = max(maxArea,area);
        }
    }
    while(!s.empty())
    {
        int temp_i = s.top();
        s.pop();
        if(!s.empty())
            area = hist[temp_i]*(i-s.top()-1);
        else
            area = hist[temp_i]*i;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main()
{
    vector<vector<char>>matrix = {  {'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'},
                                    };
//    vector<int>hist = {6, 2, 5, 4, 5, 1, 6};
//    cout<<maxRectangleHistogram(hist);
    vector<int>hist(matrix[0].size(),0);
    int ans = INT_MIN;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
                hist[j] = matrix[i][j]=='0'?0:hist[j]+1;
        }
        ans = max(ans,maxRectangleHistogram(hist));
    }
    cout<<ans<<"\n";
    return 0;
}
