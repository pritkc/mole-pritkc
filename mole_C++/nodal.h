#ifndef NODAL_H
#define NODAL_H

#include "mole.h"
#include <math.h>   
#include <armadillo>

class Nodal : public sp_mat
{

public:
    using sp_mat::operator=;

    // 1-D Constructor
    Nodal(u16 k, u32 m, double dx);
    // 2-D Constructor
    Nodal(u16 k, u32 m, double dx, u32 n, double dy);
    // 3-D Constructor
    Nodal(u16 k, u32 m, double dx,u32 n, double dy, u32 o,  double dz);

private:

};

#endif // NODAL_H
