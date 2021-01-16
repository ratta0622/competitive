#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  map<int,int> a;
  int max_num = 0;
  for(int i=0; i<N; ++i){
    int temp;
    cin >> temp;
    ++a[temp];
    max_num = max(max_num, temp);
  }

  vector<int> ans(K,0);
  int can_stack = K;
  for(int i=0; i<=max_num; ++i){
    int number = a[i];
    if(number == 0) break;
    can_stack = min(can_stack, number);
    for(int j=0; j<can_stack; ++j){
      ++ans[j];
    }
  }
  
  cout << accumulate(ans.begin(), ans.end(), 0) << endl;

  return 0;
}
