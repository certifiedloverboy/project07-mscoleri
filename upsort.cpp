#include <iostream>
#include <chrono>
#include <cstring>
#include "SinglyLinkedList.h"

using namespace std;

/**************************************************
               Note from Professors:

- Do not change the functions already provided
- Implement the upsort_with_list function
  and any helper functions you wish.

***************************************************/

/**
 * Sort the given linked list using only the methods from the list interface:
 * size, get, set, add, and remove.
 * @param list_to_sort the linked list to sort with upsort.
 */
void upsort_with_list(SinglyLinkedList &list_to_sort) {
    int current_data = 0;
    int temp = 0;
    int value = 0;
    // int notion = 0;
    int previous_data = 0;
    size_t size = list_to_sort.size();
    //list_to_sort.write(cout);
    //
    // for (int i = 0; i < size - 1; i++) {
    //     current_data = list_to_sort.get(i);
    //     //cout << current_data << '\n';
    //     next_data = list_to_sort.get(i + 1);
    //     //notion = 0;
    //     if (current_data > next_data && i < size) {
    //         int temp = current_data;
    //
    //         list_to_sort.set(i, 1);
    //         list_to_sort.set(i + 1, 2);
    //         notion++;
    //         //current_data = list_to_sort.get(i + notion);
    //         //next_data = list_to_sort.get(i + notion + 1);
    //
    //     }
    //     //list_to_sort.write(cout);
    // }
    // current_data = list_to_sort.get(value);
    // next_data = list_to_sort.get(value + 1);
    // for (int i = size - 1; i > 0; i--) {
    //     current_data = list_to_sort.get(i);
    //     previous_data = list_to_sort.get(i - 1);
    //     //cout << "current: " << current_data << '\n';
    //     value = 0;
    //     while (current_data < previous_data) {
    //         cout << "triggered" << '\n';
    //         temp = current_data;
    //         list_to_sort.set(i - 1, previous_data);
    //         list_to_sort.set(i, temp);
    //         //value++;
    //         //previous_data = current_data;
    //         current_data = previous_data;
    //         previous_data = list_to_sort.get(i--);
    //     }
    // }
    
}


/**
 * Sort the given linked list using upsort_with_list,
 * print out the time it takes in milliseconds, and
 * output the sorted linked list.
 * @param list (a reference to) the linked list to sort.
 */
void time_upsort_with_list(SinglyLinkedList & list) {
    cout << "Only list interface methods:" << endl;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time =
        std::chrono::high_resolution_clock::now();

    // sort with only methods from the list interface
    list.write(cout);
    cout << '\n';
    upsort_with_list(list);

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time =
        std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> run_time = end_time - start_time;
    cout << "   Time to sort: "
         << chrono::duration_cast<chrono::milliseconds>(run_time).count()
         << " milliseconds" << endl;
    cout << "   After upsort: ";
    list.write(cout);
}

/**
 * Sort the given linked list using the custom_upsort method
 * print out the time it takes in milliseconds, and
 * output the sorted linked list.
 * @param list (a reference to) the linked list to sort.
 */
void time_upsort_with_custom(SinglyLinkedList & list) {
    cout << "Custom methods:" << endl;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time =
        std::chrono::high_resolution_clock::now();

    // sort with custom methods
    list.custom_upsort();

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time =
        std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> run_time = end_time - start_time;
    cout << "   Time to sort: "
         << chrono::duration_cast<chrono::milliseconds>(run_time).count()
         << " milliseconds" << endl;
    cout << "   After upsort: ";
    list.write(cout);
}

// Controls operation of program
int main(int argc, char ** argv) {
    SinglyLinkedList original_list;
    original_list.read(cin);

    SinglyLinkedList copied_list = original_list;
    const bool not_autograded = argc == 1;

    // This boolean is for autograder tests
    const bool list_only = argc == 2 and strcmp(argv[1], "list") == 0;
    if (not_autograded) {
        time_upsort_with_list(original_list);
        time_upsort_with_custom(copied_list);
    } else if (list_only) {
        time_upsort_with_list(original_list);
    } else {
        time_upsort_with_custom(copied_list);
    }
    return 0;
}
