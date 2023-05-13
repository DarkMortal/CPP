#include <fstream>
#include <iostream>
#include <string.h>
#include <math.h>
#include <ctype.h>
using namespace std;
template <class X>

X ABS(X x){
	if (x > 0) return x;
	else if (x < 0) return -x;
}

namespace Maths{
	class Complex{
		float x, y;
	public:
		Complex(){
			x = 0;
			y = 0;
		}
		float MOD(){
			float z = x * x + y * y;
			z = sqrt(z);
			return z;
		}
		float ARG(){
			float z = y / x;
			z = atan(z);
			return z;
		}
		Complex Conj(){
			Complex a;
			a.Initialze(x, -y);
			return a;
		}
		void Disp(){
			if (x == 0){
				if (y == 1)
					cout << "i";
				else if (y == -1)
					cout << "-i";
				else if (y != 0)
					cout << y << "i";
				else if (y == 0)
					cout << "0";
			}
			else
			{
				cout << x;
				if (y == 1)
					cout << "+i";
				else if (y == -1)
					cout << "-i";
				else
				{
					if (y < 0)
						cout << y << "i";
					else if (y > 0)
						cout << "+" << y << "i";
				}
			}
		}
		float real() { return x; }
		float img() { return y; }
		void Initialze(float a, float b)
		{
			x = a;
			y = b;
		}
		Complex operator+(Complex &a)
		{
			Complex b;
			b.x = x + a.x;
			b.y = y + a.y;
			return b;
		}
		Complex operator-(Complex &a)
		{
			Complex b;
			b.x = x - a.x;
			b.y = y - a.y;
			return b;
		}
		Complex operator*(Complex &a)
		{
			Complex b;
			b.x = (x * a.x) - (y * a.y);
			b.y = (x * a.y) + (y * a.x);
			return b;
		}
		Complex operator*(float a)
		{
			Complex b;
			b.x = a * x;
			b.y = a * y;
			return b;
		}
		Complex operator/(Complex &e)
		{
			float n;
			Complex a, b;
			a.Initialze(x, y);
			b = e.Conj();
			a = a * b;
			n = pow(e.MOD(), -2);
			a = a * n;
			return a;
		}
		Complex(Complex &a)
		{
			x = a.x;
			y = a.y;
		}
		bool operator==(Complex &a)
		{
			if (x == a.x && y == a.y)
				return true;
			else
				return false;
		}
	};
	class Vector
	{
		float x, y, z;

	public:
		Vector()
		{
			x = 0;
			y = 0;
			z = 0;
		}
		float MOD()
		{
			float mod;
			mod = (x * x) + (y * y) + (z * z);
			mod = sqrt(mod);
			return mod;
		}
		void MULTIPLE(float a)
		{
			x = x * a;
			y = y * a;
			z = z * a;
		}
		void Disp(){
			if (x == 1) cout << "i";
			else if (x == (-1)) cout << "-i";
			else if (x != 0) cout << x << "i";
			if (y == 1){
				if (x == 0) cout << "j";
				else cout << "+j";
			}
			else if (y == (-1)) cout << "-j";
			else if (y > 0){
				if (x == 0) cout << y << "j";
				else cout << "+" << y << "j";
			}
			else if (y < 0) cout << "-" << ABS(y) << "j";
			if (z == 1){
				if (x == 0 && y == 0) cout << "k";
				else cout << "+k";
			}
			else if (z == (-1)) cout << "-k";
			else if (z > 0){
				if (x == 0 && y == 0) cout << z << "k";
				else cout << "+" << z << "k";
			}
			else if (z < 0) cout << "-" << ABS(z) << "k";
		}
		void Initialze(float a, float b, float c){
			x = a;
			y = b;
			z = c;
		}
		Vector operator+(Vector &b){
			Vector a;
			a.x = x + b.x;
			a.y = y + b.y;
			a.z = z + b.z;
			return a;
		}
		Vector operator-(Vector &b){
			Vector a;
			a.x = x - b.x;
			a.y = y - b.y;
			a.z = z - b.z;
			return a;
		}
		float operator*(Vector &v){
			float a, b, c;
			a = x * v.x;
			b = y * v.y;
			c = z * v.z;
			return (a + b + c);
		}
		Vector(Vector &b){
			x = b.x;
			y = b.y;
			z = b.z;
		}
		bool operator==(Vector &b){
			if (x == b.x && y == b.y && z == b.z)
				return true;
			else
				return false;
		}
	};
	Complex Log(Complex e){
		Complex x;
		float a, b;
		a = log(e.MOD());
		b = log(e.ARG());
		x.Initialze(a, b);
		return x;
	}
	Complex Sqrt(Complex e){
		Complex x;
		float a = e.MOD() + e.real();
		a = sqrt(a / 2);
		float b = e.MOD() - e.real();
		b = sqrt(b / 2);
		if (e.img() < 0)
			b = -b;
		x.Initialze(a, b);
		return x;
	}
	Complex Pow(Complex e, int n){
		Complex x;
		x.Initialze(e.real(), e.img());
		for (int i = 0; i < n - 1; i++)
			x = x * e;
		return x;
	}
}

class BOOK{
	float price;
	char title[100], author[100];
	char ISBN[100];

	public: void getdata(); void disp();
	void storedata(){
		ofstream x;
		x.open("BookData.dat", ios::app | ios::binary);
		getdata();
		x.write((char *)this, sizeof(*this));
		x.close();
	}
	void showdata(){
		ifstream fl;
		int sum = 0;
		fl.open("BookData.dat", ios::in | ios::binary);
		if (!fl) cout << "\nSorry, there is nothing to SHOW!!!";
		else{
			fl.seekg(0);
			fl.read((char *)this, sizeof(*this));
			while (!fl.eof()){
				disp();
				sum++;
				fl.read((char *)this, sizeof(*this));
			}
			fl.close();
			cout << "\nThere are " << sum << " records in total.";
		}
	}
	void SearchBook(char* x){
		ifstream fl;
		int cnt = 0;
		fl.open("BookData.dat", ios::in | ios::binary);
		if (!fl) cout << "Sorry, there is nothing to SHOW!!!";
		else{
			fl.seekg(0);
			fl.read((char *)this, sizeof(*this));
			while (!fl.eof()){
				if (strcmp(x, title) == 0 || strcmp(x, ISBN) == 0 || strcmp(x, author) == 0){
					cnt++;
					disp();
				}
				fl.read((char *)this, sizeof(*this));
			}
			if (cnt == 0) cout << "\nSorry, record doesn't exist!!!";
			else cout << "\nThere are " << cnt << " records in total";
		}
	}
	bool operator==(BOOK &x){
		return (x.price == price && strcmp(x.title, title) == 0 && strcmp(x.ISBN, ISBN) == 0);
	}
	void DELETE(char* a){
		ifstream x;
		ofstream y;
		x.open("BookData.dat", ios::in | ios::binary);
		if (!x)	cout << "File does not EXIST!!!";
		else{
			y.open("temp.dat", ios::out | ios::binary);
			x.read((char *)this, sizeof(*this));
			while (!x.eof()){
				if (strcmp(a, title) != 0 && strcmp(a, ISBN) != 0)
					y.write((char *)this, sizeof(*this));
				x.read((char *)this, sizeof(*this));
			}
			x.close();
			y.close();
			remove("BookData.dat");
			rename("temp.dat", "BookData.dat");
		}
	}
};

void BOOK::getdata(){
	cout << "Enter the PRICE of the BOOK:-";
	cin >> price;
	cout << "Enter the TITLE of the BOOK:-";
	fflush(stdin);
	gets(title);
	cout << "Enter the Author of the BOOK:-";
	fflush(stdin);
	gets(author);
	cout << "Enter ISBN Number:-";
	cin >> ISBN;
	cout << endl;
}

void BOOK::disp(){
	cout << "\nThe PRICE of the BOOK:-" << price << endl;
	cout << "The TITLE of the BOOK:-" << title << endl;
	cout << "The Author of the BOOK:-" << author << endl;
	cout << "The ISBN Number of the BOOK:-" << ISBN << endl;
}

class Student{
	int rn;
	char name[100], school[100];
	float prctg;

	public:	void getdata(){
		cout << "\nEnter RollNO of STUDENT:-";
		cin >> rn;
		cout << "Enter Name of STUDENT:-";
		fflush(stdin);
		fflush(stdin);
		gets(name);
		cout << "Enter School of STUDENT:-";
		fflush(stdin);
		fflush(stdin);
		gets(school);
		cout << "Enter the Prcentage:-";
		cin >> prctg;
	}
	void disp(){
		cout << "\nRollNO of STUDENT:-" << rn;
		cout << "\nName of STUDENT:-" << name;
		cout << "\nSchool of STUDENT:-" << school;
		cout << "\nThe Percentage of STUDENT:-" << prctg << endl;
	}
	void storedata();
	void loaddata();
	bool operator == (Student &x){
		return (x.rn == rn && strcmp(x.name, name) == 0 && strcmp(x.school, school) == 0 && x.prctg == prctg);
	}
	void SearchStudent(char x[]){
		ifstream fl;
		fl.open("Student.dat", ios::in | ios::binary);
		if (!fl) cout << "Sorry, there is nothing to SHOW!!!";
		else{
			fl.seekg(0);
			fl.read((char *)this, sizeof(*this));
			while (!fl.eof()){
				if (strcmp(x, name) == 0) disp();
				else fl.read((char *)this, sizeof(*this));
			}
		}
	}
	void DELETE(char x[]);
};

void Student::storedata(){
	ofstream x("Student.dat", ios::app | ios::binary);
	getdata();
	x.write((char *)this, sizeof(*this));
	x.close();
}

void Student::loaddata(){
	int sum = 0;
	ifstream x("Student.dat", ios::in | ios::binary);
	if (!x) cout << "Sorry, there are no ENTRIES to SHOW!!!";
	else{
		x.seekg(0);
		x.read((char *)this, sizeof(*this));
		while (!x.eof()){
			sum++;
			disp();
			x.read((char *)this, sizeof(*this));
			cout << "\nThere are " << sum << " ENTRIES in total";
			x.close();
		}
	}
}

void Student::DELETE(char a[]){
	ifstream x;
	ofstream y;
	x.open("Student.dat", ios::in | ios::binary);
	if (!x) cout << "File does not EXIST!!!";
	else{
		y.open("temp.dat", ios::out | ios::binary);
		x.read((char *)this, sizeof(*this));
		while (!x.eof()){
			if (strcmp(a, name) != 0)
				y.write((char *)this, sizeof(*this));
			x.read((char *)this, sizeof(*this));
		}
		x.close();
		y.close();
		remove("Student.dat");
		rename("temp.dat", "Student.dat");
	}
}
