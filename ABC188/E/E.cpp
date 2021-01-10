#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  int A[N];
  int X[M], Y[M];
  vector<vector<int>> edge(N);
  for(int i=0; i<N; ++i){
    cin >> A[i];
  }
  for(int i=0; i<M; ++i){
    cin >> X[i] >> Y[i];
    --X[i]; --Y[i];
    edge[X[i]].emplace_back(Y[i]);
  }

  vector<int> dp(N,INT_MAX);
  int ans = INT_MIN;
  for(int i=0;i<N;++i){
    ans = max(ans, A[i]-dp[i]);
    for(auto j : edge[i]){
      dp[j] = min(dp[j], dp[i]);
      dp[j] = min(dp[j], A[i]);
    }
  }
  
  cout << ans << endl;

  return 0;
}
