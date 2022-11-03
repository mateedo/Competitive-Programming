//Educational DP Contest AtCoder A - Frog 1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
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
    int a = abs(stones[i] - stones[i-1]) + dp[i-1];
    int b = abs(stones[i] - stones[i-2]) + dp[i-2];
    
    dp[i]  = min(a,b);
  }
  cout << dp[n-1] << endl;

  
  
}