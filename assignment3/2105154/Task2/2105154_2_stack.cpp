#include"2105154_2_stack.h"
template< typename x> class stack{
    queue2<x> q;
       public:
       void clear()
       {
        q.clear();
       }
       void push(x item){
        q.enqueue(item);
       }
       void show()
       {
        q.show();
       }
       int length()
       {
        return q.length();
       }
       x topvalue()
       {
        return q.back();
       }
       bool isempty()
       {
        return q.isempty();
       }
       x pop()
       {
        x item=q.back();
           int l=q.length();
           int i=1;
           queue2< x > qu;
           while(i++<l)
           {
               qu.enqueue(q.dequeue());
           } 
           q.clear();
           i=1;
           while(i++<l)
           {
            q.enqueue(qu.dequeue());
           }
        return item;
       }
};
