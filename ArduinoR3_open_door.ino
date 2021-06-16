
// include the library code:
#include <LiquidCrystal.h>
# include <Servo.h>
Servo puerta;

int LED = 8; //led conectado pin 8
int PIR = 6; //led conectado pin 6
char placa;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(LED, OUTPUT);//pin salida
  pinMode(PIR, INPUT);//pin entrada
  puerta.attach(7);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Bienvenido");
}

void loop() {
  int valorpir = digitalRead(PIR);
  //placa = Serial.read();
  if (valorpir == 1){
    lcd.setCursor(0, 0);
    lcd.print("Carro detectado");
    delay(3000);
    placa = Serial.read();
    if (placa == 'a'){
      	lcd.setCursor(0, 0);
      	lcd.print("Ingreso exitoso");
        digitalWrite(LED, HIGH);
    	puerta.write(180);
      	delay(3000);
    }
    if (placa == 'b') {
      	lcd.setCursor(0, 0);
      	lcd.print("Acceso denegado");
    	digitalWrite(LED, LOW);
    	puerta.write(0);
      	delay(3000);
    }
  }else{
    lcd.setCursor(0, 0);
  	lcd.print("Bienvenido     ");
    digitalWrite(LED, LOW);
    puerta.write(0);
  }
  delay(300);
}

 