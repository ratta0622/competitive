#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N, K;
  cin >> N >> K;
  ll a[N], b[N];
  for(int i=0; i<N; ++i){
    cin >> a[i] >> b[i];
  }

  map<ll, ll> array;

  for(int i=0; i<N; ++i){
    array[a[i]] += b[i];
  }
  
  ll count = 0;

  for(auto i=array.begin(); i!=array.end(); ++i){
    count += i->second;
    if(count >= K){
      cout << i->first << endl;
      return 0;
    }
  } 

  return 0;
}
