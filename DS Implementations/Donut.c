#include<stdio.h>
#include<string.h>
#include<math.h>

//0<X<80 , 0<Y<22, x belongs to (0,80) , y belongs to (0,22)

struct Vectors{ float x,y,z; } Normal={0,0,0},Light={0,1,-1};	//Light = Direction vector of lighting
	
float DotProduct(struct Vectors x1,struct Vectors x2){ return (x1.x*x2.x)+(x1.y*x2.y)+(x1.z*x2.z); }

int k,dist=6,radius=3;	//dist = distance of the donut from the screen
int main(){
    float A=0, B=0, i, j, z[1760];	//80*22=1760
    char b[1760];
    printf("\x1b[2J"); 		// Clears the Screen
    while(1){
        memset(b,32,1760*sizeof(char));		//fill a block of memory with a particular value. Ascii value of NULL character = 32
        memset(z,0,1760*sizeof(float));		//Params:- Block Addess,value,bytes to be assigned
        for(j=0; 6.28>j; j+=0.07) {		//Why 6.28? Because 2*PI=2*3.14=6.28
            for(i=0; 6.28 >i; i+=0.02) {
                float sini=sin(i),	//i = rotation in y-axis, i=phi
                      cosj=cos(j),	//j = parametric angle for xy plotting of circle, j=theta
                      sinA=sin(A),
                      sinj=sin(j),
                      cosA=cos(A),
                      cosj2=cosj+radius,
                      mess=1/(sini*cosj2*cosA+sinj*sinA+(float)(dist)),	//Z-inverse
                      cosi=cos(i),
                      cosB=cos(B),
                      sinB=sin(B),
                      t=sini*cosj2*sinA-sinj*cosA;	//t = precalculated common variable for x and y coordinates
                Normal.x = (sinA*sini*cosj-sinj*cosA)*sinB+cosB*cosi*cosj;
		Normal.y = ((float)(-1))*(sinA*sini*cosj-sinj*cosA)*cosB+sinB*cosi*cosj;
		Normal.z = sinA*sinj+sini*cosA*cosj;
                int x=40+30*mess*(cosi*cosj2*cosB-t*sinB),
                    y=12+15*mess*(cosi*cosj2*sinB+t*cosB),
                    o=x+80*y,
                    N=8*(DotProduct(Normal,Light));
                if(22>y&&y>0 && x>0&&80>x && mess>z[o]){
                    z[o]=mess;
                    b[o]=".,-~:;=!*#$@"[N>0?N:0];
                }
            }
        }
        printf("\x1b[d");
        for(k=0; 1761>k; k++)
            putchar(k%80?b[k]:10);	//Puts a character on stdout, in our case:- monitor
        A+=0.04;	//A = rotation about X-axis
        B+= 0.02;	//B = rotation about Z-axis
    }
}
