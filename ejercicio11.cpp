// Autor: Ivan Jesus Torres Rodriguez
// Fecha: 2018-10-14


#include <iostream>
#include <new>
#include <math.h> //Usar potencias

bool* funcionVerdaderoFalso(int entero, unsigned int *numBits){
  unsigned int n = 1;
  int i = 0;
  int temp = 0;
  while(i != 1){
    if(entero < pow(2,n)){
      i = 1;
    }
    else{
      n ++;
    }
  }
  std::cerr << n << std::endl;
  i = 0;
  *numBits = n;
  std::cerr << *numBits << std::endl;
  bool* ptrBool = new bool[*numBits];
  i = *numBits;
  while(entero > 0){ //Convertimos entero a decimal
    temp = (entero % 2 == 0) ? 0 : 1;
    entero /= 2;
    ptrBool[i] = temp;
    i --;
    std::cerr << i << std::endl;
  }
  return ptrBool;
  delete[] ptrBool;
}

int main(){
  int entero = 5;
  unsigned int numeroBits = 0;
  while(entero != 0){
  std::cerr << "Introduzca entero: " << std::endl;
  std::cin >> entero;
  if (std::cin.good()) {
    std::cin.ignore(); //quitamos salto de línea
  } else if (std::cin.fail()) { //mala conversión
    std::cin.clear();
    std::cin.ignore(1000,'\n'); //descartamos hasta \n
    return 1;
  } //caso contrario es EOF
  bool* posicionVector = funcionVerdaderoFalso(entero, &numeroBits);
  std::cerr << "Sizeof " << numeroBits << std::endl;
  std::cerr << "entero " << entero << std::endl;
  for(std::size_t i = 1; i <= numeroBits; i ++){
    if(posicionVector[i] == true){
      std::cout << "V, ";
    }
    else if(posicionVector[i] == false){
      std::cout << "F, ";
    }
    else{
      std::cerr << "Error" << std::endl;
      return 2;
    }
  }
  std::cout << std::endl;
  }
}
