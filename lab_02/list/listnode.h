/*Класс узла*/
#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include <memory>

template <typename T>
class ListNode
{
private:
    T data;
    std::shared_ptr<ListNode<T>> next;
public:
    ListNode();
    explicit ListNode(const T dataToAdd);
    explicit ListNode(const std::shared_ptr<ListNode<T>> node);
    ListNode(const T data, const std::shared_ptr<ListNode<T>> nextNode);
    virtual ~ListNode();

    void setData(const T data);
    T getData() const;
    T& getPtrData();

    void setNext(const std::shared_ptr<ListNode<T>> nextNode);
    std::shared_ptr<ListNode<T>> getNext();

    bool operator==(const ListNode<T>& secondNode) const;
    bool operator!=(const ListNode<T>& secondNode) const;
    bool operator>(const ListNode<T>& secondNode) const;
    bool operator<(const ListNode<T>& secondNode) const;
    bool operator>=(const ListNode<T>& secondNode) const;
    bool operator<=(const ListNode<T>& secondNode) const;
};

#endif
