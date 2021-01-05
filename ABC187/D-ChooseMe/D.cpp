#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  int answer = 0;
  ll vote=0;
  int N;
  cin >> N;
  ll A[N], B[N];
  vector<ll> greedy;
  for(int i=0; i!=N; ++i){
    cin >> A[i] >> B[i];
    vote += A[i];
    greedy.push_back(2*A[i]+B[i]);
  }

  sort(greedy.begin(), greedy.end(), greater<ll>());

  for(auto i=greedy.begin(); i!=greedy.end(); ++i){
    ++answer;
    vote -= *i;
    if(vote < 0) break;
  }

  cout << answer << endl;

  return 0;
}
