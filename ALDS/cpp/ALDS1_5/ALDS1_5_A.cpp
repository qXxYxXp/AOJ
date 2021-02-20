#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int a[20];

bool solve(int i, int sum){
  if(i == n) return false;
  if(sum + a[i] == m) return true;

  return solve(i + 1, sum) || solve(i + 1, sum + a[i]);
}

int main(){

  int q;

  cin >> n;
  for(int i = 0;i < n;i++) cin >> a[i];

  cin >> q;
  for(int i = 0;i < q;i++){
    cin >> m;
    if(solve(0, 0)) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
