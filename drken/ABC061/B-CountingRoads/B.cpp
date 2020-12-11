#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
  int N, M;
  cin >> N >> M;
  int a[M], b[M];
  
  int road[N]={0};
  for(int i=0; i<M; i++){
    cin >> a[i] >> b[i];
  }
  for(int i=0; i<M; i++){
    road[a[i]-1]++;
    road[b[i]-1]++;
  }
  
  for(int i=0; i<N; i++){
    cout << road[i] << endl;
  }
  return 0;
}
