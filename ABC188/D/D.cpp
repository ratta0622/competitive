#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main() {
  ll N, C;
  cin >> N >> C;
  map<int, int> event;
  for(int i=0; i<N; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    event[a]+=c;
    event[b+1]-=c;
  }
  
  ll answer=0, pay=0;
  int prev;
  for(auto i : event){
    if(pay>0){
      ll day = i.first - prev;
      if(pay>C) answer += C*day;
      else answer += pay*day; 
    }
    prev = i.first;
    pay += i.second;
  }


  cout << answer << endl;

  return 0;
}
