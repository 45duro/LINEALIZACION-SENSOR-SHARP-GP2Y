#define a -1148.09
#define b 164.31
#define c -0.15283

float sensorRead = 0.81;
float c_2 =0, raizCuadrada=0,r1=0,r2=0;
void setup() {
  Serial.begin(9600);
  //Paso 1: Sacar el valor de C
  c_2=c-sensorRead;
  Serial.println(c_2);

  //Paso 2: Raiz Cuadrada
  raizCuadrada=sqrt(pow(b,2)-(4*a*c_2));
  Serial.println(raizCuadrada);

  //paso 3: Sumar todo el numerador
  r1 = -b+raizCuadrada;
  r2 = -b-raizCuadrada;

  //paso 4: dividir
  r1/=(2*a);
  r2/=(2*a);

  //paso 5: poner cm
  Serial.print(1/r1); Serial.println("cm");
  Serial.print(1/r2); Serial.println("cm");
}

void loop() {
  sensorRead = lecturaSensor(analogRead(A3));
  Serial.print(1/funcionCuadratica()); Serial.println("cm");
  delay(100);

}

float lecturaSensor(int lectura){
  lectura /= 100;
  return lectura;
}

float funcionCuadratica(){
  //Paso 1: Sacar el valor de C
  c_2=c-sensorRead;
  //Paso 2: Raiz Cuadrada
  raizCuadrada=sqrt(pow(b,2)-(4*a*c_2));
  //paso 3: Sumar todo el numerador dejo el superior porque es el que me sirve
  r1 = -b+raizCuadrada;
      //r2 = -b-raizCuadrada;

  //paso 4: dividir
  r1/=(2*a);
       //r2/=(2*a);
  
  return r1;
}
