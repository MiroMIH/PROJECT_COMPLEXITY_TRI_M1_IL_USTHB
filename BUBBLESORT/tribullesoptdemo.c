#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
  void red () {
    printf("\033[1;31m");
  }

 void yellow() {
   printf("\033[1;33m");
 }

 void reset () {
   printf("\033[0m");
 }
 void printtables(int T[], int n)
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
void printtable(int T[], int n,int a, int b)
{

  for (int i = 0; i < n; i++)
  {
    // printf("T[%d] = %d \n",i,T[i]);
    // red();
    if (i != (n - 1) &&  i != a &&  i != b)
    {
      printf("[%d]---", T[i]);
    }
    if (i == (n-1 ) &&  i != b &&  i != a)
    {
      printf("[%d] \n", T[i]);
    }
    if (i == a)
    {
        red();
      printf("[%d]--- ", T[i]);
      reset();
    }
    if (i == b && b == n-1)
    {
        red();
      printf("[%d] \n", T[i]);
      reset();
    }
    if (i == b && b != n-1)
    {
        red();
      printf("[%d]---", T[i]);
      reset();
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
void tribullesopt(int T[], int n)
{
  int x;
  int change = 1;
  int m=n-1;
  while (change == 1)
  {
    change = 0;
    for (int j = 0; j < m; j++)
    {
      if (T[j] > T[j + 1])
      {
        x = T[j];
        T[j] = T[j + 1];
        T[j + 1] = x;
       // printf("\n");
       // printtable(T, n);
        change = 1;
        //just for printing the demo
        int a=j;
        int b=j+1;
        printtable(T,n,a,b);
      }
    }
    m=m-1;
  }
}

int main()
{
  // varaibles that are used to calculate the time needed for the execution of the algorithm inbetween t1 and t2
  clock_t t1, t2;
  float t;
//   float tbest;
//   float tworse;
//   float tmoyen;
  //different values of n that the algorithm will be tested on.
    //   int vals[40] = {2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000, 32500, 35000,
    //    37500, 40000, 42500, 45000, 47500, 50000, 52500, 55000, 57500, 60000, 62500, 65000, 67500, 70000, 72500, 75000
    //    , 77500, 80000, 82500, 85000, 87500, 90000, 92500, 95000, 97500, 100000};
    // char lines[40][255];
  // dynamyic declaration of our tables because of memeory needed for bigger values of n
//   for(int k=0; k<40; k++){
//   int n = vals[k];
    int n;
    scanf("%d",&n);
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  int p[n];

  // remplire tablue avec des number alletoire entre 0 et 100
  fillrandom(p, n);
  //printtable(p, n);
  //SORT EXECUTION 
    printtables(p,n);
    printf("\n");
  t1 = clock();
   tribullesopt(p,n);
  t2 = clock();
     // execution time calculations
  t = (float)(t2 - t1) / CLOCKS_PER_SEC;
  
  printf("\n time = %.9f \n", t);
//    sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
  
  
//     FILE* fp = fopen("gnometestAAAAAAA.txt", "w");
//    for(int i=0; i<40; i++){
//         fprintf(fp, lines[i]);
//     }

//     fclose(fp);
  

  return 0;
}

