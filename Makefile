# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# 
# @author Rubén Díaz Marrero
# @date 18/12/2023
# 

CXX = g++
CXXFLAGS = -std=c++17 -g 



all: AutomataGeneral

AutomataGeneral: juegodelavida.cc 1Dtypes.cc 2Dtypes.cc Acetypes.cc Lattice1D.cc Lattice2D.cc Lifetypes.cc Cell.cc Lattice.cc
		$(CXX) $(CXXFLAGS) -o $@ $^
	

	
.PHONY: all clean
clean:
		rm -f AutomataGeneral