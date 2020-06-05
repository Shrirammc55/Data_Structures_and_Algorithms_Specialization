#include <iostream>

int get_change(int m) {
    int number_of_coins =0;
    while(m>0)
    {
        if(m>=10)
        {
            m=m-10;
            number_of_coins++;
        }            
        else if(m>=5)
        {
            m=m-5;
            number_of_coins++;
        }
        else
        {
            number_of_coins+=m;
            break;
        }
    }
    return number_of_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

