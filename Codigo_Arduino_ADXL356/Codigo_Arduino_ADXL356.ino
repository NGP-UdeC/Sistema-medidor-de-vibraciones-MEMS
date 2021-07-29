// Este código lee las aceleraciones del ADXL356 y las guarda en la tarjeta SD.
// En el archivo donde se guardan las mediciones, la última línea correspone al tiempo de medición.
// Este código es una modificación de ADXL356_vDiego_mod3test
// La diferencia es que este tiene distintos data types para las variables
// y no convierte los datos a [g], si no que los deja como números entre 0 y 1023.

#include <SD.h>

word v;
word i = 0;
word n = 15000;
word ti;
word tf;
word ttotal = 0;
File Datos;


void setup(){
  
  Serial.begin(230400);
  analogReference(EXTERNAL);

  Serial.println("Inicializando Tarjeta SD... ");
  if (!SD.begin()) {
    Serial.println("Inicialización fallida.");
    return;}
  Serial.println("Inicialización correcta.");
  Datos = SD.open("word.txt", FILE_WRITE);

  ti = millis();
  
  while(i < n){
    v = analogRead(A0);   
    Datos.println(v);
    i++;}
  
  tf = millis();
  ttotal = tf - ti;
  Datos.print(ttotal);
  
  Datos.close();
  Serial.print("Medición finalizada.");
  }
  
void loop(){
}
