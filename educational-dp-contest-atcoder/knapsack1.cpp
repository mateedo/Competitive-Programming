//Educational DP Contest AtCoder D - Knapsack 1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n, w;
  cin >> n >> w;
  ll dp[w+1];
  memset(dp, -1, sizeof(dp));
  dp[0]=0;
  for(int i = 0; i < n; i++) {
    int item, value;

    cin >> item >> value;

    for(int p = w; p >=0; p--) {
      if(dp[p]==-1) {
        continue;
      }
      else if(p+item<=w) {
        dp[p+item] = max(dp[p+item], dp[p]+value);
      }
    }
  }

  ll largest = INT_MIN;

  for(int i = 0; i < w+1;i++) {
    largest = max(largest,dp[i]);
  }
  cout << largest << endl;

  