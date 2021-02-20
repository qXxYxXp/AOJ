#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
  int value, priority;
  Node *left, *right;
} Node;

Node* Delete(Node *, int);
Node* _delete(Node *, int);

Node *NIL, *root;

Node* rightRotate(Node *t){
  Node *s = t->left;
  t->left = s->right;
  s->right = t;
  return s; // root of the subtree
}

Node* leftRotate(Node *t){
  Node *s = t->right;
  t->right = s->left;
  s->left = t;
  return s; // root of the subtree
}

Node* makenode(int key, int priority){
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = key;
  node->priority = priority;
  node->left = node->right = NIL;

  return node;
}

Node* insert(Node *t, int key, int priority){    // 再帰的に探索
  Node *x;

  if(t == NIL) return x = makenode(key, priority); // 葉に到達したら新しい節点を生成して返す

  if(key == t->value) return t;                // 重複したkeyは無視

  if(key < t->value){                          // 左の子へ移動
      t->left = insert(t->left, key, priority); // 左の子へのポインタを更新
      if(t->priority < t->left->priority) t = rightRotate(t); // 左の子の方が優先度が高い場合右回転
  }else{                                       // 右の子へ移動
      t->right = insert(t->right, key, priority); // 右の子へのポインタを更新
      if(t->priority < t->right->priority) t = leftRotate(t); // 右の子の方が優先度が高い場合左回転
  }

  return t;
}

Node* find(Node *x, int k){
  if(x == NIL || x->value == k) return x;

  if(k < x->value) return find(x->left, k);
  else return find(x->right, k);
}

Node* Delete(Node *t, int key){
  if(t == NIL) return NIL;
  if(key < t->value) t->left = Delete(t->left, key); // 削除対象を検索
  else if(key > t->value) t->right = Delete(t->right, key);
  else return _delete(t, key);
  return t;
}

Node* _delete(Node *t, int key){ // 削除対象の節点の場合
  if(t->left == NIL && t->right == NIL) return NIL; // 葉の場合
  else if(t->left == NIL) t = leftRotate(t);   // 右の子のみを持つ場合左回転
  else if(t->right == NIL) t = rightRotate(t); // 左の子のみを持つ場合右回転
  else{                                        // 左の子と右の子を両方持つ場合
    if(t->left->priority > t->right->priority) t = rightRotate(t); // 優先度が高い方を持ち上げる
    else t = leftRotate(t);
  }
  return Delete(t, key);
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

  int n, key, priority;
  string command;

  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> command;
    if(command == "insert"){
      cin >> key >> priority;
      root = insert(root, key, priority);
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
      root = Delete(root, key);
    }
  }

  return 0;
}
