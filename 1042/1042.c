#include <stdio.h>

int main(){
	int a, b, c, i, j;

	scanf("%d %d %d", &a, &b, &c);

	int v[] = { a, b, c };

	for(i = 0; i < 3; i++){
		for(j = i+1; j < 3; j++){
			if(v[i] > v[j]){
				v[i] ^= v[j];
				v[j] ^= v[i];
				v[i] ^= v[j];
			}
		}
	}

	for(i = 0; i < 3; i++)
		printf("%d\n", v[i]);

	printf("\n");

	printf("%d\n%d\n%d\n", a, b, c);

	return 0;
}
