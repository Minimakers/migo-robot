/*
  __  __  _____   _____   ____    _____    ____   ____    ____   _______
  |  \/  ||_   _| / ____| / __ \  |  __ \  / __ \ |  _ \  / __ \ |__   __|
  | \  / |  | |  | |  __ | |  | | | |__) || |  | || |_) || |  | |   | |
  | |\/| |  | |  | | |_ || |  | | |  _  / | |  | ||  _ < | |  | |   | |
  | |  | | _| |_ | |__| || |__| | | | \ \ | |__| || |_) || |__| |   | |
  |_|  |_||_____| \_____| \____/  |_|  \_\ \____/ |____/  \____/    |_|


                         .:-+**=::
               .:::::::::=========:::::::::.
              =@+++++++++++++++++++++++++++@=
              %%+++++++++++++++++++++++++++%%
             :%%++++++#*#+++++++++#*#++++++%%:
             :%%+++++++++++++++++++++++++++%%:
             :%%++++++++++++****+++++++++++%%:
             .%%+++++++++++++++++++++++++++%%.
              %%            ::::           %%
              %%             ::            %%

  Minimakers.fun
  Escrito por Alan Silva para Minimakers.fun
  Fecha de creación: 06 de diciembre 2020

  Instrucciones:
  - Pega los códigos del control remoto donde se indique.
  - Comprueba si coinciden los pines de la placa controladora con los pines ingresados en este sketch. ------------------------------*/

#include <IRremote.h>

/* Módulo Led RGB
   Aquí puedes modificar el pin correspondiente a tu robot para coordinar los colores de las luces Led ----------------------------*/

int LEDROJO = 4;    // pin 3 a anodo LED rojo
int LEDVERDE = 3;    // pin 4 a anodo LED verde
int LEDAZUL = 5;   // pin 5 a anodo LED azul

bool parado = true;
int rep = 0;
/* Módulo Puente H modelo MX1508
   Aquí puedes modificar el pin correspondiente a tu robot para coordinar el sentido de los motores -------------------------------*/

// motor A
const int in1 = 8; // Conecta en el pin 9
const int in2 = 9; // Conecta en el pin 8

// motor B
const int in3 = 7; // Conecta en el pin 7
const int in4 = 6; // Conecta en el pin 6



/* Aquí puedes modificar la velocidad máxima de los motores ------------------------------------------------------------------------*/
int speed = 250;


/* Sensor módulo IR Control remoto -------------------------------------------------------------------------------------------------*/
IRrecv irrecv(2);
decode_results results;


void setup()
{
  Serial.begin(9600);


  /* Control de la intensidad lumínica de los módulos led RGB al encender la placa controladora --------------------------------------*/
  analogWrite(LEDROJO, 255);
  analogWrite(LEDVERDE, 255);
  analogWrite(LEDAZUL, 255);


  /* Activación de sensor infrarrojo para la detección de señal del mando a distancia ------------------------------------------------*/
  irrecv.enableIRIn();


  /* Pines de salida: alimentación de motores y luces --------------------------------------------------------------------------------*/
  //Puente H
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //RGB
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
}


/* Configuración de las instrucciones enviadas al robot ----------------------------------------------------------------------------*/
void loop() {
  if (irrecv.decode(&results)) {
    irrecv.resume();



    /* Configuración del botón ---------------------------------------------------------------------------------------------------------*/

    if (results.value == 0xFF18E7) { // Apretamos el boton "arriba" del control remoto para avanzar
      Serial.println("AVANZAR");
      // Se activa el motor
      analogWrite(in1, speed);
      analogWrite(in2, 0);
      analogWrite(in3, speed);
      analogWrite(in4, 0);

      //RGB: color azul
      analogWrite(LEDROJO, 139);
      analogWrite(LEDVERDE, 0);
      analogWrite(LEDAZUL, 139);



      /* Configuración del botón ---------------------------------------------------------------------------------------------------------*/

    } else if (results.value == 0xFF4AB5) { // Apretamos el boton "abajo" del control remoto para retroceder
      Serial.println("ATRAS");
      // Se activa el motor
      analogWrite(in1, 0);
      analogWrite(in2, speed);
      analogWrite(in3, 0);
      analogWrite(in4, speed);

      //RGB: color rojo
      analogWrite(LEDROJO, 255);
      analogWrite(LEDVERDE, 0);
      analogWrite(LEDAZUL, 0);



      /* Configuración del botón ---------------------------------------------------------------------------------------------------------*/

    } else if (results.value == 0xFF38C7) { // Apretamos el boton "OK" del control remoto para detener
      Serial.println("PARAR");
      parado = true;
      // Se desactiva el motor
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);

      //RGB: color blanco
      analogWrite(LEDROJO, 255);
      analogWrite(LEDVERDE, 255);
      analogWrite(LEDAZUL, 255);



      /* Configuración del botón ---------------------------------------------------------------------------------------------------------*/

    } else if (results.value == 0xFF5AA5) { // Apretamos el boton "derecha" del control remoto para doblar a la derecha
      Serial.println("DERECHA");
      // Se activa el motor
      analogWrite(in1, speed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);

      //RGB: color verde
      analogWrite(LEDROJO, 0);
      analogWrite(LEDVERDE, 255);
      analogWrite(LEDAZUL, 0);



      /* Configuración del botón ---------------------------------------------------------------------------------------------------------*/

    } else if (results.value == 0xFF10EF) { // Apretamos el boton "izquierda" del control remoto para doblar a la izquierda
      Serial.println("IZQUIERDA");
      // Se activa el motor
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, speed);
      analogWrite(in4, 0);

      //RGB: verde
      analogWrite(LEDROJO, 0);
      analogWrite(LEDVERDE, 255);
      analogWrite(LEDAZUL, 0);



      /* Configuración del botón ---------------------------------------------------------------------------------------------------------*/

    } else if (results.value == 0xFF6897) { // Apretamos el boton "*" del control remoto para girar en 360° derecha
      Serial.println("360°");
      // Se desactiva el motor
      analogWrite(in1, speed);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, speed);

      //RGB: verde
      analogWrite(LEDROJO, 0);
      analogWrite(LEDVERDE, 255);
      analogWrite(LEDAZUL, 0);



      /* Configura
      
      
      
      ción del botón ---------------------------------------------------------------------------------------------------------*/

    } else if (results.value == 0xFFB04F) { // Apretamos el boton "#" del control remoto para girar en 360° izquierda
      Serial.println("360°");
      // Se desactiva el motor
      analogWrite(in1, 0);
      analogWrite(in2, speed);
      analogWrite(in3, speed);
      analogWrite(in4, 0);

      //RGB: color verde
      analogWrite(LEDROJO, 0);
      analogWrite(LEDVERDE, 255);
      analogWrite(LEDAZUL, 0);
    }

    /* Configuración del botón con bucle ---------------------------------------------------------------------------------------------------------*/

    else if(results.value == 0xFFA25D){ // Apretamos el boton "1" del control remoto para caminar gateando 
for(int rep = 0; rep < 3; rep++){

  //RGB
  analogWrite(LEDROJO, 0);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 0); 


 // encienden motores
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(400);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(600); 
}  

}else if(results.value == 0xFF629D){ // Apretamos el boton "2" del control remoto para caminar recto girar y seguir caminando 
for(int rep = 0; rep < 1; rep++){ 
  // Se desactiva el motor
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(1200);
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(815); 
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
    
  //RGB
  analogWrite(LEDROJO, 0);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 0);
 }

}else if(results.value == 0xFFE21D){ // Apretamos el boton "3" del control remoto para caminar recto girar y seguir caminando, cariño 
for(int rep = 0; rep < 5; rep++){ 
  // Se desactiva el motor
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
delay(60);
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(60);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(60);
    
  //RGB
  analogWrite(LEDROJO, 255);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 0);
 }

}else if(results.value == 0xFF22DD){ // Apretamos el boton "4" del control remoto para caminar recto girar y seguir caminando 
for(int rep = 0; rep < 1; rep++){ 
  // Se activa el motor
  analogWrite(in1, speed); //recto adelante
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(1500); 
  analogWrite(in1, 0);     // giro 90° mirando al frente
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(200); 
  analogWrite(in1, 0); //recto adelante
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(500);  
 
  //RGB
  analogWrite(LEDROJO, 255);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 255);
 }
for(int rep = 0; rep < 3; rep++){ 
  
  analogWrite(in1, 0);      // baile hacia atrás
  analogWrite(in2, speed);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(250);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
delay(300); 
  //RGB
  analogWrite(LEDROJO, 255);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 0);
 }
for(int rep = 0; rep < 2; rep++){ 
  
  analogWrite(in1, 0);      // baile hacia adelante
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(250);
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(300); 
  //RGB
  analogWrite(LEDROJO, 255);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 0);
 }
 for(int rep = 0; rep < 1; rep++){ 
  analogWrite(in1, 0);  // giro trompo
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(700);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(100);
  analogWrite(in1, speed); //adelante
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(50);
  analogWrite(in1, 0); //giro derecha
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(170);
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(300);
  //RGB
  analogWrite(LEDROJO, 255);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 255);
 }
  }else if(results.value == 0xFF02FD){ // Apretamos el boton "5" del control remoto para caminar gateando 

  analogWrite(LEDROJO, 255);  
  analogWrite(LEDVERDE, 255); 
  analogWrite(LEDAZUL, 255);

  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(50);
for(int rep = 0; rep < 2; rep++){
// encienden motores
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(200);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 160);
  analogWrite(in4, 0);
delay(200); 
}  
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
delay(200);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(1000);
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
delay(200);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
delay(1000);
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(360);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0); 
delay(1000);
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
delay(360);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0); 
delay(1000);
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(1000);
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0); 
    }else if(results.value == 0xFFC23D){ // Apretamos el boton "6" del control remoto para caminar recto girar y seguir caminando 
for(int rep = 0; rep < 1; rep++){ 
  // Se desactiva el motor
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(1200);
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
delay(220); 
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
    
  //RGB
  analogWrite(LEDROJO, 0);  
  analogWrite(LEDVERDE, 255); //verde
  analogWrite(LEDAZUL, 0);
 }

    
    }}        }
