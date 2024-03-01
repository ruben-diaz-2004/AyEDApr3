/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#include <iostream>
#include <vector>
#include <string>

#include "Cell.h"
#include "CellAce.h"
#include "CellLife.h"
#include "Different_cells.h"

void CellACE110::display(std::ostream& os) {
  os << "CellACE110: " << position_ << " " << state_ << " " << next_state_ << std::endl;
}

void CellACE110::nextState(const Lattice& lattice) {
  const int C = state_;
  int next_state{0};

  int L = reticulo[position_ - 1].GetState();
  int R = reticulo[position_ + 1].GetState();  

  next_state = (C + R + C * R + L * C * R) % 2;
  next_state_ = next_state;
}



void CellACE30::nextState(const Lattice& lattice) {
  const int C = state_;
  int next_state{0};

  int L = reticulo[position_ - 1].GetState();
  int R = reticulo[position_ + 1].GetState();  

  next_state = (L + C + R + C * R) % 2;
  next_state_ = next_state;
}



void CellLife23_3::nextState(const Lattice& lattice) {
  int alive_count{0};
  State next_state;

  const State C = state_;
  State E = reticulo.GetCell(Position(position_.first+1, position_.second)).GetState();
  if (E == State::Vivo) alive_count++;
  State W = reticulo.GetCell(Position(position_.first-1, position_.second)).GetState();
  if (W == State::Vivo) alive_count++;
  State N = reticulo.GetCell(Position(position_.first, position_.second-1)).GetState();
  if (N == State::Vivo) alive_count++;
  State S = reticulo.GetCell(Position(position_.first, position_.second+1)).GetState();
  if (S == State::Vivo) alive_count++;
  State NE = reticulo.GetCell(Position(position_.first+1, position_.second-1)).GetState();
  if (NE == State::Vivo) alive_count++;
  State NW = reticulo.GetCell(Position(position_.first-1, position_.second-1)).GetState();
  if (NW == State::Vivo) alive_count++;
  State SE = reticulo.GetCell(Position(position_.first+1, position_.second+1)).GetState();
  if (SE == State::Vivo) alive_count++;
  State SW = reticulo.GetCell(Position(position_.first-1, position_.second+1)).GetState();
  if (SW == State::Vivo) alive_count++;

  if (C == State::Muerto) {
    if (alive_count == 3) {
      next_state = State::Vivo;
    }
    else {
      next_state = State::Muerto;
    }
  } else {
    if (alive_count < 2 || alive_count > 3) {
      next_state = State::Muerto;
    } else {
      next_state = State::Vivo;
    }
  }  
  next_state_ = next_state;
}



