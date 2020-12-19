#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  ll v[N];
  for(int i=0; i<N; ++i){
    cin >> v[i];
  }

  sort(v, v+N, greater<ll>());

  ll sum=0;
  double mean[B-A+1]={};

  for(int i=0; i<B; ++i){
    sum += v[i];
    if(i>=A-1){
      mean[i-A+1] = (double)sum/( i+1 );
      if(mean[i-A+1] != mean[0]) break;
    }
  }

  /* for(auto i=0; i<B-A+1; ++i){ */
  /*   cout << "mean[" << i << "]:" << mean[i] << " "; */
  /* } */
  /* cout << endl; */

  int m   = 0;
  int n   = 0;

  for(int i=0; i<A; ++i){
    if(v[i]==v[A-1]) ++m;    
  }
  for(int i=A; i<N; ++i){
    if(v[i]==v[A-1]) ++n;
  }

  /* for(int i=0; i<N; ++i){ */
  /*   cout << v[i] << " "; */
  /* } */
  /* cout << endl; */

  /* cout << "m:" << m << " n:" << n << endl; */

  ll comb[B-A+1]={};
  comb[0]=1;
  for(int i=0; i<m; ++i){
    comb[0] *= (m+n-i);
    comb[0] /= (m-i);
  }

  int count=0;
  for(int i=1; i<B-A+1; ++i){
    if(mean[i] != mean[0]) break;
    ++ count;
  }

  for(int i=1; i<=count; ++i){
    if(i>n) break;
    comb[i] = comb[i-1];
    comb[i] *= (n-i+1);
    comb[i] /= (m+i);
  }

  /* for(int i=0; i<B-A+1; ++i){ */
  /*   cout << "comb[" << i <<"]:" << comb[i] << endl; */
  /* } */

  cout << mean[0] << endl;
  cout << accumulate(comb, comb+(B-A+1), 0LL) << endl;
  

  return 0;
}
