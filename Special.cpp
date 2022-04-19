#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int x=45;
	x<<=1;
	float y=23;
	int z=*(int*)&y;
	cout<<x<<endl<<z<<endl;
}

/*23 floating point IEEE 754
sign bit = 0
Exponent = (131) = (10000011)
Mantissa = 01110000000000000000000*/

/*Therefore memory referenced by &y stores the value = 01000001101110000000000000000000 = 1102577664 in decimal*/