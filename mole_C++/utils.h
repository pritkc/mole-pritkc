#ifndef UTILS_H
#define UTILS_H

#include <armadillo>
#include <assert.h>     /* assert */

using namespace arma;

class Utils
{

public:
    static sp_mat spkron(const sp_mat &A, const sp_mat &B);
    static sp_mat spjoin_rows(const sp_mat &A, const sp_mat &B);
    static sp_mat spjoin_cols(const sp_mat &A, const sp_mat &B);
    static vec spsolve_eigen(const sp_mat &A, const vec &b);
    // 2D MeshGrid
    void meshgrid( const vec &x, const vec &y, mat &X, mat &Y);
    // 3D Meshgrid
    void meshgrid( const vec &x, const vec &y, const vec &z, cube &X, cube &Y, cube &Z);
};

#endif // UTILS_H
