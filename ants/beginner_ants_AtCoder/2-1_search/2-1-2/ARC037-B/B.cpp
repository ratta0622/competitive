#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> edge(N);
  for(int i=0; i<M; ++i){
    int u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  int ans = 0;
  vector<bool> flag(N, false);
  for(int i=0; i<N; ++i){
    bool flag_tree = false;
    if(flag[i]) continue;
    stack<pair<int,int>> DFS;
    DFS.push({i,-1});
    while(!DFS.empty()){
      pair<int,int> prev = DFS.top();
      DFS.pop();
      flag[from.first] = true;
      for(int to : edge[from.first]){
        if(flag[to] && to!=from.second){
          cout << "loop" << to << " " << from << endl;
          flag_tree = true;
          break;
        } 
        if(!flag[to.first]) DFS.push({to,from});
      }
    }
    if(!flag_tree) ++ans;
  }

  cout << ans << endl;

  return 0;
}
