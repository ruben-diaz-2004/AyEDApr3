/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#ifndef FACTORYTYPES_H
#define FACTORYTYPES_H

#include "Cell.h"
#include "CellAce.h"
#include "Acetypes.h"
#include "Lifetypes.h"
#include "FactoryCell.h"



class FactoryCellACE110: public FactoryCell {
  public:
  FactoryCellACE110() {}
  Cell* createCell(Position& position, const State& state) {
    return new CellACE110(position, state);
  }
};


class FactoryCellACE30: public FactoryCell {
  public:
  Cell* createCell(Position& position, const State& state) {
    return new CellACE30(position, state);
  }
};


class FactoryCellLife23_3: public FactoryCell {
  public:
  Cell* createCell(Position& position, const State& state) {
    return new CellLife23_3(position, state);
  }
};


class FactoryCellLife51_346: public FactoryCell {
  public:
  Cell* createCell(Position& position, const State& state) {
    return new CellLife51_346(position, state);
  }
};





#endif