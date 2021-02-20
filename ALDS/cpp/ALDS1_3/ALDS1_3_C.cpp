#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

struct Node{
  int key;
  Node *prev, *next;
};

Node *nil;

Node* search(int k){
  Node *x = nil->next;

  while(x != nil && x->key != k) x = x->next;

  return x;
}

void insert(int k){
  Node *x = (Node *)malloc(sizeof(Node));

  x->key = k;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

void deleteNode(Node *x){
  if(x == nil) return;
  x->prev->next = x->next;
  x->next->prev = x->prev;

  free(x);
}

void deleteFirst(){
  deleteNode(nil->next);
}

void deleteLast(){
  deleteNode(nil->prev);
}

int main(){

  int n, k;
  char command[20];

  nil = (Node *)malloc(sizeof(Node));
  nil->prev = nil;
  nil->next = nil;

  scanf("%d", &n);
  for(int i = 0;i < n;i++){
    scanf("%s", command);
    if(strcmp(command, "insert") == 0){
      scanf("%d", &k);
      insert(k);
    }else if(strcmp(command, "delete") == 0){
      scanf("%d", &k);
      deleteNode(search(k));
    }else if(strcmp(command, "deleteFirst") == 0){
      deleteFirst();
    }else if(strcmp(command, "deleteLast") == 0){
      deleteLast();
    }
  }

  k = 0;
  Node *x = nil->next;
  while(x != nil){
    printf((k?" ":""));
    printf("%d", x->key);
    k++;
    x = x->next;
  }
  printf("\n");

  return 0;
}
