/*
Extended Euclidean Algorithm (EEA)

@authors:
	Jonathan André Gangi 345334
	Philippe Cesar Ramos 380415

as seen on section 6.3.2 of Understanding Criptography:

	Extended Euclidean Algorithm (EEA)

	Input: positive integers r0 and r1 with r0 > r1

	Output: gcd(r0,r1), as well as s and t such that gcd(r0,r1) = s·r0 +t ·r1. 

	Initialization:
		s0=1 t0=0
		s1=0 t1=1
		i=1

	Algorithm:
		DO
			i = i+1
			ri = ri−2 mod ri−1
			qi−1 = (ri−2 −ri)/ri−1  
			si = si−2 − qi−1 · si−1
			ti = ti−2 − qi−1 · ti−1

		WHILE ri ≠= 0 

		2 RETURN
		gcd(r0,r1) = ri−1
		s = si−1 
		t = ti−1

and specified by:
<http://www.moodle.ufscar.br/file.php/4783/Aulas/Aula06/Atividades_sobre_a_teoria_dos_numeros.pdf>
	Input: two integers X and N, being 2 <= X, N < 2ˆ32.
	Output: two integers G (gcd) e I (inverse), such as I = X-1 mod N; if the inverse doesn't exist 
	it must be written the letter "N".

and Menezes' algorithm 2.107 found on Handbook of Applied Cryptography, Alfred J. Menezes,
Paul C. van Oorschot,Scott A. Vanstone since its adaptability for use with non-vector values:
	Algorithm: Extended Euclidean algorithm. (Ref: [MENE97], Algorithm 2.107)
	INPUT: Two non-negative integers a and b with a ≥ b.
	OUTPUT: d = gcd(a, b) and integers x and y satifying ax + by = d.
		If b = 0 then set d = a, x = 1, y = 0, and return(d, x, y).
		Set x2 = 1, x1 = 0, y2 = 0, y1 = 1
		While b > 0, do
		q = floor(a/b), r = a - qb, x = x2 - qx1, y = y2 - q y1.
		a = b, b = r, x2 = x1, x1 = x, y2 = y1, y1 = y.
		Set d = a, x = x2, y = y2, and return(d, x, y).
*/

#include <stdio.h>
#include <stdlib.h>

long gcd(long r0, long r1, long * s, long * t){

	long q, r;
	long s0, t1 = 1;
	long s1, t0 = 0;

	if (r1 == 0) {
		*s = 1;
		*t = 0;
		return r0;
	}

	while(r1 > 0) {
		q = r0 / r1;
		r = r0 - q * r1;
		
		*s = s0 - q * s1;
		*t = t0 - q * t1;
		
		r0 = r1;
		r1 = r;

		s0 = s1;
		s1 = *s;
		t0 = t1;
		t1 = *t;
	}
	
	*s = s0;
	*t = t0;

	return r0;

}


int main(){

	long X, N; //input

	long G, I; //output

	long s, t; //s and t pointers

	long aux;

	scanf("%ld %ld\n", &X, &N); //reading

	/* Need to X>N since Meneze's takes a>b */
	if (X<N){ 
		aux = X;
		X = N;
		N = aux;
	}

	G = gcd(X, N, &s, &t); //GCD

	/* t Mod N if t is negative to obtain a positive value for its inverse */
	I = t;
	while (I < 0){
		I = t + X;
	}

	if ( G == 1){ //Inverse exists
		printf("%ld %ld\n", G, I);
	}else{
		printf("%ld N\n", G);	
	}

	return 0;
}