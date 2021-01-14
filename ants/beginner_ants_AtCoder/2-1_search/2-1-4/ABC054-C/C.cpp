#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> edge(N);
  for(int i=0; i<M; ++i){
    int a,b;
    cin >> a >> b;
    --a; --b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  int ans = 0;
  vector<int> permutation(N);
  iota(permutation.begin(), permutation.end(), 0);
  do{
    bool flag = true;
    for(auto i=permutation.begin(); i!=prev(permutation.end(),1); ++i){
      auto result = find(edge[*i].begin(), edge[*i].end(), *(next(i)));
      if(result == edge[*i].end()) flag = false;
    }
    if(flag) ++ans;
  }while(next_permutation(next(permutation.begin()), permutation.end()));

  cout << ans << endl;

  return 0;
}
