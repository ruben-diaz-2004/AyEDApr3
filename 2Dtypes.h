/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef TYPES_H
#define TYPES_H


#include <iostream>

#include "Lattice2D.h"


class Lattice2D_reflective: public Lattice2D {
  public:
    Lattice2D_reflective(std::fstream& file, FactoryCell& factory) : Lattice2D(file, factory) {}
    Lattice2D_reflective(const int& rows, const int& columns, FactoryCell& factory) : Lattice2D(rows, columns, factory) {}
    Cell* operator[](Position& position) const;
  private:
    FactoryCell* factory_;
};


class Lattice2D_NoBorder: public Lattice2D {
  public:
    Cell* operator[](Position& position);
    void nextGeneration();
  private:
    FactoryCell* factory_;
};


#endif // TYPES_H