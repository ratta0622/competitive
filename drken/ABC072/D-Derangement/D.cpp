#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
  int N;
  cin >> N;
  int p[N];
  for(int i=0; i<N; ++i){
    cin >> p[i];
  }

  int count=0;
  for(int i=0; i<N; ++i){
    if(p[i]==i+1){
      ++count;
      int temp=p[i];
      p[i] = p[i+1];
      p[i+1] = temp;
    }
  }

  cout << count << endl;

  return 0;
}
