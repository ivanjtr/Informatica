// Autor: Ivan Jesus Torres Rodriguez
// Fecha: 2018-10-7

#include <vector> // para poder usar los vectores
#include <iostream> // para usar cout y cerr
#include <fstream> //Para acceso a ficheros
#include <string> //Para usar el tipo string


// Tiene que contar los mayores que el pivote y devolver cuantos hay
int iguales(const std::vector<int> &datos, 
  std::vector<int> &mayores, std::vector<int> &menores, int pivote){
  std::cerr << "El pivote recibido es " << pivote << std::endl;
  int numIguales=0;
  for(std::size_t i=0;i<datos.size();i++){ //Bucle para realizar tantas 
      //comparaciones como elementos tiene el vector
    std::cerr << "Considerando el dato " << datos[i] << std::endl;
    if(datos[i]>pivote){//Compara los valores del vector con el valor 
      //del pivote
      std::cerr << "El dato " << datos[i]<<" es mayor que el pivote"
        <<std::endl;
      mayores.push_back(datos[i]);//Si el valor del pivote es menor
        //se guarda el numero en el vector 
    }
    else if(datos[i]<pivote){//Compara los valores del vector con el valor 
      //del pivote
      std::cerr << "El dato " << datos[i] << " es menor que el pivote"
        << std::endl;
      menores.push_back(datos[i]);//Si el valor del pivote es mayor
        //se guarda el numero en el vector 
    }
    else{
        numIguales++;
    }
  }
  return numIguales;//Devuelve el vector con los numeros que son mayores
    //que el pivote
}

int lectura(std::vector<int>& datos, std::string nomb){//Funcion para leer
    //el fichero
  std::cerr << "Fichero de entrada " << nomb << std::endl;
  std::ifstream fent(nomb);//Leer fichero de entrada
  if( ! fent.good()){
    std::cout << "Error a la hora de trabajar con el archivo" << std::endl;
    return 1;
  }
  int linea=0;
  fent >> linea;
  while (fent.good()){
    datos.push_back(linea);
    fent >> linea;
    std::cerr << "Valor linea: " << linea << std::endl;
  }
  fent.close();
  return 0;
}

int main(int argc,char* argv[]){
  int pivote=0;
  std::cerr << "El programa tiene " << argc << " parametros de entrada "
    <<std::endl;
  for(int i=0;i<argc;i++){
    std::cerr<<"El argumento "<<i<<" contiene'"<<argv[i]<<"'"<<std::endl;
  }
  
  std::string nomb = argv[1];
  std::size_t pos = nomb.find(".dat");//pos da la posicion donde empieza .dat
  std::cerr << "Posicion del string donde empieza .dat " << pos << std::endl;
  std::cerr << "Tamaño del nombre de archivo " << nomb.length() << std::endl;
  if(nomb.length() != (pos + 4)){
    nomb = nomb + ".dat";  
  }
  std::string nombSinExtension = nomb.substr(0,pos);
  if(argc<2){
    std::cout<<"Falta el nombre del fichero "<<std::endl; 
    return 2;
  }
  if(argc<3){//Establecemos el valor del pivote como 10 si no se pasa valor
    pivote=10; 
  }
  if(argc>=3){
    try{//Manejo de errores
      pivote=std::stoi(argv[2]);//Convertir de tipo string a int
    }catch(std::invalid_argument e1){
      std::cout << "Se ha producido un error"<< std::endl;
      return 3;
    }catch(std::out_of_range e2){
      std::cout << "El numero esta fuera de rango"<< std::endl;
      return 4;
    }
  }
  std::vector<int> datos;//Declaracion de vectores
  std::vector<int> mayores;
  std::vector<int> menores;
  if(lectura(datos,nomb)!=0){//Error fichero
    std::cout << "Error usando el archivo"<< std::endl;
    return 5;
  }
  std::cerr<<"El tamaño de datos es "<< datos.size() <<std::endl;
  for(std::size_t i=0;i<datos.size();i++){//Bucle para comprobar los datos 
      //obtenidos
    std::cerr<<"El pivote es "<< pivote <<std::endl;
    std::cerr<<"El dato "<< i <<" es "<<datos[i]<<std::endl;
  }
  int resultado=iguales(datos,mayores,menores,pivote);
  std::cout<<"Pivote: "<<pivote<<std::endl;
  std::string strPivote = std::to_string(pivote);
  std::ofstream ficheroMayores("_mayores_" + strPivote + ".dat");
  std::cerr<<"Mayores: "<<std::endl;
  for(std::size_t i=0;i<mayores.size();i++){//Almacenamos los mayores 
      //con este bucle
    std::cerr<<mayores[i]<<std::endl;
    ficheroMayores << mayores[i];
  }
  ficheroMayores.close();
  std::ofstream ficheroMenores("_menores_" + strPivote + ".dat");
  std::cerr<<"Menores: "<<std::endl;
  for(std::size_t i=0;i<menores.size();i++){//Almacenamos los menores 
      //con este bucle
    std::cerr<<menores[i]<<std::endl;
    ficheroMenores << menores[i];
  }
  ficheroMenores.close();
  std::cout<<"Iguales: "<<resultado<<std::endl;
  return 0;
}

