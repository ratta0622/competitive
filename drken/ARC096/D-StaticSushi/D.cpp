#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main(){
  int N;
  ll C;
  cin >> N >> C;
  ll x[N], v[N];
  for(int i=0; i<N; ++i){
    cin >> x[i] >> v[i];
  }

  ll max = 0;

  ll sum_v=0;
  for(int i=0; i<N; ++i){
    for(int j=N; j>i; --j){
      sum_v=0;
      if(j==N){
        for(int k=0; k<=i; ++k){
          sum_v += v[k];
        }
        if(sum_v-x[i] > max) max = sum_v-x[i];
      }else{
        for(int k=0; k<=i; ++k){
          sum_v += v[k];
        }
        for(int k=N-1; k>=j; --k){
          sum_v += v[k];
        }
        if(sum_v-2*x[i]+x[j]-C > max) max = sum_v-2*x[i]+x[j]-C;
      }
    }
  }

  sum_v = 0;
  for(int i=N-1; i>=0; --i){
    sum_v += v[i];
    if(sum_v+x[i]-C > max) max = sum_v+x[i]-C;
  }

  cout << max << endl;
  

  return 0;
}
