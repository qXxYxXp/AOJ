#include<iostream>
#include<algorithm>

using namespace std;

typedef struct process{
  string name;
  int time;
} process; 

int n, head, tail;
process arr[100000];

void enqueue(process x){
  arr[tail] = x;

  if(tail + 1 == 100000) tail = 0;
  else tail++;
}

process dequeue(){
  process x = arr[head];

  if(head + 1 == 100000) head = 0;
  else head++;

  return x;
}

int main(){

  int q, t, total = 0;
  process x;

  cin >> n >> q;
  for(int i = 0;i < n;i++) cin >> arr[i].name >> arr[i].time;

  head = 0;
  tail = n;

  while(head != tail){
    x = dequeue();
    t = min(x.time, q);
    x.time -= t;
    total += t;
    if(x.time != 0) enqueue(x);
    else cout << x.name << " " << total << endl;
  }

  return 0;
}
