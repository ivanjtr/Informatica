// Autor: Ivan Jesus Torres Rodriguez
// Fecha: 2018-10-7

#include <vector> // para poder usar los vectores
#include <iostream> // para usar cout y cerr
#include <fstream> //Para acceso a ficheros
#include <string> //Para usar el tipo string


// Tiene que contar los mayores que el pivote y devolver cuantos hay
std::vector<int> cuantosMayores(const std::vector<int> &datos, int pivote){
  std::cerr<<"El pivote recibido es "<< pivote << std::endl;
  std::vector<int> vectorMayores;
  for(std::size_t i=0;i<datos.size();i++){ //Bucle para realizar tantas 
      //comparaciones como elementos tiene el vector
    std::cerr<<"Considerando el dato "<< datos[i] << std::endl;
    if(datos[i]>pivote){//Compara los valores del vector con el valor 
      //del pivote
      std::cerr<<"El dato "<<datos[i]<<" es mayor que el pivote"
        <<std::endl;
      vectorMayores.push_back(datos[i]);//Si el valor del pivote es menor
        //se guarda el numero en el vector 
    }
  }
  return vectorMayores;//Devulve el vector con los numeros que son mayores
    //que el pivote
}

int lectura(std::vector<int>& datos, std::string nomb){//Funcion para leer
    //el fichero
  std::cerr<<"Fichero de entrada "<< nomb <<std::endl;
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
  std::cerr<<"El programa tiene "<< argc<<" parametros de entrada "
    <<std::endl;
  for(int i=0;i<argc;i++){
    std::cerr<<"El argumento "<<i<<" contiene'"<<argv[i]<<"'"<<std::endl;
  }
  if(argc<2){
    std::cout<<"Falta el nombre del fichero "<<std::endl; 
    return 2;
  }
  if(argc<3){//Establecemos el valor del pivote como 2 si no se pasa valor
    pivote=2; 
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
  std::vector<int> resultado;
  std::string nomb=argv[1];
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
  resultado=cuantosMayores(datos,pivote);//Calculamos el vector de numeros
    //mayores al pivote
  std::cout<<"Pivote: "<<pivote<<std::endl;
  std::cout<<"Resultado: "; 
  for(std::size_t i=0;i<resultado.size();i++){//Mostramos el resultado 
      //con este bucle
    std::cout<<resultado[i]<<", ";
  }
  return 0;
}

