//Educational DP Contest AtCoder C - Vacation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int options[n][3];
  int dp[n][3];

  for(int i =0; i <n; i++)
    {
      for(int j = 0; j < 3; j++)
        {
          cin >> options[i][j];
        }
    }
  dp[0][0] = options[0][0];
  dp[0][1] = options[0][1];
  dp[0][2] = options[0][2];
  for(int i = 1; i < n;i++)
    {
      for(int k=0;k<3;k++)
        {
          if(k==0)
          {
            dp[i][k] = options[i][k] + max(dp[i-1][1],dp[i-1][2]);
          }
          if(k==1)
          {
            dp[i][k] = options[i][k] + max(dp[i-1][0],dp[i-1][2]);
          }
          if(k==2)
          {
            dp[i][k] = options[i][k] + max(dp[i-1][1],dp[i-1][0]);
          }
        }
    }
  cout << max( dp[n-1][0] , max(dp[n-1][1],dp[n-1][2]));
}