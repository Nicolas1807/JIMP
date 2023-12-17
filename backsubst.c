#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
        int n = mat->r;
        x->r = n;
        if(n!=mat->c){
            printf("Metoda eliminacji Gaussa jest mozliwa tylko dla macierzy kwadratowej!");
            return 1;
        }

    for (int i = n - 1; i >= 0; i--) {
        double s = 0;
        for (int j = i+1; j < n; j++) {
            s+= mat->data[i][j] * x->data[j][0];
        }
        if(mat->data[i][i] ==0){
            printf("Luju nie dzielimy przez 0!");
            return 2;
        }
        x->data[i][0] = (b->data[i][0] - s) / mat->data[i][i];
    }
    return 0;

}


