/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#include "Lifetypes.h"
#include "2Dtypes.h"


void CellLife23_3::updateState() {
  state_ = next_state_;
}

void CellLife23_3::display(std::ostream& os) {
  if (state_ == '0') {
    os << "-";
  } else {
    os << "X";
  }
}


void CellLife23_3::nextState(const Lattice& reticulo) {
  int alive_neighbours{0};
  State next_state;

  const State C = state_;

  int position_x = position_[0];
  int position_y = position_[1];

  Position* aux_pos;

  for (int i = position_x - 1; i <= position_x + 1; i++) {
    for (int j = position_y - 1; j <= position_y + 1; j++) {
      aux_pos = new PositionDim<2>(2, i, j);
      alive_neighbours += reticulo[*aux_pos].getState();
    }
  }
  alive_neighbours -= C;

  if (C == '0') {
    if (alive_neighbours == 3) {
      next_state = '1';
    } else {
      next_state = '0';
    }
  } else {
    if (alive_neighbours == 2 || alive_neighbours == 3) {
      next_state = '1';
    } else {
      next_state = '0';
    }
  }
  next_state_ = next_state;
}


void CellLife51_346::updateState() {
  state_ = next_state_;
}


void CellLife51_346::display(std::ostream& os) {
  if (state_ == '0') {
    os << "-";
  } else {
    os << "X";
  }
}



void CellLife51_346::nextState(const Lattice& reticulo) {
  int alive_neighbours{0};
  State next_state;

  const State C = state_;

  int position_x = position_[0];
  int position_y = position_[1];

  Position* aux_pos;

  for (int i = position_x - 1; i <= position_x + 1; i++) {
    for (int j = position_y - 1; j <= position_y + 1; j++) {
      aux_pos = new PositionDim<2>(2, i, j);
      alive_neighbours += reticulo[*aux_pos].getState();
    }
  }
  alive_neighbours -= C;

  if (C == '0') {
    if (alive_neighbours == 3 || alive_neighbours == 4 || alive_neighbours == 6) {
      next_state = '1';
    } else {
      next_state = '0';
    }
  } else {
    if (alive_neighbours == 5 || alive_neighbours == 1) {
      next_state = '1';
    } else {
      next_state = '0';
    }
  }
  next_state_ = next_state;
}