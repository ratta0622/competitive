#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int x[M], y[M];
  vector<bool> flag(N, false);
  vector<vector<int>> graph(N);
  for(int i=0; i<M; ++i){
    int x, y;
    cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  
  int ans = INT_MIN;
  for(int bit=1; bit<1<<N; ++bit){
    bool flag=false;
    for(int i=0; i<N-1; ++i){
      for(int j=i+1; j<N; ++j){
        if(bit&(1<<i) && bit&(1<<j)){
          auto itr = find(graph[i].begin(), graph[i].end(), j);
          if(itr == graph[i].end()){
            flag = true;
          }
        }
        if(flag) continue;
      }
      if(flag) continue;
    }
    if(flag) continue;
    if(__builtin_popcount(bit)>ans) ans = __builtin_popcount(bit);
  }

  cout << ans << endl;

  return 0;
}
