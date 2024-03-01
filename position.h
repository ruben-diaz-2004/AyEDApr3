/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef POSITION_H
#define POSITION_H

#include <stdarg.h> // Para el uso de listas de parámetros variable [6]


typedef int Coor_t;
class Position {
public:
// Operador de acceso a la i-ésima coordenada
virtual Coor_t operator[](unsigned int) const = 0;
};


// Las clases derivadas, que representan una posición en la dimensión indicada, se
// generan a partir de la siguiente plantilla. Se incluye el código del constructor, que
// utiliza una lista de parámetros variable definida en <stdarg.h> [6].
template <int Dim=2, class Coordinate_t=int>
class PositionDim: public Position {
  public:
  // Constructor con lista variable de parámetros
  PositionDim(int sz, ...) {
    va_list vl;
    va_start(vl, sz);
    for(int d=0; d<Dim; d++) {
      Coordinates[d] = va_arg(vl, Coor_t);
    }
    va_end(vl);
  }
  Coor_t operator[](unsigned int) const;
  
  private:
  Coor_t Coordinates[Dim];
};







#endif // POSITION_H