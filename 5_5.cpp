#include <iostream>
#include <cmath>

int number_of_digits(int num)
{
    if (num == 0) {
        return 1;
    }

    int count = 0;
    
    while (num) {
        num /= 10;
        count++;
    }

    return count;
}

// Végtelen ciklusba fog kerülni a végrehajtás, mert ilyen számok nem léteznek.
// (Ezt csak az után vettem észre, hogy megírtam a programot)
//
// Bizonyítás:
// Legyen C = i * a + i, ahol a = pow(10, i_szamjegyeinek_szama).
// Mivel a fenti kifejezésben a > i, C mindig nagyobb lesz, mint i * i.
int main() {
    int found = 0;

    for (int i = 1; found < 1 ; i++) {
        int combined = i * std::pow(10, number_of_digits(i)) + i;
        
        if (i * i == combined) {
            std::cout << i;
            found++;
        }
    }
}
