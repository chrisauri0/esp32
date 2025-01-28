const int LEDPIN = 22;
const int PushButton = 15;
void setup()
{

pinMode(LEDPIN, OUTPUT);
pinMode(PushButton, INPUT);
}
void loop()
{
int Push_button_state = digitalRead(PushButton);

if ( Push_button_state == HIGH )
{
digitalWrite(LEDPIN, HIGH);
}
else
{
digitalWrite(LEDPIN, LOW);
}
}