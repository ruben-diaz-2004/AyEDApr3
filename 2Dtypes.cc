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
#include "my_vector.h"


/**
 * Operador de indexación para obtener una celda del retículo
*/
Cell& Lattice2D_reflective::operator[](Position& position) const {
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
  return *lattice_[y][x];
}



/**
 * Operador de indexación para obtener una celda del retículo
*/
Cell& Lattice2D_NoBorder::operator[](Position& position) const {
  int x = position[0];
  int y = position[1];

  if ( x < lattice_[0].negative_index()+1 || y < lattice_.negative_index()+1 ) {
    return *lattice_[0][0];
  }
  if ( x > (lattice_[0].size()+lattice_[0].negative_index()) && x >= 0) {
    return *lattice_[0][0];
  }
  if ( y > (lattice_.size()+lattice_.negative_index()) && y >= 0) {
    return *lattice_[0][0];
  }
  return *lattice_[y-(lattice_.negative_index()+1)][x+(-(lattice_[0].negative_index()+1))];
}



/**
 * Método para calcular la siguiente generación del retículo
*/
void Lattice2D_NoBorder::nextGeneration() {
  CheckBorder();

  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[0].size(); j++) {
      lattice_[i][j]->nextState(*this);
    }
  }

  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[0].size(); j++) {
      lattice_[i][j]->updateState();
    }
  }

  CheckBorder();
}



/**
 * Método para comprobar si hay que incrementar el tamaño del retículo
*/
void Lattice2D_NoBorder::CheckBorder() {
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[0].size(); j++) {
      if (i == 0 && lattice_[i][j]->getState() == '1') {
        IncrementSize('N');
      }
      if (i == lattice_.size()-1 && lattice_[i][j]->getState() == '1') {
        IncrementSize('S');
      }
      if (j == 0 && lattice_[i][j]->getState() == '1') {
        IncrementSize('W');
      }
      if (j == lattice_[0].size()-1 && lattice_[i][j]->getState() == '1') {
        IncrementSize('E');
      }
    }
  }
}



/**
 * Método para incrementar el tamaño del retículo
*/
void Lattice2D_NoBorder::IncrementSize(char direction) {
  Position* new_position;
  my_vector<Cell*> new_row;
  switch (direction) {
    case 'E':
      for (int i{0}; i < lattice_.size(); ++i) {
        new_position = new PositionDim<2>(2, i+(lattice_.negative_index()+1), lattice_[i].size()-(-(lattice_[i].negative_index()+1)));
        lattice_[i].push_back(factory_->createCell(*new_position, '0'));
      }
      columns_++;
      break;
    case 'W':
      for (int i{0}; i < lattice_.size(); ++i) {
        new_position = new PositionDim<2>(2, i+(lattice_.negative_index()+1), lattice_[i].negative_index());
        lattice_[i].push_front(factory_->createCell(*new_position, '0'));
        lattice_[i].DecrementNegativeIndex();
      }
      columns_++;
      break;
    case 'N':
      new_row.resize(lattice_[0].size());
      new_row.SetNegativeIndex(lattice_[0].negative_index());
      for (int i{0}; i < lattice_[0].size(); ++i) {
        new_position = new PositionDim<2>(2, lattice_.negative_index(), i+(lattice_[0].negative_index()+1));
        new_row[i] = factory_->createCell(*new_position, '0');
      }
      lattice_.push_front(new_row);
      lattice_.DecrementNegativeIndex();
      rows_++;
      break;
    case 'S':
      new_row.resize(lattice_[0].size());
      new_row.SetNegativeIndex(lattice_[0].negative_index());
      for (int i{0}; i < lattice_[0].size(); ++i) {
        new_position = new PositionDim<2>(2, lattice_.size()-(-(lattice_.negative_index()+1)), i+(lattice_[0].negative_index()+1));
        new_row[i] = factory_->createCell(*new_position, '0');
      }
      lattice_.push_back(new_row);
      rows_++;
      break;
  }
}