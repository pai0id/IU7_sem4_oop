#include <iostream>
#include <vector>
#include "list.hpp"
#include "listnode.hpp"
#include "listiterator.hpp"
#include "errors.h"

using namespace std;

void test_constructors() {
    cout << "Testing Constructors" << endl;
    try {
        List<int> list0;
        List<double> list1({3, 0.1, 0.2, 0.4});
        List<int> list2({3, 8, 21});
        List<int> list3(list2);

        std::vector<int> vect_list4{10, 20, 30};
        List<int> list4(vect_list4.begin(), vect_list4.end());
        cout << list4 << endl;

        int arr[] = {1, 2, 3, 4, 5};
        List<int> list5(arr, 5); // arr, size
        cout << list5 << endl;

        cout << "Default constructor" << endl;
        cout << list0 << endl;

        cout << "Constructor with parameters" << endl;
        cout << list1 << endl;
        cout << list2 << endl;
        cout << list3 << endl;

        cout << "Copying constructor" << endl;
        list0 = list3;
        cout << list0 << endl;
    } catch (ListErrorBase& error) {
        cout << error.what() << endl;
    }
}

void test_addition() {
    cout << "Testing Elements Addition" << endl;
    try {
        List<int> list0;
        cout << "append(data)" << endl;
        cout << list0 << endl;

        list0.append(1);
        cout << list0 << endl;

        list0.append(2);
        cout << list0 << endl;

        List<int> list1({5, 7});
        cout << "\ninsert(data, iter)" << endl;
        cout << list1 << endl;

        Iterator<int> iter0(list1.begin());
        list1.insert(1, iter0);
        cout << list1 << endl;

        Iterator<int> iter2(list1.end());
        list1.insert(3, iter2);
        cout << list1 << endl;
        list1.insert(4, iter2);
        cout << list1 << endl;

        List<int> list2;
        cout << "\nextend(list)" << endl;
        cout << list2 << endl; // empty

        list2.extend(list2);
        cout << list2 << endl; // empty

        list2.extend(list0);
        cout << list2 << endl; // = list0 = 1 2

        list2.extend(list2);
        cout << list2 << endl;

        list2.extend(list1); // list1 = 1 5 3 4 7
        cout << list2 << endl;
    } catch (ListErrorBase& error) {
        cout << error.what() << endl;
    }
}

void test_removal() {
    cout << "Testing Elements Removal" << endl;
    try {
        List<int> list0({1, 2, 3, 4, 5, 78});

        cout << "remove(iter)" << endl;
        Iterator<int> iter0(list0.begin());
        cout << list0 << endl;

        list0.remove(iter0);
        cout << list0 << endl;

        Iterator<int> iter1(list0.begin());
        iter1++;
        list0.remove(iter1);
        cout << list0 << endl;

        cout << "\npop()" << endl;
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        list0.pop();
        cout << list0 << endl;

        cout << "\nclear()" << endl;
        List<int> list1({1, 2, 3, 4, 5, 78});
        cout << list1 << endl;

        list1.clear();
        cout << list1 << endl;
    } catch (ListErrorBase& error) {
        cout << error.what() << endl;
    }
}

void test_other() {
    cout << "Testing Other Operations" << endl;
    try {
        List<int> list0({1, 2, 3, 4});
        List<int> list1({5, 1, 5});
        List<int> list2({5, 1, 5});

        cout << "Starter Lists" << endl;
        cout << list0 << endl;
        cout << list1 << endl;
        cout << list2 << endl;

        cout << "\nsize()" << endl;
        cout << list0.size() << endl;
        cout << list1.size() << endl;

        cout << "\noperators" << endl;
        if (list0 != list1)       
            cout << "list0 not equal list1" << endl;
        if (list0.isNotEqual(list1))
            cout << "list0 not equal list1" << endl;
        if (list1.isEqual(list2))
            cout << "list0 is equal list2" << endl;

        list0 += list1;
        cout << list0 << endl;
        list0 += 15;
        cout << list0 << endl;

        cout << "size()" << endl;
        cout << list0.size() << endl;
        cout << list1.size() << endl;
    } catch (ListErrorBase& error) {
        cout << error.what() << endl;
    }
}

int main() {
    cout << "Running List Tests" << endl;
    test_constructors();
    test_addition();
    test_removal();
    test_other();

    cout << "All tests completed successfully." << endl;
    return 0;
}
