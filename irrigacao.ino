#define sensorPin2 2   // Entrada digital do higrômetro LM393
#define relePin7 7     // Pino que aciona o relé

void setup() {
  pinMode(sensorPin2, INPUT);
  pinMode(relePin7, OUTPUT);
  digitalWrite(relePin7, LOW); // Válvula desligada no início

  Serial.begin(9600);
  Serial.println("Sistema de irrigação iniciado.");
}

void loop() {
  int seco = digitalRead(sensorPin2); // 0 = seco, 1 = molhado

  if (seco == LOW) {
    Serial.println("Solo seco - ativando irrigação.");
    digitalWrite(relePin7, HIGH); // Liga válvula
  } else {
    Serial.println("Solo úmido - desligando irrigação.");
    digitalWrite(relePin7, LOW); // Desliga válvula
  }

  delay(2000); // Espera 2 segundos antes da próxima leitura
}
