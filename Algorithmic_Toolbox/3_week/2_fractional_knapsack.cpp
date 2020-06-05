#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    // write your code here
    double value = 0.0;
    vector<double> value_per_weight(weights.size());
    for(int i=0;i<weights.size();i++)
        value_per_weight[i]=values[i]/weights[i];
    auto vperw = value_per_weight;
    //std::cout<<"Before Sort"<<std::endl;
    //for(auto it:vperw)
    //    std::cout<<it<<"\t";
    //std::cout<<std::endl;
    std::sort(vperw.begin(), vperw.end(), std::greater<double>());
    //std::cout<<"After Sort"<<std::endl;
    //for(auto it:vperw)
    //    std::cout<<it<<"\t";
    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

