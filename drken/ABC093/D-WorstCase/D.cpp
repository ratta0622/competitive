#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b){
  if(a == b) return (a-1)*2;
  
  if(b<a) swap(a,b);
  /* binary search */
  ll left=1, right=2*b;
  while(right - left >1){
    ll mid = (right + left)/2;
    ll max_score = mid/2 * (mid-mid/2);
    if(max_score > a*b-1) right = mid;
    else left = mid;
  }
  return left;
}

int main(){
  int Q;
  cin >> Q;
  ll A[Q], B[Q];
  for(int i=0; i<Q; ++i){
    cin >> A[i] >> B[i];
  }
  for(int i=0; i<Q; ++i){
    cout << solve(A[i], B[i]) << endl;
  }
  return 0;
}
