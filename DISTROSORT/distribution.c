#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


float pire(float* val){
    float p = val[0];
    for(int i=1; i<5; i++){
        if(val[i] > p) p = val[i];
    }
    return p;
}

float moyenne(float* val){
    float m = 0;
    for(int i=0; i<5; i++){
        m += val[i];
    }
    return m/5;
}

float meilleur(float* val){
    float m = val[0];
    for(int i=1; i<5; i++){
        if(val[i] < m) m = val[i];
    }
    return m;
}




int cle(int i, int j){

    int k1 = pow(10, j+1);
    int k2 = k1/10;

    int t = ((i % k1) - (i % k2))/k2;

    return t;
}

void triAux(int* T, int n, int i){
    int m = 0;
    for(int k=0; k<10; k++){
        for(int j=0; j<n; j++){
            if(cle(T[j], i) == k){
                int temp = T[j];
                for(int l = j; l>m; l--){
                    T[l] = T[l-1];
                }
                T[m] = temp;
                m++;
            }
        }
    }

}

void TriBase(int* T, int n, int k){
    for(int i=0; i<k; i++){
        triAux(T, n, i);
    }

}

int main(){

    int valeurs[40] = {2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500, 25000, 27500, 30000, 32500, 35000, 37500, 40000, 42500, 45000, 47500, 50000, 52500, 55000, 57500, 60000, 62500, 65000, 67500, 70000, 72500, 75000, 77500, 80000, 82500, 85000, 87500, 90000, 92500, 95000, 97500, 100000};
    int n;

    char lines[40][255];
   

    for(int k=0; k<40; k++){
        n = valeurs[k];
        int T[n];
        
        float times[5] = {0, 0, 0, 0, 0};
        
        for(int j=0; j<5; j++){
            srand(time(NULL));

            for(int i=0; i<n; i++){
                T[i] = rand()%1000000;
            }


            double time_spent = 0;
            clock_t begin = clock();

            TriBase(T, n, 6);

            clock_t end = clock();
            time_spent += (double) (end - begin);
            times[j] = time_spent/CLOCKS_PER_SEC;

            }

            printf("%d,%f,%f,%f\n", n, moyenne(times), meilleur(times), pire(times));
            sprintf(lines[k], "%d,%f,%f,%f\n", n, moyenne(times), meilleur(times), pire(times));
    }

    FILE* fp = fopen("distribution.txt", "w");

    for(int i=0; i<40; i++){
        fprintf(fp, lines[i]);
    }

    fclose(fp);

    return 0;

}