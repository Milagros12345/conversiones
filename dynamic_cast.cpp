#include <iostream>
#include <cstring>
using namespace std;

class Persona { // Virtual
  public:
   Persona(char *n) { strcpy(nombre, n); }
   virtual void VerNombre() = 0; // Virtual pura
  protected:
   char nombre[30];
};

class Empleado : public Persona {
  public:
   Empleado(char *n, float s) : Persona(n), sueldo(s) {}
   void VerNombre() {
      cout << "Emp: " << nombre << endl;
   }
   void VerSueldo() {
      cout << "Salario: " << sueldo << endl;
   }
  private:
   float sueldo;
};

class Estudiante : public Persona {
  public:
   Estudiante(char *n) : Persona(n) {}
   void VerNombre() {
      cout << "Est: " << nombre << endl;
   }
};

void VerSueldo(Persona *p) {
   if(Empleado *pEmp = dynamic_cast<Empleado *> (p))
      pEmp->VerSueldo();
   else
      cout << "No tiene salario." << endl;
}

int main() {
   Persona *Pepito = new Estudiante("Jose");
   Persona *Carlos = new Empleado("Carlos", 1000.0);

   Carlos->VerNombre();
   VerSueldo(Carlos);

   Pepito->VerNombre();
   VerSueldo(Pepito);

   delete Pepito;
   delete Carlos;

   return 0;
}
