#include<iostream>
#include<algorithm>
using namespace std;

//l-child, r-sibling representation

int n;
int p[100010], l[100010], r[100010];

void dfs(int n, int depth){
  if(p[n] == -1){
    cout << "depth = " << depth << ", ";
    return ;
  }

  dfs(p[n], depth + 1);
  return ;
}

void searchchild(int c){
  cout << '[';
  for(int i = 0;;i++){
    if(c == -1) break;
    cout << (i?", ":"");
    cout << c;
    c = r[c];
  }
  cout << ']' << endl;
}

void searchtype(int i){
  if(p[i] == -1) cout << "root, ";
  else if(l[i] != -1) cout << "internal node, ";
  else cout << "leaf, ";
}

void solve(){
  for(int i = 0;i < n;i++){
    cout << "node " << i << ": ";
    cout << "parent = " << p[i] << ", ";
    dfs(i, 0);
    searchtype(i);
    searchchild(l[i]);
  }
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++) p[i] = l[i] = r[i] = -1;
  for(int i = 0;i < n;i++){
    int id, k, c, s;

    cin >> id >> k;
    for(int j = 0;j < k;j++){
      cin >> c;
      if(j == 0) l[id] = c;
      else r[s] = c;
      p[c] = id;
      s = c;
    }
  }

  solve();

  return 0;
}
