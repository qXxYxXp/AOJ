#include<iostream>
#include<algorithm>

using namespace std;

bool linearSearch(int *A, int length, int key){
  for(int i = 0;i < length;i++){
    if(A[i] == key) return true;
  }
  return false;
}

int main(){

  int n, q, cnt = 0;
  int s[10000], t[500];

  cin >> n;
  for(int i = 0;i < n;i++) cin >> s[i];
  cin >> q;
  for(int i = 0;i < q;i++) cin >> t[i];

  for(int i = 0;i < q;i++){
    if(linearSearch(s, n, t[i])) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
