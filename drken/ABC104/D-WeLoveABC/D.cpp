#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  const ll MOD=1e9+7;
  int N = S.size();

  /* dp[i][j] i:=Si j:=(0, empty) (1, A) (2, B) (3, C) */
  ll dp[100010][4] = {}; 

  dp[0][0]=1;
  for(int i=1; i<=N; ++i){
    for(int j=0; j<=3; ++j){
      if(S[i-1]=='?'){
        dp[i][j] += 3*dp[i-1][j];
        if(j!=0){
          dp[i][j] += dp[i-1][j-1];
        }
      }else{
        dp[i][j] += dp[i-1][j];
        if(j==1 && S[i-1]=='A'){
          dp[i][j] += dp[i-1][j-1];
        }else if(j==2 && S[i-1]=='B'){
          dp[i][j] += dp[i-1][j-1];
        }else if(j==3 && S[i-1]=='C'){
          dp[i][j] += dp[i-1][j-1];
        }
      }
      dp[i][j] %= MOD;
    }
  }

  cout << dp[N][3] << endl;

  return 0;
}
