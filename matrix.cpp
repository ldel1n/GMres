#include"C:\Users\mouli\OneDrive\Documents\Master\info\TPL\matrix.h"
#include "C:\Users\mouli\source\repos\GMERS\vector.h"
 
/////////////////// Constructors //////////////////////////////////////////
 
// Constructor 
 matrix::matrix()
 {
 // constructeur matrice vide 
 rows = 0;
 columns = 0;
 xx = NULL;
 }

 // Constructor matrice dimension données
 matrix::matrix(int no_of_rows, int no_of_columns)
 {
 // Matrix dimension 
 rows = no_of_rows;
 columns = no_of_columns;

 // 
 // pointeur  première entrée nombre de colonne 
 xx = new double *[no_of_rows];

 // Allocate mémoire pour les entrées de la matrice
 for (int i=0; i<no_of_rows; i++)
 {
 // Creates 'no of rows' et 'no of columns'
 xx[i] = new double[no_of_columns];
}
 for (int i=0; i<no_of_rows; i++)
 {
 for (int j=0; j<no_of_columns; j++)
 {
 // Initialise les entrées matrice 0
 xx[i][j]=0.0;
 }
 }
 }

 // Copy constructor ? creates matrix with the same entries as input, A
 matrix::matrix(const matrix& A)
 {
 rows = A.rows; // Matrix dim
 columns = A.columns;

 // A array de m pointers de la première entrée dans le vect 
 // (longeur 'A.columns')
 xx = new double *[A.rows];

 // Allocate mémoire pour les entrées de la matrice
 for (int i=0; i<A.rows; i++)
 {
 // Creates 'A.rows' et 'A.columns'
 xx[i] = new double[A.columns];

}
 for (int i=0; i < A.rows; i++)
 {
 for (int j=0; j < A.columns; j++)
 {
 // Copy de la matrice A
 xx[i][j]=A.xx[i][j];
 }
 }
 }

 // Destructor
 matrix::~matrix()
 {
 if ( rows > 0 || columns > 0 )
 {
 for (int i=0; i < rows; i++)
 {
 delete[] xx[i];
 }
 delete[] xx;
 }
 }

 // Surcharge du + donne : A + B, sommes deux matrices
 matrix operator +(const matrix& A, const matrix& B)
 {
 int m = rows(A), n = columns(A), p = rows(B), q = columns(B);

 if ( m != p || n !=q )
 {
 std::cout << "Error: Matrices of different dimensions";
 std::cout << "Returned first argument";
 return A;
 }
 else
 {
 matrix C(m,n);
 for (int i=0; i<m; i++)
 {
 for (int j=0; j<n; j++)
 {
 C.xx[i][j]=A.xx[i][j]+B.xx[i][j];
 }
 }
 return C;
 }
 }



 // Surcharge - operator to evaluate: A - B, soustraction de deux matrices
 matrix operator -(const matrix& A, const matrix& B)
 {
 int m,n,p,q;
 m = rows(A);
 n = columns(A);
 p = rows(B);
 q = columns(B);


 if ( m != p || n !=q )
 {
 std::cout << "Error: Matrices of different dimensions";
 std::cout << "Returned first argument";
 return A;
 }
 else
 {
 matrix C(m,n);
 for (int i=0; i<m; i++)
 {
 for (int j=0; j<n; j++)
 {
 C.xx[i][j]=A.xx[i][j]-B.xx[i][j];
 }
 }
 return C;
 }
 }
 matrix operator /(const matrix& A, const matrix& B)
 {
	 int m, n, p, q;
	 m = rows(A);
	 n = columns(A);
	 p = rows(B);
	 q = columns(B);


	 if (m != p || n != q)
	 {
		 std::cout << "Error: Matrices of different dimensions";
		 std::cout << "Returned first argument";
		 return A;
	 }
	 else
	 {
		 matrix C(m, n);
		 for (int i = 0; i < m; i++)
		 {
			 for (int j = 0; j < n; j++)
			 {
				 C.xx[i][j] = A.xx[i][j]/B.xx[i][j];
			 }
		 }
		 return C;
	 }
 }


 // Def multiplication entre  scalar, p et matrix, A
 matrix operator *(const double& p, const matrix& A)
 {
 // Create a matrix with the same dimensions as A
 matrix B(A.rows,A.columns);

 for (int i=0; i<A.rows; i++)
 {
 for (int j=0; j<A.columns; j++)
 {
 B.xx[i][j]= p * A.xx[i][j]; // Multiplie par p
 }
 }
 return B;
 }


 // Definition  multiplication entre matrix, A et scalar, p
 matrix operator *(const matrix& A, const double& p)
 {
 // Créé matrice même dimension de A
 matrix B(A.rows,A.columns);

 for (int i=0; i<A.rows; i++)
 {
 for (int j=0; j<A.columns; j++)
 {
 B.xx[i][j]= p * A.xx[i][j]; // Multiplie par p chaques éléments
 }
 }
 return B;
 }


 // Definition division d'une matrice par un scalaire p A/p
 matrix operator /(const matrix& A, const double& p)
 {
 // Créé matrice même dimension de A
 matrix B(A.rows,A.columns);


 for (int i=0; i<A.rows; i++)
 {
 for (int j=0; j<A.columns; j++)
 {
 B.xx[i][j]= A.xx[i][j]/p; // Divise chaques éléments par p
 }
 }
 return B;
 }


 // Même fct mais entrées inversées
 matrix operator /(const double& p, matrix& A)
 {
	 matrix B(A.rows, A.columns);


	 for (int i = 0; i < A.rows; i++)
	 {
		 for (int j = 0; j < A.columns; j++)
		 {
			 B.xx[i][j] = A.xx[i][j] / p; 
		 }
	 }
	 return B;
 }


 // multiplication de matrices:

 matrix operator *(const matrix& A, const matrix& B)
 {
 // Verifie que les deux matrices ont les mêmes dimensions
 assert(A.columns==B.rows);

 // Donne matrice C avec les bonnes dimensions 
 matrix C(A.rows,B.columns);

 double temp = 0;

 // rows (m)
 for (int i=0; i < A.rows ; i++)
 {
 // columns (q)
 for (int j=0; j < B.columns ; j++)
 {

 for (int k=0; k < A.columns ; k++)
 {
 temp = temp + A.xx[i][k]*B.xx[k][j];
 }

 // Donne valeurs de C
 C.xx[i][j]=temp;

 // reset temp
 temp = 0;
 }
 }

 return C;
 }

 ////////////////////// Unary operators ////////////////////////////////////

 		
 
matrix operator +(const matrix& A) 
{	// Definie l'operateur, '+'	 
  // Créé une matrice même dim que A
 matrix B(A.rows,A.columns);

 // Mêmes éléments de A dans B
 for (int i=0; i < A.rows; i++)
 {
 for (int j=0; j < A.columns; j++)
 {
 B.xx[i][j] = A.xx[i][j];
 }
 }
 return B;

}
matrix operator -(const matrix& A) // Definie operator, '-'
{
	// Créé une matrice même dim que A
	matrix B(A.rows, A.columns);

	// Mêmes éléments de A dans B
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.columns; j++)
		{
			B.xx[i][j] = -A.xx[i][j];
		}
	}
	return B;
}

 matrix transpose(const matrix& A) 
 {
 // Créé matrice temporelle avec dim inversée 
 matrix B(A.columns,A.rows);

 // Mêmes éléments de A dans B
 for (int i=0; i < A.columns; i++)
 {
 for (int j=0; j < A.rows; j++)
 {
 B.xx[i][j] = A.xx[j][i];
 }
 }
 return B;
}
		
 // Def matrice operateur '='
 // Retourne matrice égale 
 matrix& matrix::operator =(const matrix &A)
 {
 // Detruit anciens éléments
 for (int i=0; i < rows; i++)
 {
 delete[] xx[i];
 }
 delete[] xx;

 // donne les mêmes dimensions que la matrice d'entrée
 rows = A.rows;
 columns = A.columns;

 // Allocate mémoire 
 xx = new double *[A.rows];

for (int i=0; i < A.rows ; i++)
 {
 xx[i] = new double[A.columns];
}
 // Copie les valeurs de la matrice d'entrée 
for (int i=0; i < A.rows; i++)
 {
for (int j=0; j < A.columns ; j++)
 {
 
 xx[i][j]=A.xx[i][j];
 }
 }
 return *this;
}
 
 // fonction pour donner matrice de la forme a(i,j)
 double &matrix::operator() (int i, int j)
 {
 if (i <1 || j <1)
 {
 std::cout << "Error: One of your indices may have been too small \n\n";
}
 else if (i > rows || j > columns)
 {
 std::cout << "Error: One of your indices may have been too large \n\n";
 }
return xx[i-1][j-1];
}
 int rows(matrix A);
 int columns(matrix A);

 // Retourne 'rows'
 int rows(matrix A)
 {
 return A.rows;
}
 // Retourne 'columns'
 int columns(matrix A)
 {
 return A.columns;
}

 // Surcharge '<<' operator pour print matrice
 ostream& operator << (ostream& output, const matrix &A)
 {
 for (int i=0; i<A.rows; i++)
 {
 for (int j=0; j < A.columns; j++)
 {
 output << " " << A.xx[i][j];
 }
 output << "\n";
 }
 output << "\n";
 return output;
 }

matrix eye(int size)
{
		 // matrice temporelle même dim que A 
matrix temp_eye(size, size);

		 //Mêmes éléments de A dans B
for (int i = 0; i <= size; i++)
{
temp_eye(i,i) = 1;
}
return temp_eye;
}


 // Function that returns an nxn permutation matrix which swaps rows i and j
 matrix permute_r(int n, int i, int j)
 {
 // Créé une matrice identité nxn 
 matrix I=eye(n);

 // Zero sur diag
 I(i,i)=0;
 I(j,j)=0;

 // Rajoute les 1
 I(i,j)=1;
 I(j,i)=1;

 return I;
 }

 // Fonction retourne l'indice de la ligne du plus grands élement sous la diagonale d'une colonne

 int find_pivot(matrix A, int column)
{
 // Initialise maxval 
 double maxval=fabs(A(column,column));

 // Initialise rowval en column
 int rowval=column;

 for (int i=column+1; i <= A.rows; i++)
 {
 if ( fabs(A(i,column)) > maxval)
 {
 // Fait en sorte que maxval et rowval prends l'autre argument si plus grand que le précedent 
 maxval = fabs(A(i,column));
 rowval = i;
 }
 }
 return rowval;
 }


 // Fonction retourne matrice mxn avec les mêmes éléments que A

 matrix resize(matrix A, int m, int n)
 {
 int p,q;
 matrix Mout(m,n);


 // Prends la plus petite dim d'une des matrices 
 if (m<=A.rows)
 {
 p=m;
 }
 else
 {
 p=A.rows;
 }

 if (n<=A.columns)
 {
 q=n;
 }
 else
 {
 q=A.columns;
 }

 // Copie les éléments 
 for (int i=1; i <= p; i++)
 {
 for (int j=1; j <= q; j++)
 {
 Mout(i,j) = A(i,j);
 }
 } 

 return Mout;
}

