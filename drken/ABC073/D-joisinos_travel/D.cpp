#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main(){
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r;
  int A[M], B[M], C[M];
  for(int i=0; i<R; ++i){
    int temp;
    cin >> temp;
    r.push_back(temp-1);
  }
  for(int i=0; i<M; ++i){
    cin >> A[i] >> B[i] >> C[i];
    --A[i];
    --B[i];
  }
  
  /* Warshall-Floyd Algorithm */
  int dist[N][N];
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = INT_MAX;
    }
  }
  for(int i=0; i<M; ++i){
    dist[A[i]][B[i]] = C[i];
    dist[B[i]][A[i]] = C[i];
  }
  for(int k=0; k<N; ++k){
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }

  /* Full search for sequence without repetition of {r1, ... , rR} */
  ll answer = LLONG_MAX;
  sort(r.begin(), r.end());
  do{
    ll distance=0;
    for(auto i=r.begin()+1; i!=r.end(); ++i){
      distance += dist[*i][*(i-1)];
    }
    answer = min(answer, distance);
  }while(next_permutation(r.begin(), r.end()));
  
  cout << answer << endl;

  return 0;
}
