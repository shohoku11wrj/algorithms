#include<iostream>
using namespace std;

class Cshape {
	public:
		void SetColor(int color) { m_nColor=color;}
		virtual void Display( void) { cout<<"Cshape"<<endl; }
	private:
		int m_nColor;
};

class Crectangle: public Cshape {
	public:
		virtual void Display( void) { cout<<"Crectangle"<<endl; }
};

class Ctriangle: public Cshape {
	public:
	virtual void Display( void) { cout<<"Ctriangle"<<endl; }
};

class Cellipse :public Cshape {
	public:
		virtual void Display(void) { cout<<"Cellipse"<<endl;}
};

int main()
{
	Cshape obShape;
	Cellipse obEllipse;
	Ctriangle obTriangle;
	Crectangle obRectangle;
	Cshape * pShape[4]= { &obShape,&obEllipse,&obTriangle,& obRectangle };
	for( int I= 0; I< 4; I++)
		pShape[I]->Display( );
	return 0;
}
