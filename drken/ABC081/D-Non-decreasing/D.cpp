#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
  int N;
  cin >> N;
  int a[N];
  for(int i=0; i!=N; ++i){
    cin >> a[i];
  }
  
  int* max = max_element(a, a+N);
  int* min = min_element(a, a+N);

  vector<pair<int, int>> proc;

  bool flag;

  /* make all elements positive or negative */
  if(abs(*max) > abs(*min)){
    flag = true;
    for(int i=0; i<N; ++i){
      if(a[i]<0){
        a[i] += *max;
        proc.push_back(pair<int, int>(max-a+1, i+1));
      }
    }
  }else{
    flag = false;
    for(int i=0; i<N; ++i){
      if(a[i]>0){
        a[i] += *min;
        proc.push_back(pair<int, int>(min-a+1, i+1));
      }
    }
  }
  
  /* make a1 <= a2 <= ... <= aN */
  if(flag){ // all elements are positive
    for(int i=0; i<N-1; ++i){
      a[i+1] += a[i];
      proc .push_back(pair<int, int>(i+1, i+2));
    }
  }else{ // all elements are negative
    for(int i=N-1; i>0; --i){
      a[i-1] += a[i];
      proc .push_back(pair<int, int>(i+1, i));
    }
  }

  /* answer */
  cout << proc.size() << endl;
  for(auto i=proc.begin(); i!=proc.end(); ++i){
    cout << i->first << " " << i->second << endl;
  }


  return 0;
}
