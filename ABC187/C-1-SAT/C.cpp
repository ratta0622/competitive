#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  set<string> exc;
  set<string> no_exc;
  for(int i=0; i<N; ++i){
    string temp;
    cin >> temp;
    if(temp[0]=='!') exc.insert(temp.substr(1));
    else no_exc.insert(temp);
  }

  bool flag=true;
  for(auto i=exc.begin(); i!=exc.end(); ++i){
    auto itr = no_exc.find(*i);
    if(itr!=no_exc.end()){
      cout << *itr << endl;
      flag = false;
      break;
    }
  }
  if(flag) cout << "satisfiable" << endl;

  return 0;
}
