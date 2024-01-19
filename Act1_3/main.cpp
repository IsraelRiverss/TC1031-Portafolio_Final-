// =========================================================
// File: main.cpp
// Authors
//   - Fernando Israel Rios Garcia-A01709118
//   - Daniel Aguilar Darío - A01750975
//   - Luis Daniel Garcia Espinosa - A01643058
// Created Date: Noviembre 12th, 2024
// Modification Date: Noviembre 17th, 2024
// =========================================================
/**
 * Ejemplo que implementa objetos de la clase Registro
 * que contienen una fecha-hora convertida a Linux timestamp
 * para realizar comparaciones (sobrecarga de operadores)
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include "Bitacora.h"
#include "Registro.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  Bitacora bitacora;//se crea un objeto de la clase Bitacora
  bitacora.leerArchivo("bitacora.txt");//Lee el archivo y lo guarda en un vector
  bitacora.doQuickSort();//Ordena el vector
  bitacora.imprimirBitacora();//Imprime el vector ordenado
  bitacora.imprimirBitacoraOrdenada("bitacora_ordenada.txt");//Imprime el vector ordenado en un archivo

  string fechaInicio, fechaFin;//Se crean las variables para las fechas de inicio y fin
  cout << "Introduce la fecha de inicio (mes dia hora:minutos:segundos): ";
  getline(cin, fechaInicio);//Se lee la fecha de inicio
  cout << "Introduce la fecha de fin (mes dia hora:minutos:segundos): ";
  getline(cin, fechaFin);//Se lee la fecha de fin

  try {//Se intenta buscar las fechas en el vector
      Registro inicio = bitacora.convertirEntradaFecha(fechaInicio);//Se convierte la fecha de inicio en un objeto de la clase Registro
      Registro fin = bitacora.convertirEntradaFecha(fechaFin);//Se convierte la fecha de fin en un objeto de la clase Registro
      auto registrosFiltrados = bitacora.obtenerRegistrosEntreFechas(inicio, fin);//Se obtienen los registros entre las fechas de inicio y fin

      for (const auto &registro : registrosFiltrados) {//Se imprimen los registros filtrados
          cout << registro.getAll() << endl;
      }
  } catch (const invalid_argument &e) {//Si las fechas no se encuentran en el vector, se muestra un mensaje de error
      cerr << "Error: " << e.what() << endl;
  }

  return 0;
  }