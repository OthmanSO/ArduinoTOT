#include <Key.h>
#include <Keypad.h>

void setup() {
  Serial.begin(9600);
}
char keys[4][4]={{'A','B','C','D'},{'E','F','U','H'},{'I','J','K','M'},{'N','O','P','Q'}};
byte rows [4]= {5,4,3,2};
byte columns [4]= {6,7,8,9};

void loop() {
 Keypad k = Keypad( makeKeymap(keys), rows, columns, 4, 4 );
 char x = k.getKey();
 if(x)
  Serial.println(x);

}
