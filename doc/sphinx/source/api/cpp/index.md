# C++ API Documentation

Welcome to the C++ API documentation for the Mimetic Operators Library Enhanced (MOLE). This section provides detailed information about the library's classes and their usage.

```{admonition} Installation Note
:class: note
Make sure you have installed the MOLE library properly to use these classes. See the [Getting Started Guide](../intros/gettingstarted.md) for installation instructions.
```

## Class Structure

The following diagram shows the key classes in the MOLE C++ API and their relationships:

```{mermaid}
classDiagram
    sp_mat <|-- Interpol
    sp_mat <|-- Gradient
    sp_mat <|-- Divergence
    sp_mat <|-- Laplacian
    sp_mat <|-- RobinBC
    sp_mat <|-- MixedBC
    
    Gradient --> Laplacian : used by
    Divergence --> Laplacian : used by
    
    class sp_mat {
        +operator=()
    }
    
    class Interpol {
        +Interpol(u32 m, Real c)
        +Interpol(u32 m, u32 n, Real c1, Real c2)
        +Interpol(u32 m, u32 n, u32 o, Real c1, Real c2, Real c3)
        +Interpol(bool type, u32 m, Real c)
        +Interpol(bool type, u32 m, u32 n, Real c1, Real c2)
        +Interpol(bool type, u32 m, u32 n, u32 o, Real c1, Real c2, Real c3)
    }
    
    class Gradient {
        -vec P
        +Gradient(u16 k, u32 m, Real dx)
        +Gradient(u16 k, u32 m, u32 n, Real dx, Real dy)
        +Gradient(u16 k, u32 m, u32 n, u32 o, Real dx, Real dy, Real dz)
        +vec getP()
    }
    
    class Divergence {
        -vec Q
        +Divergence(u16 k, u32 m, Real dx)
        +Divergence(u16 k, u32 m, u32 n, Real dx, Real dy)
        +Divergence(u16 k, u32 m, u32 n, u32 o, Real dx, Real dy, Real dz)
        +vec getQ()
    }
    
    class Laplacian {
        +Laplacian(u16 k, u32 m, Real dx)
        +Laplacian(u16 k, u32 m, u32 n, Real dx, Real dy)
        +Laplacian(u16 k, u32 m, u32 n, u32 o, Real dx, Real dy, Real dz)
    }
    
    class RobinBC {
        +RobinBC(u16 k, u32 m, Real dx, Real a, Real b)
        +RobinBC(u16 k, u32 m, Real dx, u32 n, Real dy, Real a, Real b)
        +RobinBC(u16 k, u32 m, Real dx, u32 n, Real dy, u32 o, Real dz, Real a, Real b)
    }
    
    class MixedBC {
        +MixedBC(u16 k, u32 m, Real dx, string left, vector~Real~ coeffs_left, string right, vector~Real~ coeffs_right)
        +MixedBC(u16 k, u32 m, Real dx, u32 n, Real dy, ...)
        +MixedBC(u16 k, u32 m, Real dx, u32 n, Real dy, u32 o, Real dz, ...)
    }
    
    class Utils {
        +static spkron(sp_mat A, sp_mat B)
        +static spjoin_rows(sp_mat A, sp_mat B)
        +static spjoin_cols(sp_mat A, sp_mat B)
        +static spsolve_eigen(sp_mat A, vec b)
        +meshgrid(vec x, vec y, mat X, mat Y)
        +meshgrid(vec x, vec y, vec z, cube X, cube Y, cube Z)
    }
```

```{toctree}
:maxdepth: 2
:caption: API Components

operators
boundary
utils
```


```{admonition} Advanced Usage
:class: tip
For advanced usage patterns and performance optimization, check out the individual class documentation pages.
``` 