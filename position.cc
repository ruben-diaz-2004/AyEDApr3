/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#include "Position.h"



template <int DIM, class Coordinate_t>
Coor_t PositionDim<DIM, Coordinate_t>::operator[](unsigned int i) const {
  return coordinates_[i];
}