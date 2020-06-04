#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long find_sequence(long long n, long long m) {
	long long  f_0 = 0, f_1 =1, f = f_0+f_1;
    for(int i=0;i<m*m;i++)
    {
    	f = (f_1+f_0)%m;
    	f_0 = f_1;
    	f_1 = f;
    	if(f_0==0 && f_1==1)
    	{
    		// std::cout<<"i = "<<i-1<<std::endl;
    		return i+1;
    	}
    }
}

long long get_fibonacci_huge(long long n, long long m)
{	
	long long rem = n%find_sequence(n,m);
	long long f_0 = 0, f_1 = 1, f = rem;
	for(int i=1;i<rem;i++)
	{
		f = (f_1+f_0)%m;
    	f_0 = f_1;
    	f_1 = f;
	}
    if((f%m)==0)
        return 9;
    else
	    return (f%m)-1;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << get_fibonacci_huge(n+2,10);
}

