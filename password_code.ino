#include<LiquidCrystal.h> 
#include <EEPROM.h>
LiquidCrystal lcd(7,6,5,4,3,2); 

int row[]={A1,A0,8,9};// Defining row pins of keypad connected to Arduino pins
int col[]={10,11,12,13};//Defining column pins of keypad connected to Arduino
int i,j,lcd_count,count=1,a=0,key_id=0,flag,entry=0;// See About the Program 
int col_scan;// Variable to identify a key press
byte temp_press; // Variable to hold value of key press
byte check[5],pass[5]; // See About the Program
int test[20];
char keypress(int i, int j) // Subroutine to Identify the value of Key pressed
{
if(i==0&&j==0)
{
return('1');
}
if(i==0&&j==1)
{
return('2');
}
if(i==0&&j==2)
{
return('3');
}
if(i==0&&j==3)
{
return('A');
}
if(i==1&&j==0)
{
return('4');
}
if(i==1&&j==1)
{
return('5');
}
if(i==1&&j==2)
{
return('6');
}
if(i==1&&j==3)
{
return('B');
}
if(i==2&&j==0)
{
return('7');
}
if(i==2&&j==1)
{
return('8');
}
if(i==2&&j==2)
{
return('9');
}
if(i==2&&j==3)
{
return('C');
}
if(i==3&&j==0)
{
return('*');
}
if(i==3&&j==1)
{
return('0');
}
if(i==3&&j==2)
{
return('#');
}
if(i==3&&j==3)
{
return('D');
}
} // Subroutine to identify Keypress Ends







char keyscan()// Subroutine to Scan Keypad for a Keypress
{
for(i=0; i<=3; i++)  
{
digitalWrite(row[0],HIGH);
digitalWrite(row[1],HIGH);
digitalWrite(row[2],HIGH);
digitalWrite(row[3],HIGH);
digitalWrite(row[i],LOW);
for(j=0; j<=3; j++)
{
col_scan=digitalRead(col[j]);
if(col_scan==LOW)
{
key_id=1;
entry++;
temp_press=keypress(i,j);
lcd.setCursor(lcd_count++,1);
lcd.print(temp_press);
Serial.print(temp_press);
delay(300);
break;
}
}
}}// Subroutine to Scan Keypress Ends






void setup()
{
  Serial.begin(9600);
lcd.begin(16, 2);
for(i=0;i<=3;i++)
{
pinMode(row[i],OUTPUT);
pinMode(col[i],INPUT);
digitalWrite(col[i],HIGH);
}
lcd.setCursor(0,0);
lcd.print("ENTER 5 Digit PASS");
Serial.print("ENTER5Dp");

}
/* Main Program Begins */
void loop()
{ 
  entry=0; //key scan 
  j=0;
while(entry<=4)// Password Setting Loop begins
{  
  key_id=0;
  keyscan();
 if(key_id==1) // Condition to Check Key is Pressed check for and cond i.e a<5 as well
    {
           Serial.println("Hii");
           
           check[entry-1]=temp_press;
           check[entry-1]= check[entry-1]-48 ;

         
    }
    }
for(i=0;i<5;i++)
{
  Serial.println(check[i]);
}

    for(i=0;i<=4&&flag==0;i++)
{
  pass[i]= EEPROM.read(i);
  Serial.println(" i = ");
  Serial.print(i);
  Serial.print( "\t pass=");
  Serial.println(pass[i]);
  Serial.print("Printing check:");
  Serial.println(check[i]);

if(check[i]==pass[i])
{
  Serial.println( "flag0");
flag=0;
}
else 
{
  Serial.println( "flag1");
  flag=1;
}
}



  
         if(flag==0)
            {
                lcd.setCursor(0,0);
                lcd.print("UNLOCKED");
                 Serial.print("UNLOCKED");

              }else{ 
                 lcd.setCursor(0,0);
                 lcd.print("WRONG PASSWORD");
                 Serial.print("WRONGPASSWORD");

                 delay(200);
                 lcd.clear();
                 lcd.print("LOCKED");
                  Serial.print("LOCKED");

                  }

            
        
      }
/* Condition to LOCK Ends*/

/* Actions on Key Press Ends*/

/* Main Program Ends */

