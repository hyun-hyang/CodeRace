#include <stdio.h>

int main() {
	int n, ind=0;
	double st[200];
	char ex[200];

	scanf("%ld", &n);
	double *val = (double *)malloc(sizeof(double)*n);

	scanf("%s", ex);

	for(int i=0; i<n; i++)
		scanf("%lf", &val[i]);

	double x, y;

	for(int i=0; ex[i]!='\0'; i++) {
		if(ex[i] == '*') {
			y=st[--ind];
			x=st[--ind];
			st[ind++] = x*y;
		}
		else if(ex[i] == '-') {
			y=st[--ind];
			x=st[--ind];
			st[ind++] = x-y;
		}
		else if(ex[i] == '+') {
			y=st[--ind];
			x=st[--ind];
			st[ind++] = x+y;
		}
		else if(ex[i] == '/') {
			y=st[--ind];
			x=st[--ind];
			st[ind++] = x/y;
		}
		else
			st[ind++] = val[ex[i]-'A'];
	}
    
	printf("%.2f", st[ind-1]);
	return 0;
	//dfdfsdf
}