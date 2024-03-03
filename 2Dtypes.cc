/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#include "2Dtypes.h"


Cell* Lattice2D_reflective::operator[](Position& position) const {
  int x = position[0];
  int y = position[1];

  if ( x < 0 || y < 0 || x > lattice_[0].size()-1 || y > lattice_.size()-1) {
    if (x < 0) {
      x = 0;
      if (y < 0) {
        y = 0;
      } else if (y > lattice_.size()-1) {
        y = lattice_.size()-1;
      }
    }
    if (x > lattice_[0].size()-1) {
      x = lattice_[0].size()-1;
      if (y < 0) {
        y = 0;
      } else if (y > lattice_.size()-1) {
        y = lattice_.size()-1;
      }
    }
    if (y < 0) {
      y = 0;
      if (x < 0) {
        x = 0;
      } else if (x > lattice_[0].size()-1) {
        x = lattice_[0].size()-1;
      }
    }
    if (y > lattice_.size()-1) {
      y = lattice_.size()-1;
      if (x < 0) {
        x = 0;
      } else if (x > lattice_[0].size()-1) {
        x = lattice_[0].size()-1;
      }
    }
  }
  return lattice_[y][x];
}


