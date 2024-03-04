/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#include "Lattice2D.h"
#include "FactoryCell.h"
#include "Cell.h"
#include "position.h"


/**
 * Constructor de un retículo a partir de un fichero
*/
Lattice2D::Lattice2D(std::fstream& file, FactoryCell& factory) {
    // line 1: dimension (must be 2)
    // line 2: number of rows
    // line 3: number of columns
  int dimension;
  file >> dimension;
  if (dimension != 2) {
    throw std::invalid_argument("Dimension must be 2");
  }
  int rows;
  file >> rows;
  int columns;
  file >> columns;
  lattice_.resize(rows);
  for (int i = 0; i < rows; i++) {
    lattice_[i].resize(columns);
  }

  State state;
  std::string line;
  std::getline(file, line);
  for (int i = 0; i < rows; i++) {
    std::getline(file, line);
    for (int j = 0; j < columns; j++) {
      state = line[j];
      Position* position = new PositionDim<2>(2, i, j);
      lattice_[i][j] = factory.createCell(*position, state);
    }
  }
  rows_ = rows;
  columns_ = columns;
}


/**
 * Constructor de un retículo a partir de un número de filas y columnas
*/
Lattice2D::Lattice2D(const int& rows, const int& columns, FactoryCell& factory) {
  lattice_.resize(rows);
  for (int i = 0; i < rows; i++) {
    lattice_[i].resize(columns);
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      Position* position = new PositionDim<2>(2, i, j);
      lattice_[i][j] = factory.createCell(*position, '0');
    }
  }
  rows_ = rows;
  columns_ = columns;
}



/**
 * Destructor de la clase Lattice2D
*/
Lattice2D::~Lattice2D() {
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      delete lattice_[i][j];
    }
  }
}


/**
 * Operador de acceso a la celda de la posición dada
*/
void Lattice2D::nextGeneration() {
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      lattice_[i][j]->nextState(*this);
    }
  }
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      lattice_[i][j]->updateState();
    }
  }
}


/**
 * Método que devuelve el número de celdas vivas en el retículo
*/
std::size_t Lattice2D::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      if (lattice_[i][j]->getState() == '1') {
        population++;
      }
    }
  }
  return population;
}


/**
 * Método que muestra el retículo
*/
std::ostream& Lattice2D::display(std::ostream& os) const {
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      os << *lattice_[i][j];
    }
    os << std::endl;
  }
  return os;
}


/**
 * Método que muestra el retículo en un fichero
*/
std::ofstream& Lattice2D::displayfile(std::ofstream& os) const {
  os << 2 << std::endl;
  os << rows_ << std::endl;
  os << columns_ << std::endl;
  for (int i = 0; i < lattice_.size(); i++) {
    for (int j = 0; j < lattice_[i].size(); j++) {
      os << *lattice_[i][j];
    }
    os << std::endl;
  }
  return os;
}