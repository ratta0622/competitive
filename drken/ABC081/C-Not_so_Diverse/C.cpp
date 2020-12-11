#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,K;
  cin >> N >> K;
  int A[N];
  for(int i=0; i<N; ++i){
    cin >> A[i];
  }
  
  map<int, int> ball;
  
  for(int i=0; i<N; ++i){
    ++ball[A[i]];
  }

  int diff = max(0, int( ball.size()-K ));

  int sort_ball[ball.size()];
  int idx=0;
  for(auto i=ball.begin(); i!=ball.end(); ++i){
    sort_ball[idx] = i->second;
    ++idx;
  }
  sort(sort_ball, sort_ball+ball.size());

  
  int answer = 0;
  for(int i=0; i<diff; ++i){
    answer += sort_ball[i];
  }

  cout << answer << endl;

  return 0;
}
