#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;

  ll num;
  int digit;
  int min_digit = INT_MAX;
  for(ll i=1; i<=sqrt(N); ++i){
    if(N%i==0){
      num = max(i, (ll)N/i);
    }
    digit = to_string(num).size();
    if(min_digit>digit) min_digit=digit; 
  }

  cout << min_digit << endl;

  return 0;
}
