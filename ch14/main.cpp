#include <iostream>

using namespace std;

struct B1
{
	virtual void vf() const {cout<<"B1::vf"<<endl;}	//Absztrakt mert tiszta virtual van benne
	void f() const {cout<<"B1::f"<<endl;}
	virtual void pvf() =0;
};

struct D1:B1 //Átadja az értéket
{	
	void vf() const override {cout<<"D1::vf"<<endl;}
	void f() const {cout<<"D1::f"<<endl;}

};

struct D2:D1
{
	void pvf() override {cout<<"D2:pvf"<<endl;}
};

struct B2
{	
	virtual void pvf()=0; //Tiszta virtual = 0 az értéke nincs alap érték de átadható neki
};

struct D21:B2
{
	string szoveg="Alma";
	void pvf() override {cout<<szoveg<<endl;}
};

struct D22:B2
{
	int number=11;
	void pvf() override {cout<<number<<endl;}
};

void f(B2 &ref)
{
	ref.pvf();
}

int main()
{
	
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	return 0;
}