//COCI '14 Contest 2 #2 Utrka
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int>runners;
int main() {
  int n;
  cin >> n;
  string name;
  for(int i =0; i < n; i++) {
    cin >> name;
    runners[name]++;
  }
  for(int i = 0; i < n-1;i++) {
    cin >> name;
    runners[name]--;
    if(runners[name] == 0) {
      runners.erase(runners.find(name));
    }
  }
  cout << (*runners.begin()).first << endl;
  
}