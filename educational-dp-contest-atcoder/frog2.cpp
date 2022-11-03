//Educational DP Contest AtCoder B - Frog 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int stones[n];
  int dp[n];
  for(int i = 0; i < n; i++)
  {
    cin >> stones[i];
    
  }
  
  dp[0] = 0;
  dp[1] = abs(stones[1] - stones[0]);
  for(int i = 2; i < n; i++)
  {
    int d = abs(stones[i] - stones[i-1]) + dp[i-1];
    for(int j = 2; j <= k; j++)
      {
        if(i-j<0)
        {
          break;
        }
        int b = abs(stones[i] - stones[i-j]) + dp[i-j];
        d = min(d,b);
      }
    
    
    dp[i]  = d;
  }
  cout << dp[n-1] << endl;

  
  
}