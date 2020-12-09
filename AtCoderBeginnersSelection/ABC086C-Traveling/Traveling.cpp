#include <iostream>
using namespace std;

int distance(int x1, int y1, int x2, int y2);

int main(){
  int N;
  cin >> N;

  int t[N+1], x[N+1], y[N+1];
  
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;

  for(int i=1;i<N+1;i++){
    cin >> t[i] >> x[i] >> y[i];
  }

  int delta_t;
  int dist;
  for(int i=1;i<N+1;i++){

    delta_t = abs(t[i]-t[i-1]);
    dist = distance(x[i], y[i], x[i-1], y[i-1]);

    if(delta_t < dist){
      cout << "No" << endl;
      return 0;
    }

    if( (delta_t-dist)%2 == 1 ){
      cout << "No" << endl;
      return 0;
    }
    
  }
   
  cout << "Yes" << endl;

  return 0;
}

int distance(int x1, int y1, int x2, int y2){
  return abs(x1-x2)+abs(y1-y2);
}
