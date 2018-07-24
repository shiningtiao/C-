#include <iostream>
#include <vector>
using namespace std;
int backpack(int m, vector<int> A)
{
    int len = A.size();
    vector<vector<int>> dp(len,vector<int>(m+1));

    for(int i = 0; i < len; i++)
        dp[i][0] = 0;

    for(int j =1; j < m+1; j++)
    {
        if(j >= A[0]) dp[0][j] = A[0]; //第0个物品空间小于等于当前背包空间j， 背包可装满的空间是第0个物品体积
        else dp[0][j] = 0; //第0个物品大于当前背包空间j，背包可装满空间是0
        for(int i = 1; i < len; i++)
        {
            if(A[i] > j) dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max((dp[i-1][j-A[i]] +A[i]), dp[i-1][j]);
        }
    }
    return dp[len-1][m];
}

int main()
{
    vector<int> A;
    A = {2,3,5,7};
    int m = 12;
    int packr;
    packr = backpack(m,A);
    cout << packr <<endl;
    return 0;
}
