// Variables used in the program
int button = LOW; // button state variable, initial value 0 (LOW)
int i; // variable used in for loops
int j; // variable used in for loops

/* The following routines are executed only when called by instructions
in the void loop () section */

// ************************ routine for displaying number 1 **************
void one(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, HIGH); // activate all ports and turn off all LEDs
  digitalWrite(4, LOW); // deactivate port 4 and light up the right high vertical segment
  digitalWrite(6, LOW); // deactivate port 6 and light up the right low vertical segment
}

// *********************** routine for displaying number 2 **********************
void two(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(6, HIGH); // activate port 6 and turn off the low right vertical segment
  digitalWrite(2, HIGH); // activate port 2 and turn off the high left vertical segment
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
}

// ********************** routine for displaying number 3 *********************
void three(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(2, HIGH); // activate port 2 and turn off the high left vertical segment
  digitalWrite(8, HIGH); // activate port 8 and turn off the low left vertical segment
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
}

// ********************* routine for displaying number 4 **********************
void four(void)
{
  digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
  digitalWrite(7, HIGH); // activate port 7 and turn off the bottom horizontal segment
  digitalWrite(8, HIGH); // activate port 8 and turn off the left low vertical segment
  digitalWrite(3, HIGH); // activate port 3 and turn off the top horizontal segment
}

// *************************** routine for displaying number 5 **********************
void five(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
  digitalWrite(4, HIGH); // activate port 4 and turn off the right high vertical segment
  digitalWrite(8, HIGH); // activate port 8 and turn off the left low vertical segment
}

// ************************ routine for displaying number 6 ****************************
void six(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
  digitalWrite(4, HIGH); // activate port 4 and turn off the right high vertical segment
}

// ***************************** routine for displaying number 7 ************************
void seven(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, HIGH); // deactivate all ports and turn off all LEDs
  digitalWrite(3, LOW); // deactivate port 3 and light up the top horizontal segment
  digitalWrite(4, LOW); // deactivate port 4 and light up the right high vertical segment
  digitalWrite(6, LOW); // deactivate port 6 and light up the right low vertical segment
}

// ********************************* routine for displaying number 8 ********************
void eight(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
}

// ************************ routine for displaying number 9 ***********************
void nine(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
  digitalWrite(8, HIGH); // activate port 8 and turn off the left low vertical segment
}

// **************************** routine for displaying number zero *************************
void zero(void)
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, LOW); // deactivate all ports and light up all LEDs
  digitalWrite(5, HIGH); // activate port 5 and turn off the decimal point
  digitalWrite(1, HIGH); // activate port 1 and turn off

 the middle horizontal segment
}

void setup()
{
  for (i = 1; i <= 8; i++)
    pinMode(i, OUTPUT); // define ports 1 through 8 as output ports
  pinMode(11, INPUT);   // define port 11, to which the button is connected, as an input port
  pinMode(12, OUTPUT);  // define port 12, to which the buzzer is connected, as an output port
  pinMode(13, OUTPUT);  // define port 13, to which the LED is connected, as an output port
}

void loop()
{
  for (j = 1; j <= 8; j++)
    digitalWrite(j, HIGH); // activate all ports and turn off all LEDs of the digital figure
  button = digitalRead(11); // read button state
  while (button)             // execute the following instructions only if the button value is 1 (High)
  {                          // i.e., if the button is pressed
    nine();                  // call the routine for displaying number 9
    delay(1000);             // wait for 1 second
    eight();                 // call the routine for displaying number 8 .....
    delay(1000);
    seven();
    delay(1000);
    six();
    delay(1000);
    five();
    delay(1000);
    four();
    delay(1000);
    three();
    delay(1000);
    two();
    delay(1000);
    one();
    delay(1000);
    zero();
    delay(1000);
    for (j = 1; j <= 8; j++)
      digitalWrite(j, HIGH); // activate all ports and turn off all LEDs
    for (i = 1; i <= 20; i++) // routine for emitting the sound signal and for blinking the LED
    {
      digitalWrite(13, HIGH); // turn on the LED
      digitalWrite(12, LOW);  // turn off the buzzer
      digitalWrite(5, LOW);   // turn on the decimal point
      delay(70);
      digitalWrite(13, LOW);  // turn off the LED
      digitalWrite(12, HIGH); // turn on the buzzer
      digitalWrite(5, HIGH);  // turn off the decimal point
      delay(70);
      button = LOW;           // set the button to LOW state, so as not to repeat the countdown
                              // until the button is pressed again
      digitalWrite(12, LOW);  // turn off the buzzer
    }
  }
}
