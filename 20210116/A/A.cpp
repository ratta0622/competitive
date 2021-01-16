#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;  
  cin >> N;
  ll a[N], b[N];
  for(int i=0; i<N; ++i){
    cin >> a[i];
  }
  for(int i=0; i<N; ++i){
    cin >> b[i];
  }
  
  /* vector<vector<ll>> product(N, vector<ll>(N, 0)); */

  /* ll ans = 0; */
  /* for(int n=0; n<N; ++n){ */
  /*   vector<ll> product(n+1); */
  /*   for(int i=0; i<=n; ++i){ */
  /*     product[i] = a[i]*b[n]; */
  /*   } */
  /*   ll max_el = *max_element(product.begin(), product.end()); */
  /*   ans = max(max_el, ans); */
  /*   cout << ans << endl; */
  /* } */

  vector<int> a_max(N,0);
  vector<int> b_max(N,0);
  for(int i=1; i<N; ++i){
    if(a[i] > a[a_max[i-1]]) a_max[i] = i;
    else a_max[i] = a_max[i-1];
    /* if(b[i] > b[b_max[i-1]]) b_max[i] = i; */
    /* else b_max[i] = b_max[i-1]; */
  }

  cout << a[0] * b[0] << endl;
  ll ans = a[0]*b[0];
  for(int n=1; n<N; ++n){
    ll temp = b[n] * a[a_max[n]];
    ans = max(temp, ans);
    cout << ans << endl;
  }


  return 0;
}
