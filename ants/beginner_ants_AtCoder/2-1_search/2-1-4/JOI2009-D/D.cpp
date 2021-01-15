#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

vector<string> input(10);
set<string> number;

/* vector<int> index is (0, 1, ... ,n-1) */
/* copy index and erase chosen number -> can choose number without overlapping */
/* vector class is passed by reference */
void choose(vector<int>& index, int k, string s){
  string str;
  if(k==1){
    for(int i : index){
      str = s + input[i];
      number.insert(str);
    }
  }else{
    vector<int> cp_idx = index;
    for(auto i=cp_idx.begin(); i!=cp_idx.end(); ++i){
      str = s + input[*i];
      cp_idx.erase(i);
      choose(cp_idx, k-1, str);
      cp_idx = index;
    }
  }
}

int main(){
  int n, k;
  cin >> n >> k;
  for(int i=0; i<n; ++i){
    cin >> input[i];
  }
  vector<int> index(n);
  iota(index.begin(), index.end(), 0);

  choose(index, k, "");

  /* cout << endl; */
  /* for(auto i : number){ */
  /*   cout << i <<  " " << endl; */

  /* } */

  cout << number.size() << endl;


  return 0;
}
