#include <stdio.h>
#include <math.h>

int it = 0;

double f (double x) {
	return cos (x) - (x * exp (x));
}

double regulaFalsi (double x1, double x2, double prev, double prec, int miter) {
	if (!miter)
		return prev; //previous

	double cur = (x1 * f (x2) - x2 * f (x1)) / (f (x2) - f (x1)); //current

	if (fabs (cur - prev) < prec) {
		++it;
		return cur;
	}

	printf ("Value at iteration %d: %lf\n", ++it, cur);

	if (f (x1) * f (cur) < 0)
		return regulaFalsi (x1, cur, cur, prec, miter - 1);

	return regulaFalsi (cur, x2, cur, prec, miter - 1);
}

int main () {
	double x1, x2, prec;
	int miter;
	printf ("Method: Regula Falsi\n\nEnter the lower and upper limits: ");
	scanf ("%lf %lf", &x1, &x2);

	printf ("Enter precision: ");
	scanf ("%lf", &prec);

	printf ("Enter maximum iterations: ");
	scanf ("%d", &miter);

	while (1) {
		if (f (x1) * f (x2) < 0) {
			double root = regulaFalsi (x1, x2, -1, prec, miter);
			printf ("\nRoot at iteration %d: %lf\n", it, root);
			break;
		}

		printf ("Wrong limits, enter them again: ");
		scanf ("%lf %lf", &x1, &x2);
	}
	return 0;
}
