#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
      printf("[%d] \n", T[i]);
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
void gnomesort(int T[],int n)
{
  int i=0;
  int x;
  while(i<n)
  {
    //when going backgroun so the i doesnt go negative
    if(i==0)
    {
      i++;
    }
    //if two element are in the correct order we pass into the next two
    if(T[i]>=T[i-1])
    {
      i++;
    }
    // if the two element arent in correct order we swap them and start going background to sort the set
    else
    {
      //swap
      x=T[i];
      T[i]=T[i-1];
      T[i-1]=x;
      //decrement the index each time to sort array backwards
      i--;
    }
    printtable(T,n);
  }
}

int main()
{
  // varaibles that are used to calculate the time needed for the execution of the algorithm inbetween t1 and t2
  clock_t t1, t2;
  float t;
    char lines[40][255];
  // dynamyic declaration of our tables because of memeory needed for bigger values of n
  int n;
  printf("DONNEZ LA VALUE DE n \n");
  scanf("%d",&n);
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  int p[n];

  // remplire tablue avec des number alletoire entre 0 et 100
  fillrandom(p, n);
  //printtable(p, n);
  //SORT EXECUTION 
  t1 = clock();
   gnomesort(p,n);
  t2 = clock();
     // execution time calculations
  t = (float)(t2 - t1) / CLOCKS_PER_SEC;
  
  printf("\n time = %.9f \n", t);
  

  return 0;
}

