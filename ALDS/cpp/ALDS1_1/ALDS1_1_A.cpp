#include<iostream>
using namespace std;

void insertionSort(int *A, int N){
  for(int i=1;i<N;i++){
    int v=A[i];
    int j=i-1;

    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }

    A[j+1]=v;

    for(int i=0;i<N;i++){
      cout<<(i?" ":"");
      cout<<A[i];
    }
    cout<<endl;
  }
}

int main(){

  int n;
  int a[110];

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    cout<<(i?" ":"");
    cout<<a[i];
  }
  cout<<endl;

  insertionSort(a, n);

  return 0;
}
