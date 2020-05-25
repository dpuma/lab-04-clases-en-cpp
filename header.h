#include<iostream>
using namespace std;

// CLASE CURSO ===============================================================

class Curso
{
    string nombre;
    string codigo;
    int nroAlumnos;
public:
    string getNombre() const;
    string getCodigo() const;
    int getNroAlumnos() const;
    Curso();
    Curso(Curso &);
    void setNombre(const string nombre);
    void setCodigo(const string codigo);
    void setNroAlumnos(const int nroAlumnos);
    void print();
};

// CLASE ARREGLODECURSO ==========================================================

class ArregloDeCursos
{
    Curso* listaCursos;
    int size;
public:
    Curso* getLista();
    const int getSize() const;
    ArregloDeCursos(const Curso[], const int);
    ArregloDeCursos(const ArregloDeCursos &);
    ~ArregloDeCursos();
    void redimensionar(int);
    void insert(const int , const Curso &);
    void pushback(const Curso &);
    void remove(const int pos);
    void clear();
    void print();
};
