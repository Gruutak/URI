#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	double n1, n2, n3, media;

	cin >> n1 >> n2 >> n3;

	media = (n1*0.2) + (n2*0.3) + (n3*0.5);

	if(media > 10)
		media = 10;

	printf("MEDIA = %.1f\n", media);

	return 0;
}