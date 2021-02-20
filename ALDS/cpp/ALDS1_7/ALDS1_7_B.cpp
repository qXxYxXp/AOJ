#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n;
int p[30], l[30], r[30];

void dfs(int n, int depth){
  if(p[n] == -1){
    cout << "depth = " << depth << ", ";
    return ;
  }

  dfs(p[n], depth + 1);
  return ;
}

int height(int i, int h){
  int hl = 0, hr = 0;

  if(l[i] == -1 && r[i] == -1) return h;
  if(l[i] != -1) hl = height(l[i], h + 1);
  if(r[i] != -1) hr = height(r[i], h + 1);

  return max(hl, hr);
}

void searchsibling(int i){
  if(p[i] == -1) cout << "sibling = " << -1 << ", ";
  else if(l[p[i]] == i) cout << "sibling = " << r[p[i]] << ", ";
  else cout << "sibling = " << l[p[i]] << ", ";
}

void searchdegree(int i){
  if(l[i] == r[i]) cout << "degree = " << 0 << ", ";
  else if(l[i] == -1 || r[i] == -1) cout << "degree = " << 1 << ", ";
  else cout << "degree = " << 2 << ", ";
}

void searchtype(int i){
  if(p[i] == -1) cout << "root";
  else if(l[i] == -1 && r[i] == -1) cout << "leaf";
  else cout << "internal node";
}

void solve(){
  for(int i = 0;i < n;i++){
    cout << "node " << i << ": ";
    cout << "parent = " << p[i] << ", ";
    searchsibling(i);
    searchdegree(i);
    dfs(i, 0);
    cout << "height = " << height(i, 0) << ", ";
    searchtype(i);
    cout << endl;
  }
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++) p[i] = l[i] = r[i] = -1;
  for(int i = 0;i < n;i++){
    int id, left, right;

    cin >> id >> left >> right;
    l[id] = left;
    r[id] = right;
    p[left] = p[right] = id;
  }

  solve();

  return 0;
}
