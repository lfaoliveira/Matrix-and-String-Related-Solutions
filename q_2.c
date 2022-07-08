#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0




int tamString(char* str){
if(str != NULL){
	int cont = 0;
	char c = str[cont];

	while(c != '\0'){
		cont++;
		c = str[cont];
	}
	return cont;

}

return -1;
}






void troca(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int vec_strings[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if ( tamString( (char*)vec_strings[j]) <= tamString( (char*)vec_strings[j + 1]) )
                troca(&vec_strings[j], &vec_strings[j + 1]);
}




char** LeStrings(int max_str_size){
	int n;
	printf("Numero de strings:");
	scanf("%i",&n);
	while (n < 1){
		printf("Numero menor que 1, tente novamente:\n");
	}
	printf("Insira as strings, aperte enter para definir a string\n");
	int i,j;

	char** vec_strings = (char**) malloc(n*sizeof(char*));

	getchar();

	for(i = 0; i< n; i++){
			char* str = (char*) malloc(max_str_size * sizeof(char));
			printf("String (%i)",i);
			fgets(str,max_str_size,stdin);

			j = 0;
			char c = str[0];
			while(c != '\n'){
				j++;
				c = str[j];
			}
			str[j] = '\0';
			vec_strings[i] = str;
	}

	return vec_strings;
}





char* Concatenar(char** vec_strings, int tam_vec,int max_str_size){
 if(vec_strings != NULL){
		int j,i;

		int tam_total = 0;

		char* str;

		char c;
		int maior = 0;

		for(i = 0; i < tam_vec; i++){
			str = vec_strings[i];


			j = 0;
			c = str[j];

			while(c != '\0'){
				tam_total++;
				++j;
				c = str[j];
			}
		}

	bubbleSort(vec_strings,tam_vec);

	char* str_aux = (char*) malloc((tam_total + 1) * sizeof(char));

int atual = 0;
	for(i = 0; i < tam_vec ; i++){

			str = vec_strings[i];

			j = 0;
			c = str[j];

			while(c != '\0'){
				str_aux[atual] = c;
				++j;
				atual++;

				c = str[j];
			}
			str_aux[atual] = ',';
			++atual;
	}
		str_aux[atual - 1] = '\0';



		return str_aux;

 }




return NULL;
}


void ImprimeConcatenada(char* s){
char c = s[0];
int j = 0;

int loop = true;
while(c != '\0'){
		if( (char) s[j + 1] == ',')
				printf(" ");
	printf("%c",c);
	++j;
	c = s[j];
}

}



int main(){
	int i,j;
	int tam = 3;
	int max_str_size = 128;
	char** vec_str = LeStrings(max_str_size);


	char* s = Concatenar(vec_str,tam,max_str_size);
	ImprimeConcatenada(s);


	return 0;
}
