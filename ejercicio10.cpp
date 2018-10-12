// Autor: Ivan Jesus Torres Rodriguez
// Fecha: 2018-10-10

#include <vector> // para poder usar los vectores
#include <iostream> // para usar cout y cerr
#include <fstream> //Para acceso a ficheros
#include <string> //Para usar el tipo string
#include <iomanip> //Para convertir en hexadecimal
#include <math.h> //Usar potencias

unsigned int decimal(unsigned int indiceInicial,
    const std::vector<bool> &vector, unsigned int indiceFinal){
  int j = 0;
  unsigned int numDecimal = 0;
  for(unsigned int i = indiceInicial; i <= indiceFinal; i++){
    numDecimal += vector[i]*pow(2,j);
    j ++;
  }
return numDecimal;
}

int lectura(std::vector<bool> &datos, std::string nomb){//Funcion para leer
    //el fichero
  int q = 0;
  int j = 0;
  int k = 0;
  int n = 0;
  int m = 0;
  int l = 0; 
  int p = 0;
  std::cerr<<"Fichero de entrada "<< nomb <<std::endl;
  std::ifstream fent(nomb);//Leer fichero de entrada
  if( ! fent.good()){
    std::cout << "Error a la hora de trabajar con el archivo" << std::endl;
    return 1;//Error devuelve numero distinto a 0
  }
  char linea = '0';//Creamos una variable para almacenar los datos del fichero
  fent >> linea;
  std::cerr << "Valor linea: " << linea;
  while (fent.good()){
    if(linea == 'v' || linea == 'e' || linea == 'r' || linea == 'd' 
        || linea == 'a'){
      q ++;
      std::cerr << "q " << q << std::endl;
    }
    if(linea == 't' || linea == 'r' || linea == 'u' || linea == 'e'){
      j ++;
    }
    if(linea == 's' || linea == 'i'){
      k ++;
    }
    if(linea == 'n' || linea == 'o'){
      n ++;
    }
    if(linea == 'f' || linea == 'a' || linea == 'l' || linea == 's' 
        || linea == 'e'){
      m ++;
    }
    if(linea == 'f' || linea == 'a' || linea == 'l' || linea == 's' 
        || linea == 'o'){
      l ++;
    }
    if(q == 6 || j == 4 || k == 2 || linea == '1'){
      q = 0; 
      j = 0;
      k = 0;
      n = 0;
      m = 0;
      l = 0;
      datos.push_back(true);
      std::cerr << datos[p] << std::endl;
      p ++;
    }
    if(n == 2 || m == 5 || l == 5 || linea == '0'){
      q = 0; 
      j = 0;
      k = 0;
      n = 0;
      m = 0;
      l = 0;
      datos.push_back(false);
      std::cerr << datos[p] << std::endl;
      p ++;
    }
    fent >> linea;
    std::cerr << linea;
  }
  p = 0;
  q = 0; 
  j = 0;
  k = 0;
  n = 0;
  m = 0;
  l = 0;
  fent.close();//Cerramos el fichero
  return 0;
}

double numeroBitsAUno(unsigned int entero){
  double bitsAUno = 0;
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

int main(int argc,char* argv[]){ //argc numero de argumentos argv argumentos
  std::cerr << "El programa tiene " << argc << " parametros de entrada "
    << std::endl;
  unsigned int indiceInicial, indiceFinal = 0;
  std::cerr << "Introduzca indice inicial: " << std::endl;
  //std::cin >> indiceInicial;//Guardamos el numero introducido
  std::cerr << "Introduzca indice inicial: " << std::endl;
  //std::cin >> indiceFinal;//Guardamos el numero introducido
  std::vector<bool> datos;
  std::string nomb = argv[1];
  //Añadir .dat
  std::size_t pos = nomb.find(".dat");//pos da la posicion donde empieza .dat
  std::cerr << "Posicion del string donde empieza .dat " << pos << std::endl;

  std::cerr << "Tamaño del nombre de archivo " << nomb.length() << std::endl;
  if(nomb.length() != (pos + 4)){
    nomb = nomb + ".dat";  
  }
  
  if(lectura(datos,nomb) != 0){//Si ocurrre un error al leer el archivo
    std::cout << "Error usando el archivo"<< std::endl;
    return 5;
  }
  if(argc > 2){
    try{//Manejo de errores
      indiceInicial = std::stoi(argv[2]);//Convertir de tipo string a int
      indiceFinal = datos.size();
    }catch(std::invalid_argument e1){
      std::cout << "Se ha producido un error"<< std::endl;
      return 3;
    }catch(std::out_of_range e2){
      std::cout << "El numero esta fuera de rango"<< std::endl;
      return 4;
    }
  }
  if(argc > 3){
    try{//Manejo de errores
      indiceInicial = std::stoi(argv[2]);
      indiceFinal = std::stoi(argv[3]);//Convertir de tipo string a int
    }catch(std::invalid_argument e1){
      std::cout << "Se ha producido un error"<< std::endl;
      return 3;
    }catch(std::out_of_range e2){
      std::cout << "El numero esta fuera de rango"<< std::endl;
      return 4;
    }
  }
  if(argc <= 2){
    indiceInicial = 0;
    indiceFinal = datos.size();
  }
  if(indiceFinal < indiceInicial){
    std::cerr << "Error los indices son incorrectos" <<std::endl;
    return 8;
  }
  std::cerr << "Vector bool" << std::endl;
  for(std::size_t i = 0; i < datos.size(); i++){
    std::cerr << datos[i];
  }
  std::cerr << std::endl;
  unsigned int numeroDecimal = decimal(indiceInicial, datos, indiceFinal);
  std::vector<int> numeroBinario;
  std::cout << numeroDecimal;
  std::cout << " 0x" << std::hex << numeroDecimal;
  std::cout << " 0b";
  double temp = 0;
  numeroBinario.push_back(0);
  while(numeroDecimal != 0){ //Convertimos entero a decimal
    temp = (fmod(numeroDecimal,2) == 0) ? 0 : 1;
    numeroDecimal /= 2;
    numeroBinario.push_back(temp);
  }
  for(std::size_t i = (numeroBinario.size()-1); i > 0; i--){
    std::cout << numeroBinario[i];
  }
}
