#include<iostream>
#include<algorithm>

#define INFTY 1000000001

using namespace std;

int n, s[500010], cnt = 0;

void merge(int *A, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j;

  int L[n1 + 10], R[n2 + 10];
  for(i = 0;i < n1;i++) L[i] = A[left + i];
  for(i = 0;i < n2;i++) R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(int k = left;k < right;k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int *A, int left, int right){
  if(left + 1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){

  cin >> n;
  for(int i = 0;i < n;i++) cin >> s[i];

  mergeSort(s, 0, n);

  for(int i = 0;i < n;i++){
    cout << (i?" ":"");
    cout << s[i];
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}
