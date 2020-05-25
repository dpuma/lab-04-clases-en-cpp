#include "header.h"

// METODOS DE LA CLASE CURSO ===============================================================

Curso::Curso()
{
    nombre = "o";
    codigo = "o";
    nroAlumnos = 0;
}
Curso::Curso(Curso &o)
{
    this->nombre = o.nombre;
    this->codigo = o.codigo;
    this->nroAlumnos = o.nroAlumnos;
}

string Curso::getNombre() const { return nombre; }
string Curso::getCodigo() const { return codigo; }
int Curso::getNroAlumnos() const { return nroAlumnos; }
void Curso::setNombre(const string nombre) { this->nombre = nombre; }
void Curso::setCodigo(const string codigo) { this->codigo = codigo; }
void Curso::setNroAlumnos(const int nroAlumnos) { this->nroAlumnos = nroAlumnos; }

void Curso::print()
{
    cout << "Nombre     : " << nombre << endl;
    cout << "Codigo     : " << codigo << endl;
    cout << "nroAlumnos : " << nroAlumnos << endl << endl;
}

// METODOS DE LA CLASE ARREGLODECURSOS =========================================================

const int ArregloDeCursos::getSize() const { return size; }
Curso* ArregloDeCursos::getLista() { return listaCursos; }

ArregloDeCursos::ArregloDeCursos(const Curso cursos[], const int tam)
{
    listaCursos = new Curso[tam];
    size = tam;
    for (int i = 0; i < size; i++)
        listaCursos[i] = cursos[i];
}
ArregloDeCursos::ArregloDeCursos(const ArregloDeCursos &o)
{
    listaCursos = new Curso[o.size];
    size = o.size;
    for(int i = 0; i < size; i++)
        listaCursos[i] = o.listaCursos[i];
}
ArregloDeCursos::~ArregloDeCursos()
{
    delete[] listaCursos;
}

void ArregloDeCursos::redimensionar(int n)
{
    Curso *listaTemp = new Curso[n];
    int it = min(this->size, n);
    for(int i = 0; i < it; i++) {
        listaTemp[i].setNombre(this->listaCursos[i].getNombre());
        listaTemp[i].setCodigo(this->listaCursos[i].getCodigo());
        listaTemp[i].setNroAlumnos(this->listaCursos[i].getNroAlumnos());
    }
    delete[] listaCursos;
    listaCursos = listaTemp;
    size = n;
}

void ArregloDeCursos::insert(const int posicion, const Curso &p)
{
    redimensionar(size+1);
    int i = size;
    while(--i > posicion)
    {
        listaCursos[i].setNombre(listaCursos[i-1].getNombre());
        listaCursos[i].setCodigo(listaCursos[i-1].getCodigo());
        listaCursos[i].setNroAlumnos(listaCursos[i-1].getNroAlumnos());
    }
    listaCursos[i].setNombre(p.getNombre());
    listaCursos[i].setCodigo(p.getCodigo());
    listaCursos[i].setNroAlumnos(p.getNroAlumnos());
}

void ArregloDeCursos::pushback(const Curso &p)
{
    this->insert(size,p); //no size-1 pq sino cuando redimensiona estaria una pos por detrás de lo que espera
}

void ArregloDeCursos::remove(const int pos)
{
    int i = pos;
    while(i < size-1)
    {
        listaCursos[i].setNombre(listaCursos[i+1].getNombre());
        listaCursos[i].setCodigo(listaCursos[i+1].getCodigo());
        listaCursos[i].setNroAlumnos(listaCursos[i+1].getNroAlumnos());
        i++;
    }
    redimensionar(size-1);
}

void ArregloDeCursos::clear()
{
    redimensionar(0);
}

void ArregloDeCursos::print()
{
    for(int i = 0; i < size; i++)
        listaCursos[i].print();
    cout << "--------------------------" << endl;
}

// MAIN ================================================================

int main()
{
    // pruebas:
    Curso Fisica;
    Fisica.setNombre("fisica");
    Fisica.setCodigo("012345");
    Fisica.setNroAlumnos(12);

    Curso Quimica;
    Quimica.setNombre("quimica");
    Quimica.setCodigo("111111");
    Quimica.setNroAlumnos(3);

    Curso Geometria;
    Geometria.setNombre("geometria");
    Geometria.setCodigo("22222");
    Geometria.setNroAlumnos(13);

    Curso arr[3] = {Fisica, Quimica, Geometria};
    ArregloDeCursos arrCursos(arr, 3); // constructor
    arrCursos.print();

    Curso Dibujo;
    Dibujo.setNombre("dibujo");
    Dibujo.setCodigo("1AAA");
    Dibujo.setNroAlumnos(35);
    arrCursos.insert(2,Dibujo);     // insert
    arrCursos.print();

    arrCursos.remove(1);            // remove
    arrCursos.print();

    arrCursos.clear();              // clear
    cout << "array vacio con clear" << endl;
    arrCursos.print();

    arrCursos.pushback(Quimica);    // pushback
    arrCursos.print();

    return 0;
}
