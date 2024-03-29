/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#include "Lattice.h"


/**
 * Operador de inserción en flujo para mostrar un retículo
*/
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  lattice.display(os);
  return os;
}


/**
 * Operador de inserción en flujo para mostrar un retículo en un fichero
*/
std::ofstream& operator<<(std::ofstream& os, const Lattice& lattice) {
  lattice.displayfile(os);
  return os;
}