// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class Base { virtual void dummy() {} };//dinamic_cast
class Derived: public Base { int a; };
void print (char * str)
{
  cout << str << '\n';
}
//const_cast
class student
{
private:
	int roll;
public:
	// constructor
	student(int r):roll(r) {}

	// A const function that changes roll with the help of const_cast
	void fun() const
	{
		( const_cast <student*> (this) )->roll = 4;
	}

	int getRoll() { return roll; }
};
int fun(int* ptr)
{
    return (*ptr + 10);
}
int main () {
  try {
    Base * pba = new Derived;//APUNTA COMPLETO A  LA CLASE DEIVED
    Base * pbb = new Base;//apunta a base pero esto es incompleto
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);
    if (pd==0) cout << "Null pointer on first type-cast.\n";

    pd = dynamic_cast<Derived*>(pbb);
    if (pd==0) cout << "Null pointer on second type-cast.\n";

  } catch (exception& e) {cout << "Exception: " << e.what();}
  const char * c = "sample text";
  print ( const_cast<char *> (c) );
  student s(2);
	cout << "Old roll number: " << s.getRoll() << endl;
	s.fun();
	cout << "New roll number: " << s.getRoll() << endl;
	const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    cout << fun(ptr1);
  return 0;
}
