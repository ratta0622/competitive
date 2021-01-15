#include <bits/stdc++.h>
using namespace std;

vector<string> input(10);
set<string> number;

void comb(int n_begin, int n_end, int k, string sum){
  string temp = sum;
  if(k==1){
    for(int i=n_begin; i<=n_end; ++i){
      sum = temp;
      sum += input[i];
      number.insert(sum);
    }
  }else{
    for(int i=n_begin; i<=n_end; ++i){
      sum = temp;
      sum += input[i];
      comb(i+1, n_end, k-1, sum);
    }
  }
}

int main(){
  int n, k;
  cin >> n >> k;
  for(int i=0; i<n; ++i){
    cin >> input[i];
  }

  comb(0, n-1, k, "");

  cout << endl;
  for(auto i : number){
    cout << i <<  " " << endl;

  }


  return 0;
}
