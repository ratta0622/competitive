#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int N, M;
  cin >> N >> M;
  vector<P> ab(M);
  for(int i=0; i<M; ++i){
    int a,b;
    cin >> a >> b;
    ab[i].first = a;
    ab[i].second = b;
  }
  
  sort(ab.begin(), ab.end(), [](P a, P b){return a.second < b.second;});

  int ans = 0;
  int cut = -1;
  for(auto i=ab.begin(); i!=ab.end(); ++i){
    if(i->first <= cut) continue;
    ++ans;a
    cut = i->second - 1;
  }

  cout << ans << endl;

  return 0;
}
