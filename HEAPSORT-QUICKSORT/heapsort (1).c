#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void fillrandom(int T[], int n)
{
  srand(time(0));
  for (int i = 0; i < n; i++)
  {
    T[i] = rand() % 1000;
  }
}
void fillbest(int T[], int n)
{
  for (int i = 0; i < n; i++)
  {
    T[i] = i;
  }
}
void fillworst(int T[], int n)
{
  for (int i = 0; i < n; i++)
  {
    T[i] = n-i;
  }
}


void supprimer_min(int T[],int a)
{
    int x;
    x = T[a];
    T[a] = T[0];
    T[0] = x;
}

void creer_tas(int T[], int n, int i)
{
    int p = i;
    int gauche = 2 * i + 1; // fils gauche
    int droite = 2 * i + 2; // fils droit
    int x;

    if (gauche < n && T[gauche] < T[p])
    {
        p = gauche;
    }

    if (droite < n && T[droite] < T[p])
    {
        p = droite;
    }

    if (p != i) {
        x = T[i];
        T[i] = T[p];
        T[p] = x;

        creer_tas(T, n, p);
    }
}

void tri_tas(int T[], int n)
{
    int x;
    int i;
    i = (n/2) - 1;
    while(i>=0)
    {
        creer_tas(T, n, i);
        i--;
    }
    i = n-1;
    while(i>=0)
    {
        supprimer_min(T,i);
        creer_tas(T, i, 0);
        i--;
    }


    //inverser les élements du tableau
    for(i=0;i<n/2;i++)
    {
        x = T[i];
        T[i] = T[n-i-1];
        T[n-i-1] = x;
    }
}

int main()
{
   // varaibles that are used to calculate the time needed for the execution of the algorithm inbetween t1 and t2
  clock_t t1, t2;
  float t[5]={0,0,0,0,0};
  float tbest;
  float tworse;
  float tmoyen;
  //different values of n that the algorithm will be tested on.
      int vals[40] = {2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000, 32500, 35000,
       37500, 40000, 42500, 45000, 47500, 50000, 52500, 55000, 57500, 60000, 62500, 65000, 67500, 70000, 72500, 75000
       , 77500, 80000, 82500, 85000, 87500, 90000, 92500, 95000, 97500, 100000};
    char lines[40][255];
  // dynamyic declaration of our tables because of memeory needed for bigger values of n
  for(int k=0; k<40; k++){
  int n = vals[k];
  //long n = 32500;
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  //int p[n];
  int* p = malloc(n * sizeof(int));

  // remplire tablue avec des number alletoire entre 0 et 100
  for(int j=0; j<5;j++)
  {
  fillrandom(p, n);
  //printtable(p, n);
  //SORT EXECUTION
  t1 = clock();
   tri_tas(p,n);
  t2 = clock();
     // execution time calculations
  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;

  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
  }
  }
    FILE* fp = fopen("tri_par_tas.txt", "w");
   for(int i=0; i<40; i++){
        fprintf(fp, lines[i]);
    }

    fclose(fp);


  return 0;
}


