## Metodi numerici
Some of the codes that were put forward in the "Metodi numerici per la fisica" lectures' at Unipa.

# Non linear equations
Three methods are presented here. "bis.c" inplements a basic bisection method, "gen.c" consists of a sequence generator method and "rap.c" show the Newton-Raphson method. 
All of three are presented in specific implementation in order to solve a particular equation. Details of those problems are of no importance, since every routine will hopefully works correctly only by substituting the used equation with the desired one.

# Interpolation
The only method presented leads to the Gregory-Newton formulae, using finite differences. Both forward and backward Newton interpolation are implemented in "inter.c".

# Numerical integration
Both the routine listed consist of composite closed integration, found using a Gregory-Newton forward formula to find the approximation-polynomial. In "trapezium.c" it is used a piecewise-linear integration which leads to teh Trapezium Rule; in "simpson.c" it is used a piecewise-quadratic integration, which turns out to the Simpson Rule.

