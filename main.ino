#include <checker.h>

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  
}
void loop() {
 /*************************************************/ 
 int counter=1;
 int turbidity_sensor_value=0;
 double ph_sensor_value=0;
  while(counter<= N_Avrg){
    //turbidity
   int turbidity_val=analogRead(A0);
   ///ph
   double ph_vltValue = 5/1024.0 * analogRead(A1);
   double ph_val=7 + ((2.5 - ph_vltValue) / 0.18);

   turbidity_sensor_value+=turbidity_val;// read the input on analog pin 0:
   ph_sensor_value+=ph_val;
   counter++;
   delay(500);
  }

  /*************************************************/
  int turbidity_avrg=turbidity_sensor_value/N_Avrg;
  int ph_avrg=ph_sensor_value/N_Avrg;
  Serial.println(turbidity_avrg);
  if(turbidity_avrg<TURBIDITY_THRESHOLD || !(7.1<ph_avrg<7.5) ){
    checker::not_good_quility();
  }else{
    checker::good_quility();
  }
  delay(500);
}