#ifndef __SJ_LIST_H
#define __SJ_LIST_H

#include <iostream>

namespace sjstl
{

template <typename T>
class ListItem
{
public:
    ListItem(T v, ListItem* n) : _value(v), _next(n)
    {}
public:
    T value() const { return _value; }
    ListItem* next() const { return _next; }
    void setNext(ListItem* const n) { _next = n; }
    //...
    bool operator== (const T rhs) const
    {
        return _value == rhs;
    }

    bool operator!= (const T rhs) const
    {
        return _value != rhs;
    }
private:
    T _value;
    ListItem* _next;
};

template <typename T>
class List
{
public:
    List() : _front(nullptr), _end(nullptr)
    {}
    ~List();

public:
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream &os = std::cout) const;
    ListItem<T>* front() const 
    {
        return _front;
    }
    //...
private:
    ListItem<T>* _end;
    ListItem<T>* _front;
    long _size;
};

template <typename T>
List<T>::~List()
{
    ListItem<T>* node = _front;
    while(node != nullptr)
    {
        ListItem<T>* tmp = node->next();
        delete node;
        node = tmp;
    }
}

template <typename T>
void List<T>::insert_front(T value)
{
    ListItem<T>* nf = new ListItem<T>(value, _front);
    if (_end == nullptr) _end = nf;
    _front = nf;
}

template <typename T>
void List<T>::insert_end(T value)
{
    ListItem<T>* ne = new ListItem<T>(value, nullptr);
    if (_end)
    {
        _end->setNext(ne); 
    }
    else if (_front == nullptr)
    {
        _front = ne;
    }
    _end = ne;
}

template <typename T>
void List<T>::display(std::ostream &os) const
{
    os << "List : ";
    ListItem<T>* node = _front;
    while(node != nullptr)
    {
        os << node->value();
        os << " -> ";
        node = node->next();
    }
    os << "end" << std::endl;
}

} // namespace sjstl
#endif