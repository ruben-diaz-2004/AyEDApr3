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
#include "position.h"



typedef char State;

class Lattice;

class Cell {
  public:
  Cell(Position& position, const State& state) : position_(position), state_(state) {}
  State getState() const { return state_; }
  void setState(State state) { state_ = state; }
  virtual void nextState(const Lattice& reticulo) = 0;
  virtual void updateState() { state_ = next_state_; }
  friend std::ostream& operator<<(std::ostream& os, Cell& cell);

  protected:
  virtual void display(std::ostream& os) = 0;
  Position& position_;
  State state_;
  State next_state_;
};


std::ostream& operator<<(std::ostream& os, Cell& cell) {
  cell.display(os);
  return os;
}




#endif