#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	double n1, n2, media, temp;

	cin >> n1 >> n2;

	temp = (n1*0.35) + (n2*0.75);

	media = (temp*10)/11;

	if(media > 10)
		media = 10;

	printf("MEDIA = %.5f\n", media);

	return 0;
}