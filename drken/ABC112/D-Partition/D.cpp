#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> gcd;
  for(int i=1; i<=sqrt(M); ++i){
    if(M%i == 0){
      gcd.push_back(i);
      gcd.push_back(M/i);
    }
  }
  sort(gcd.begin(), gcd.end());
  int answer;
  for(auto i=gcd.begin(); i!=gcd.end(); ++i){
    if(*i>M/N) break;
    answer = *i;
  }

  cout << answer << endl;

  return 0;
}
