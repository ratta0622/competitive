#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main(){
  int N;
  ll C;
  cin >> N >> C;
  ll x[N+2], v[N+2];
  x[0] = 0; v[0] = 0;
  x[N+1] = C; v[N+1] = 0;
  for(int i=1; i<=N; ++i){
    cin >> x[i] >> v[i];
  }

  ll max = 0;

  ll sum_v=0;
  for(int i=0; i<=N; ++i){
    for(int j=N+1; j>i; --j){
      sum_v=0;
      for(int k=0; k<=i; ++k){
        sum_v += v[k];
      }
      for(int k=N+1; k>=j; --k){
        sum_v += v[k];
      }
      if(sum_v-2*x[i]-(C-x[j]) > max) max = sum_v-2*x[i]-(C-x[j]);
      if(sum_v-2*(C-x[j])-x[i] > max) max = sum_v-2*(C-x[j])-x[i];
    }
  }

  cout << max << endl;
  

  return 0;
}
