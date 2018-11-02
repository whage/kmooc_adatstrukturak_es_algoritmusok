#include <iostream>

typedef struct entry {
    int year;
    int month;
    double temp;
    struct entry* next;
} entry;

int main() {
    const int SIZE = 24;

    int year[SIZE]={2010, 2010, 2011, 2011, 2011, 2017, 2017, 2016, 2016, 2016, 2015, 2015, 2013,2013, 2012, 2011, 2015, 2016, 2017, 2011, 1013, 2014, 2015, 2016 };

    int month[SIZE]={1 , 2 , 1 , 2 , 3 , 7, 8, 2, 6, 7, 3, 5, 10, 11, 12, 5, 6, 10, 10,11, 12, 4, 11, 12 };

    double temp[SIZE]={-10.4,-2.8, -5.1,-2.1, 3.5 , 30.9, 35.7, -7.3, 20.3, 34.2, 6.2, 15.4,10.13, 1.56,-12.7,15.8, 16.2, 0.21, 9.9, 4.4, -3.3, 4.7, 0, 20.4 };

    struct entry* list; // = new ....

    for (int i = 0; i < SIZE; i++) {

    }
}
