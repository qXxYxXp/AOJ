#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

#define M 1000003
#define L 14

char H[M][L];

long long h1(long long k){
  return k % M;
}

long long h2(long long k){
  return 1 + (k % (M - 1));
}

long long h(long long k, long long i){
  return (h1(k) + i * h2(k)) % M;
}

int getChar(char ch){
if ( ch == 'A') return 1;
else if ( ch == 'C') return 2;
else if ( ch == 'G') return 3;
else if ( ch == 'T') return 4;
return 0;
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int find(char str[]){
  long long key, i, id;

  key = getKey(str);
  i = 0;

  while(true){
    id = h(key, i);
    if(strcmp(H[id], str) == 0) return 1;
    else if(strlen(H[id]) == 0) return 0;
    i++;
  }
  return 0;
}

int insert(char str[]){
  long long key, i, id;

  key = getKey(str);
  i = 0;

  while(true){
    id = h(key, i);
    if(strcmp(H[id], str) == 0) return 1;
    else if(strlen(H[id]) == 0){
      strcpy(H[id], str);
      return 0;
    }
    i++;
  }
  return 0;
}

int main(){

  int n;
  char str[L], command[10];

  for (int i = 0; i < M; i++ ) H[i][0] = '\0';

  scanf("%d", &n);
  for(int i = 0;i < n;i++){
    scanf("%s %s", command, str);

    if(command[0] == 'i') insert(str);
    else{
      if(find(str)) printf("yes\n");
      else printf("no\n");
    }
  }


  return 0;
}
