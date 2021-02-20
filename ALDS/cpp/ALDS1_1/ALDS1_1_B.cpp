#include<iostream>
using namespace std;

int GCD(int x, int y){
  if(x%y) return GCD(y, x%y);
  else return y;
}

int main(){

  int x, y;

  cin>>x>>y;

  if(x>y) cout<<GCD(x, y)<<endl;
  else cout<<GCD(y, x)<<endl;

  return 0;
}
