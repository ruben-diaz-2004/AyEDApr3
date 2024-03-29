/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef FACTORYCELL_H
#define FACTORYCELL_H


#include "Cell.h"


class FactoryCell {
  public:
  FactoryCell() {}
  virtual Cell* createCell(Position& position, const State& state) = 0;
};




#endif // FACTORYCELL_H