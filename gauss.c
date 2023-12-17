#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>
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

        for(i = 0; i<r-1;i++){

            int max = -100000000;
            int max_index = 0;

            for(k = i; k<r;k++){
                if(mat->data[i][k]>max)
                {
                    max = mat->data[i][k];
                    max_index = k;
                }
            }

            if(max_index != i)
            {
                int z;
                for(z = 0; z<r; z++)
                {
                    tmp[z] = mat->data[z][i];
                }
                for(z = 0; z<r; z++)
                {
                    mat->data[z][i] = mat->data[z][max_index];
                }

                for(z = 0; z<r; z++)
                {
                    mat->data[z][max_index] = tmp[z];
                }


            }

            for(j=i+1; j<r; j++){
                wspolczynnik = mat->data[i][j] / mat->data[i][i];
                for(k = i; k<r;k++)
                    mat->data[k][j] -= wspolczynnik * mat->data[k][i];
            }
            b->data[j][0] -= wspolczynnik * b->data[i][0];
        }
		free(tmp);
        return 0;
}
