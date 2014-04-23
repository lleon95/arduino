/*
Creatinueva.com - Un proyecto de Open Klooid Innovations (www.klooid.org)
Controlador para 4 servos con un mando de 6 botones con Arduino
Por: Luis Leon
*/

#include <Servo.h>

/*
Posicion inicial de los servos
Iniciaran en posicion central (90°)
*/
int servoval1=90; //Posicion inicial del servo 1
int servoval2=90; //Posicion inicial del servo 2
int servoval3=90; //Posicion inicial del servo 3
int servoval4=90; //Posicion inicial del servo 4

// Declaración de los servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Patillas de entrada
// Direccion
int direccion1=11;
int direccion2=12;
// Seleccion de servos
int select1=6;
int select2=7;
int select3=8;
int select4=9;

void setup() {
  // Vincular servos
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  /* 
  Vincular patillas de direccion
  Boton 1: Giro a la izquierda
  Boton 2: Giro a la derecha
  */
  pinMode(direccion1, INPUT);
  pinMode(direccion2, INPUT);
  /* 
  Estos 4 botones serán para seleccionar los servos que queremos que hagan movimiento
  */
  pinMode(select1, INPUT);
  pinMode(select2, INPUT);
  pinMode(select3, INPUT);
  pinMode(select4, INPUT);
}

void loop() {
  // Condiciones para determinar que botones son pulsados para ejecutar una determinada acción
  // Para que funcione el circuito, es necesario tener presionado un boton de selección para poder presionar un boton de direccion
  if(digitalRead(select1)==HIGH && digitalRead(select2)==LOW && digitalRead(select3)==LOW && digitalRead(select4)==LOW){
    //Si el boton de seleccion "Servo1" esta presionado
    if(digitalRead(direccion1)==HIGH && digitalRead(direccion2)==LOW){
      //Si al mismo tiempo está presionado el boton de direccion "Izquierda"
      servoval1++;
    }
    else if(digitalRead(direccion1)==LOW && digitalRead(direccion2)==HIGH){
      //Si al mismo tiempo está presionado el boton de direccion "Derecha"
      servoval1--;
    }
  }
  else if(digitalRead(select1)==LOW && digitalRead(select2)==HIGH && digitalRead(select3)==LOW && digitalRead(select4)==LOW){
    //Si el boton de seleccion "Servo2" esta presionado
    if(digitalRead(direccion1)==HIGH && digitalRead(direccion2)==LOW){
      //Si al mismo tiempo está presionado el boton de direccion "Izquierda"
      servoval2++;
    }
    else if(digitalRead(direccion1)==LOW && digitalRead(direccion2)==HIGH){
      //Si al mismo tiempo está presionado el boton de direccion "Derecha"
      servoval2--;
    }
  }
  else if(digitalRead(select1)==LOW && digitalRead(select2)==LOW && digitalRead(select3)==HIGH && digitalRead(select4)==LOW){
    //Si el boton de seleccion "Servo3" esta presionado
    if(digitalRead(direccion1)==HIGH && digitalRead(direccion2)==LOW){
      //Si al mismo tiempo está presionado el boton de direccion "Izquierda"
      servoval3++;
    }
    else if(digitalRead(direccion1)==LOW && digitalRead(direccion2)==HIGH){
      //Si al mismo tiempo está presionado el boton de direccion "Derecha"
      servoval3--;
    }
  }
  else if(digitalRead(select1)==LOW && digitalRead(select2)==LOW && digitalRead(select3)==LOW && digitalRead(select4)==HIGH){
    //Si el boton de seleccion "Servo4" esta presionado
    if(digitalRead(direccion1)==HIGH && digitalRead(direccion2)==LOW){
      //Si al mismo tiempo está presionado el boton de direccion "Izquierda"
      servoval4++;
    }
    else if(digitalRead(direccion1)==LOW && digitalRead(direccion2)==HIGH){
      //Si al mismo tiempo está presionado el boton de direccion "Derecha"
      servoval4--;
    }
  }
  
  //Escribir valores en los servos
  servo1.write(servoval1);
  servo2.write(servoval2);
  servo3.write(servoval3);
  servo4.write(servoval4);
  delay(10); //Retraso (Si requieren mas velocidad de movimiento, eliminar esta linea de codigo o aumentar el retardo para movimientos mas lentos)
}
