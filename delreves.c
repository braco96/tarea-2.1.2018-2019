#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Este programa procesa cada fichero en el orden indicado leyendo cada linea y emite en su salida la invesion del contenido de las mismas.

  int main(int argc, char* argv[]){
      argv0 = "delreves";
      char array[2048];//Array para guardar líneas
      char letra;      //Char que se utilizará como auxiliar
        
      //Cuando se quiere mostrar ayuda
           
      if(((argc==2) && strcmp(argv[1],"-h") ==0)||((argc==2) && strcmp(argv[1], "--help")==0)){

          printf("delreves: Uso: delreves [ fichero... ]\n");
          printf("delreves: Invierte el contenido de las lineas de los ficheros (o de la entrada).\n");
          return EX_OK;
      }
  
     //Caso de recibo redirigida la entrada estándar

     else if(argc<2){

       int i;
       int j;

       while(fgets(array, 2048, stdin)){

         i = 0;
         j = strlen(array)-2;
         while(i<j){
             letra = array[i];
             array[i] = array[j];
             array[j] = letra;
             i++;
             j--;
           }
           fputs(array, stdout);
        }
        return EX_OK;
    }
    
    //Caso se pasan fichero

    else{

         int i;
         FILE *p; //Puntero al archivo

         for(i=1; i<argc; i++){ //Mientras haya ficheros sin abrir 
             p = fopen(argv[i],"r"); //Abrir el fichero
              
             if(p == NULL){
          
               Error(EX_NOINPUT, "El fichero \"%s\" no puede ser leído.", argv[i]);
             }
 
             else{
                 int j;
                 int k;
 
                 while(fgets(array, 2048, p)){
                      j = 0;
                      k = strlen(array)-2;
                      while(j<k){
                          letra = array[j];
                          array[j] = array[k];
                          array[k] = letra;
                          j++;
                          k--;
                      }
                      fputs(array, stdout);
                  }
                  fclose(p);
                }
             }
             return EX_OK;
        }
}

