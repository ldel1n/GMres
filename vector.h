#ifndef VECTORDEF
#define VECTORDEF

#include "C:\Users\mouli\source\repos\GMERS\matrix.h"

// 'vector' enfant de la classe 'matrix' 
class vector : public matrix 
 {

public:

 //////////////////////// Constructors ////////////////////////////////////

 // default constructor
 vector();
 // Constructor prends un argument (size du vector)
 vector(int no_of_elements);

 ////////////////// Binary Operators //////////////////////////////////////

 friend vector operator +(const vector& A, const vector& B);
 friend vector operator -(const vector& A, const vector& B);

 friend vector operator *(const double& p, const vector& A);
 friend vector operator *(const vector& A, const double& p);

 friend vector operator /(const vector& A, const double& p);


 ////////////////////// Unary operators //////////////////////////////////

 friend vector operator +(const vector& A);
 friend vector operator -(const vector& A);


 /////////////////////// Autres operators /////////////////////////////////

 // Overloads (), so x(i) retourne la ième entrée
 double &operator() (int i);

 // Overloads l'operator, '=' 
 vector& operator =(const vector &v);

 ////////////////////// Functions that are friends //////////////////////

 friend vector mat2vec(matrix A);

 // Default call is norm(v) and returns 2-norm
 friend double norm(vector v, int p); //p=2

 friend vector GMRES(matrix A, matrix b, matrix x0, double tol);

// friend vector GMRESout(matrix A, matrix b, matrix x0, double tol=1e-6);


 };
 #endif
