#include<iostream>
#include<algorithm>

using namespace std;

int cnt, m;
int G[100]={1};

void insertionSort(int *A, int n, int g){
  for(int i=g;i<n;i++){
    int v=A[i];
    int j=i-g;

    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
    }

    A[j+g]=v;
  }
}

void shellSort(int *A, int n){
  cnt=0;

  for(int i=1;i<100;i++){
    G[i]=3*G[i-1]+1;
    if(G[i]>n){
      m=i;
      break;
    }
  }

  for(int i=0;i<m;i++){
    insertionSort(A, n, G[m-i-1]);
  }
}

int main(){

  int n, a[1000000];

  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];

  shellSort(a, n);

  cout<<m<<endl;

  for(int i=0;i<m;i++){
    cout<<(i?" ":"");
    cout<<G[m-i-1];
  }
  cout<<endl;

  cout<<cnt<<endl;

  for(int i=0;i<n;i++) cout<<a[i]<<endl;

  return 0;
}
