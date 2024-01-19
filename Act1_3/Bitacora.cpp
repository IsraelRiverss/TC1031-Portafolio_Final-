#include "Bitacora.h"

Bitacora::Bitacora() {//Constructor
  listaRegistros.clear();
}

Bitacora::~Bitacora() {}//Destructor

void Bitacora::leerArchivo(std::string filePath) {//Método para leer el archivo y guardar los datos en un vector de objetos de la clase Registro
  std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;//Declaración de variables para almacenar los datos de cada línea del archivo
  std::ifstream archivo(filePath);//Se abre el archivo en modo lectura
  if (!archivo.good()) {//Se verifica si el archivo se pudo abrir correctamente
    archivo.close();
    throw std::invalid_argument("File not found");//Se lanza una excepción si el archivo no se pudo abrir
  } 
  else {
    while (!archivo.eof()) {//Se lee el archivo línea por línea
      std::getline(archivo, mes, ' ');
      if (mes.length() > 0) {//Se verifica si la línea tiene contenido
        std::getline(archivo, dia, ' ');
        std::getline(archivo, horas, ':');
        std::getline(archivo, minutos, ':');
        std::getline(archivo, segundos, ' ');
        std::getline(archivo, ip, ':');
        std::getline(archivo, puerto, ' ');
        std::getline(archivo, falla);
        Registro nuevoRegistro(mes, dia, horas, minutos, segundos, ip, puerto, falla);//Se crea un objeto de la clase Registro con los datos de la línea
        listaRegistros.push_back(nuevoRegistro);//Se agrega el objeto Registro al vector listaRegistros
      }
    }
    archivo.close();
  }
}

//Complejidad O(n)
void Bitacora::selectionSort(int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      compara++;
      if (listaRegistros[j] < listaRegistros[minIndex])
        minIndex = j;
    }
    std::swap(listaRegistros[minIndex], listaRegistros[i]);
    swap++;
  }
}

// Complejidad: O(n)
int Bitacora::partition(int low, int high, unsigned int &compara,unsigned int &swap) {
  Registro pivot = listaRegistros[high];
  int i = low - 1;
  for (int j = low; j <= high; j++) {
    compara++;
    if (listaRegistros[j] < pivot) {
      i++;
      std::swap(listaRegistros[i], listaRegistros[j]);
      swap++;
    }
  }
  std::swap(listaRegistros[i + 1], listaRegistros[high]);
  swap++;
  return i + 1;
}

//Complejidad: O(n^2)
void Bitacora::quickSort(int low, int high, unsigned int &compara, unsigned int &swap) {
  if (low < high) {
    // encontrar la particion del vector
    int pi = partition(low, high, compara, swap);
    // ordenar la particion izquierda y derecha
    quickSort(low, pi - 1, compara, swap);
    quickSort(pi + 1, high, compara, swap);
  }
}

void Bitacora::doQuickSort() {
  unsigned int comparaQuicksort;
  unsigned int swapQuicksort;

  quickSort(0, listaRegistros.size()-1, comparaQuicksort, swapQuicksort);

  std::cout << "Quicksort - Comparaciones: " << comparaQuicksort << ", Swaps: " << swapQuicksort << std::endl;
}

//Complejidad: O(n)
int Bitacora::busquedaBinaria(Registro key, int &compara) {
  int l = 0;
  int r = listaRegistros.size() - 1;
  compara = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    compara++;
    if (key == listaRegistros[m])
      return m;
    else if (key < listaRegistros[m])
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

//Complejidad: O(n)
void Bitacora::imprimirBitacora() const {//Muestra la bitacora
  for (int i = 0; i < (int)listaRegistros.size(); i++) {//Recorre la bitacora
    std::cout << listaRegistros[i].getAll() << std::endl;//Imprime la bitacora
  }
}

void Bitacora::imprimirBitacoraOrdenada(std::string filePath) const {//Método para imprimir la bitácora ordenada en un archivo nuevo
  std::ofstream archivo(filePath);//Se crea un archivo nuevo
  for (int i = 0; i < (int)listaRegistros.size(); i++) {//Se recorre la bitácora
    archivo << listaRegistros[i].getAll() << std::endl;//Se imprime en el archivo nuevo
  }
  archivo.close();
}

std::vector<Registro> Bitacora::obtenerRegistrosEntreFechas(const Registro& inicio, const Registro& fin) {//Método para obtener los registros entre dos fechas
  std::vector<Registro> registrosFiltrados;//Vector para almacenar los registros filtrados
  for (const auto& registro : listaRegistros) {//Recorremos la lista de registros
    if (registro >= inicio && registro <= fin) {//Comparamos cada registro con las fechas de inicio y fin
      registrosFiltrados.push_back(registro);//Agregamos el registro al vector de registros filtrados
    }
  }
  return registrosFiltrados;
}

Registro Bitacora::convertirEntradaFecha(const std::string& entrada) {//Método para convertir la entrada de fecha en un objeto de tipo Registro
    std::string mesI, diaI, horaI, minI, segundoI;//Se crean las variables para almacenar los valores de la entrada
    std::istringstream qwq(entrada);//Se crea un objeto de tipo istringstream para leer la entrada

    std::getline(qwq, mesI, ' ');
    std::getline(qwq, diaI, ' ');
    std::getline(qwq, horaI, ':');
    std::getline(qwq, minI, ':');
    std::getline(qwq, segundoI);

    return Registro(mesI, diaI, horaI, minI, segundoI, "", "", "");
}