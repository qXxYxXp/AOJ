#include<iostream>
#include<algorithm>
using namespace std;

int n, pre[50], in[50], post[50], p = 0, cnt = 0;

void reconstruction(int left, int right){
  
  if(left >= right) return ;
  
  int c = pre[p++], m;
  for(int i = 0;;i++){
    if(c == in[i]){
      m = i;
      break;
    }
  }
  
  reconstruction(left, m);
  reconstruction(m + 1, right);
  
  post[cnt++] = c;
}

int main(){
  
  cin >> n;
  for(int i = 0;i < n;i++) cin >> pre[i];
  for(int i = 0;i < n;i++) cin >> in[i];
  
  reconstruction(0, n);
  
  for(int i = 0;i < n;i++){
    cout << (i?" ":"");
    cout << post[i];
  }
  cout << endl;
  
  return 0;
}
