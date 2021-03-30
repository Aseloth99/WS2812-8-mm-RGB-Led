#define kirmiziPin 9
#define yesilPin 10
#define maviPin 11

int kirmizi;
int yesil;
int mavi;
float r,g,b;
float r1,g1,b1; 
int r2,g2,b2;
int r3,g3,b3;
int x=9;
int y=3;
int renkler[11][3]={
  {20,255,255},  //kırmızı
  {20,0,255},   //turuncu
  {70,0,255},   //sarı
  {255,0,255},  //yeşil
  {255,20,0},   //turkuaz
  {255,255,0},  //mavi
  {100,255,0},  //mor
  {100,10,0},  //beyaz
};

void renkAyarla(int kirmizi, int yesil, int mavi) {
  analogWrite(kirmiziPin, kirmizi);
  analogWrite(yesilPin, yesil);
  analogWrite(maviPin, mavi);
}

void setup() {
  //pinMode(kirmiziPin, OUTPUT);
  //pinMode(yesilPin, OUTPUT);
  //pinMode(maviPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //r=255;g=0;b=0;
  //renkAyarla(255, 0, 0); //kirmizi
  for(int i=0;i<x;i++){
      r=renkler[i][0]; r2=renkler[i+1][0];
      g=renkler[i][1]; g2=renkler[i+1][1];
      b=renkler[i][2]; b2=renkler[i+1][2];
      if(i==7) i=-1;
      r1=(r2-r)/200.0;
      g1=(g2-g)/200.0;
      b1=(b2-b)/200.0;
      for(int m=0;m<200;m++){
        r+=r1;
        g+=g1;
        b+=b1;
        /*Serial.print(m);
        Serial.print(" Kırmızı:");
        Serial.print(r);
        Serial.print("  Yeşil:");
        Serial.print(g);
        Serial.print("  Mavi:");
        Serial.println(b);*/
        renkAyarla(r, g, b);
        delay(7); 
      }
   }
    /*renkAyarla(0, 255, 255); //kirmizi
    delay(1500);
    renkAyarla(20, 0, 255); //turuncu
    delay(1500);
    renkAyarla(70, 0, 255); //sarı
    delay(1500);
    renkAyarla(255, 0, 255); //yeşil
    delay(1500);
    renkAyarla(255, 20, 0); //turkuaz
    delay(1500);
    renkAyarla(255, 255, 0); //mavi
    delay(1500);
    renkAyarla(100, 255, 0); //mor
    delay(1500);*/
    //renkAyarla(100, 10, 0); //beyaz
    //delay(1500);
}
