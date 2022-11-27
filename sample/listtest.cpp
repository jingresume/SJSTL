#include "sjList-iter.h"
#include "sjList.h"
#include <algorithm>

int main()
{
    sjstl::List<int> myList;
    
    for (int i = 0; i < 5; ++i)
    {
        myList.insert_front(i);
        myList.insert_end(i+2);
    }

    std::cout << "insert test sucess" << std::endl;
    myList.display();

    sjstl::ListIter<sjstl::ListItem<int> > begin(myList.front());
    sjstl::ListIter<sjstl::ListItem<int> > end;
    sjstl::ListIter<sjstl::ListItem<int> > iter;

    iter = std::find(begin, end, 3);
    if (iter == end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found. " << iter->value() << std::endl;

    iter = std::find(begin, end, 7);
    if (iter == end)
        std::cout << "not found " << 7 << std::endl;
    else
        std::cout << "found. " << iter->value() << std::endl;
    
    return 0;
}