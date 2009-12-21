#include <stdio.h>
#include <string.h>

long arr[10] = {3,6,1,2,3,8,4,1,7,2};
void bubble(void *p, size_t width, int N);
int compare(void *m, void *n);

int main (int argc, const char * argv[]) {
	int i;
	putchar('\n');
	for (i = 0; i < 10; i++) {
		printf("%li ", arr[i]);
	}
	bubble(arr, sizeof(long), 10);
	putchar('\n');
	for (i = 0; i < 10; i++) {
		printf("%li ", arr[i]);
	}
    return 0;
}

void bubble(void *p, size_t width, int N) {
	int i, j;
	unsigned char buf[4];
	unsigned char *bp = p;
	
	for (i = N - 1; i >= 0; i--) {
		for (j = 1; j <= i; j++) {
			if (compare((void *)(bp + width*(j-1)) , (void *)(bp+ width*j))) {
				memcpy(buf, bp + width*(j-1), width);
				memcpy(bp + width*(j-1), bp + width*j, width);
				memcpy(bp + width*j, buf, width);
			}
		}
	}
}

int compare(void *m, void *n) {
	long *m1, *n1;
	m1 = (long *)m;
	n1 = (long *)n;
	return (*m1 > *n1);
}