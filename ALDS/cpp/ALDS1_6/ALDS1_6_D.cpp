#include<iostream>
#include<algorithm>
using namespace std;

int n, w[1010], a[1010], b[10010] = {}, mi=100000;
bool used[1010];

int partition(int *A, int p, int r){
  int x = A[r];
  int i = p - 1;
    for(int j = p;j < r;j++){
      if(A[j] <= x){
        i++;
        swap(A[i], A[j]);
      }
    }
    swap(A[i + 1], A[r]);
  return i + 1;
}

void quicksort(int *A, int p, int r){
  if(p < r){
    int q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

int solve(){
  
  int ans = 0;
  
  quicksort(a, 0, n - 1);
  for(int i = 0;i < n;i++) b[a[i]] = i;
  
  for(int i = 0;i < n;i++){
    int cnt = 0, sum = 0, now = i, mimi = 100000;
    
    if(used[i]) continue;
    
    while(true){
      if(used[now]) break;
      cnt++;
      used[now] = true;
      mimi = min(mimi, w[now]);
      sum += w[now];
      now = b[w[now]];
    }
    
    ans += min(sum + (cnt - 2) * mimi, sum + mimi + (cnt + 1) * mi);
  }
  
  return ans;
}

int main(){
  
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> w[i];
    a[i] = w[i];
    mi = min(mi, w[i]);
  }
  
  cout << solve() << endl;

  return 0;
}
