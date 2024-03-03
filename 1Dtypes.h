/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#ifndef DTYPES_H
#define DTYPES_H


#include <iostream>

#include "Lattice1D.h"


class Lattice1D_open: public Lattice1D {
  public:
    Cell* operator[](Position& position);
};


class Lattice1D_periodic: public Lattice1D {
  public:
    Cell* operator[](Position& position);
};



#endif // DTYPES_H