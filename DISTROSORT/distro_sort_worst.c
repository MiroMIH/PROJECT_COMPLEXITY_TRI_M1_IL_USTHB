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

    int k1 = pow(10, j+1);
    int k2 = k1/10;

    int t = ((i % k1) - (i % k2))/k2;

    return t;
}

void triAux(int* T, int n, int i){
    int cles[10];
    int *resultat = (int*)malloc(n * sizeof(int));

    for(int k=0; k<10; k++) cles[k] = 0;

    for(int j=0; j<n; j++){
        cles[cle(T[j], i)]++;
    }

    for(int k=1; k<10; k++) cles[k] += cles[k-1];

    for(int j=n-1; j>=0; j--){
        resultat[cles[cle(T[j], i)] - 1] = T[j];
        cles[cle(T[j], i)]--;
    }

    for(int j=0; j<n; j++) T[j] = resultat[j];

}

void TriBase(int* T, int n, int k){
    for(int i=0; i<k; i++){
        triAux(T, n, i);
        // printtable(T,n);
        // printf("\n");
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
  printf("n = %d \n",n);
  //printf("Donner la taile de tablue : \n");
  int p[n];

  // remplire tablue avec des number alletoire entre 0 et 100
  for(int j=0; j<5;j++)
  {
  fillworst(p, n);
  //printtable(p, n);
  //SORT EXECUTION 
  t1 = clock();
   TriBase(p, n, 6);
  t2 = clock();
     // execution time calculations
  t[j] = (float)(t2 - t1) / CLOCKS_PER_SEC;
  
  printf("\n time = %.9f \n", t[j]);
   sprintf(lines[k], "%d,%f,%f,%f,%f,%f \n", n, t[0],t[1],t[2],t[3],t[4]);
  }
  }
    FILE* fp = fopen("TRI_DISTRO_WORST_SORT.txt", "w");
   for(int i=0; i<40; i++){
        fprintf(fp, lines[i]);
    }

    fclose(fp);
  

  return 0;
}

