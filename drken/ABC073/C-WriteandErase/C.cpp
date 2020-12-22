#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  map<int, int> count;
  int answer = 0;

  int N;
  cin >> N;
  for(int i=0; i<N; ++i){
    int A;
    cin >> A;
    ++count[A];
  }
  for(auto i=count.begin(); i!=count.end(); ++i){
    if(i->second%2==1) ++answer;
  }
  
  cout << answer << endl;

  return 0;
}
