#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;

  int m[N];
  int count=0;
  for(int i=0;i<N;i++){
    cin >> m[i];
    X -= m[i];
    count++;
  }

  int min = 1001;
  for(int i=0;i<N;i++){
    if(min > m[i]) min = m[i];
  }

  count += X/min;

  cout << count << endl;

  return 0;
}
