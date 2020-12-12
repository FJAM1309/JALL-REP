
int EKG = A0;
int EKGreadings = 0;

void setup ()
{
  Serial.begin ( 9600 );
}

void loop ()
{
  //Serial.print ( 500 );
  //Serial.print ( "," );
  ////Serial.print ( 100 );
  ////Serial.print ( "," );
  EKGreadings = analogRead ( EKG );
  Serial.println ( EKGreadings );
  delay ( 0.01 );
}
