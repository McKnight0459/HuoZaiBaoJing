const int TiaoJie = A3;
const int YanGan = A2;
const int LD = 2;
const int HD = 3;
const int LaBa = 10;
const int delayGSM = 2000;
void gsmCN() {
  Serial.println("AT");
  delay(delayGSM);
  Serial.println("AT+CMGF=1");
  delay(delayGSM);
  Serial.println("AT+CSMP=17,167,2,25");
  delay(delayGSM);
  Serial.println("AT+CSCS=\"UCS2\"");
  delay(delayGSM);
  Serial.println("AT+CMGS=\"00310035003200340035003900380031003500380036\"");
  delay(delayGSM);
  Serial.print("67D00033003553434F0F53D8753562400038005800580058005851FA7EBF9AD8538B5F00517367DC53D173B0706B60C5FF018BF76CE8610F68C067E5FF01");
  delay(delayGSM);
  Serial.println((char)26);
  delay(delayGSM);
}
void setup() {
  Serial.begin(115200);
  pinMode(LD, OUTPUT);
  pinMode(HD, OUTPUT);
  pinMode(LaBa, OUTPUT);
  digitalWrite(LD, HIGH);
  digitalWrite(HD, LOW);
}
void loop() {
  // Serial.print("TiaoJie = ");
  // Serial.print(analogRead(TiaoJie));
  // Serial.print("      ");
  // Serial.print("YanGan = ");
  // Serial.println(analogRead(YanGan));
  if (analogRead(YanGan) > analogRead(TiaoJie)) {
    digitalWrite(LD, LOW);
    digitalWrite(HD, HIGH);
    gsmCN();
    for (int i = 200; i <= 800; i++)
    {
      tone(LaBa, i);
      delay(5);
    }
    delay(4000);
    for (int i = 800; i >= 200; i--)
    {
      tone(LaBa, i);
      delay(10);
    }
  } else {
    digitalWrite(LD, HIGH);
    digitalWrite(HD, LOW);
    noTone(LaBa);
  }
  delay(1000);
}
