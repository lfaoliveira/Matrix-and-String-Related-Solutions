#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0




int** LeMatriz(){
	printf("Leitura de matriz\n");
	printf("---------------------\n");
	printf("Tamanho da Matriz:");
	int tam;
	scanf("%i",&tam);

	while(tam <= 0){
		printf("Numero menor que 1, tente novamente:");
		scanf("%i",&tam);
	}



	int** mat = (int**) malloc(tam*sizeof(int*));
	int i,j;

	if(mat == NULL){
		return NULL;
	}

	for(i = 0 ; i < tam; i++){
		mat[i] = (int*) malloc(tam*sizeof(int));
	}





	for(i = 0; i < tam; i++){
			for(j = 0; j < tam; j++){
					printf("Elemento[%i][%i]: ",i,j);
					int x;
					scanf("%i",&x);
					mat[i][j] = x;

			}
			printf("\n");

	}
	printf("Leitura Finalizada\n");
	return mat;
}







int** MaximoLocal(int** mat, int tam){

if(mat != NULL && tam >= 3){
	//impossivel ter 8 vizinhos com tamanho menor que 3


		int i,j;

		int** matAux = (int**) malloc(tam*sizeof(int*));
		for(i = 0 ; i < tam ; i++){
			matAux[i] = (int*) malloc(tam*sizeof(int));

		}


			for(i = 0; i < tam; i++){
					for(j = 0; j < tam; j++){
						matAux[i][j] =  false;
				}
			}



			//loop para achar os maximos locais

		int cont;
		for(i = 1; i <= tam - 2; i++){
			for(j = 1; j <= tam - 2; j++){

				int vec_octal[8] = {mat[i - 1][j - 1], mat[i - 1][j], mat[i - 1][j + 1], mat[i][j - 1], mat[i][j + 1], mat[i + 1][j - 1], mat[i + 1][j], mat[i + 1][j + 1]};
				int valor = mat[i][j];

				cont = 0;
				while(cont  < 7){
					if(vec_octal[cont] >= valor){
							matAux[i][j] = false;
						break;
					}
					++cont;
					matAux[i][j] = mat[i][j];
				}
				// fim while

			}

			//fim for do j
		}

		//fim for do i


		return matAux;

} // fim do primeiro if


return NULL;
}


int MaximoGlobal(int** mat , int tam){
if (mat != NULL && tam >= 3){
	int maior = mat[1][1];
	int i,j;

	for(i = 1; i <= tam - 2; i++){
			for(j = 1; j <= tam - 2; j++){
					if(mat[i][j] >= maior){
						maior = mat[i][j];
					}


				// fim while

			}
			//fim for do j
		}
		return maior;

}


return -0;

}


void PrintMaximoLocal(int** mat, int tam){

if(mat != NULL && tam >= 3){
	//impossivel ter 8 vizinhos com tamanho menor que 3


		int i,j;

		int** matAux = (int**) malloc(tam*sizeof(int*));
		for(i = 0 ; i < tam ; i++){
			matAux[i] = (int*) malloc(tam*sizeof(int));
		}

			for(i = 0; i < tam; i++){
					for(j = 0; j < tam; j++){
						matAux[i][j] =  false;
				}
			}

			//loop para achar os maximos locais

		int cont;
		for(i = 1; i <= tam - 2; i++){
			for(j = 1; j <= tam - 2; j++){

				int vec_octal[8] = {mat[i - 1][j - 1], mat[i - 1][j], mat[i - 1][j + 1], mat[i][j - 1], mat[i][j + 1], mat[i + 1][j - 1], mat[i + 1][j], mat[i + 1][j + 1]};
				int valor = mat[i][j];

				cont = 0;
				while(cont  < 7){
						// se houver alguem maior que o elemento, ele nao e maximo local
					if(vec_octal[cont] >= valor){
							matAux[i][j] = false;
						break;
					}
					++cont;
					matAux[i][j] = mat[i][j];
				}
				// fim while

			}

			//fim for do j
		}


		for(i = 1; i <= tam - 2; i++){
			for(j = 1; j <= tam - 2; j++){
				int elem = matAux[i][j];
				if( elem != false){
					printf("%i (%i,%i)",elem,i,j);
				}

			}
			printf("\n");

			//fim for do j
		}

		//fim for do i

} // fim do primeiro if



}




void ImprimeMatriz(int** mat,int tam){
if (mat != NULL && tam > 0){
	int i,j;
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			printf("%i ",mat[i][j]);
		}
		printf("\n");
	}
}
}


int main(){
	printf( "(Na Main) Insira o tamanho da matriz" );
	int tam;
	scanf("%i",&tam);

	int** mat  = LeMatriz();

	int i,j;

	ImprimeMatriz(mat,tam);


	int** mat2= (int**) malloc(tam*sizeof(int*));

	for(i = 0 ; i < tam ; i++){
		mat2[i] = (int*) malloc(tam*sizeof(int));
	}

	mat2 = MaximoLocal(mat,tam);


	int** k = MaximoGlobal(mat,tam);

	PrintMaximoLocal(mat,tam);



	return 0;
}
