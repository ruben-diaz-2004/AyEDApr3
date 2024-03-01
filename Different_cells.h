/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef DIFFERENT_CELLS_H
#define DIFFERENT_CELLS_H

#include <iostream>
#include <vector>
#include <string>

#include "position.h"
#include <stdarg.h> // Para el uso de listas de parámetros variable [6]
#include "cell.h"
#include "CellLife.h"
#include "CellAce.h"


class CellACE110: public CellACE {
  public:
  CellACE110(const Position&, const State&) : CellACE(position_, state_) {}
  void nextState(const Lattice&);
  void display(std::ostream&);
};


class CellACE30: public CellACE {
  public:
  CellACE30(const Position&, const State&) : CellACE(position_, state_) {}
  void nextState(const Lattice&);
  void display(std::ostream&);
};



class CellLife23_3: public CellLife {
  public:
  CellLife23_3(const Position&, const State&) : CellLife(position_, state_) {}
  void nextState(const Lattice&);
  void display(std::ostream&);
};


class CellLife51_346: public CellLife {
  public:
  CellLife51_346(const Position&, const State&) : CellLife(position_, state_) {}
  void nextState(const Lattice&);
  void display(std::ostream&);
};









#endif // DIFFERENT_CELLS_H