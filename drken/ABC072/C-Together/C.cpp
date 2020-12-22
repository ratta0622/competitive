#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  int a[N];
  for(int i=0; i<N; ++i){
    cin >> a[i];
  }

  /* int max_count = INT_MIN; */
  /* for(int i=*min_element(a,a+N); i<*max_element(a,a+N); ++i){ */
  /*   int count = 0; */
  /*   for(int j=0; j<N; ++j){ */
  /*     if(a[j]==i-1 || a[j]==i || a[j]==i+1) ++count; */
  /*   } */
  /*   if(count>max_count) max_count=count; */
  /* } */

  int X[100000]={};
  for(int i=0; i<N; ++i){
    ++X[a[i]];
    ++X[a[i]-1];
    ++X[a[i]+1];
  }
  cout << *max_element(X, X+100000) << endl;

  /* cout << max_count << endl; */

  return 0;
}
