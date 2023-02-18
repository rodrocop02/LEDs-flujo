const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;
const int BOTON = 10;
const int RETARDO_LED = 2000;

int estadoBoton = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  
  pinMode(BOTON, INPUT_PULLUP);

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
  estadoBoton = digitalRead(BOTON);

  if (estadoBoton == LOW) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(i+2, HIGH);
      delay(100);
      digitalWrite(i+2, LOW);
    }
  } else if (Serial.available() > 0) {
    int opcion = Serial.read();

    if (opcion == 50) {
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
