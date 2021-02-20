#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

#define PI acos(-1)

using namespace std;

typedef struct Point{
  double x, y;
} P;

int n;

void koch(int cnt, P p1, P p2){
  P s, t, u;

  if(cnt == n) return ;

  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  u.x = (t.x - s.x) * cos(PI / 3) - (t.y - s.y) * sin(PI / 3) + s.x;
  u.y = (t.x - s.x) * sin(PI / 3) + (t.y - s.y) * cos(PI / 3) + s.y;

  koch(cnt + 1, p1, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(cnt + 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(cnt + 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(cnt + 1, t, p2);
}

int main(){

  P l, r;

  l.x = 0.0;
  l.y = 0.0;
  r.x = 100.0;
  r.y = 0.0;

  cin >> n;

  printf("%.8f %.8f\n", l.x, l.y);
  koch(0, l, r);
  printf("%.8f %.8f\n", r.x, r.y);

  return 0;
}
