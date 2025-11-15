#include <stdio.h>
    int main() {
      int n;
      scanf("%d", &n);
      int a[n];
      int i;
      int d = 0;
      for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
      }
      int c = 0;
      while (d!=1) {
	d = 1;
        int j;
        int s;
        for (i = 0; i < n; i++) {
          j = (i + 1) % n;
          s = a[i] + a[j];
          if (s % 2 == 1) {
            s--;
            c++;
          }
          s /= 2;
          a[i] = s;
          a[j] = s;
        }
	for (i=0; i<n; i++){
	j = (i+1)%n;
	if (a[i] != a[j]){
	d = 0;
	}
	}
      }
      printf("%d %d", c, a[0]);
    }
