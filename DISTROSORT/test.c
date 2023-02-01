#include<stdio.h>
#include<math.h>

int cle(int i, int j){
    int p1 = pow(10, j+1);
    int p2 = p1/10;
    int t = ((i % p1) - (i % p2))/p2;
    return t;
}

void TriAux(int* T, int n, int i){
  int max = 0;
  for(int j = 0; j < n; j++){
    int digit = (T[j] / (int) pow(10, i)) % 10;
    max = max > digit ? max : digit;
  }
  int count[max + 1];
  for(int j = 0; j <= max; j++) count[j] = 0;

  for(int j = 0; j < n; j++){
    int digit = (T[j] / (int) pow(10, i)) % 10;
    count[digit]++;
  }
  for(int j = 1; j <= max; j++) count[j] += count[j - 1];
  int output[n];
  for(int j = n - 1; j >= 0; j--){
    int digit = (T[j] / (int) pow(10, i)) % 10;
    output[--count[digit]] = T[j];
  }
  for(int j = 0; j < n; j++) T[j] = output[j];
}


void TriBase(int* T, int n, int k){
    for(int i=0; i<k; i++){
        TriAux(T, n, i);
    }
}

int main(){
    int T[] = {141, 232, 045, 112, 143};
    int n = sizeof(T) / sizeof(T[0]);
    int k = 3;
    TriBase(T, n, k);
    for(int i=0; i<n; i++){
        printf("%d ", T[i]);
    }
    return 0;
}
