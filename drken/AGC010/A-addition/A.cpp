#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int n_odd  = 0;
  int n_even = 0;

  for(int i=0; i<N; ++i){
    int temp;
    cin >> temp;
    if(temp%2==0) ++n_even;
    else ++n_odd;
  }

  n_even += n_odd/2;
  n_odd = n_odd%2;
  if(n_even!=0) n_even = 1;

  if(n_odd+n_even > 1) cout << "NO" << endl;
  else cout << "YES" << endl;

  return 0;
}
