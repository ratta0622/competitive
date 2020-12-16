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

  ll f_a[N+2];
  ll f_b[N+2];

  f_a[0] = 0;
  f_a[N+1] = 0;
  for(int i=1; i<=N; ++i){
    f_a[i] = f_a[i-1] + v[i] + x[i-1] - x[i];
  }

  f_b[N+1] = 0;
  f_b[0] = 0;
  for(int i=N; i>=1; --i){
    f_b[i] = f_b[i+1] + v[i] + (C-x[i+1]) - (C-x[i]);
  }

  ll max_f_a[N+1];
  ll max_f_b[N+1];
  max_f_a[0] = f_a[0];
  max_f_b[0] = f_b[0];
  for(int i=1; i<=N; ++i){
    max_f_a[i] = max(max_f_a[i-1], f_a[i]);
  }
  for(int i=N; i>=1; --i){
    max_f_b[i] = max(max_f_b[i+1], f_b[i]);
  }

  ll max_v = 0;
  ll sum_v = 0;

  /* A which is turning point clockwise is fixed */
  for(int i=0; i<=N; ++i){
    max_v = max(max_v, max_f_b[i+1]+f_a[i]-x[i]);
  }

  /* B which is turning point clockwise is fixed */
  for(int i=N+1; i>=1; --i){
    max_v = max(max_v, max_f_a[i-1]+f_b[i]-(C-x[i]));
  }

  cout << max_v << endl;
  

  for(int i=0; i<N+2; ++i){
    cout << f_a[i] << " " << f_b[i] << " " <<  max_f_a[i] << " " << max_f_b[i] << endl;
  }


  return 0;
}
