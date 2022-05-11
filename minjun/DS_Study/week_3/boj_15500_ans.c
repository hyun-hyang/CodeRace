#include <stdio.h>

int arr1[1<<20];
int arr2[1<<20];
int arr3[1<<20];
int ans[1<<20];

int main() {
	int n;
	scanf("%d", &n);
	int t1=n-1, t2=-1, t3=-1;
	for(int i=0; i<n; i++)
		scanf("%d", &arr1[i]);
	
	int r=1;
	int togo=n;
	
	int z=0;
	
	while(togo) {
		if(r==1) {
			while(t1 != -1) {
				int t=arr1[t1--];
				if(t == togo) {
					ans[z] = 13;
					z++;
					togo--;
				}
				else{
					ans[z] = 12;
					z++;
					arr2[++t2] = t;
				}
			}
			if(t1 == -1)
				r=0;
		}
		else {
			while(t2 != -1) {
				int t=arr2[t2--];
				if(t == togo) {
					ans[z] = 23;
					z++;
					togo--;
				}
				else {
					ans[z] = 21;
					z++;
					arr1[++t1] = t;
				}
			}
			if(t2 == -1)
				r=1;
		}
	}
	
	printf("%d\n", z);
	for(int i=0; i<z; i++)
		printf("%d %d\n", ans[i]/10, ans[i]%10);
	
	return 0;
}