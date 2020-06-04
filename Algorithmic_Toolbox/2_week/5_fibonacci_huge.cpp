#include <iostream>
#include <vector>

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
	return f%m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}

