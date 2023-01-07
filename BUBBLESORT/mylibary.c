#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//  printing in color functions
  void red () {
    printf("\033[1;31m");
  }

 void yellow() {
   printf("\033[1;33m");
 }

 void reset () {
   printf("\033[0m");
 }

// function to print talbe
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

void tribulles(int T[], int n)
{
  int x;
  int change = 1;
  while (change == 1)
  {
    change = 0;
    for (int j = 0; j < n - 1; j++)
    {
      if (T[j] > T[j + 1])
      {
        x = T[j];
        T[j] = T[j + 1];
        T[j + 1] = x;
        printf("\n");
        printtable(T, n);
        change = 1;
      }
    }
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
  }
}

// void distrosort(int T[], int n , int max)
// {
//   max=maxtable(T,n);
//   int count[max];
//   int sorted[n];

//   for(int i=0;i<=max;i++)
//   {
//     count[i]=0;
//   }

//   for(int i=0;i<n-1;i++)
//   {
//     count[T[i]]=count[T[i]]+1;
//   }
//   printtable(count,max);
//   for(int i=0;i<n;i++)
//   {
//     printf("i=%d \n",i);
//     red();
//     printf("\n next = %d old = %d i = %d \n",count[i+1],count[i],i);
//     reset();
//     count[i+1]=count[i+1]+count[i];
//   }
//   printf("n=%d \n",n);
//   int j=n;
//   int valeur;
//   int postion;
//     printf("j=%d \n",j);
//     printtable(count,max);
//   while(j>0)
//   {
//     printf("inside the loop \n");
//     printf("n=%d \n",n);
//     printf("j=%d \n",j);
    
//     valeur=T[j];
//     postion=count[valeur];
//     sorted[postion]=T[j];
//      printf("postion=%d \n",postion);
//      printf("valeur=%d \n",valeur);
//       printf("sorted=%d \n",sorted[j]);
//     j=j-1;
//   }
//  printf("\n i am outside the loop \n ");

//  for (int i = 0; i < n; i++)
//   {
//     // printf("T[%d] = %d \n",i,T[i]);
//     // red();

//     if (i != (n - 1))
//     {
//       printf("[%d]---", sorted[i]);
//     }
//     else
//     {
//       printf("[%d]", sorted[i]);
//     }
//   }
// }

void fillrandom(int T[], int n)
{
  srand(time(0));
  for (int i = 0; i <= n; i++)
  {
    T[i] = rand() % 5;
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

int maxtable(int T[], int n)
{
  int max=T[0];
  for(int i=1;i<=n;i++)
  {
    if(max<T[i])
    {
      max=T[i];
    }
  }
  printf("max value dans le tablue est : %d \n",max);
  return max;
}

int main()
{
  // varaibles that are used to calculate the time needed for the execution of the algorithm inbetween t1 and t2
  FILE *fp;
  fp = fopen("MYRESULTSAREHERE.txt", "a+");
  clock_t t1, t2;
  float t;
  // varaibales of files : files are used to store the results of the execution

  // dynamyic declaration of our tables because of memeory needed for bigger values of n
  int n;
  printf("Donner la taile de tablue : \n");
  scanf("%d", &n);
  int *p = malloc(n); /*printtable(p,n);*/

  // remplire tablue avec des number alletoire entre 0 et 100
  fillrandom(p, n);
  printtable(p, n);
  // printf("\n");
  // fillbest(p, n);
  // printtable(p, n);
  // printf("\n");
  // fillworst(p, n);
  // printtable(p, n);
  // end
  // the tri algorithem is put here
  int max;
  t1 = clock();
  printf("\n");
  // tribulles(p,n);
  // gnomesort(p,n);
  max=maxtable(p,n);
  // distrosort(p,n,max);
  t2 = clock();
  // printtable(p,n);

  // execution time calculations
  t = (float)(t2 - t1) / CLOCKS_PER_SEC;
  //  printf("\033[32m\nt=%f \n \033[0m",t);
  printf("\n time = %f \n", t);
  // filet to store execution time
  fprintf(fp, "result is %f \n", t);
  fclose(fp);

  return 0;
}