#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;

int top = 0;
int arr[200];

void push(int x){
  top++;
  arr[top] = x;
}

int pop(){
  top--;
  return arr[top + 1];
}

int main(){
  char x[10];
  int a, b;

  while(scanf("%s", x) != EOF){
    if(x[0] == '+'){
      a = pop();
      b = pop();
      push(a + b);
    }else if(x[0] == '-'){
      a = pop();
      b = pop();
      push(b - a);
    }else if(x[0] == '*'){
      a = pop();
      b = pop();
      push(a * b);
    }else{
      push(atoi(x));
    }
  }

  cout << pop() << endl;

  return 0;
}
