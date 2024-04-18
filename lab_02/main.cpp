#include <iostream>
#include <vector>
#include <list>
#include "list.h"

int main() {
    List<int> list1;
    std::cout << "Size of list1: " << list1.size() << std::endl;

    List<int> list2(list1);
    std::cout << "Size of list2: " << list2.size() << std::endl;

    List<int> list3(std::move(list2));
    std::cout << "Size of list3: " << list3.size() << std::endl;

    List<int> list4(5);
    std::cout << "Size of list4: " << list4.size() << std::endl;

    List<int> list5(3, 10);
    std::cout << "Size of list5: " << list5.size() << std::endl;

    List<int> list6({1, 2, 3});
    std::cout << "Size of list6: " << list6.size() << std::endl;

    std::vector<int> vec = {4, 5, 6};
    List<int> list7(vec);
    std::cout << "Size of list7: " << list7.size() << std::endl;

    std::list<int> list8 = {7, 8, 9};
    List<int> list9(list8.begin(), list8.end());
    std::cout << "Size of list9: " << list9.size() << std::endl;

    List<int> list10;
    list10 = list1;
    std::cout << "Size of list10: " << list10.size() << std::endl;

    List<int> list11;
    list11 = std::move(list10);
    std::cout << "Size of list11: " << list11.size() << std::endl;

    list11.pushFront(0);
    std::cout << "Size of list11 after pushFront: " << list11.size() << std::endl;

    list11.popFront();
    std::cout << "Size of list11 after popFront: " << list11.size() << std::endl;

    list11.pushBack(10);
    std::cout << "Size of list11 after pushBack: " << list11.size() << std::endl;

    list11.popBack();
    std::cout << "Size of list11 after popBack: " << list11.size() << std::endl;

    list11.insert(list11.cbegin(), 5);
    std::cout << "Size of list11 after insert: " << list11.size() << std::endl;

    list11.reverse();
    std::cout << "Is list11 reversed? " << (list11.begin() == list11.getBack() ? "Yes" : "No") << std::endl;

    list11.clear();
    std::cout << "Is list11 empty? " << (list11.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}