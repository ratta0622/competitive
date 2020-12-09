#include <iostream>
#include <string>
using namespace std;

bool search(string T, string& S);

int main(){
  string S;
  cin >> S;
  
  string T;

  search(T,S)?(cout<<"YES"<<endl):(cout<<"NO"<<endl); 

  return 0;
}

bool search(string T, string& S){
  string str[4]={"dream", "dreamer", "erase", "eraser"};
  string T2;
  for(int i=0;i<4;i++){
    T2 = T+str[i];
    if( equal(begin(T2), end(T2), begin(S), begin(S)+T2.length()) ){
      if(T2.length() == S.length()){
        return 1;
      }else{
        if( search(T2, S) ) return 1;;
      }
    }
  }
  return 0;
}
