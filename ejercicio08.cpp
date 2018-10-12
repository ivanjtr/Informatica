// Autor: Ivan Jesus Torres Rodriguez
// Fecha: 2018-10-9

#include <vector> // para poder usar los vectores
#include <iostream> // para usar cout y cerr
#include <fstream> //Para acceso a ficheros
#include <string> //Para usar el tipo string
#include <iomanip> //Para convertir en hexadecimal

double numeroBitsAUno(int entero){
  int bitsAUno = 0;
  std::vector<int> numeroBinario;
  int i = 0;
  int temp = 0;
  while(entero != 0){ //Convertimos entero a decimal
    temp = (entero % 2 == 0) ? 0 : 1;
    entero /= 2;
    numeroBinario.push_back(temp);
    i++;
  }
  for (std::size_t j =0; j < numeroBinario.size(); j++) {
    if(numeroBinario[j] == 1)//Si encontramos un bit a 1 contamos
      bitsAUno++;
  }
  return bitsAUno; 
}

int main(){
  int entero=4;//Inicializamos entero en un valor distinto a 0
  while(entero != 0){
  std::cerr << "Introduzca un numero: " << std::endl;
  std::cin >> entero;//Guardamos el numero introducido
  if(std::cin.good()) {
    std::cin.ignore(); //Quitamos salto de línea
    std::cerr << entero << std::endl;
  }
  else if (std::cin.fail()) { //Mala conversión
    std::cin.clear();
    std::cin.ignore(1000,'\n'); //Descartamos hasta \n
    std::cerr << "Error" << std::endl;
    return 1;
  } //Caso contrario es EOF
  double cantidadBitsAUno = numeroBitsAUno(entero);
  std::cerr << "Numero de bits a uno: " << std::endl;
  std::cout << cantidadBitsAUno  << " ";
  std::cout << "0x" << std::hex << entero
    << std::endl;
    //Mostramos numero en hexadecimal
  cantidadBitsAUno = 0;
  }
  return 0;
}
