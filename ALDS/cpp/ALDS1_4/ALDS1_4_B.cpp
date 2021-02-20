#include<iostream>
#include<algorithm>

using namespace std;

bool binarySearch(int *A, int length, int key){
  int left = 0, right = length;

  while(left < right){
    int mid = (left + right) / 2;

    if(key == A[mid]) return true;
    else if(key > A[mid]) left = mid + 1;
    else if(key < A[mid]) right = mid;
  }
  return false;
}

int main(){

  int n, q, cnt = 0;
  int s[100000], t[50000];

  cin >> n;
  for(int i = 0;i < n;i++) cin >> s[i];
  cin >> q;
  for(int i = 0;i < q;i++) cin >> t[i];

  for(int i = 0;i < q;i++){
    if(binarySearch(s, n, t[i])) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
