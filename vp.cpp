#include <iostream>
#include <cstdlib>

typedef struct entry {
    int year;
    int month;
    double temp;
    struct entry* next;
} entry;

void print_list(entry *list) {
    entry *p = list;

    while (p != NULL) {
        std::cout << p->year << "." << p->month << ": " << p->temp << "\n";
        p = p->next;
    }
}

void filter_by_year(entry *list, int year) {
    entry *p = list;

    do {
        if (p->year == year) {
            std::cout << p->year << "." << p->month << ": " << p->temp << "\n";
        }
        p = p->next;
    } while (p->next != NULL);
}

entry *delete_by_year(entry *list, int year) {
    entry *p = list;
    entry *head = list;
    entry *prev = NULL;

    while (p != NULL) {
        if (p->year == year) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                head = p->next;
            }
        } else {
            prev = p;
        }

        p = p->next;
    }

    return head;
}

entry *reverse(entry *list) {
    entry *prev = NULL;
    entry *next = NULL;
    entry *current = list;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list = prev;

    return list;
}

int main() {
    const int SIZE = 24;

    int year[SIZE]={2010, 2010, 2011, 2011, 2011, 2017, 2017, 2016, 2016, 2016, 2015, 2015, 2013,2013, 2012, 2011, 2015, 2016, 2017, 2011, 1013, 2014, 2015, 2016 };

    int month[SIZE]={1 , 2 , 1 , 2 , 3 , 7, 8, 2, 6, 7, 3, 5, 10, 11, 12, 5, 6, 10, 10,11, 12, 4, 11, 12 };

    double temp[SIZE]={-10.4,-2.8, -5.1,-2.1, 3.5 , 30.9, 35.7, -7.3, 20.3, 34.2, 6.2, 15.4,10.13, 1.56,-12.7,15.8, 16.2, 0.21, 9.9, 4.4, -3.3, 4.7, 0, 20.4 };

    // create list head pointer and allocate space
    entry *list_head = new entry;

    // initialize first entry
    list_head->year  = year[0];
    list_head->month = month[0];
    list_head->temp  = temp[0];

    // initialize walker pointer
    entry *walker = list_head;
    entry *previous = NULL;

    // create and insert new entries
    for (int i = 1; i < SIZE; i++) {
        entry *new_entry = new entry;
        
        new_entry->year  = year[i];
        new_entry->month = month[i];
        new_entry->temp  = temp[i];

        while (walker->next != NULL && walker->year <= new_entry->year) {
            previous = walker;
            walker = walker->next;
        }

        if (new_entry->year > walker->year) {
            walker->next = new_entry;
        } else {
            if (previous != NULL) {
                new_entry->next = previous->next;
                previous->next = new_entry;
            } else {
                new_entry->next = list_head;
                list_head = new_entry;
            }
        }


        // reset
        walker = list_head;
        previous = NULL;
    }

    print_list(list_head);

    int year_filter;

    std::cout << "filter by which year: ";
    std::cin >> year_filter;
    
    // test filtering
    filter_by_year(list_head, year_filter);

    // test reverse listing
    list_head = reverse(list_head);
    std::cout << "in reverse order:\n";
    print_list(list_head);

    // test removing entries with given date
    int year_to_delete;
    std::cout << "delete which years: ";
    std::cin >> year_to_delete;

    list_head = delete_by_year(list_head, year_to_delete);
    print_list(list_head);
}
