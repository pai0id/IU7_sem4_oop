#include <iostream>
#include <vector>
#include <list>
#include "list.h"

int main() {
    List<int> list1;
    std::cout << "List1: " << list1 << std::endl;
    std::cout << "Size of list1: " << list1.size() << std::endl;

    List<int> list2(list1);
    std::cout << "List2: " << list2 << std::endl;
    std::cout << "Size of list2: " << list2.size() << std::endl;

    List<int> list3(std::move(list2));
    std::cout << "List3: " << list3 << std::endl;
    std::cout << "Size of list3: " << list3.size() << std::endl;

    List<int> list4(5);
    std::cout << "List4: " << list4 << std::endl;
    std::cout << "Size of list4: " << list4.size() << std::endl;

    List<int> list5(3, 10);
    std::cout << "List5: " << list5 << std::endl;
    std::cout << "Size of list5: " << list5.size() << std::endl;

    List<int> list6({1, 2, 3});
    std::cout << "List6: " << list6 << std::endl;
    std::cout << "Size of list6: " << list6.size() << std::endl;

    std::vector<int> vec = {4, 5, 6};
    List<int> list7(vec);
    std::cout << "List7(from vec): " << list7 << std::endl;
    std::cout << "Size of list7: " << list7.size() << std::endl;

    std::list<int> list8 = {7, 8, 9};
    List<int> list9(list8.begin(), list8.end());
    std::cout << "List9(from list): " << list9 << std::endl;
    std::cout << "Size of list9: " << list9.size() << std::endl;

    List<int> listTmp = 1.2 + list9;
    std::cout << "Tmp: " << listTmp << std::endl;

    List<int> list10;
    list10 = list1;
    std::cout << "List10cpy: " << list10 << std::endl;
    std::cout << "Size of list10: " << list10.size() << std::endl;

    List<int> list11;
    list11 = std::move(list10);
    std::cout << "List11mv: " << list11 << std::endl;
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

    List<double> list12_float{1.1, 4.4, 7.7};
    std::cout << "List 12 float: " << list12_float << std::endl;
    std::cout << "List 12 float size: " << list12_float.size() << std::endl;

    List<int> list12_int = (List<int>)list12_float;
    std::cout << "List 12 int: " << list12_int << std::endl;
    std::cout << "List 12 int size: " << list12_int.size() << std::endl;

    return 0;
}