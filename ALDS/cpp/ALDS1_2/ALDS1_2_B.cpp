#include<iostream>
#include<algorithm>
using namespace std;

int cnt=0;

void selectionSort(int *A, int N){
  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    if(i!=minj){
      swap(A[i], A[minj]);
      cnt++;
    }
  }
}

int main(){

  int n, a[110];

  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];

  selectionSort(a, n);

  for(int i=0;i<n;i++){
    cout<<(i?" ":"");
    cout<<a[i];
  }
  cout<<endl<<cnt<<endl;

  return 0;
}
