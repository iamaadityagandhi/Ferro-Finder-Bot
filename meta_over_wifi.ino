
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "JioFiber_4G";
const char* password = "yayavi@5162";

// Define motor control pins (modify pin numbers if needed)
const int in1_motor1 = 22;
const int in2_motor1 = 21;
const int enable_motor1 = 5;

const int in1_motor2 = 19;
const int in2_motor2 = 18;
const int enable_motor2 = 23;


WebServer server(80);

void setup() {
  Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());

  pinMode(25,OUTPUT);

  pinMode(in1_motor1, OUTPUT);
  pinMode(in2_motor1, OUTPUT);
  pinMode(enable_motor1, OUTPUT);

  pinMode(in1_motor2, OUTPUT);
  pinMode(in2_motor2, OUTPUT);
  pinMode(enable_motor2, OUTPUT);

  // Configure PWM channels for motor speed control (optional for basic on/off)
  ledcSetup(0, 5000, 8); // 5 kHz frequency, 8-bit resolution (0-255) for channel 0
  ledcSetup(1, 5000, 8); // 5 kHz frequency, 8-bit resolution (0-255) for channel 1

  ledcAttachPin(enable_motor1, 0);
  ledcAttachPin(enable_motor2, 1);

  // Start with motors off (optional for PWM control)
  digitalWrite(enable_motor1, HIGH); // Enable pin is usually active LOW
  digitalWrite(enable_motor2, HIGH); // Enable pin is usually active LOW

  digitalWrite(25,HIGH);
  
  server.on("/receive_char", HTTP_POST, [](){
    String received_char = server.arg("plain");
    Serial.print("Received character: ");
    Serial.println(received_char);
    // Perform actions based on received character

    if (received_char == "F") {
      digitalWrite(in1_motor1, HIGH);
      digitalWrite(in2_motor1, LOW);
      digitalWrite(in1_motor2, LOW);
      digitalWrite(in2_motor2, HIGH);
      ledcWrite(0, 255); // Set motor 1 speed (adjust duty cycle for PWM control)
      ledcWrite(1, 255); // Set motor 2 speed (adjust duty cycle for PWM control)
    } 

    else if (received_char == "B") {
     digitalWrite(in1_motor1, LOW);
      digitalWrite(in2_motor1, HIGH);
      digitalWrite(in1_motor2, HIGH);
      digitalWrite(in2_motor2, LOW);
      ledcWrite(0, 255); // Set motor 1 speed (adjust duty cycle for PWM control)
      ledcWrite(1, 255); // Set motor 2 speed (adjust duty cycle for PWM control)
    } 
    else if (received_char == "L") {
          digitalWrite(in1_motor1, HIGH);
          digitalWrite(in2_motor1, LOW);
          digitalWrite(in1_motor2, HIGH);
          digitalWrite(in2_motor2, LOW);
          ledcWrite(0, 255); // Set motor 1 speed (adjust duty cycle for PWM control)
          ledcWrite(1, 255); // Set motor 2 speed (adjust duty cycle for PWM control)
    }

     else if (received_char == "R") {
      digitalWrite(in1_motor1, LOW);
      digitalWrite(in2_motor1, HIGH);
      digitalWrite(in1_motor2, LOW);
      digitalWrite(in2_motor2, HIGH);
      ledcWrite(0, 255); // Set motor 1 speed (adjust duty cycle for PWM control)
      ledcWrite(1, 255); // Set motor 2 speed (adjust duty cycle for PWM control)
    }

    else if (received_char == "S") {
      digitalWrite(in1_motor1, LOW);
      digitalWrite(in2_motor1, LOW);
      digitalWrite(in1_motor2, LOW);
      digitalWrite(in2_motor2, LOW);
    }

     else if(received_char=="D"){
      digitalWrite(25, HIGH);
    }

    else if(received_char=="M"){
      digitalWrite(25, LOW);
    }



    server.send(200, "text/plain", "Character received");
  });

  server.begin();
}

void loop() {
  server.handleClient(); // Continuously handle incoming requests
}
