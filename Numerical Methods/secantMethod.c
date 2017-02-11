#include <stdio.h>
#include <math.h>

double f (double x) {
        return (x * x * x) - x - 1;
}

int main () {
        double x1, x2, x3;
        printf ("Enter two initial guesses: ");
        scanf ("%lf %lf", &x1, &x2);

        double prec;
        printf ("Enter precision: ");
        scanf ("%lf", &prec);

        int miter, iter = 0;
        printf ("Enter maximum iterations: ");
        scanf ("%d", &miter);

        while (iter != miter) {
                if (f(x1) == f(x2)) {
                        printf ("Solution indeterminate!\n");
                        return;
                }

                x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
                x1 = x2;
                x2 = x3;
                printf ("Value at iteration %d: %lf\n", ++iter, x3);
                if (fabs (f(x3)) <= prec)
                        break;
        }
        printf ("\nValue found: %0.4lf\n", x3);
        return 0;
}
