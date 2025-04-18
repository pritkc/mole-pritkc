MATLAB/Octave Function Index
=========================================

This page provides an index of all MATLAB/Octave functions in the MOLE library.

.. toctree::
   :maxdepth: 2

.. mermaid::

    classDiagram
        %% Main operator categories
        class DifferentialOperators {
            Gradient
            Divergence
            Laplacian
            Nodal
        }
        
        class InterpolationOperators {
            Interpol
            InterpolD
            NodesToCenters
            CentersToNodes
            CentersToFaces
            FacesToCenters
        }
        
        class BoundaryConditions {
            MixedBC
            RobinBC
            addBC
        }
        
        class GridTransformation {
            gridGen
            tfi
            ttm
            jacobian2D
            jacobian3D
        }
        
        class UtilityFunctions {
            weightsP/Q
            amean/hmean
            curl2D
            DI2/DI3
            GI1/GI2/GI13
            rk4
        }
        
        %% Function relationships
        DifferentialOperators -- InterpolationOperators : work with
        DifferentialOperators -- BoundaryConditions : enhanced by
        BoundaryConditions --> DifferentialOperators : use
        GridTransformation -- DifferentialOperators : support
        UtilityFunctions -- DifferentialOperators : support
        
        %% Dimensionality inheritance/extensions
        class Grad1D {
            grad(k,m,dx)
            gradNonUniform(k,m,dx,x)
        }
        
        class Grad2D {
            grad2D(k,m,n,dx,dy)
            grad2DCurv(...)
            grad2DNonUniform(...)
        }
        
        class Grad3D {
            grad3D(k,m,n,o,dx,dy,dz)
            grad3DCurv(...)
            grad3DNonUniform(...)
        }
        
        class Div1D {
            div(k,m,dx)
            divNonUniform(k,m,dx,x)
        }
        
        class Div2D {
            div2D(k,m,n,dx,dy)
            div2DCurv(...)
            div2DNonUniform(...)
        }
        
        class Div3D {
            div3D(k,m,n,o,dx,dy,dz)
            div3DCurv(...)
            div3DNonUniform(...)
        }
        
        class Lap1D {
            lap(k,m,dx)
        }
        
        class Lap2D {
            lap2D(k,m,n,dx,dy)
        }
        
        class Lap3D {
            lap3D(k,m,n,o,dx,dy,dz)
        }
        
        class BC1D {
            mixedBC(k,m,dx,...)
            robinBC(k,m,dx,...)
            addBC1D(...)
        }
        
        class BC2D {
            mixedBC2D(k,m,n,dx,dy,...)
            robinBC2D(k,m,n,dx,dy,...)
            addBC2D(...)
        }
        
        class BC3D {
            mixedBC3D(k,m,n,o,dx,dy,dz,...)
            robinBC3D(k,m,n,o,dx,dy,dz,...)
            addBC3D(...)
        }
        
        %% Operator relationships
        Lap1D --> Grad1D : uses
        Lap1D --> Div1D : uses
        Lap2D --> Grad2D : uses
        Lap2D --> Div2D : uses
        Lap3D --> Grad3D : uses
        Lap3D --> Div3D : uses
        
        BC1D --> Grad1D : uses
        BC2D --> Grad2D : uses
        BC3D --> Grad3D : uses

Gradient Operators
----------------------------

* :mat:func:`grad` - Returns a m+1 by m+2 one-dimensional mimetic gradient operator
* :mat:func:`grad2D` - Returns a two-dimensional mimetic gradient operator
* :mat:func:`grad2DCurv` - Returns a 2D curvilinear mimetic gradient
* :mat:func:`grad2DNonUniform` - Returns a two-dimensional non-uniform mimetic gradient
* :mat:func:`grad3D` - Returns a three-dimensional mimetic gradient operator
* :mat:func:`grad3DCurv` - Returns a 3D curvilinear mimetic gradient
* :mat:func:`grad3DNonUniform` - Returns a three-dimensional non-uniform mimetic gradient
* :mat:func:`gradNonUniform` - Returns a m+1 by m+2 one-dimensional non-uniform mimetic gradient

Divergence Operators
----------------------------

* :mat:func:`div` - Returns a m+2 by m+1 one-dimensional mimetic divergence operator
* :mat:func:`div2D` - Returns a two-dimensional mimetic divergence operator
* :mat:func:`div2DCurv` - Returns a 2D curvilinear mimetic divergence
* :mat:func:`div2DNonUniform` - Returns a two-dimensional non-uniform mimetic divergence
* :mat:func:`div3D` - Returns a three-dimensional mimetic divergence operator
* :mat:func:`div3DCurv` - Returns a 3D curvilinear mimetic divergence
* :mat:func:`div3DNonUniform` - Returns a three-dimensional non-uniform mimetic divergence
* :mat:func:`divNonUniform` - Returns a m+2 by m+1 one-dimensional non-uniform mimetic divergence

Laplacian Operators
----------------------------

* :mat:func:`lap` - Returns a m+2 by m+2 one-dimensional mimetic laplacian operator
* :mat:func:`lap2D` - Returns a two-dimensional mimetic laplacian operator
* :mat:func:`lap3D` - Returns a three-dimensional mimetic laplacian operator

Nodal Operators
----------------------------

* :mat:func:`nodal` - Returns a one-dimensional operator that approximates the first-order
* :mat:func:`nodal2D` - Returns a two-dimensional operator that approximates the first-order
* :mat:func:`nodal2DCurv` - Returns a 2D curvilinear nodal operator
* :mat:func:`nodal3D` - Returns a three-dimensional operator that approximates the first-order
* :mat:func:`nodal3DCurv` - Returns a 3D curvilinear nodal operator
* :mat:func:`sidedNodal` - Returns a one-dimensional nodal operator with one-sided stencils

Interpolation Functions
------------------------------------------------

* :mat:func:`interpol` - Returns a m+1 by m+2 one-dimensional interpolation operator
* :mat:func:`interpol2D` - Returns a two-dimensional interpolation operator
* :mat:func:`interpol3D` - Returns a three-dimensional interpolation operator
* :mat:func:`interpolD` - Returns a m+1 by m+2 one-dimensional interpolation operator
* :mat:func:`interpolD2D` - Returns a two-dimensional interpolation operator
* :mat:func:`interpolD3D` - Returns a three-dimensional interpolation operator
* :mat:func:`interpolCentersToFacesD1D` - Interpolates values from cell centers to faces
* :mat:func:`interpolCentersToFacesD2D` - Interpolates values from cell centers to faces
* :mat:func:`interpolCentersToFacesD3D` - Interpolates values from cell centers to faces
* :mat:func:`interpolCentersToNodes1D` - Interpolates values from cell centers to nodes
* :mat:func:`interpolCentersToNodes2D` - Interpolates values from cell centers to nodes
* :mat:func:`interpolCentersToNodes3D` - Interpolates values from cell centers to nodes
* :mat:func:`interpolFacesToCentersG1D` - Interpolates values from faces to cell centers
* :mat:func:`interpolFacesToCentersG2D` - Interpolates values from faces to cell centers
* :mat:func:`interpolFacesToCentersG3D` - Interpolates values from faces to cell centers
* :mat:func:`interpolNodesToCenters1D` - Interpolates values from nodes to cell centers
* :mat:func:`interpolNodesToCenters2D` - Interpolates values from nodes to cell centers
* :mat:func:`interpolNodesToCenters3D` - Interpolates values from nodes to cell centers

Boundary Conditions
----------------------------

* :mat:func:`addBC1D` - Apply boundary conditions to a 1D system
* :mat:func:`addBC1Dlhs` - Create left-hand side matrix for 1D boundary conditions
* :mat:func:`addBC1Drhs` - Create right-hand side vector for 1D boundary conditions
* :mat:func:`addBC2D` - Apply boundary conditions to a 2D system
* :mat:func:`addBC2Dlhs` - Create left-hand side matrix for 2D boundary conditions
* :mat:func:`addBC2Drhs` - Create right-hand side vector for 2D boundary conditions
* :mat:func:`addBC3D` - Apply boundary conditions to a 3D system
* :mat:func:`addBC3Dlhs` - Create left-hand side matrix for 3D boundary conditions
* :mat:func:`addBC3Drhs` - Create right-hand side vector for 3D boundary conditions
* :mat:func:`boundaryIdx2D` - Get boundary indices for a 2D domain
* :mat:func:`mixedBC` - Constructs a 1D mimetic mixed boundary conditions operator
* :mat:func:`mixedBC2D` - Constructs a 2D mimetic mixed boundary conditions operator
* :mat:func:`mixedBC3D` - Constructs a 3D mimetic mixed boundary conditions operator
* :mat:func:`neumann2DCurv` - Returns a 2D curvilinear Neumann BC operator
* :mat:func:`neumann3DCurv` - Returns a 3D curvilinear Neumann BC operator
* :mat:func:`robinBC` - Returns a m+2 by m+2 one-dimensional mimetic boundary operator that
* :mat:func:`robinBC2D` - Returns a two-dimensional mimetic boundary operator that implements
* :mat:func:`robinBC3D` - Returns a three-dimensional mimetic boundary operator that

Grid and Transformation Functions
--------------------------------------------------------

* :mat:func:`gridGen` - Generate a grid using transfinite interpolation
* :mat:func:`tfi` - Transfinite interpolation for grid generation
* :mat:func:`ttm` - Tensor-product transfinite mapping
* :mat:func:`jacobian2D` - Calculate the Jacobian matrix for 2D grid transformations
* :mat:func:`jacobian3D` - Calculate the Jacobian matrix for 3D grid transformations

Utility Functions
----------------------------

* :mat:func:`amean` - Returns the arithmetic mean for every two pairs in a column vector
* :mat:func:`hmean` - Returns the harmonic mean for every two pairs in a column vector
* :mat:func:`weightsP` - Returns the m+1 weights of P
* :mat:func:`weightsP2D` - Returns the two-dimensional weights of P
* :mat:func:`weightsQ` - Returns the m+2 weights of Q
* :mat:func:`weightsQ2D` - Returns the two-dimensional weights of Q
* :mat:func:`rk4` - Explicit Runge-Kutta 4th-order method
* :mat:func:`curl2D` - Returns a two-dimensional mimetic curl operator
* :mat:func:`DI2` - Returns a 2D diagonal scaling matrix
* :mat:func:`DI3` - Returns a 3D diagonal scaling matrix
* :mat:func:`GI1` - Returns a 1D geomeric interpretation matrix
* :mat:func:`GI13` - Returns a 3D geometric interpretation matrix
* :mat:func:`GI2` - Returns a 2D geometric interpretation matrix
* :mat:func:`mimeticB` - Returns a m+2 by m+1 one-dimensional mimetic boundary operator
* :mat:func:`tensorGrad2D` - Calculate tensor gradient in 2D 