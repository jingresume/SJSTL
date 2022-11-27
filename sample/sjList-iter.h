#ifndef __SJ_LIST_ITER_H
#define __SJ_LIST_ITER_H

#include "sjList.h"
#include <iterator>

namespace sjstl
{

template <class Item>
class ListIter : public std::iterator<std::forward_iterator_tag, Item>
{
public:
    ListIter(Item* p = 0) : ptr(p)
    {}

    Item& operator*() const { return *ptr; }
    Item* operator->() const { return ptr; }

    //++i
    ListIter& operator++()
    {
        ptr = ptr->next();
        return *this;
    }

    //i++
    ListIter& operator++(int)
    {
        Item* tmp = ptr;
        ptr = ptr->next();
        return tmp;
    }

    bool operator==(const ListIter& i) const
    {
        return ptr == i.ptr;
    }

    bool operator!=(const ListIter& i) const
    {
        return ptr != i.ptr;
    }

private:
    Item* ptr;
};

}// namespace sjstl
#endif