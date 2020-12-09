#include <iostream>
using namespace std;

int main(){
  int s, count=0;
  cin >> s;

  if(s%2==1){
    count++;
  }
  if((s/10)%2==1){
    count++;
  }
  if((s/100)%2==1){
    count++;
  }

  cout << count << endl;

  return 0;
}
