#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void red()
{
  printf("\033[1;31m");
}

void yellow()
{
  printf("\033[1;33m");
}

void reset()
{
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
void printtable(int T[], int n, int a, int b)
{

  for (int i = 0; i < n; i++)
  {
    // printf("T[%d] = %d \n",i,T[i]);
    // red();
    if (i != (n - 1) && i != a && i != b)
    {
      printf("[%d]---", T[i]);
    }
    if (i == (n - 1) && i != b && i != a)
    {
      printf("[%d] \n", T[i]);
    }
    if (i == a)
    {
      red();
      printf("[%d]--- ", T[i]);
      reset();
    }
    if (i == b && b == n - 1)
    {
      red();
      printf("[%d] \n", T[i]);
      reset();
    }
    if (i == b && b != n - 1)
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
int iter=1;
void tribulles(int T[], int n)
{
  int x;
  int change = 1;
  while (change == 1)
  {
    change = 0;
    printf("Iteration %d:\n", iter);

    for (int j = 0; j < n - 1; j++)
    {
      if (T[j] > T[j + 1])
      {
        x = T[j];
        T[j] = T[j + 1];
        T[j + 1] = x;
       // printf("\n");
       // printtable(T, n);
        change = 1;
        printtable(T, n, j, j+1);
      }
    }
    iter++;
  }
}

int main()
{
// variables to calculate the execution time of the algorithm between t1 and t2
clock_t t1, t2;
float t;

// variable to store the size of the array
int n;

// input the size of the array
printf("DONNEZ LA TAILE DE TABLUE ");
scanf("%d", &n);
printf("n = %d \n", n);

// create an array of size n
int p[n];

// fill the array with random numbers between 0 and 100
fillrandom(p, n);

// print the initial unsorted array
printtables(p, n);
printf("\n");

t1 = clock();
// call the optimized bubble sort function
tribulles(p, n);

t2 = clock();

// calculate the execution time
t = (float)(t2 - t1) / CLOCKS_PER_SEC;
printf("\n time = %.9f \n", t);

// return statement
return 0;
}
