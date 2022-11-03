//CCC '22 S2 - Good Groups
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
string groups[MAX][3];
string must[MAX][2];
string cant[MAX][2];

set<pair<string, string>> ryan;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int allowed, disallowed, G, violated;
  violated=0;
  // string kid1, kid2, kid3;  
  cin >> allowed;
  for(int i = 0; i < allowed; i++) {
    cin >> must[i][0] >> must[i][1];
  }
  cin >> disallowed;
  for(int i = 0; i < disallowed; i++) {
    cin >> cant[i][0] >> cant[i][1];
  }
  cin >> G;
  for(int i = 0; i < G; i++) {
    cin >> groups[i][0] >> groups[i][1] >> groups[i][2];
    ryan.insert({groups[i][0], groups[i][1]});
    ryan.insert({groups[i][1], groups[i][0]});
    ryan.insert({groups[i][1], groups[i][2]});
    ryan.insert({groups[i][2], groups[i][1]});
    ryan.insert({groups[i][0], groups[i][2]});
    ryan.insert({groups[i][2], groups[i][0]});
  }
  for(int i=0; i < allowed; i++) {
    pair<string, string>mateo = {must[i][0], must[i][1]};
    if(ryan.find(mateo) == ryan.end()) {
      violated++;
    }
  }
  for(int i=0; i < disallowed; i++) {
    pair<string, string>mateo = {cant[i][0], cant[i][1]};
    if(ryan.find(mateo) != ryan.end()) {
      violated++;
    }
      
  }
                  cout << violated << endl;
}