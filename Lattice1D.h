/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#ifndef LATTICE1D_H
#define LATTICE1D_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Lattice.h"
#include "FactoryCell.h"

class Lattice1D: public Lattice {
  public:
    Lattice1D(std::fstream& file, FactoryCell& factory);
    Lattice1D(const int& size, FactoryCell& factory);
    virtual ~Lattice1D();
    void nextGeneration();
    std::size_t Population() const;
  protected:
    std::ostream& display(std::ostream& os) const;
    std::vector<Cell*> lattice_;
    int size_;
};


#endif // LATTICE1D_H