// Autor: Ivan Jesus Torres Rodriguez
// Fecha: 2018-10-9

#include <vector> // para poder usar los vectores
#include <iostream> // para usar cout y cerr
#include <fstream> //Para acceso a ficheros
#include <string> //Para usar el tipo string
#include <iomanip> //Para convertir en hexadecimal

std::vector<int> numBinario(unsigned int entero){
  std::vector<int> numeroBinario;
  int i = 0;
  int temp = 0;
  numeroBinario.push_back(0);
  if(entero == 0){
    numeroBinario.push_back(0);
  }
  while(entero > 0){ //Convertimos entero a decimal
    temp = (entero % 2 == 0) ? 0 : 1;
    entero /= 2;
    numeroBinario.push_back(temp);
    i++;
  }
  return numeroBinario; 
}

int main(){
  unsigned int entero=4;//Inicializamos entero en un valor distinto a 0
  while(entero != 0){
  if(entero <0){
    return 1;
    std::cerr << "Error" << std::endl;
  } 
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
    return 2;
  } //Caso contrario es EOF
  std::vector<int> representacionBinaria = numBinario(entero);
  std::cerr << "Numero de bits a uno: " << std::endl;
  for(std::size_t i = (representacionBinaria.size() - 1); i > 0; i--){
    std::cout << representacionBinaria[i];
  }
  std::cout << " 0x" << std::hex << entero
    << std::endl;
    //Mostramos numero en hexadecimal
  }
}
