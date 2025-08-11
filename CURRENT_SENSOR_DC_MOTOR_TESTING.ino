// Pin definitions
#define CURRENT_SENSOR_PIN A0     // Current sensor analog pin
#define MOTOR_PWM_PIN      5      // PWM pin for motor speed control
#define MOTOR_IN1_PIN      6      // Direction control pin
#define MOTOR_IN2_PIN      7      // Direction control pin

// Constants
const float SENSOR_ZERO_CURRENT_VOLTAGE = 2.5;  // Voltage at 0A (typically 2.5V)
const float SENSOR_SENSITIVITY = 0.040;         // Volts per Amp (e.g., 40mV/A)

// Calibration values (tweak if needed)
const float ADC_REF_VOLTAGE = 5.0;              // Mega uses 5V ADC reference
const int ADC_RESOLUTION = 1023;

void setup() {
  Serial.begin(9600);

  pinMode(CURRENT_SENSOR_PIN, INPUT);
  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(MOTOR_IN1_PIN, OUTPUT);
  pinMode(MOTOR_IN2_PIN, OUTPUT);

  // Start motor (clockwise at 60% speed)
  digitalWrite(MOTOR_IN1_PIN, HIGH);
  digitalWrite(MOTOR_IN2_PIN, LOW);
  analogWrite(MOTOR_PWM_PIN, 153);  // 60% of 255
}

void loop() {
  // Read analog value
  int adcValue = analogRead(CURRENT_SENSOR_PIN);

  // Convert ADC to voltage
  float voltage = (adcValue * ADC_REF_VOLTAGE) / ADC_RESOLUTION;

  // Calculate current (based on 2.5V zero current)
  float current = (voltage - SENSOR_ZERO_CURRENT_VOLTAGE) / SENSOR_SENSITIVITY;

  // Display results
  Serial.print("ADC Value: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Current: ");
  Serial.print(current, 3);
  Serial.println(" A");

  delay(500);  // Adjust as needed
}
