#include<bits/stdc++.h>
#define all(s) s.begin(),s.end()
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(i == j)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += max(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        return *min_element(all(triangle[triangle.size()-1]));
}
int main()
{
    vector<vector<int>>A  = {{2},{3,4},{6,5,7},{4,1,8,3} };
    cout<<minimumTotal(A);
}
