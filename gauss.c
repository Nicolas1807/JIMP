#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
		int i,j,k;
        double wspolczynnik;
        int r = mat->r;
        int c = mat->c;
        if(r!=c){
            printf("Metoda eliminacji Gaussa jest mozliwa tylko dla macierzy kwadratowej!");
            return -1;
        }
        for(i = 0; i<r;i++){
            if(mat->data[i][i] == 0.0){
                printf("Macierz A jest osobliwa, nie mozna uzyc metody eliminacji Gaussa!");
                return 1;
            }
        }

        double *tmp = (double*)malloc(sizeof(*tmp)*r);
        double t;

        for(i = 0; i<r-1;i++){

            int max = -100000000;
            int max_index = 0;

            for(k = i; k<r;k++){
                if(fabs(mat->data[k][i])>max)
                {
                    max = mat->data[k][i];
                    max_index = k;
                }
            }

            if(max_index != i)
            {
                int z;
                
                t = b->data[i][0];
                b->data[i][0] = b->data[max_index][0];
                b->data[max_index][0] = t;

                for(z = 0; z<r; z++)
                {
                    tmp[z] = mat->data[i][z];
                    
                }
                for(z = 0; z<r; z++)
                {
                    mat->data[i][z] = mat->data[max_index][z];

                }

                for(z = 0; z<r; z++)
                {
                    mat->data[max_index][z] = tmp[z];
                }


            }

            for(j=i+1; j<r; j++){
                wspolczynnik = mat->data[j][i] / mat->data[i][i];
                for(k = i; k<r;k++)
                {
                    mat->data[j][k] -= wspolczynnik * mat->data[i][k];  
                }
                b->data[j][0] -= wspolczynnik * b->data[i][0];
            }
            
        }
		free(tmp);
        return 0;
}
