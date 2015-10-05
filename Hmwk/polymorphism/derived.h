#ifndef DERIVED_H
#define DERIVED_H
#include "base.h"


class Derived: public Base
{
private:
    Derived();

public:


    Derived(int rows, int cols);
};

#endif // DERIVED_H
