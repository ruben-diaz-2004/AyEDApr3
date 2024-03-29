/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef CELLACE_H
#define CELLACE_H


#include "Cell.h"


class CellACE: public Cell {
  public:
  CellACE(Position& position, const State& state) : Cell(position, state) {}
};






#endif // CELLACE_H