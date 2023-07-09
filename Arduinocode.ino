int Htime; //integer for storing high time
 int Ltime; //integer for storing low time
 float Ttime; // integer for storing total time of a cycle
 float frequency; //storing frequency
 float avg_frequency;
 String park_string;
 void setup()
 {
 pinMode(3,INPUT);
 Serial.begin(9600);
 }
 void loop()
 {
 avg_frequency=0;
 for(int i=0; i<1000; i++)
 {
 Htime=pulseIn(3,HIGH); //read high time8 Ltime=pulseIn(3,LOW); //read low time
 Ttime = Htime+Ltime;
 frequency=1000000/Ttime;
 avg_frequency=avg_frequency+frequency;
 }
 avg_frequency=avg_frequency/1000;
 // Serial.println("Frequency of signal");
 // Serial.print(avg_frequency);
 // Serial.println(" Hz");
 if(avg_frequency<42000)
 {
 park_string="Empty";
 } else {
 park_string="Parked";
}
Serial.println(park_string);
delay(2000);
}