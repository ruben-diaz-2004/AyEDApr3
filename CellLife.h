/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef CELLLIFE_H
#define CELLLIFE_H

#include <iostream>
#include "cell.h"



class CellLife: public Cell {
  public:
  CellLife(const Position&, const State&);
  void nextState(const Lattice&);
  void updateState();
  void display(std::ostream&);
};





#endif // CELLLIFE_H