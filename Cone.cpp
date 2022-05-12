#include<bits/stdc++.h>
using namespace std;

//0<X<80 , 0<Y<22, x belongs to (0,80) , y belongs to (0,22)
float r = 3, h = 5, m1 = (h/r)*(-1), m2 = (r/h), dist = 5;
const int rangeX = 80, rangeY= 25;

struct Vector{
    float x,y,z;
    Vector(float a,float b,float c):x(a),y(b),z(c){}
    Vector Normalize();
    float operator * (const Vector&);
} Light(0,1,1), Normal(r,h,0);

float Line(float x){
    return (m1*x+h);
}

float Rotation[3][3]=
{
    {0,0,0},{0,0,0},{0,0,0}
};

int main(){
    int k;
    float A=0, B=0,i,x,y,z,z2,Z[rangeX*rangeY],mess;
    x=y=z=0;
    //A=3.14/6;
    //Rotation[1][1] = 1;
    char b[rangeX*rangeY]; cout<<"\x1b[2j";
    while(1){
        memset(b,32,1760*sizeof(char));		//fill a block of memory with a particular value. Ascii value of NULL character = 32
        memset(Z,0,1760*sizeof(float));		//Params:- Block Addess,value,bytes to be assigned
        for(i=0;i<6.28;i+=0.02){
            for(x=0;x<=r;x+=0.02){

                float cosA=cos(A),sinA=sin(A),
                      cosB=cos(B),sinB=sin(B),
                      cosi=cos(i),sini=sin(i);

                //Setting the rotation Matrix

                Rotation[0][0] = cosB*cosi; Rotation[0][1] = cosB*sini*sinA-sinB*cosA; Rotation[0][2] = sinB*sinA+cosB*sini*sinA;
                Rotation[1][0] = sinB*cosi; Rotation[1][1] = cosA*cosB+sini*sinA*sinB; Rotation[1][2] = sinB*sini*cosA-cosB*sinA;
                Rotation[2][0] = -sini; Rotation[2][1] = cosi*sinA; Rotation[2][2] = cosi*cosA;

                //float sini = x*sin(i)*(-1.0);
                y = Line(x);
                //y = (y>0?y:0);
                z2 = x*Rotation[2][0]+y*Rotation[2][1]+z*Rotation[2][2];
                mess = 1/(dist+z2);
                Normal.z = z2;
                int X = 40.0+30.0*mess*(x*Rotation[0][0]+y*Rotation[0][1]+z*Rotation[0][2]),
                    Y = 5.0+15.0*mess*(x*Rotation[1][0]+y*Rotation[1][1]+z*Rotation[1][2]),
                    O = X+rangeX*Y,
                    //N = 8.0*(Normal.Normalize()*Light);
                    N = 3.0*(Normal*Light);
                if(rangeY>Y&&Y>0 && X>0&&rangeX>X && mess>Z[O]){
                    Z[O]=mess;
                    b[O]=".,-~:;=!*#$@"[N>0?(N>=11?11:N):0];
                }
            }
        }
        cout<<"\x1b[d";
        for(k=0; 1761>k; k++)
            cout<<char(k%80?b[k]:10);	//Puts a character on stdout, in our case:- monitor
        //A+=0.04;	//A = rotation about X-axis
        B+= 0.02;	//B = rotation about Z-axis
    }
    return 0;
}

Vector Vector::Normalize(){
    float s = sqrt(x*x+y*y+z*z);
    return Vector(x/s,y/s,z/s);
}

float Vector::operator*(const Vector& a){
    return (x*a.x+y*a.y+z*a.z);
}
