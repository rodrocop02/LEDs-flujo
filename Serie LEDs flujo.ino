//Definir los pines de los LED
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;

//Definir el pin del botón
const int BOTON = 10;

//Definir el tiempo de retardo para la intermitencia de LED
const int RETARDO_LED = 2000;

//Variable para almacenar el estado del botón
int estadoBoton = 0;


void setup() {
  //Iniciar el puerto serial
  Serial.begin(9600);
  
  //Configurar los pines de los LED como salida
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  
  //Configurar el pin del botón como entrada con pull-up interno
  pinMode(BOTON, INPUT_PULLUP);

  //Encender todos los LEDs al iniciar el proyecto
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
  digitalWrite(LED8, HIGH);
}

void loop() {
  //Leer el estado actual del botón
  estadoBoton = digitalRead(BOTON);

  if (estadoBoton == LOW) {
    //Si el botón está presionado, encender los LED de manera intermitente
    for (int i = 0; i < 8; i++) {
      digitalWrite(i+2, HIGH);
      delay(100);
      digitalWrite(i+2, LOW);
    }
  } else if (Serial.available() > 0) {
    //Si hay datos disponibles en el monitor serial
    int opcion = Serial.read();

    if (opcion == 50) {
      //Serial.println("--------");
      //Serial.print(opcion);
      //Serial.println();
      //Serial.write(opcion);
      //Serial.println("----------");

      //Si se envió el número 2, encender los LED con retardo 4 veces
      for (int i=0 ; i < 4 ; i++){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      delay(RETARDO_LED);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, HIGH);
      digitalWrite(LED8, HIGH);
      delay(RETARDO_LED);
      }
    }
  }
}