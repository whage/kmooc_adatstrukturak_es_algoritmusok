#include <iostream>

#include "5.hpp"

int main() {
    const int size = 10;
    int numbers[size];

    std::cout << "enter " << size << " numbers!\n";

    for (int i = 0; i < size; i++) {
        std::cout << "#" << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    int prime_count = 0;

    for (int i = 0; i < size; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    std::cout << "found " << prime_count << " prime numbers";
}
