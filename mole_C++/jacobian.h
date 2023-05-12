#ifndef JACOBIAN_H
#define JACOBIAN_H

// Curvilinear Operator Helpers

#include <armadillo>
#include "utils.h"
#include "nodal.h"

using namespace arma;

class Jac
{

public:

    vec Jacob;

    vec Xe; vec Xn; vec Xc;
    vec Ye; vec Yn; vec Yc;
    vec Ze; vec Zn; vec Zc;

    // 2-D Jacobian Constructor
    void Jacobian(const u16 k, const mat &Xin, const mat &Yin);
    // 3-D Jacobian Constructor
    void Jacobian(const u16 k, const cube &Xin, const cube&Yin, const cube &Zin);

private:

    mat Dx;
    mat Dy;
    mat Dz;

};

#endif // Jacobian_H