#include "nodal.h"

// 1-D Constructor
Nodal::Nodal(u16 k, u32 m, double dx) : sp_mat(m+1, m+1)
{
    assert(k == 2);
    assert(m >= 2*k);

    switch (k) {
        case 2:
            // A
            at(0, 0) = -1.5;
            at(0, 1) =  2.0;
            at(0, 2) = -0.5;
            // A'
            at(m, m)   =  1.5;
            at(m, m-1) = -2.0;
            at(m, m-2) =  0.5;
            // Middle
            for (u32 i = 1; i < m; i++) {
                at(i, i-1) = -0.5;
                at(i, i+1) =  0.5;
            }
            // Weights
            break;
        
    }

    // Scaling
    *this /= dx;
}

// 2-D Constructor
Nodal::Nodal(u16 k, u32 m, double dx,  u32 n, double dy)
{
    Nodal Nx( k, m, dx );
    Nodal Ny( k, n, dy );

    sp_mat Im = speye(m+1, m+1);
    sp_mat In = speye(n+1, n+1);

    sp_mat G1 = Utils::spkron(In, Nx);
    sp_mat G2 = Utils::spkron(Ny, Im);

    // Dimensions = 2*m*n+m+n, (m+2)*(n+2)
    if (m != n)
        *this = Utils::spjoin_cols(G1, G2);
    else {
        sp_mat A1(2, 1);
        sp_mat A2(2, 1);
        cout <<"A1 A2 done"<<endl;
        A1(0, 0) = A2(1, 0) = 1.0;
        cout <<"A1 A2 st to 1"<<endl;
        *this = Utils::spkron(A1, G1) + Utils::spkron(A2, G2);
        cout <<"Add spkrons"<<endl;

    }

}

// 3-D Constructor
Nodal::Nodal(u16 k, u32 m, double dx, u32 n, double dy, u32 o, double dz)
{
    Nodal Nx(k, m, dx);
    Nodal Ny(k, n, dy);
    Nodal Nz(k, o, dz);

    sp_mat Im = speye(m+1, m+1);
    sp_mat In = speye(n+1, n+1);
    sp_mat Io = speye(o+1, o+1);

    sp_mat G1 = Utils::spkron(Utils::spkron(Io, In), Nx);
    sp_mat G2 = Utils::spkron(Utils::spkron(Io, Ny), Im);
    sp_mat G3 = Utils::spkron(Utils::spkron(Nz, In), Im);

    // Dimensions = 3*m*n*o+m*n+m*o+n*o, (m+2)*(n+2)*(o+2)
    if ((m != n) || (n != o))
        *this = Utils::spjoin_cols(Utils::spjoin_cols(G1, G2), G3);
    else {
        sp_mat A1(3, 1);
        sp_mat A2(3, 1);
        sp_mat A3(3, 1);
        A1(0, 0) = A2(1, 0) = A3(2, 0) = 1.0;
        *this = Utils::spkron(A1, G1) + Utils::spkron(A2, G2) + Utils::spkron(A3, G3);
    }
}
