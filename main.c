#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	

	x = createMatrix(b->r, 1);
	res = eliminate(A,b);
	printToScreen(A);
	printToScreen(b);
	
	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res != 0){
			return res;
		}
		printToScreen(x);
	  	freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
