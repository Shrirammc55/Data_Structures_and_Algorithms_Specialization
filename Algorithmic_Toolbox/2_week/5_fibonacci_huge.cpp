#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

bool sequence_check(long long fib[], long long index)
{
	for(int i=0;i<index;i++)
	{
		std::cout<<"i = "<<i<<std::endl;
		std::cout<<"index  = "<<index<<std::endl;
		if(fib[i]!=fib[i+index])
			return false;			
	}
	std::cout<<std::endl;
	return true;
}
long long find_sequence(long long n, long long m) {
    // write your code here
    long long *fib = new long long[n+1];	
    long long *fib_mod = new long long[n+1];
    long long even_counter = 3;
    fib[0]=0; fib[1]=1; 	
    fib_mod[0]=0; fib_mod[1]=1;
    for(int i=2;i<=n;i++)
    {
		fib[i]=fib[i-1]+fib[i-2];
		fib_mod[i]=fib[i]%m;
   		if(even_counter==i)
		{
        	if(sequence_check(fib_mod,(even_counter+1)/2))
				return (n%((even_counter+1)/2));
	    	even_counter+=2;
		}
    }
    return 0;
}

long long get_fibonacci_huge(long long n, long long m)
{
	long long sequence = find_sequence(n,m);
	if(sequence==0)
	{
		std::cout<<"Sequence not found"<<std::endl;	
		return 0;
	}
	while(sequence<m && m!=1)
	{
		sequence = find_sequence(sequence,m);	
	}
	
    int *fib = new int[sequence+1];
    fib[0]=0; fib[1]=1;
    for(int i=2;i<=sequence;i++)
		fib[i]=fib[i-1]+fib[i-2];
    return fib[sequence]%m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}

