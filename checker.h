int red_light_pin = 8;
int green_light_pin = 9;
int blue_light_pin = 10;

int N_Avrg = 5;
int TURBIDITY_THRESHOLD = 730;
int PH_THRESHOLD = 730;

namespace checker
{
  void good_quility()
  {
    RGB_color(0, 255, 0); // Green
    delay(1000);
    Serial.println(" :) good water"); // print out the turbidity_value you read:
  }

  void not_good_quility()
  {
    RGB_color(255, 0, 0); // Red
    delay(1000);
    Serial.println(" not good water"); // print out the turbidity_value you read:
  }

  void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
  {
    analogWrite(red_light_pin, red_light_value);
    analogWrite(green_light_pin, green_light_value);
    analogWrite(blue_light_pin, blue_light_value);
  }
};