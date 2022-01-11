#include "C:\Users\mouli\source\repos\GMERS\vector.h" // include the header file
#include "C:\Users\mouli\source\repos\GMERS\matrix.h"
//#include "C:\Users\mouli\source\repos\GMERS\gmres.h" // include the header file




//////////////////////// Constructors /////////////////////////////////////

// Dans class, 'vector' il y un contructeur
 vector::vector()

// constructeur
 : matrix()
 {

 }

 vector::vector(int no_of_elements)

 : matrix(no_of_elements,1)
 {

 }

 /////////////////////// Other operators //////////////////////////////////
 

 // Surcharge (), x(i) retourne la ième entrée
 double &vector::operator() (int i)
 { 
 if (i < 1)
 {
 std::cout << "Error: Your index may be too small \n\n";
 }

 else if (i > rows)
 {
 std::cout << "Error: Your index may be too large \n\n";
 }
 return xx[i-1][0];
 }

 
 vector& vector::operator =(const vector &v)
 {
 // Detruit entrée précedentes
 for (int i=0; i < rows; i++)
 {
 delete[] xx[i];
 }
 delete[] xx;

 // new dimensions 
 rows = v.rows;
 columns = v.columns;

 // Allocate mémoire 
 xx = new double *[v.rows];

 for (int i=0; i < v.rows ; i++)
 {
 xx[i] = new double[v.columns];
 }

 // Copie les valeurs de la matrice =
 for (int i=0; i < v.rows; i++)
 {
 for (int j=0; j < v.columns ; j++)
 {
 // Donne les mçme valeurs dans la matrice
 xx[i][j]=v.xx[i][j];
 }
 }
 return *this;

 }
 ////////////////// Binary Operators ///////////////////////////////////////

 vector operator +(const vector& A, const vector& B)
 {
 int m,n;
 m = rows(A);
 n = rows(B);

 if ( m != n )
 {
 std::cout << "Error: Matrices of different dimensions.";
 std::cout << " Returned first argument";
 return A;
 }
 else
 {
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = A.xx[i][0]+B.xx[i][0];
 }
 return v;
 }
 }

 vector operator -(const vector& A, const vector& B)
 {
 int m,n;
 m = rows(A);
 n = rows(B);

 if ( m != n )
 {
 std::cout << "Error: Matrices of different dimensions.";
 std::cout << " Returned first argument";
 return A;
 }
 else
 {
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = A.xx[i][0]-B.xx[i][0];
 }
 return v;
 }
 }

 //
 vector operator *(const double& p, const vector& A)
 {
 int m = rows(A);
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = p*A.xx[i][0];
 }
 return v;
 }
 //
 vector operator *(const vector& A, const double& p)
 {
 int m = rows(A);
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = p*A.xx[i][0];
 }
 return v;
 }
 //
 vector operator /(const vector& A, const double& p)
 {
 int m = rows(A);
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = A.xx[i][0]/p;
 }
 return v;
 }
 //

 //////////////////////// Unary operators /////////////////////////////////

vector operator +(const vector& A)
 {
 int m = rows(A);
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = A.xx[i][0];
 }
 return v;
 }
 //
 vector operator -(const vector& A)
 {
 int m = rows(A);
 vector v(m);
 for (int i=0; i<m; i++)
 {
 v(i+1) = -A.xx[i][0];
 }
 return v;
 }

 ////////////////////// Functions that are friends ////////////////////////

 // Function that returns the first column of a matrix, A as a vector

 vector mat2vec(matrix A)
 {
 // crée un vector même nombre ligne que A avec une colonne
 vector v(rows(A));

 for (int i=1; i = rows(A); i++)
 {
 v(i)=A(i,1); // copie la première colonne seulement
 }

 return v;
 }

 double norm(vector v, int p)
 {
 // definie variables et initialise sum
 double temp, value, sum = 0.0;

 for (int i=1; i = rows(v); i++)
 {
 // floating valeur absolue
 temp = fabs(v(i));
 sum += pow(temp, p);
 }

 value = pow(sum, 1.0/((double)(p)));

 return value;
 }
 