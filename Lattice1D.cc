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

Lattice1D::Lattice1D(const int& size, FactoryCell& factory) {
  size_ = size;
  lattice_.resize(size);
  Position* pos;
  for (int i = 0; i < size; i++) {
    pos = new PositionDim<1>(1, i);
    lattice_[i] = factory.createCell(*pos, '0');
  }
}


Lattice1D::Lattice1D(std::fstream& file, FactoryCell& factory) {
  int dimension;
  file >> dimension;
  std::cout << "Dimension: " << dimension << std::endl;

  file >> size_;
  lattice_.resize(size_);
  Position* pos;
  char state;

  for (int i = 0; i < size_; i++) {
    pos = new PositionDim<1>(1, i);
    file >> state;
    lattice_[i] = factory.createCell(*pos, state);
  }
}



Lattice1D::~Lattice1D() {
  for (int i = 0; i < size_; i++) {
    delete lattice_[i];
  }
}

void Lattice1D::nextGeneration() {
  for (int i = 0; i < size_; i++) {
    lattice_[i]->nextState(*this);
  }
  for (int i = 0; i < size_; i++) {
    lattice_[i]->updateState();
  }
}

std::size_t Lattice1D::Population() const {
  std::size_t population = 0;
  for (int i = 0; i < size_; i++) {
    if (lattice_[i]->getState() == '1') {
      population++;
    }
  }
  return population;
}


std::ostream& Lattice1D::display(std::ostream& os) const {
  for (int i = 0; i < size_; i++) {
    os << *lattice_[i];
  }
  os << std::endl;
  return os;
}
