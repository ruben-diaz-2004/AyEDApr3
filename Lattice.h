/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#ifndef LATTICE_H
#define LATTICE_H

#include <iostream>
#include "position.h"


class Cell;

class Lattice {
  public:
    virtual Cell& operator[](Position&) const = 0;
    virtual void nextGeneration() = 0;
    virtual std::size_t Population() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);

  protected:
    virtual std::ostream& display(std::ostream& os) const = 0;
};




#endif // LATTICE_H