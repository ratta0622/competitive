#include <bits/stdc++.h>
using namespace std;
using edge = pair<int, int>;

int main(){
  int N, M;
  cin >> N >> M;
  int L[M], R[M], D[M];
  for(int i=0; i<M; ++i){
    cin >> L[i] >> R[i] >> D[i];
    --L[i]; --R[i];
  }
  
  /* make graph */ 
  /* node1 --w--> node2 means person2 is w to the right of person1 */
  vector<vector<edge>> graph;
  for(int i=0; i<M; ++i){
    graph[L[i]].push_back({R[i], D[i]});
    graph[R[i]].push_back({L[i], -D[i]});
  }

  vector<int> distance(N, INT_MAX);
  vector<bool> flag(N, false);
  for(int i=0; i<N; ++i){
    if(distance[i] == INT_MAX) continue;
   
    distance[i] = 0;
    stack<vector<edge>> DFS;
    DFS.push(graph[i]);


    while(!DFS.empty()){
      auto next_nodes = DFS.top();
      DFS.pop();
      for(auto j : next_nodes){
        DFS.push(graph[j.first]);

      }
    }
    
  }

  return 0;
}
