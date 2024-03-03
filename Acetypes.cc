/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#include "Acetypes.h"
#include "1Dtypes.h"

void CellACE110::updateState() {
  state_ = next_state_;
}

void CellACE110::display(std::ostream& os) {
  if (state_ == '0') {
    os << "-";
  } else {
    os << "X";
  }
}

void CellACE110::nextState(const Lattice& reticulo) {
  const State C = state_;
  State next_state{0};

  int position = position_[0];

  Position* Left = new PositionDim<1>(1, position - 1);
  Position* Right = new PositionDim<1>(1, position + 1);

  State L = reticulo[*Left].getState();
  State R = reticulo[*Right].getState();

  next_state = (C + R + C * R + L * C * R) % 2;
  if (next_state == 0) {
    next_state_ = '0';
  } else {
    next_state_ = '1';
  }
}



void CellACE30::updateState() {
  state_ = next_state_;
}

void CellACE30::display(std::ostream& os) {
  if (state_ == '0') {
    os << "-";
  } else {
    os << "X";
  }
}


void CellACE30::nextState(const Lattice& reticulo) {
  const State C = state_;
  State next_state{0};

  int position = position_[0];

  Position* Left = new PositionDim<1>(1, position - 1);
  Position* Right = new PositionDim<1>(1, position + 1);

  State L = reticulo[*Left].getState();
  State R = reticulo[*Right].getState();

  next_state = (L + C + R + C * R) % 2;
  if (next_state == 0) {
    next_state_ = '0';
  } else {
    next_state_ = '1';
  }
}
