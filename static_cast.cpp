#include <iostream>
#include <exception>
using namespace std;
class Base {
  public:
   Base(int valor) : x(valor) {}
   void Mostrar() { cout << x << endl; }

  protected:
   int x;
};

class Derivada : public Base {
  public:
   Derivada(int ivalor, float fvalor) :
      Base(ivalor), y(fvalor) {}
   void Mostrar() {
      cout << x << ", " << y << endl;
   }

  private:
   float y;
};
class Tiempo {
  public:
   Tiempo(int h=0, int m=0) : hora(h), minuto(m) {}

   void Mostrar();
   operator int() {
      return hora*60+minuto;
   }
  private:
   int hora;
   int minuto;
};
int main() {
   Derivada *pDer = new Derivada(10, 23.3);
   Base *pBas;

   pDer->Mostrar(); // Derivada
   pBas = static_cast<Base *> (pDer);
   // pBas = pDer; // Igualmente legal, pero implícito
   pBas->Mostrar(); // Base

   delete pDer;
   Tiempo Ahora(12,24);
   int minutos;

   Ahora.Mostrar();
   minutos = static_cast<int> (Ahora);
   // minutos = Ahora; // Igualmente legal, pero implícito

   cout << minutos << endl;
   return 0;
}
