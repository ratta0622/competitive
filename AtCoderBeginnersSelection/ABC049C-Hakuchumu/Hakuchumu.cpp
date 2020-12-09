#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;

  string word[4] = {"dream", "erase", "dreamer", "eraser"};
  for(int i=0;i<4;i++){
    reverse( word[i].begin(), word[i].end() );
  }

  reverse(S.begin(), S.end());
  
  bool flag = true;

  while(flag){
    flag = false;
    
    if(equal(S.begin(), S.begin()+5, word[0].begin())){
      S.erase(S.begin(), S.begin()+5);
      flag = true;
    }
    if(equal(S.begin(), S.begin()+5, word[1].begin())){
      S.erase(S.begin(), S.begin()+5);
      flag = true;
    }
    if(equal(S.begin(), S.begin()+7, word[2].begin())){
      S.erase(S.begin(), S.begin()+7);
      flag = true;
    }
    if(equal(S.begin(), S.begin()+6, word[3].begin())){
      S.erase(S.begin(), S.begin()+6);
      flag = true;
    }
    if(S == ""){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}
