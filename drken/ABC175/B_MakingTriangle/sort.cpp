#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){

  vector<int> v = {0};
  for(int i=0;i<v.size();i++){
    cout << v[i] << endl;
  }

  v[0]=3; v[1]=2; v[2]=1;
  for(int i=0;i<v.size();i++){
    cout << v[i] << endl;
  }

  sort(v.begin(), v.end(), greater<int>{});
  for(int i=0;i<v.size();i++){
    cout << v[i] << endl;
  }
  
  return 0;
}
