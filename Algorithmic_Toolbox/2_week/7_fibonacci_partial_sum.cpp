#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
    long long from, to;
    std::cin >> from >> to;
    if(from==0 && to==0)
        std::cout <<0<< '\n';        
    else if(from==to)
        std::cout <<get_fibonacci_huge(to, 10)+1<< '\n';
    else
        {
            long long from_sum =get_fibonacci_huge(from+1, 10);
            long long to_sum =  get_fibonacci_huge(to+2, 10);
            //std::cout<<"from_sum = "<<from_sum<<std::endl;
            //std::cout<<"to_sum = "<<to_sum<<std::endl;
            if(to_sum-from_sum < 0)
                std::cout<<(to_sum-from_sum+10)<<std::endl;
            else
                std::cout<<(to_sum-from_sum)<<std::endl;
            //std::cout<<get_fibonacci_huge(to+2, 10)<<"\t"<<get_fibonacci_huge(from+2, 10)<<std::endl;
            //std::cout << get_fibonacci_huge(to+2, 10)-get_fibonacci_huge(from+2, 10) << '\n';
        }
}

