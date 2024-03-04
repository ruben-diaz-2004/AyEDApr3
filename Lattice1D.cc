/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#include "Lattice1D.h"
#include "position.h"
#include "FactoryCell.h"


/**
 * Constructor de la clase Lattice1D
*/
Lattice1D::Lattice1D(const int& size, FactoryCell& factory) {
  size_ = size;
  lattice_.resize(size);
  Position* pos;
  for (int i = 0; i < size; i++) {
    pos = new PositionDim<1>(1, i);
    lattice_[i] = factory.createCell(*pos, '0');
  }
}


/**
 * Constructor de la clase Lattice1D mediante fichero
*/
Lattice1D::Lattice1D(std::fstream& file, FactoryCell& factory) {
  char dimension;
  file >> dimension;
  std::cout << "Dimension: " << dimension << std::endl;

  file >> size_;
  lattice_.resize(size_);
  Position* pos;
  State state;

  std::string line;
  std::getline(file, line);
  std::getline(file, line);
  for (int i = 0; i < size_; i++) {
    pos = new PositionDim<1>(1, i);
    state = line[i];
    lattice_[i] = factory.createCell(*pos, state);
  }
}



/**
 * Destructor de la clase Lattice1D
*/
Lattice1D::~Lattice1D() {
  std::cout << "Destructor" << std::endl;
  for (int i = 0; i < size_; i++) {
    delete lattice_[i];
  }
}


/**
 * Método que calcula la siguiente generación del retículo
*/
void Lattice1D::nextGeneration() {
  for (int i = 0; i < size_; i++) {
    lattice_[i]->nextState(*this);
  }
  for (int i = 0; i < size_; i++) {
    lattice_[i]->updateState();
  }
}



/**
 * Método que muestra la población del retículo
*/
std::size_t Lattice1D::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < size_; i++) {
    if (lattice_[i]->getState() == '1') {
      population++;
    }
  }
  return population;
}


/**
 * Método que muestra el retículo
*/
std::ostream& Lattice1D::display(std::ostream& os) const {
  for (int i = 0; i < size_; i++) {
    os << *lattice_[i];
  }
  os << std::endl;
  return os;
}


/**
 * Método que muestra el retículo en un fichero
*/
std::ofstream& Lattice1D::displayfile(std::ofstream& os) const {
  os << 1 << std::endl;
  os << size_ << std::endl;
  for (int i = 0; i < size_; i++) {
    os << *lattice_[i];
  }
  os << std::endl;
  return os;
}
