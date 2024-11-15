/**
 * @example i2c_to_pwm.ino
 */

#include "i2c_to_pwm.h"

namespace {
em::I2cToPwm g_i2c_to_pwm;
}

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  Serial.println(String("i2c to pwm lib version: ") + em::I2cToPwm::Version());

  Wire.begin();

  const auto ret = g_i2c_to_pwm.Init();

  if (em::I2cToPwm::kOK == ret) {
    Serial.println("i2c to pwm initialization successful");
  } else {
    Serial.print("i2c to pwm initialization failed: ");
    Serial.println(ret);
    while (true);
  }

  Serial.println(F("setup successful"));
}

void loop() {
  g_i2c_to_pwm.Pwm(0, 0);
  g_i2c_to_pwm.Pwm(1, 4095);
  g_i2c_to_pwm.Pwm(2, 0);
  g_i2c_to_pwm.Pwm(3, 4095);
  Serial.println("F");
  delay(1000);

  g_i2c_to_pwm.Pwm(0, 4095);
  g_i2c_to_pwm.Pwm(1, 0);
  g_i2c_to_pwm.Pwm(2, 4095);
  g_i2c_to_pwm.Pwm(3, 0);
  Serial.println("B");
  delay(1000);
}
