#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printtable(int T[], int n)
{

  for (int i = 0; i < n; i++)
  {
    // printf("T[%d] = %d \n",i,T[i]);
    // red();
    if (i != (n - 1))
    {
      printf("[%d]---", T[i]);
    }
    else
    {
      printf("[%d]", T[i]);
    }
  }
}
void initwithnull(int T[], int n)
{
  for (int i = 0; i < n; i++)
  {
    T[i] = 0;
  }
}
void fillrandom(int T[], int n)
{
  srand(time(0));
  for (int i = 0; i <= n; i++)
  {
    T[i] = rand() % 1000;
  }
}
void fillbest(int T[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    T[i] = i;
  }
}
void fillworst(int T[], int n)
{
  for (int i = 0; i <= n; i++)
  {
    T[i] = n-i;
  }
}


int cle(int i, int j){

    int p1 = pow(10, j+1);
    int p2 = p1/10;
    int t = ((i % p1) - (i % p2))/p2;
    return t;
}

void triAux(int* T, int n, int i){
  // Step 1: Find the maximum digit of the current iteration
  int max = 0;
  for(int j = 0; j < n; j++){
    int digit = cle(T[j], i);
    if (digit > max) {
      max = digit;
    }
  }
  
  // Step 2: Initialize the count array and set all values to 0
  int count[max + 1];
  memset(count, 0, sizeof count);
  printf("THE COUNT ARRAY : \n");
  printtable(count,max+1);
  printf("\n");

  // Step 3: Count the occurrences of each digit
  for(int j = 0; j < n; j++){
    int digit = cle(T[j], i);
    count[digit]++;
  }
  printf("THE COUNT ARRAY  OCCU : \n");
  printtable(count,max+1);
    printf("\n");

  // Step 4: Accumulate the count of each digit
  for(int j = 1; j <= max; j++) count[j] += count[j - 1];
  printf("THE COUNT ARRAY  ACCU : \n");
  printtable(count,max+1);
    printf("\n");

  // Step 5: Place each element in its correct position in the output array
  int output[n];
  for(int j = n - 1; j >= 0; j--){
    int digit = cle(T[j], i);
    if(digit >= 0) {
      output[--count[digit]] = T[j];
    }
    else {
      output[--count[0]] = T[j];
    }
  }

  // Step 6: Copy the sorted elements back to the input array
  for(int j = 0; j < n; j++) T[j] = output[j];
}





void TriBase(int* T, int n, int k){
    for(int i=0; i<k; i++){
           printf("\n Iteration %d:\n", i);
        triAux(T, n, i);

        printtable(T,n);

    }

}

int main()
{
  // varaibles that are used to calculate the time needed for the execution of the algorithm inbetween t1 and t2
  clock_t t1, t2;
  float t;
  //different values of n that the algorithm will be tested on.
  int n ;
  printf("Donnez la value de n \n");
  scanf("%d",&n);
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  int p[n];

  // remplire tablue avec des number alletoire entre 0 et 100
  
  fillrandom(p, n);
    printtable(p, n);
  //SORT EXECUTION 
  t1 = clock();
   TriBase(p, n, 5);
  t2 = clock();
  printf("\n");
      printtable(p, n);

     // execution time calculations
  t = (float)(t2 - t1) / CLOCKS_PER_SEC;
  
  printf("\n time = %.9f \n", t);

  return 0;
}

