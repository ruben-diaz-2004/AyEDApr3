/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef LATTICE2D_H
#define LATTICE2D_H


#include <iostream>

#include "Lattice.h"
#include "my_vector.h"
#include "FactoryCell.h"

class Lattice2D: public Lattice {
  public:
    Lattice2D(std::fstream& file, FactoryCell& factory);
    Lattice2D(const int& rows, const int& columns, FactoryCell& factory);
    virtual ~Lattice2D();
    virtual void nextGeneration();
    std::size_t Population() const;
    std::ostream& display(std::ostream& os) const;

  protected:
    my_vector<my_vector<Cell*>> lattice_;
};


#endif // LATTICE2D_H