#include<iostream>
#include<algorithm>
using namespace std;

int cnt=0;

void bubbleSort(int *A, int N){
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=N-1;i>0;i--){
      if(A[i-1]>A[i]){
        swap(A[i-1], A[i]);
        flag=true;
        cnt++;
      }
    }
  }
}

int main(){

  int n, a[110];

  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];

  bubbleSort(a, n);

  for(int i=0;i<n;i++){
    cout<<(i?" ":"");
    cout<<a[i];
  }
  cout<<endl<<cnt<<endl;

  return 0;
}
