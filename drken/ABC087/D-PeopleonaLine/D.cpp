#include <bits/stdc++.h>
#include <climits>
#include <utility>
using namespace std;
using pair_int = pair<int,int>;

int main(){
  bool flag = true;
  int N, M;
  cin >> N >> M;
  int L[M], R[M], D[M];
  for(int i=0; i<M; ++i){
    cin >> L[i] >> R[i] >> D[i];
    --L[i]; --R[i];
  }

  vector<vector<pair_int>> G;
  for(int i=0; i<M;++i){
    G[L[i]].push_back(make_pair(R[i], D[i]));
    G[R[i]].push_back(make_pair(L[i], -D[i]));
  }

  queue<pair_int> q;
  vector<int> dist(N, INT_MAX);

  for(int i=0; i<N; ++i){
    if(dist[i] != INT_MAX) continue;

    q.push(make_pair(i,0));
    dist[i] = 0;

    while(!q.empty()){
      pair_int next = q.front();
      q.pop();
      int next_pair_vector = next.first;

      for(pair_int next_pair: G[next_pair_vector]){
        int next_node = next_pair.first;
        int distance = dist[next_pair_vector] + next_pair.second;

        if(dist[next_node] == INT_MAX){
          dist[next_node] = distance;
          q.push(next_pair);
        }else{
          if(dist[next_node] != distance) cout << "No" << endl; return 0;
        }
      }
    }
    
  }

  cout << "Yes" << endl;

  return 0;
}
