/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "position.h"
#include <stdarg.h> // Para el uso de listas de parámetros variable [6]


typedef char State;

class Lattice;

class Cell {
  public:
  Cell(Position& position, const State& state) : position_(position), state_(state) {}
  State getState() const { return state_; }
  void setState(State state) { state_ = state; }
  virtual void nextState(const Lattice&) = 0;
  virtual void updateState() { state_ = next_state_; }
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

  protected:
  virtual void display(std::ostream&) = 0;
  Position& position_;
  State state_;
  State next_state_;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  cell.display(os);
  return os;
}









#endif // CELL_H