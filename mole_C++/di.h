#ifndef DI_H
#define DI_H

// Curvilinear Operator Helpers

#include <armadillo>

using namespace arma;

class Dinter
{

public:

    sp_mat DI_inter;
    void DI( const u16 m, const u16 n, const u16 t);
    void DI( const u16 m, const u16 n, const u16 o, const u16 t);

private:

};

#endif // DI_H
