/*
#include "C:\Users\mouli\source\repos\GMERS\matrix.h"
#include "C:\Users\mouli\source\repos\GMERS\vector.h"

#include <stdlib.h>
#include <iostream> 

int useGMRES()
 {

matrix A(5,5);
 //A(1,5)=1;
 //A(2,1)=1;
 //A(3,2)=1;
 //A(4,3)=1;
 //A(5,4)=1;

 A(1,1)=0.8780;A(1,2)=0.8316;A(1,3)=0.2663;A(1,4)=0.9787;A(1,5)=0.0239;
 A(2,1)=0.1159;A(2,2)=0.2926;A(2,3)=0.2626;A(2,4)=0.7914;A(2,5)=0.2085;
 A(3,1)=0.9857;A(3,2)=0.5109;A(3,3)=0.5826;A(3,4)=0.2115;A(3,5)=0.2943;
 A(4,1)=0.8573;A(4,2)=0.7512;A(4,3)=0.4431;A(4,4)=0.9486;A(4,5)=0.3660;
 A(5,1)=0.4416;A(5,2)=0.3803;A(5,3)=0.4465;A(5,4)=0.0586;A(5,5)=0.8501;

 vector b(5);
 //b(1)=1;

 b(1)=1;b(2)=1;b(3)=1;b(4)=1;b(5)=1;

 vector x0(5);

 std::cout << "matrix A: \n\n" << A;
 std::cout << "vector b: \n\n" << b;
 std::cout << "initial guess vector, x0: \n\n" << x0;

 vector x = GMRES(A,b,x0);

 std::cout << "GMRES solution, x is: \n\n" << x;

 std::cout << "Check: Ax = \n\n" << A*x;

 std::cout << "Backslash solution b/A \n\n" << b/A;

 srand(7);

 //std::cout << "Random number 1: " << - 1000 + rand() 2000 << " \n\n";
 //std::cout << "Random number 2: " << - 1000 + rand() 2000 << " \n\n";
 //std::cout << "Random number 3: " << - 1000 + rand() 2000 << " \n\n";

 exit(0);
 }
 
 */