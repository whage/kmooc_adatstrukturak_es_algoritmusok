#include <iostream>

int sum_recursive(int num, int acc) { 
    if (num == 0) {
        return acc;
    }

    int digit = num % 10;

    return sum_recursive(num / 10, acc + digit);
}

int main() {
    int num;

    std::cout << "enter number: ";
    std::cin >> num;

    std::cout << "sum is: " << sum_recursive(num, 0) << "\n";
}
