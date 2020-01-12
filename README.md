# Metodi numerici
Some of the codes presented in the "Metodi numerici per la fisica" lectures' at Unipa.

## Non linear equations
Three methods are presented here. "bis.c" implements a basic bisection method, "gen.c" consists of a sequence generator method and "rap.c" show the Newton-Raphson method. 
All of three are presented in specific implementation in order to solve a particular equation. Details of those problems are of no importance, since every routine will hopefully works correctly only by substituting the used equation with the desired one.

## Interpolation
The only method presented leads to the Gregory-Newton formulae, using finite differences. Both forward and backward Newton interpolation are implemented in "inter.c".

## Numerical integration
Both the routine listed consist of composite closed integration, found using a Gregory-Newton forward formula to find the approximating-polynomial. In "trapezium.c" it is used a piecewise-linear integration which leads to teh Trapezium Rule; in "simpson.c" it is used a piecewise-quadratic integration, which turns out to the Simpson Rule.

## Ordinary differential equation
Here there are presented two single-step method based on the Runge-Kutta alghoritms and a predictor-corrector method, based on the Adams-Bashfort-Moulton formulae, helpful for initial-value problems. "heun.c" consists of a second-order Runge-Kutta method whereas "RK4.c" is, obviously, a fourth-order Runge-Kutta method. Finally, in "predictor-corrector.c" it's presented a fourth-order predictor-corrector method with an iterative improvement of the solution.

## Linear systems
Methods of solving systems of linear equations falls into two categories: direct methods and iterative ones. Examples of both tecniques are here listed. 
The iterative tecniques presented are the Jacobi Method, implemented in "jacobi.c", and the Successive-Over-Relaxation Method, used in "SOR.c". We notice that the Gauss-Seidel Method could be implemented only posing in "SOR.c" the relaxation factor equal to one. This explains why explicit routines for G-S Method are not listed.
On the direct side, the only source code listed implements the LU Factorization with Doolittle's Method("LU.c"). Routines for bacward and forward substitution in triangular systems could be found also in "LU.c", so they are not taken apart.

## MonteCarlo simulations
As an example, it is here listed the Box-Muller alghoritm for generating pseudo-random numbers normally distributed. This general method could be applied for a huge variety of problems and situations.
