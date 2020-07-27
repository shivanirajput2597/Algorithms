#include<iostream>
using namespace std;

#define ll long long

//NAIVE Approach O(sqrt(N))


//Sieve Approach - Generate a array containing prime numbers
void prime_sieve(int *p , int n)
{
	//first mark all odd number's prime
	for(int i = 3; i <= n ; i+=2 )
	{
		p[i] = 1;
	}
	
	//Sieve
	for(ll i = 3 ; i <= n ; i+=2)
	{
		//if the current number is not marked (it is prime)
		if(p[i] == 1)
		{
			//mark all the multiples of i as not prime
			for(ll j = i*i ; j <= n ; j = j+i)
			{
				p[j] = 0;
			}
		}
	}
	//special case
	p[2] = 1;
	p[1] = p[0] = 0;
	
	
}

int main()
{
	int n;
	cin>>n;
	
	int p[n] = {0};
	prime_sieve(p, n);
	
	for(int i = 0 ; i<= n ; i++)
	{
		if(p[i] == 1)
		{
			
				cout<< i <<" ";
			
		}
	}
	
	return 0;
}
	
