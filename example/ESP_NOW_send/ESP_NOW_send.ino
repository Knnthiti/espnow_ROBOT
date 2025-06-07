#include <espnow_ROBOT.h>

uint8_t broadAddress[6] = { 0xF4, 0x65, 0x0B, 0x59, 0x3B, 0xC8 };
// F4:65:0B:59:3B:C8
ESPNOW_ROBOT joy(broadAddress);

typedef struct __attribute__((packed)) {
  uint8_t Header[2];

  union {
    uint8_t moveBtnByte;
    struct {
      uint8_t move1 : 1;
      uint8_t move2 : 1;
      uint8_t move3 : 1;
      uint8_t move4 : 1;
      uint8_t res1 : 2;
      uint8_t set1 : 1;
      uint8_t set2 : 1;
    } moveBtnBit;
  };

  union {
    uint8_t attackBtnByte;
    struct {
      uint8_t attack1 : 1;
      uint8_t attack2 : 1;
      uint8_t attack3 : 1;
      uint8_t attack4 : 1;
      uint8_t res1 : 4;
    } attackBtnBit;
  };

  int8_t stickValue[4];  //joyL_X,joyL_Y ,joyR_X,joyR_Y

} ControllerData;

ControllerData data;

void setup() {
  joy.Setup_send_ESPNOW();
}

void loop() {
  data.moveBtnBit.move1 = 1;
  data.moveBtnBit.move3 = 1;

  data.attackBtnBit.attack2 = 1;
  data.attackBtnBit.attack3 = 1;

  data.stickValue[0] = 100;
  data.stickValue[2] = random(-128,127);

  joy.Sendvalue_ESPNOW((uint8_t*)&data, sizeof(data));
  delay(10);
}
