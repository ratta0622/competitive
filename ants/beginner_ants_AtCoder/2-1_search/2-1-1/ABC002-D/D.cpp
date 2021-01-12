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
  for(int i=0; i<N; ++i){
    if(flag[i]) continue;
    int count = 1;
    queue<int> BFS;
    BFS.push(i);
    while(!BFS.empty()){
      int prev = BFS.front();
      flag[prev] = true;
      BFS.pop();
      cout << "start:" << prev+1 << endl;
      for(auto j : graph[prev]){
        if(!flag[j]){
          ++count;
          BFS.push(j);
          flag[j] = true;
          cout << "to:" << j+1 << endl;
        }
      }
    }
    cout << "end(count=" << count << ")" << endl;
    if(ans<count) ans = count;
  }

  cout << ans << endl;

  return 0;
}
