#ifndef GI_H
#define GI_H

// Curvilinear Operator Helpers

#include <armadillo>
#include "utils.h"

using namespace arma;

class Ginter
{

public:

    sp_mat GI_inter;
    void GI( u16 m, u16 n, u16 t);
    void GI( u16 m, u16 n, u16 o, u16 t);

private:


};

#endif // UTILS_H

