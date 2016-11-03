#include<stdio.h>

//Definizione dei prototipi delle funzioni necessarie.
//-------------------------------------------------------------------------------
/*Funzione "verificaSchema(int mat[][9])", necessaria a verificare la correttezza
dell'intero schema di gioco.
int mat[][9]=>Matrice rappresentante lo schema di gioco.*/
int verificaSchema(int mat[][9]);
/*Funzione "vericaRighe(const int mat[][9],int riga)", necessarria a verificare la
correttezza di una singola riga.
const int mat[][9]=>Matrice rappresentante lo schema di gioco.
int riga =>Variabile che rappresenta la riga da controllare.*/
int verifichaRighe(const int mat[][9],int riga);
/*Funzione "verificaColonne(const int mat[][9],int colonna)", ncessaria a verificare la
correttezza di una singola colonna.
const int mat[][9]=>Matrice rappresentante lo schema di gioco.
int colonna =>Variabile che rappresenta la colonna da controllare.*/
int verificaColonne(const int mat[][9],int colonna);
/*Funzione verificaSettore(const int mat[][9],int righe,int colonne)", necessaria a verificare
la correttezza di un singolo settore.
const int mat[][9]=>Matrice rappresentante lo schema di gioco.
int righe=>Indice di inizio righe.
int colonne=>Indice di inizio colonne.*/
int verificaSettore(const int mat[][9],int righe,int colonne);
//-------------------------------------------------------------------------------

//Definizione della funzione "main()".
int main()
{
	//Dichiarazione della matrice rappresentante lo schema di gioco.
	int schema[9][9];
	//Caricamento della matrice.
	printf("Inserire  la matrice: \n\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			printf("Inserire l'elemento n.%d-%d: ",i+1,j+1);
			scanf("%d",&schema[i][j]);
		}
	}
	/*Invocazione della funzione "verificaSchema()", necessaria a verificare
	la correttezza dello schema di gioco e salvataggio del valore di ritorno
	nella variabile booleana "test".*/
	int test=verificaSchema(schema);
	/*Se, al termine del ciclo, la varibile "test" ha assunto valore "1", significa che lo schema
	di gioco inserito è corretto, in caso contrario, no. Comunicazione in output del risultato della
	verifica della correttezza dello schema di gioco.*/
	if(test)
	{
		printf("\n\nSchema valido!!!");
	}
	else
	{
		printf("\n\nSchema non valido!!!");
	}
	printf("\n\n");
}
//--------------------------------------------
/*Definizione della funzione "verificaSchema(int mat[][9])".
La funzione restituisce:
0=>Lo schema di gioco non è valido.
1=>Lo schema di gioco è valido.
*/
int verificaSchema(int mat[][9])
{
	//Definizione degli indici necessari.
	int i,j;
	//Variabile "schemaValido", contenente il risultato del controllo.
	int schemaValido=1;
	i=0;
	/*Verifica per righe, mediante la funzione "verificaRighe()".
	La verifica per righe si interrompe se viene riscontrata
	una riga che non rispetta lo schema di gioco.*/
	while(i<9 && schemaValido)
	{
		//Invocazione della funzione "verificaRighe()".
		if(!verificaRighe(mat,i))
		{
			schemaValido=0;
		}
		i++;
	}
	/*Se la verifica per righe ha restituito un risultato positivo, la funzione passerà
	a controllare la validità delle colonne.*/
	if(schemaValido)
	{
		j=0;
		/*Verifica per righe, mediante la funzione "verificaColonne()".
		La verifica per righe si interrompe se viene riscontrata
		una riga che non rispetta lo schema di gioco.*/
		while(j<9 && schemaValido)
		{
			//Invocazione della funzione "verificaColonne()".
			if(!verificaColonne(mat,j))
			{
				schemaValido=0;
			}
			j++;
		}
		/*Se la verifica per righe ha restituito un risultato positivo, la funzione passerà
		a controllare la validità dei settori.*/
		if(schemaValido)
		{
			i=0;
			while(i<9 && schemaValido)
			{
				j=0;
				while(j<9 && schemaValido)
				{
					//Verifica per settore mediante l'invocazione dell'apposita funzione.
					if(!verificaSettore(mat,i,j))
					{
						schemaValido=0;
					}
					j+=3;
				}
				i+=3;

			}
		}
	}
	return schemaValido;
}
//--------------------------------------------
/*Definizione della funzione "verificaRighe()"
La funzione restituisce:
0=>La riga non rispetta lo schema di gioco.
1=>La riga rispetta lo schema di gioco.
*/
int verificaRighe(const int mat[][9],int riga)
{
	int rigaValida=1;
	int i,j;

	i=0;
	while(i<9-1 && rigaValida)
	{
		j=i+1;
		while(j<9 && rigaValida)
		{
			if(mat[riga][i]==mat[riga][j])
			{
				rigaValida=0;
			}
			j++;
		}
		i++;
	}

	return rigaValida;

}
//--------------------------------------------
/*Definizione della funzione "verificaColonne()"
La funzione restituisce:
0=>La colonna non rispetta lo schema di gioco.
1=>La colonna rispetta lo schema di gioco.
*/
int verificaColonne(const int mat[][9],int colonna)
{
	int colonnaValida=1;
	int i,j;

	i=0;
	while(i<9-1 && colonnaValida)
	{
		j=i+1;
		while(j<9 && colonnaValida)
		{
			if(mat[i][colonna]==mat[j][colonna])
			{
				colonnaValida=0;
			}
			j++;
		}
		i++;
	}

	return colonnaValida;

}
//--------------------------------------------
/*Definizione della funzione "verificaColonne()"
La funzione restituisce:
0=>Il settore non rispetta lo schema di gioco.
1=>Il settore rispetta lo schema di gioco.
*/
int verificaSettore(const int mat[][9],int riga1,int colonna1)
{
	int settoreValido=1;

	int i,j,k,z;

	k=riga1;
	z=colonna1;

	while(k<(riga1+3) && settoreValido)
	{
		i=k;
		while(z<(colonna1+3) && settoreValido)
		{
			j=z+1;
			while(j<(colonna1+3) && settoreValido)
			{
				if(mat[k][z]==mat[i][j])
				{
					settoreValido=0;
				}
				j++;
			}
			z++;
		}
		k++;
	}
	return settoreValido;
}
