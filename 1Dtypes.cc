/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#include "1Dtypes.h"



Lattice1D_open::Lattice1D_open(const int& size, FactoryCell& factory, bool open_type) : Lattice1D(size, factory), open_type_(open_type) {
  Position* position;
  if (open_type_ == 0) {
    position = new PositionDim<1>(1, -1);
    border_ = factory.createCell(*position, '0');
  } else {
    position = new PositionDim<1>(1, -1);
    border_ = factory.createCell(*position, '1');
  }
}


Cell* Lattice1D_open::operator[](const Position& position) const {
  int pos = position[0];
  if (pos < 0 || pos >= size_) {
    return border_;
  } else {
    return lattice_[pos];
  }
}


Cell* Lattice1D_periodic::operator[](const Position& position) const {
  int pos = position[0];
  if (pos < 0) {
    pos = size_-1;
  } else if (pos >= size_) {
    pos = 0;
  }
  return lattice_[pos];
}