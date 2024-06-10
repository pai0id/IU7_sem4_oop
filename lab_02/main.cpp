#include <iostream>
#include <vector>
#include <list>
#include "list.h"
#include <ranges>

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

    List<int> list2_1;
    list2_1 = List<int>({1, 2, 3});
    std::cout << "List2: " << list2_1 << std::endl;
    std::cout << "Size of list2: " << list2_1.size() << std::endl;

    List<int> list1_1;
    list1_1 = list2_1;
    std::cout << "List1: " << list1_1 << std::endl;
    std::cout << "Size of list1: " << list1_1.size() << std::endl;

    list1_1 = {9.0, 8.1, 7.2};
    std::cout << "List1: " << list1_1 << std::endl;
    std::cout << "Size of list1: " << list1_1.size() << std::endl;

    List<int> list5(3, 10);
    std::cout << "List5: " << list5 << std::endl;
    std::cout << "Size of list5: " << list5.size() << std::endl;

    List<int> list6({1, 2, 3});
    std::cout << "List6: " << list6 << std::endl;
    std::cout << "Size of list6: " << list6.size() << std::endl;

    list6.pushFront(List<int>({6, 6}));
    std::cout << "List6: " << list6 << std::endl;

    list6.pushFront(List<double>({8.1, 7.2}));
    std::cout << "List6: " << list6 << std::endl;

    list6.pushFront(std::vector({8.1, 7.2}));
    std::cout << "List6: " << list6 << std::endl;

    list6.pushBack(List<int>({6, 6}));
    std::cout << "List6: " << list6 << std::endl;

    list6.pushBack(List<double>({8.1, 7.2}));
    std::cout << "List6: " << list6 << std::endl;

    list6.pushBack(std::vector({8.1, 7.2}));
    std::cout << "List6: " << list6 << std::endl;

    auto pos = ++(list6.begin());

    list6.insert(pos, List<int>({0, 0}));
    std::cout << "List6: " << list6 << std::endl;

    list6.insert(pos, List<double>({-1.1, -1.2}));
    std::cout << "List6: " << list6 << std::endl;

    list6.insert(pos, std::vector({-8.1, -7.2}));
    std::cout << "List6: " << list6 << std::endl;

    std::vector<int> vec = {4, 5, 6};
    List<int> list7(vec);
    std::cout << "List7(from vec): " << list7 << std::endl;
    std::cout << "Size of list7: " << list7.size() << std::endl;

    List<int> list8({7, 8, 9});
    List<int> list9(++list8.begin(), list8.end());
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

    list11.insert(list11.begin(), 5);
    std::cout << "Size of list11 after insert: " << list11.size() << std::endl;

    list11.insert(list11.begin(), list8);
    std::cout << "List11: " << list11 << std::endl;
    std::cout << "Size of list11 after insert: " << list11.size() << std::endl;

    list11.clear();
    std::cout << "Is list11 empty? " << (list11.isEmpty() ? "Yes" : "No") << std::endl;

    List<double> list12_float{1.1, 4.4, 7.7};
    std::cout << "List 12 float: " << list12_float << std::endl;
    std::cout << "List 12 float size: " << list12_float.size() << std::endl;

    List<int> list12_int = (List<int>)list12_float;
    std::cout << "List 12 int: " << list12_int << std::endl;
    std::cout << "List 12 int size: " << list12_int.size() << std::endl;

    List<int> list13  =  {4,  3,  5,  -2,  7};
    static_assert(std::ranges::range<List<int>>);
    std::for_each(list13.cbegin(), list13.cend(), [](const auto& elem) {std::cout << elem << std::endl;});

    return 0;
}