#include<iostream>
#include<algorithm>

using namespace std;

int main(){

  int n, mi=1e9, ans=-1e9;

  cin>>n;
  for(int i=0;i<n;i++){
    int R;
    cin>>R;
    ans=max(ans, R-mi);
    mi=min(mi, R);
  }

  cout<<ans<<endl;

  return 0;
}
