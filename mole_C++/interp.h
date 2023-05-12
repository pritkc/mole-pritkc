#ifndef INTERP_H
#define INTERP_H

#include <cassert>
#include <math.h>   
#include "mole.h"
//#include <armadillo>

class Interpolator
{
public:
    // Interpolate from Centers to faces
    sp_mat Inter_CenterToFaces( u32 k, u32 m);
    sp_mat Inter_CenterToFaces( u32 k, u32 m, u32 n);
    sp_mat Inter_CenterToFaces( u32 k, u32 m, u32 n, u32 o);

    // Interpolate from Faces to Centers
    sp_mat Inter_FacesToCenters( u32 k, u32 m);
    sp_mat Inter_FacesToCenters( u32 k, u32 m, u32 n);
    sp_mat Inter_FacesToCenters( u32 k, u32 m, u32 n, u32 o);

    //Interpolate Nodes to centers
    sp_mat Inter_NodesToCenters( u32 k, u32 m);
    sp_mat Inter_NodesToCenters( u32 k, u32 m, u32 n);
    sp_mat Inter_NodesToCenters( u32 k, u32 m, u32 n, u32 o);

    // Interpolate Centers to Nodes
    sp_mat Inter_CentersToNodes( u32 k, u32 m);
    sp_mat Inter_CentersToNodes( u32 k, u32 m, u32 n);
    sp_mat Inter_CentersToNodes( u32 k, u32 m, u32 n, u32 o);

    // Interpolate Nodes to specific faces (Concatenation of interps)
    sp_mat Inter_NodeToU( u32 k, u32 m, u32 n );
    sp_mat Inter_NodeToU( u32 k, u32 m, u32 n, u32 o);
    sp_mat Inter_NodeToV( u32 k, u32 m, u32 n );
    sp_mat Inter_NodeToV( u32 k, u32 m, u32 n, u32 o);
    sp_mat Inter_NodeToW( u32 k, u32 m, u32 n, u32 o);
    
    sp_mat Inter_UtoNode( u32 k, u32 m, u32 n );
    sp_mat Inter_UtoNode( u32 k, u32 m, u32 n, u32 o);
    sp_mat Inter_VtoNode( u32 k, u32 m, u32 n );
    sp_mat Inter_VtoNode( u32 k, u32 m, u32 n, u32 o);
    sp_mat Inter_WtoNode( u32 k, u32 m, u32 n, u32 o);
    
};
#endif