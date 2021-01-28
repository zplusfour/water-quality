int red_light_pin= 8;
int green_light_pin = 9;
int blue_light_pin = 10;

int N_Avrg=5; 
int TURBIDITY_THRESHOLD=730;
int PH_THRESHOLD=730;

void setup() {
  Serial.begin(9600); //Baud rate: 9600
  pinMode(A0, INPUT);       //Set the turbidity sensor pin to input mode
  pinMode(A1, INPUT);       //Set the ph sensor pin to input mode\
  
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
    not_good_quility();
  }else{
    good_quility();
  }
  delay(500);
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
void not_good_quility(){
  RGB_color(255, 0, 0); // Red
  delay(1000);
  Serial.println(" not good water"); // print out the turbidity_value you read:  

}

void good_quility(){
  RGB_color(0, 255, 0); // Green
  delay(1000);
  Serial.println(" :) good water"); // print out the turbidity_value you read: 
}
