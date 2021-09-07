#include <Keyboard.h>
#include <IRremote.h>

const int irReceiverPin = 7;
IRrecv irrecv(irReceiverPin);
decode_results results;
void setup()
{
  x = 0;
  Serial.begin(9600);  //定义波特率
  irrecv.enableIRIn(); //给红外接收模块进行使能
  Keyboard.begin();
}

void send(int key)
{
  Keyboard.press(key);
  delay(10); //延时600毫秒（按键消抖）
  Keyboard.release(key);
  delay(10); //延时600毫秒（按键消抖）
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.print("irCode: ");
    int res = results.value;
    Serial.print(res);
    Serial.println();
    irrecv.resume();
    if (res == 25245)
    { //up
      send(214);
    }
    if (res == -22441)
    { //down
      send(211);
    }
  }
}
