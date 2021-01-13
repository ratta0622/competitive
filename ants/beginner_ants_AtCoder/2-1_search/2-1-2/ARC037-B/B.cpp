#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

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
    bool flag_loop = false;
    if(flag[i]) continue;
    queue<P> BFS;
    BFS.push({i,-1});
    while(!BFS.empty()){
      P prev = BFS.front();
      flag[prev.first] = true;
      BFS.pop();
      for(auto next : edge[prev.first]){
        if(!flag[next]){
          BFS.push({next, prev.first});
        }else if(next != prev.second){
          /* cout << "loop" << endl; */
          flag_loop = true;
          break;
        }
      }
    }
    if(!flag_loop)++ans;
  }

  cout << ans << endl;

  return 0;
}
