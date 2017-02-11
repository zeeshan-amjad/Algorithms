#include <stdio.h>
#include <math.h>

int it = 0;

double f (double x) {
        return (x * x * x) - (8 * x) - 4;
}

double df (double x) {
        return (3 * x * x) - 8;
}

double newtonRaphson (double x, int miter, double prec) {
        if (!miter)
                return x;
        double h = f (x) / df (x);
        double newX = x - h;
        printf ("Value at iteration %d: %lf\n", ++it, newX);
        if (fabs (h) < prec)
                return newX;
        return newtonRaphson(newX, miter--, prec);
}

int main () {
        printf ("Enter initial guess: ");
        double x;
        scanf ("%lf", &x);

        printf ("Enter maximum iterations: ");
        int miter;
        scanf ("%d", &miter);

        printf ("Enter precision: ");
        double prec;
        scanf ("%lf", &prec);

        double root = newtonRaphson (x, miter, prec);
        printf ("\nRoot at iteration %d: %lf\n", it, root);
        return 0;
}
