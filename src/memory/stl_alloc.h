#ifdef __USE_MALLOC
typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<__NODE_ALLOCATOR_THREADS, 0> alloc;
#endif

template<class T, class Alloc>
class simple_alloc
{

};


template <int inst>
class __malloc_alloc_template
{

};

template<bool threads, int inst>
class __default_alloc_template
{

};