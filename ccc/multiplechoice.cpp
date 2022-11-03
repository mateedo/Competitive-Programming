//CCC '11 S2 - Multiple Choice
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, correct;
  char j;
  cin >> n;

  char arr[n];
  

  for(int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  for(int i = 0; i < n; i++)
    {
      cin >> j;
      if(j == arr[i])
      {
        correct++;
      }
    }
  cout << correct;
}