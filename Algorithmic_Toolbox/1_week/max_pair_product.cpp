#include <iostream>
#include <vector>
#include <algorithm>

long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long int max_product = 0;
    long long max_1=0, max_2=0;
    int n = numbers.size();
    int count =0;
    for (int first = 0; first < n; ++first) {
    	if(numbers[first]>max_1)
		max_1 = numbers[first];
    }
    //std::cout<<"Max_1 = "<<max_1<<std::endl;
    for (int first = 0; first < n; ++first) {
	if(numbers[first]==max_1 && count==0)
		count=1;
    	else if(numbers[first]>max_2 && (count==1||numbers[first]!=max_1))
		max_2 = numbers[first];
    }  
    //std::cout<<"Max_2 = "<<max_2<<std::endl;
    return max_1*max_2;

}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}

