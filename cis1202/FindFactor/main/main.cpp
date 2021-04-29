// Ashley Nixon Lane
// mostly a success... minor issues, and a little late for a work day... calling it a success because I learned however.
//Function that fills vector divisiors with all divisors of the natural number n


#include "pch.h"
#include <iostream>
#include <vector>
using namespace std; //probably bad practice, heard multiple voices on this... still seems in wide use though.

//const t& n - should get n of type T as a reference since it can be too large of an object to copy
//const because it won't be changed
//vector <T>& T divisors - should get vector as a reference for the same reason as the n. 
template <typename T>
void getDivisors(const T &n, vector<T>& divisors) {
	for (T i = 2; i * i <= n; ++i) {	//taking a look at ever number from 2 to sqrt(n).
										//NOTE: i * i == n and i == sqrt(n) are equal,
										//but it's more expensive to find square root that square of a number.
										//It's enough to look at every number up to sqrt(n)
										//k >= sqrt(n), if n = m * k, then m <= sqrt(n)
										//and all divisors >= sqrt(n) will be visited
										//since all numbers <= sqrt(n) will be checked.

		if (n % i == 0) {				//if i is divisor of the n,
			divisors.push_back(i);		//add i to the vector
			divisors.push_back(n / i);	//and n / i too.
		}
	}

	for (auto&& i : divisors) std:cout << i << " ";
}

//divisors found in the previous function can be prime and composite.
//composite divisors will be changed to zero here.
//get vector as a reference.
//don't return anything.....
template <typename T>
void annulComposite(vector<T>& divisors) {
	for (size_t l = 0; l < divisors.size(); ++l) {						//get every pair of divisors
		for (size_t r = 0; r < divisors.size(); ++r) {
			if (l == r) continue;										//if they are equal, skip
			if (divisors[l] != 0 && divisors[r] % divisors[l] == 0) {	//if divisor l != zero (it could become zero before, in previous iterations), 
				divisors[r] = 0;										//and if divisor r is divided by divisor l,
			}															//then divisor r is exactly composite and can be annulled.
		}																//the vector will contain all the prime divisors of the number n, and some zeros.
	}
}																		//vector contained ALL the divsors of some number n, prime and composite (without number 1 and n by itself)
																		//for every m - composite divisor of the n, - there is prime number p - divisor of the m,
																		//thus, p is divisor of n and p is in the vector provided.
																		//since prime numbers won't be annulled (because they haven't divisors except 1 and themselves),
																		//all composite divisors will be annuled (because it takes a look at every pair of numbers)



/*Function that for each prime number int he vector divisors provided finds its power
that this divisor is included in the factorization fo the number n with.
for example... if n=36, prime divisors are 2 and 3, their powers are 2 and 2 (36 = 2^2 * 3^2)
T& n - get n as a link (not const, because will change it woithout copying)
vector<T>& divisors - vector of prime divisors and zeros
vector<T>& powers - vector of zeros of such size as vector divisors.
*/
template<typename T>
void getPowers(T& n, vector<T>& divisors, vector<T>& powers) {
	for (size_t i = 0; i < divisors.size(); ++i) { //for every non-zero element in divisors
		T divisor = divisors[i];
		if (divisor == 0) {
			continue;
		}

		while (n % divisor == 0) {	//while it is possible, 
			n /= divisor;			//divide n by i
			++powers[i];			//and increment power of i
		}
	}
}

int main() {
	long long n = 77528432733029;			//number from the task... may have taken me a few tries to get it correct... oops
	vector<long long> divisors{};			//declare vector of all the divisors of the number n
	getDivisors<long long>(n, divisors);	//find divisors of the  number n
	annulComposite(divisors);				//in the vector to zero

	vector<long long> powers(divisors.size(), 0);	//declare a new vector for powers of divisors found
	getPowers(n, divisors, powers);					//fill in the last vector with corresponding values

	for (size_t i = 0; i < divisors.size(); ++i) {	//for every divisor m
		for (size_t j = 0; j < powers[i]; ++j) {	//take its power p
			cout << divisors[i] << " \n";				//and print number m p times
		}											//will be skipped for zero elements of vector divisors
	}												//because corresponding elements of vector powers will be zero

	return 0;
}


