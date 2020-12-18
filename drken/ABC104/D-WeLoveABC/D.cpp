#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  int N = S.size(), MOD = 1000000007;

  ll dp[100000][4]={};
  for(int i=N; i>=0; --i){
    for(int j=3; j>=0; --j){
      if(i==N){
        dp[i][j] = (j==3?1:0);
      }else{
        dp[i][j] = dp[i+1][j] * (S[i] == '?'? 3:1);
        if(j<3 && (S[i] == '?' || S[i] == "ABC"[j])){
          dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}
