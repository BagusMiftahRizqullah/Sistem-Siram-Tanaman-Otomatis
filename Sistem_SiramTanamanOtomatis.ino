//SISTEM SIRAM TANAMAN OTOMATIS
//By : Bagus Miftah Rizqullah


const int pinRelay = 11;   // definisikan Relay pada pin digital 11
byte ldr = A0;
byte led = 13;
int lmb = A2;
int nilai_icahaya;
int nilai_lembab;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinRelay,OUTPUT);          // definisikan keluaran
  Serial.begin(115200);        // initialize serial
}

void loop() {
  // put your main code here, to run repeatedly:
  
  nilai_icahaya = analogRead(ldr);
  Serial.print("Nilai LDR: ");
  Serial.println(nilai_icahaya);
  delay(10000);

   if (nilai_icahaya < 40) {
    //digitalWrite(led, HIGH);
    nilai_lembab = analogRead(lmb);
    Serial.print("Kelembaban tanah : ");
    Serial.println(nilai_lembab);
      if(nilai_lembab > 650){
        Serial.println("Tanah kering, siram air");
        digitalWrite(pinRelay,LOW);   // nyala pas cahaya terang
        }
      else if (nilai_lembab < 650 && nilai_lembab > 350){
        Serial.println("Kelembaban normal gan");
        digitalWrite(pinRelay,HIGH);
        Serial.println("POMPA MATI !!!"); //hanya ngeprint pompa mati
        }
      else if (nilai_lembab < 350) {
        Serial.println("Tanah lembab gan");
        digitalWrite(pinRelay,HIGH);
        Serial.println("POMPA MATI !!!"); //hanya ngeprint pompa mati
        }
        
    }
    
    else {
      digitalWrite(led, LOW);
      digitalWrite(pinRelay,HIGH);
      Serial.print("CAHAYA GELAP ## ");
    }

   
}
