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

  ll sum=0LL;
  double mean;

  for(int i=0; i<A; ++i){
    sum += v[i];
  }
  mean = (double)sum/A;

  int n = 0;
  for(int i=0; i<N; ++i){
      if(v[i]==v[A-1]) ++n;
  }

  /* for(int i=0; i<N; ++i){ */
  /*   cout << v[i] << " "; */
  /* } */
  /* cout << endl; */
  /* cout << "n:" << n << endl; */

  /* comb[i] is nCi */
  ll comb[N+1]={};
  comb[0]=1;
  for(int i=1; i<=N; ++i){
    if(i>n) break;
    comb[i] = comb[i-1]*(n-i+1)/i;
  }


  /* for(int i=0; i<N; ++i){ */
  /*   cout << "comb[" << i <<"]:" << comb[i] << endl; */
  /* } */

  int m = 0;
  for(int i=0; i<A; ++i){
      if(v[i]==v[A-1]) ++m;
  }

  ll answer = 0LL;
  if(v[0]!=v[A-1]){
    answer = comb[m];
  }else{
    for(int i=A;i<=B;++i){
      answer += comb[i];
    }
  }

  cout << mean << endl;
  cout << answer << endl;

  return 0;
}
