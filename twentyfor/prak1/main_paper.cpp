#include "Paper.hpp"
int main()
{
    Paper *a = new Paper('A'); // ctor A
    Paper b('B');              // ctor B
    Paper c('C');              // ctor C
    Paper d = c;               // cctor C

    a->fold(); // fold A(1)
    b.fold();  // fold B(1)
    c.fold();  // fold C(1)

    c.glue(); // glue C and fold C(2)

    delete a;       // dtor A
    c.setName('X'); // setName C => X
    d.fold();       // fold C(1)
    d.glue();       // glue C and fold C(2)

    return 0;
}