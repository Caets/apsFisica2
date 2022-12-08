#include "BluetoothSerial.h"  // Nome da biblioteca ja disponibilizada na IDE.

BluetoothSerial ESP_BT; // Objeto do BT (Padrão).

// Nome das portas no ESP-32
int ventilador = 5;   //Porta do ventilador.
int tv = 4;   //Porta de uma TV, mas no caso usamos um led.
int luzes = 18;  //Porta das luzes (uma lâmpada para o exemplo).
int entrada;  // Declarei uma variavel para a entrada do programa.

void setup() {
  Serial.begin(19200);   //Leitura do meu Serial.
  ESP_BT.begin("Automacao_Residencial");    //Nome do BT que a aparece para o dispositivo.
//Declaração das variaveis (Como entrada e saída).
  pinMode(ventilador, OUTPUT);
  pinMode(tv, OUTPUT);
  pinMode(luzes, OUTPUT);
}

void loop() {

  if (ESP_BT.available()) { //Se o ESP_BT der algum sinal ele entra no if.
    entrada = ESP_BT.read();  //Leitura App == A entrada.
//Criei mais duas variaveis.
    int comando = floor(entrada / 10);  //Calculo que representa o comando entrada/10= 1,2,3...
    int valor = entrada % 10;   //Resto da divisão para resultar em positivo ou negativo (HIGH ou LOW).

    switch (comando) {
      case 1:
        Serial.print("Button 1:");    // liga o ventilador.
        Serial.println(valor);
        digitalWrite(ventilador, valor);
        break;
      case 2:
        Serial.print("Button 2:");    //Liga o led.
        Serial.println(valor);
        digitalWrite(tv, valor);
        break;
      case 3:
        Serial.print("Button 3:");    //Liga a Lampada.
        Serial.println(valor);
        digitalWrite(luzes, valor);
        break;

    }
  }
}
