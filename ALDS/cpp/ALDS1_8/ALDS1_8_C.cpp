#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef struct Node{
  int value;
  Node *parent, *left, *right;
} Node;

Node *NIL, *root;

void insert(int k){
  Node *y = NIL, *x = root, *z;

  z = (Node *)malloc(sizeof(Node));
  z->value = k;
  z->left = z->right = NIL;

  while(x != NIL){
    y = x;
    if(z->value < x->value) x = x->left;
    else x = x->right;
  }
  z->parent = y;

  if(y == NIL) root = z;
  else if(z->value < y->value) y->left = z;
  else y->right = z;
}

Node* find(Node *x, int k){
  if(x == NIL || x->value == k) return x;

  if(k < x->value) return find(x->left, k);
  else return find(x->right, k);
}

Node* treeMinimum(Node *x){
  while(x->left != NIL) x = x->left;
  return x;
}

Node* treeSuccessor(Node *x){
  Node *y;

  if(x->right != NIL) return treeMinimum(x->right);
  y = x->parent;
  while(y != NIL && x == y->right){
    x = y;
    y = y->parent;
  }
  return y;
}

void Delete(Node *z){
  Node *x, *y;

  if(z->left == NIL || z->right == NIL) y = z;
  else y = treeSuccessor(z);

  if(y->left != NIL) x = y->left;
  else x = y->right;

  if(x != NIL) x->parent = y->parent;

  if(y == NIL) root = x;
  else if(y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;

  if(y != z) z->value = y->value;
}

void preParse(Node *node){
  if(node == NIL) return ;

  cout << " " << node->value;
  if(node->left != NIL) preParse(node->left);
  if(node->right != NIL) preParse(node->right);
}

void inParse(Node *node){
  if(node == NIL) return ;

  if(node->left != NIL) inParse(node->left);
  cout << " " << node->value;
  if(node->right != NIL) inParse(node->right);
}

int main(){

  int n, key;
  string command;

  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> command;
    if(command == "insert"){
      cin >> key;
      insert(key);
    }else if(command == "print"){
      inParse(root);
      cout << endl;
      preParse(root);
      cout << endl;
    }else if(command == "find"){
      cin >> key;
      if(find(root, key)) cout << "yes" << endl;
      else cout << "no" << endl;
    }else if(command == "delete"){
      cin >> key;
      Delete(find(root, key));
    }
  }

  return 0;
}
