#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Registro.h"

class Bitacora {
private:
  std::vector<Registro> listaRegistros;//vector de objetos de la clase Registro
  int partition(int low, int high, unsigned int &compara, unsigned int &swap);//Metodo de particion
  void quickSort(int low, int high, unsigned int &compara, unsigned int &swap);//Metodo de ordenamiento QuickSort

public:
  Bitacora();//Constructor
  ~Bitacora();//Destructor
  std::vector<Registro> obtenerRegistrosEntreFechas(const Registro &inicio, const Registro &fin);//Metodo para obtener los registros entre dos fechas
  void leerArchivo(std::string filePath);//Metodo para leer el archivo
  void selectionSort(int n, unsigned int &compara, unsigned int &swap); //Metodo para ordenar los registros por fecha
  void doQuickSort();//Metodo para ordenar los registros por fecha
  int busquedaBinaria(Registro key, int &compara);//Metodo para buscar un registro por fecha
  void imprimirBitacora() const;//Metodo para imprimir la bitacora
  void imprimirBitacoraOrdenada(std::string filePath) const;//Metodo para imprimir la bitacora ordenada
  Registro convertirEntradaFecha(const std::string& entrada);//Metodo para convertir una fecha en formato de entrada a un objeto de la clase Registro
};

#endif // _BITACORA_H_