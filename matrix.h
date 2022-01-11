#ifndef MATRIXDEF
#define MATRIXDEF
// include the header file



#include <math.h>
#include <string>
#include <iostream>
#include <cassert>

using std::ostream;


 class matrix
 {

 /////////////////// Variables of the matrix class /////////////////////////

 public:
 // Def dimension de la matrice
 int rows, columns;
 // Pointeur première entrée de vect ou matrice 

 double **xx;

 public:

/////////////////// Constructors //////////////////////////////////////////

 
 // constructor default
 matrix();

 // créer une matrice avec les dimension données
 matrix(int no_of_rows,int no_of_columns);

 // copy constructor
 matrix(const matrix& A);

 ////////////////// Destructor /////////////////////////////////////////////

 ~matrix();

 ////////////////// Binary Operators ///////////////////////////////////////

 friend matrix operator +(const matrix& A, const matrix& B);
 friend matrix operator -(const matrix& A, const matrix& B);

 friend matrix operator *(const double& p, const matrix& A);
 friend matrix operator *(const matrix& A, const double& p);
 friend matrix operator *(const matrix& A, const matrix& B);

 friend matrix operator /(const matrix& A, const double& p);
 friend matrix operator /(const matrix& b, const matrix& A);

 ////////////////////// Unary operators ////////////////////////////////////
 friend matrix operator +(const matrix& A);
 friend matrix operator -(const matrix& A);




 /////////////////////// Other operators ///////////////////////////////////

 // Surcharge operator, '='
 matrix& operator =(const matrix &v);

 // Surcharge (), A(i,j) retourne matrice taille i,j  
 double &operator() (int i, int j);

 // Retourne  nombre ligne (row)
 friend int rows(matrix A);
 // Retourne  nombre ligne colonne (columns)
 friend int columns(matrix A);

 ////////////////////// Functions that are friends /////////////////////////

 // Surcharge de '<<' operator pour print matrice
 friend ostream& operator<<(ostream& output, const matrix& A);

 // Create nxn Identity matrix
 friend matrix eye(int size);

 // Permute ligne i et j matrice taille nxn
 friend matrix permute_r(int n, int i, int j);

 // Trouve le plus grand nombre sous la diagonale de la matrice A
 friend int find_pivot(matrix A, int column);

 friend matrix resize(matrix A, int m, int n);

 friend matrix transpose(const matrix& A);

 };


 #endif
