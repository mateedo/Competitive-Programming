//Disjoint Set Test
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int lol = 1e5;
int n, m;
int root[lol];
int si[lol];
void initialize(){
  for(int i = 0; i < n; i++){
    root[i] = i;
  }
  for(int i = 0; i < n; i++){
    si[i] = 1;
  }
}
int findRoot(int a){
  if(root[a] == a) return a;
  return root[a] = findRoot(root[a]);
}
void connect(int a, int b){
  a = findRoot(a);
  b = findRoot(b);
  if(si[a] < si[b]) swap(a,b);
  si[a]+= si[b];
  root[b] = a;
}
int main() {
  cin >> n >> m;
  vector<int> edges;
  initialize();
  for(int i = 1; i < m+1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if(findRoot(a) == findRoot(b))continue;
    connect(a,b);
    edges.push_back(i);
  }
  if(edges.size() != n-1){
    cout << "Disconnected Graph" << endl;
  }else{
    for(int i = 0; i < edges.size(); i++){
      cout << edges.at(i) << endl;
    }
  }
}
