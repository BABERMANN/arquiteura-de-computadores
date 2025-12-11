// ===================================================================
// 1. DEFINIÇÕES GLOBAIS (Variáveis e Constantes)
// ===================================================================

// --- Definição dos Pinos ---
const int PIN_LDR = A0;      // Sensor de Luz (Entrada Analógica)
const int PIN_BUZZER = 12;   // Buzzer (Conforme a sua montagem)
const int PIN_LED = 13;      // LED Único (Conforme a sua montagem)

// --- Variáveis do Sistema ---
// AJUSTE ESTE VALOR: 
// O alarme dispara quando a leitura do LDR for MENOR que este número.
int LIMITE_ESCURIDAO = 300; 


// ===================================================================
// 2. FUNÇÕES AUXILIARES (Definidas antes do Setup)
// ===================================================================

void toqueFeedback(int duracao, int frequencia) {
  // Função para tocar um tom no Buzzer
  tone(PIN_BUZZER, frequencia, duracao);
}


// ===================================================================
// 3. VOID SETUP() (Executado apenas uma vez ao ligar)
// ===================================================================

void setup() {
  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);
  
  // Configura os pinos de saída
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  
  Serial.println("Detector de Escuridão Simples Ativo.");
  Serial.print("Limite de Escuridão: ");
  Serial.println(LIMITE_ESCURIDAO);
}


// ===================================================================
// 4. VOID LOOP() (Executado continuamente)
// ===================================================================

void loop() {
  // Leitura do sensor de luz (LDR)
  int valorLDR = analogRead(PIN_LDR);

  // Se o valorLDR for MENOR que o limite, significa que está escuro.
  if (valorLDR < LIMITE_ESCURIDAO) {
    // --- Condição de ALERTA (Escuridão Detectada) ---
    
    // Pisca o LED (pino 13)
    digitalWrite(PIN_LED, (millis() % 200) < 100 ? HIGH : LOW); 
    
    // Toca o alarme (pino 12)
    tone(PIN_BUZZER, 800); 

    Serial.print("ALARME! Valor LDR: ");
    Serial.println(valorLDR);

  } else {
    // --- Condição NORMAL (Luz Suficiente) ---
    digitalWrite(PIN_LED, LOW); // LED apagado
    noTone(PIN_BUZZER);          // Buzzer silencioso

    Serial.print("Normal. Valor LDR: ");
    Serial.println(valorLDR);
  }
  
  delay(100); 
}
