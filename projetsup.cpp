
#include "C:\Users\mouli\OneDrive\Documents\Master\info\TPL\matrix.h"
#include "C:\Users\mouli\OneDrive\Documents\Master\info\TPL\vector.h"

#include<math.h>
#include <iostream>
#include <cmath>


///////////// Supplément de projet /////////////


#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
const int mu = 1;
const int q = 1;
const int p = 1;
const int N = 10;
double h;

///////////// Solution de l'equation diff du problème (1) /////////////

vector Uex(vector x, vector y) //
{
	double lambda;
	vector Uex;
	double A, B;
	lambda = 1 / (pow(q * M_PI, 2) + pow(p * M_PI, 2) + mu);
	for (int i = 0; i < pow(N, 2) + 1; i++)
	{
		A = p * M_PI;
		B = q * M_PI;
		Uex(i)=(lambda * sin(A*x(i)) * sin(B * y(i)));
	}
	return Uex;
}

///////////// Création de la matrix A du schéma 2 /////////////

matrix A() {

	h = 0.1;
	int d;
	d = (int)(pow(N, 2) + 1);

	//	matrix U(pow(N, 2) + 1, pow(N, 2) + 1);
	matrix A(d, d);

	for (int i = 0; i < (pow(N, 2) + 1); i++)
	{
		if ((N + 1 < i) && (i < (N - 1) * N + 1))
		{
			A(i, i) = 4.0 + (pow(h, 2) * pow(mu, 2));
			A(i, i + 1) = A(i, i - 1) =A(i, i - (N + 1)) = A(i, i + (N + 1)) = -1;

		}


	}

	for (int k = 0; k < N; k++)
	{
		for (int j = 0; j < pow(N, 2); j++)
		{
			A(k * N, j) = 0;
			A(k * N + 1, j) = 0;

		}
	}
	std::cout << "Matrix A is: \n\n" << A;
	return (A);
};

vector En(vector U, vector Uex)
{
	vector num, den;
	num = norm(U - Uex, 2);
	den = norm(Uex, 2);
	vector En = num / den;

	return (En);
}