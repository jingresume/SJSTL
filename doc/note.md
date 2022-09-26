+ place new
在已经申请好的内存块上构造对象。
```C++
#include <new.h>
new (p) T1(value);
```
表示在内存地址p上构造一个对象T1，并使用value来初始化这个对象。
***