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
    Lattice1D_open(const int& size, FactoryCell& factory, bool open_type);
    Lattice1D_open(std::fstream& file, FactoryCell& factory, bool open_type);
    Cell* operator[](Position& position) const;
  
  private:
    bool open_type_; // 0: open, 1: periodic
    Cell* border_;
};


class Lattice1D_periodic: public Lattice1D {
  public:
    Lattice1D_periodic(const int& size, FactoryCell& factory) : Lattice1D(size, factory) {}
    Lattice1D_periodic(std::fstream& file, FactoryCell& factory) : Lattice1D(file, factory) {}
    Cell* operator[](Position& position) const;
};



#endif // DTYPES_H