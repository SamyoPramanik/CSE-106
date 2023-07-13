#include"2105154_1_ll_queue.h"
template< typename x> class queue2{
LL< x > linkq;
public:
void enqueue(x item)
{
    linkq.moveToEnd();
    linkq.insert(item);
}
void show()
{
    linkq.show();
}
x dequeue()
{
    linkq.moveToStart();
    return linkq.remove();
}
int length()
{
    return linkq.length();
}
x front()
{
    linkq.moveToStart();
    return linkq.getValue();
}
x back()
{
    linkq.moveToEnd();
    linkq.prev();
    return linkq.getValue();
}
bool isempty()
{
    if(linkq.length()==0){
        return 1;
    }
    return 0;
}
void clear()
{
   linkq.clear();
}
};
