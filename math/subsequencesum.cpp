//A Math Contest P2 - Subsequence Sum
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() {

    int n;
    cin >> n;
    int temp;
    long long count = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        count+=temp;
    }
    count%=mod;
    for(int i = 0; i < n-1; i++){
        count*=2;
        count%=mod;
    }
    cout << count << endl;
}
