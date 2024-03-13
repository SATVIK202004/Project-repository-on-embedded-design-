#include "BluetoothSerial.h" 
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run
make menuconfig to and enable it
#endif
BluetoothSerial SerialBT;
// define the GPIO connected with Relays and switches
#define RelayPin1 4  //D23
#define RelayPin2 22  //D22
#define RelayPin3 21  //D21
#define RelayPin4 19  //D19
#define RelayPin5 18  //D18
#define RelayPin6 5   //D5
#define RelayPin7 25  //D25
#define RelayPin8 26  //D26
#define SwitchPin1 13  //D13
#define SwitchPin2 12  //D12
#define SwitchPin3 14  //D14
#define SwitchPin4 27  //D27
#define SwitchPin5 33  //D33
#define SwitchPin6 32  //D32
#define SwitchPin7 15  //D15
#define SwitchPin8 23   //D4
int toggleState_1 = 1; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 1; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 1; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 1; //Define integer to remember the toggle state for relay 4
int toggleState_5 = 1; //Define integer to remember the toggle state for relay 5
int toggleState_6 = 1; //Define integer to remember the toggle state for relay 6
int toggleState_7 = 1; //Define integer to remember the toggle state for relay 7
int toggleState_8 = 1; //Define integer to remember the toggle state for relay 8
char bt_data; 
void relayOnOff(int relay){
    switch(relay){
      case 1: 
             if(toggleState_1 == 1){
              digitalWrite(RelayPin1, LOW); // turn on relay 1
              toggleState_1 = 0;
              Serial.println("Device1 ON");
              }
             else{
              digitalWrite(RelayPin1, HIGH); // turn off relay 1
              toggleState_1 = 1;
              Serial.println("Device1 OFF");
              }
             delay(100);
      break;
      case 2: 
             if(toggleState_2 == 1){
              digitalWrite(RelayPin2, LOW); // turn on relay 2
              toggleState_2 = 0;
              Serial.println("Device2 ON");
              }
             else{
              digitalWrite(RelayPin2, HIGH); // turn off relay 2
              toggleState_2 = 1;
              Serial.println("Device2 OFF");
              }
             delay(100);
      break;
      case 3: 
             if(toggleState_3 == 1){
              digitalWrite(RelayPin3, LOW); // turn on relay 3
              toggleState_3 = 0;
              Serial.println("Device3 ON");
              }
             else{
              digitalWrite(RelayPin3, HIGH); // turn off relay 3
              toggleState_3 = 1;
              Serial.println("Device3 OFF");
              }
             delay(100);
      break;
      case 4: 
             if(toggleState_4 == 1){
              digitalWrite(RelayPin4, LOW); // turn on relay 4
              toggleState_4 = 0;
              Serial.println("Device4 ON");
              }
             else{
              digitalWrite(RelayPin4, HIGH); // turn off relay 4
              toggleState_4 = 1;
              Serial.println("Device4 OFF");
              }
             delay(100);
      break;
      case 5: 
             if(toggleState_5 == 1){
              digitalWrite(RelayPin5, LOW); // turn on relay 5
              toggleState_5 = 0;
              Serial.println("Device5 ON");
              }
             else{
              digitalWrite(RelayPin5, HIGH); // turn off relay 5
              toggleState_5 = 1;
              Serial.println("Device5 OFF");
              }
             delay(100);
      break;
      case 6: 
             if(toggleState_6 == 1){
              digitalWrite(RelayPin6, LOW); // turn on relay 6
              toggleState_6 = 0;
              Serial.println("Device6 ON");
              }
             else{
              digitalWrite(RelayPin6, HIGH); // turn off relay 6
              toggleState_6 = 1;
              Serial.println("Device6 OFF");
              }
             delay(100);
      break;
      case 7: 
             if(toggleState_7 == 1){
              digitalWrite(RelayPin7, LOW); // turn on relay 7
              toggleState_7 = 0;
              Serial.println("Device7 ON");
              }
             else{
              digitalWrite(RelayPin7, HIGH); // turn off relay 7
              toggleState_7 = 1;
              Serial.println("Device7 OFF");
              }
             delay(100);
      break;
      case 8: 
             if(toggleState_8 == 1){
              digitalWrite(RelayPin8, LOW); // turn on relay 8
              toggleState_8 = 0;
              Serial.println("Device8 ON");
              }
             else{
              digitalWrite(RelayPin8, HIGH); // turn off relay 8
              toggleState_8 = 1;
              Serial.println("Device8 OFF");
              }
             delay(100);
      break;
      default : break;      
      }  
}
void without_internet(){
    if (digitalRead(SwitchPin1) == LOW){
      delay(200);
      relayOnOff(1);      
    }
    else if (digitalRead(SwitchPin2) == LOW){
      delay(200);
      relayOnOff(2);
    }
    else if (digitalRead(SwitchPin3) == LOW){
      delay(200);
      relayOnOff(3);
    }
    else if (digitalRead(SwitchPin4) == LOW){
      delay(200);
      relayOnOff(4);
    }
    else if (digitalRead(SwitchPin5) == LOW){
      delay(200);
      relayOnOff(5);      
    }
    else if (digitalRead(SwitchPin6) == LOW){
      delay(200);
      relayOnOff(6);
    }
    else if (digitalRead(SwitchPin7) == LOW){
      delay(200);
      relayOnOff(7);
    }
    else if (digitalRead(SwitchPin8) == LOW){
      delay(200);
      relayOnOff(8);
    }
}
void all_Switch_ON(){
  digitalWrite(RelayPin1, LOW); toggleState_1 = 0; delay(100);
  digitalWrite(RelayPin2, LOW); toggleState_2 = 0; delay(100);
  digitalWrite(RelayPin3, LOW); toggleState_3 = 0; delay(100);
  digitalWrite(RelayPin4, LOW); toggleState_4 = 0; delay(100);
  digitalWrite(RelayPin5, LOW); toggleState_5 = 0; delay(100);
  digitalWrite(RelayPin6, LOW); toggleState_6 = 0; delay(100);
  digitalWrite(RelayPin7, LOW); toggleState_7 = 0; delay(100);
  digitalWrite(RelayPin8, LOW); toggleState_8 = 0; delay(100);
}
void all_Switch_OFF(){
  digitalWrite(RelayPin1, HIGH); toggleState_1 = 1; delay(100);
  digitalWrite(RelayPin2, HIGH); toggleState_2 = 1; delay(100);
  digitalWrite(RelayPin3, HIGH); toggleState_3 = 1; delay(100);
  digitalWrite(RelayPin4, HIGH); toggleState_4 = 1; delay(100);
  digitalWrite(RelayPin5, HIGH); toggleState_5 = 1; delay(100);
  digitalWrite(RelayPin6, HIGH); toggleState_6 = 1; delay(100);
  digitalWrite(RelayPin7, HIGH); toggleState_7 = 1; delay(100);
  digitalWrite(RelayPin8, HIGH); toggleState_8 = 1; delay(100);
}
void Bluetooth_handle()
{
  bt_data = SerialBT.read();
//  Serial.println(bt_data);
  delay(20);
  switch(bt_data)
      {
        case 'A': digitalWrite(RelayPin1, LOW);  toggleState_1 = 0; break; 
        case 'a': digitalWrite(RelayPin1, HIGH); toggleState_1 = 1; break; 
        case 'B': digitalWrite(RelayPin2, LOW);  toggleState_2 = 0; break; 
        case 'b': digitalWrite(RelayPin2, HIGH); toggleState_2 = 1; break; 
        case 'C': digitalWrite(RelayPin3, LOW);  toggleState_3 = 0; break; 
        case 'c': digitalWrite(RelayPin3, HIGH); toggleState_3 = 1; break; 
        case 'D': digitalWrite(RelayPin4, LOW);  toggleState_4 = 0; break; 
        case 'd': digitalWrite(RelayPin4, HIGH); toggleState_4 = 1; break; 
        case 'E': digitalWrite(RelayPin5, LOW);  toggleState_5 = 0; break; 
        case 'e': digitalWrite(RelayPin5, HIGH); toggleState_5 = 1; break; 
        case 'F': digitalWrite(RelayPin6, LOW);  toggleState_6 = 0; break; 
        case 'f': digitalWrite(RelayPin6, HIGH); toggleState_6 = 1; break; 
        case 'G': digitalWrite(RelayPin7, LOW);  toggleState_7 = 0; break; 
        case 'g': digitalWrite(RelayPin7, HIGH); toggleState_7 = 1; break; 
        case 'H': digitalWrite(RelayPin8, LOW);  toggleState_8 = 0; break; 
        case 'h': digitalWrite(RelayPin8, HIGH); toggleState_8 = 1; break; 
        case 'Z': all_Switch_ON(); break;  
        case 'z': all_Switch_OFF(); break; 
        default : break;
      }
}
void setup()
{
  Serial.begin(9600);
  btStart();  //Serial.println("Bluetooth On");
  SerialBT.begin("ESP32_BT"); 
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(5000);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT);
  pinMode(RelayPin6, OUTPUT);
  pinMode(RelayPin7, OUTPUT);
  pinMode(RelayPin8, OUTPUT);
//  pinMode(wifiLed, OUTPUT);
  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);
  pinMode(SwitchPin5, INPUT_PULLUP);
  pinMode(SwitchPin6, INPUT_PULLUP);
  pinMode(SwitchPin7, INPUT_PULLUP);
  pinMode(SwitchPin8, INPUT_PULLUP);
  digitalWrite(RelayPin1, toggleState_1);
  digitalWrite(RelayPin2, toggleState_2);
  digitalWrite(RelayPin3, toggleState_3);
  digitalWrite(RelayPin4, toggleState_4);
  digitalWrite(RelayPin5, toggleState_5);
  digitalWrite(RelayPin6, toggleState_6);
  digitalWrite(RelayPin7, toggleState_7);
  digitalWrite(RelayPin8, toggleState_8);
  delay(200);
}
void loop()
{  
    without_internet();
    if (SerialBT.available()){
     Bluetooth_handle();
   }
}
