#include <stdio.h>
#include <math.h>

int it = 0;

double f (double x) {
	return (x * x * x) - (5 * x) + 1;
}

double bisectionMethod (double low, double hi, double pmid, double prec, int miter) {
	if (!miter)
		return pmid; //previous mid

	double cmid = (low + hi) / 2; //current mid

	if (fabs (cmid - pmid) < prec) {
		++it;
		return cmid;
	}
	
	printf ("Value at iteration %d: %lf\n", ++it, cmid);

	if (f (low) * f (cmid) < 0)
		return bisectionMethod (low, cmid, cmid, prec, miter - 1);

	return bisectionMethod (cmid, hi, cmid, prec, miter - 1);
}

int main () {
	double low, hi, prec;
	int miter;
	printf ("Method: Bisection\n\nEnter the lower and upper limits: ");
	scanf ("%lf %lf", &low, &hi);

	printf ("Enter maximum iterations: ");
	scanf ("%d", &miter);
	
	printf ("Enter precision: ");
	scanf ("%lf", &prec);

	while (1) {
		if (f (low) * f (hi) < 0) {
			double root = bisectionMethod (low, hi, -1, prec, miter);
			printf ("\nRoot at iteration %d: %lf\n", it, root);
			break;
		}

		printf ("Wrong limits, enter them again: ");
		scanf ("%lf %lf", &low, &hi);
	}
	return 0;
}
