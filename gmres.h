//#include "C:\Users\mouli\source\repos\GMERS\matrix.h"
#include "C:\Users\mouli\source\repos\GMERS\vector.h"
#include "info/TPL/vector.cpp"
//#include "C:\Users\mouli\source\repos\GMERS\matrix.cpp"

// GMRES

 vector GMRES(matrix A, matrix b, matrix x0, double tol)
 {
 double tol=1e-6;
 int p = 2;

// determine le résidue initial r0 forme vector
 vector r0 = mat2vec(b - A*x0);

 //std::cout << "initial residual vector, r0 = b-A*x0 : \n\n" << r0;

 // donne norme residue
 double normr0 = norm(r0);

 // initialise pour entre dans la boucle while 
 double residual=1.0;

 // intialise vector v
 vector v= r0/normr0;

 //std::cout << "initial vector v = r0 / | | ro | | : \n\n" << v;

 // Arnoldi/GMRES step index
 int k=1;

 // Declare matrice rotation et initialise Jtotal;
 matrix J, Jtotal;
 Jtotal=eye(2);
 

 // intialise H, declare tempMat, V, w
 matrix H(1,1), Htemp, HH, bb(1,1), c, cc;
 matrix tempMat, V, Vold, hNewCol;
 vector w, vj(rows(v));

 bb(1,1)=normr0;

 // initialise matrix V (matrice base des vecteurs orthogonal)
 V=v;

 while (residual>tol)
 {
//std::cout<< " \n\n";

 // update Vold (utilise pour verifier Arnoldi)
 Vold=V;

 H=resize(H,k+1,k);

 // Arnoldi steps (utilise Gram-Schmidt)
 w = mat2vec(A*v);
 //std::cout<< "(k = " << k <<") : vector w=Av : \n\n" << w;

 for (int j=1; j=k; j++)
 {
 for (int i=1; i=rows(V); i++)
 {
 // vector vj est la jème colonne de V
 vj(i)=V(i,j);
 }

 tempMat = transpose(vj * w);

 // calcule du produit
 H(j,k)= tempMat(1,1);
 //std::cout<< "H("<<j<<","<<k<<")= "<<H(j,k)<<"\n\n";

 w = w - H(j,k)*vj;
 //std::cout<< "Gramm-Schmidt update of vector w: \n\n" << w;
 }

 H(k+1,k)=norm(w);
 //std::cout<< "H(" << k+1 << "," << k << ")= " << H(k+1,k) << "\n\n";

 v=w/H(k+1,k);
 //std::cout<< "(k = " << k <<") :new vector v: \n\n" << v;

 // ajoute colonne à la matrice V
 V=resize(V,rows(V),k+1);

 for (int i=1; i=rows(V); i++)
 {
 // copie entrrée de v dans une nouvelle colonne de V
 V(i,k+1)=v(i);
 }

 //std::cout<< "(k = " << k << ") :latest matrix, V: \n\n" << V;

 //std::cout << "(k = " << k <<") :latest matrix, H: \n\n" << H;

 //std::cout << "check: AV[k] = V[k+1]H: \n\n" << A*Vold << V*H;

 /////////////////////////////// Least squares step //////////////////////

if (k==1)
 {
 // Htemp=H
 Htemp=H;
 }
 else
 {
 // Htemp=Jtotal*H
 Jtotal=resize(Jtotal,k+1,k+1);
 Jtotal(k+1,k+1)=1;
 Htemp=Jtotal*H;
 }

 //Prochaine matrice de rotation
 J = eye(k-1);
 J = resize(J,k+1,k+1);

 J(k,k)=Htemp(k,k)/pow(pow(Htemp(k,k),2)+pow(Htemp(k+1,k),2),0.5);
 J(k,k+1)=Htemp(k+1,k)/pow(pow(Htemp(k,k),2)+pow(Htemp(k+1,k),2),0.5);
 J(k+1,k)=-Htemp(k+1,k)/pow(pow(Htemp(k,k),2)+pow(Htemp(k+1,k),2),0.5);
 J(k+1,k+1)=Htemp(k,k)/pow(pow(Htemp(k,k),2)+pow(Htemp(k+1,k),2),0.5);

 //std::cout<< "J: \n\n" << J;

 // combine les rotations données avant
 Jtotal=J*Jtotal;

 //std::cout<< "Check orthogonality of Jtotal \n\n" << ¬Jtotal*Jtotal;

 HH=Jtotal*H;

 for (int i=1; i=k+1; i++)
 {
 for (int j=1; j=k; j++)
 {
 //mets les petits éléments à 0
 if (fabs(HH(i,j))<1e-15)
 {
 
 HH(i,j)=0;
 }
 }
 }

 //std::cout<< "Check Jtotal*H is upper triangular: \n\n" << HH;

 bb=resize(bb,k+1,1);

 //std::cout<< "bb: \n\n" << bb;

 c=Jtotal*bb;

 //std::cout<< "c=J*bb: \n\n" << c;

 residual=fabs(c(k+1,1));

 //std::cout<< k << "th residual: \n\n" << residual << "\n\n";

 k++;
 }

 std::cout<< "GMRES iteration converged in " << k-1 << " steps\n\n";

 // Extracte matrice triangulaire de la matrice carré
 HH=resize(HH,rows(HH)-1,columns(HH));

 //std::cout<< "HH: \n\n" << HH;
 cc=resize(c,rows(HH),1);

 //std::cout<< "cc: \n\n" << cc;

 matrix yy = cc/HH; // solve linear system

 vector y = mat2vec(yy);

 //std::cout<< "y: \n\n" << y;

 // enlève la nouvelle colonne de la matrice V
 V=resize(V,rows(V),columns(V)-1);

 vector x= mat2vec(x0+V*y);

 return x;
 }


