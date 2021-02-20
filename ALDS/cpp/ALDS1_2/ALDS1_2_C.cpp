#include<iostream>
#include<algorithm>
using namespace std;

void bubbleSort(string *A, int N){
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=N-1;i>0;i--){
      if(A[i-1][1]>A[i][1]){
        swap(A[i-1], A[i]);
        flag=true;
      }
    }
  }
}

void selectionSort(string *A, int N){
  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i;j<N;j++){
      if(A[j][1]<A[minj][1]) minj=j;
    }
    if(i!=minj){
      swap(A[i], A[minj]);
    }
  }
}

int main(){

  int n;
  string c1[40], c2[40];

  cin>>n;
  for(int i=0;i<n;i++){
    string card;

    cin>>card;
    c1[i]=card;
    c2[i]=card;
  }

  bubbleSort(c1, n);
  selectionSort(c2, n);

  for(int i=0;i<n;i++){
    cout<<(i?" ":"");
    cout<<c1[i];
  }
  cout<<endl<<"Stable"<<endl;

  for(int i=0;i<n;i++){
    cout<<(i?" ":"");
    cout<<c2[i];
  }
  cout<<endl;

  bool flag=true;
  for(int i=0;i<n;i++){
    if(c1[i]!=c2[i]) flag=false;
  }
  if(flag) cout<<"Stable"<<endl;
  else cout<<"Not stable"<<endl;

  return 0;
}
