/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#include "Cell.h"




/**
 * Operador de inserción en flujo para mostrar una célula
*/
std::ostream& operator<<(std::ostream& os, Cell& cell) {
  cell.display(os);
  return os;
}