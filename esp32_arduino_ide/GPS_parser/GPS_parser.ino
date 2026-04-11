#define RXD
#define TXD

string nmea_data = "";


void setup(){
  Serial.begin(115200);
  while(!Serial){
    ; //wait till Serial monitor connects
  }
  Serial2.begin(unsigned long 9600, SERIAL_8N_1, int8_t RXD, int8_t TXD);
  Serial.println("Communication between NEO-7M and esp32 has started!");

}

void GPS_DATA_PARSER(string data){
  //the example of a typical nmea data structure looks like this - "$GPRMC,030742.00,A,2232.73830,N,11404.558520...."
  if (data.substring(0,6) == "$GPRMC"){
    string starter = data.substring(0,6);
    first_comma = data.indexof(',');
    second_comma = data.indexof(',', first_comma + 1);
    third_comma = data.indexof(',', second_comma + 1);
    fourth_comma = data.indexof(',', third_comma + 1);
    fifth_comma = data.indexof(',', fourth_comma + 1);
    sixth_comma = data.indexof(',' , fifth_comma + 1);
    sevenh_comma = data.indexof(',', sixth_comma + 1);

    string time_0 = data.substring(first_comma, second_comma + 1);
    string time = time_0.substring(0,2) + ":" + time_0.substring(2,4) + ":" + time_0.substring(4,6);
    if (data.substring(second_comma, third_comma + 1) == "A"){
      string lat = data.substring(third_comma,fourth_comma + 1);
      string lat_dir = data.substring(fourth_comma, fifth_comma + 1);
      string lon = data.substring(fifth_comma, sixth_comma + 1);
      string lon_dir = data.substring(sixth_comma, seventh_comma + 1);

    }
  }
  Serial.println(time); 
  Serial.print(' ');
  Serial.print(lat + ' ' + lat_dir);
  Serial.print(' ');
  Serial.print(lon + ' ' + lon_dir);


}

void loop(){
  while (Serial2.available()){
    char C = Serial2.read();
    if (C == '\n'){
      GPS_DATA_PARSER(nmea_data);
      nmea_data = "";
    }
    else {
      nmea_data += C;
    }

    
    }
  }

}