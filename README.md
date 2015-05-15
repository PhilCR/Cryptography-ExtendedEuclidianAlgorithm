# ExtendedEuclidianAlgorithm
*for **Criptography**'s class*

##Authors:
	* Jonathan André Gangi
	* Philippe Cesar Ramos

Adaptation of **Menezes' algorithm 2.107** found on **Handbook of Applied Cryptography**, *Alfred J. Menezes, Paul C. van Oorschot, Scott A. Vanstone*:
	
	####Extended Euclidean algorithm. *(Ref: [MENE97], Algorithm 2.107)*####
	**INPUT:** Two non-negative integers a and b with a ≥ b.
	**OUTPUT:** d = gcd(a, b) and integers x and y satifying ax + by = d.
		
	**Algorithm:** 
	'''
		If b = 0 then set d = a, x = 1, y = 0, and return(d, x, y).
		Set x2 = 1, x1 = 0, y2 = 0, y1 = 1
		While b > 0, do
		q = floor(a/b), r = a - qb, x = x2 - qx1, y = y2 - q y1.
		a = b, b = r, x2 = x1, x1 = x, y2 = y1, y1 = y.
		Set d = a, x = x2, y = y2, and return(d, x, y).
	'''

**Input:** two integers X and N, being 2 <= X, N < 2ˆ32.
**Output:** two integers G (gcd) e I (inverse), such as I = X-1 mod N; if the inverse doesn't exist 
	it is written the letter "N".

To compile: ' gcc EEA.c -o EEA '