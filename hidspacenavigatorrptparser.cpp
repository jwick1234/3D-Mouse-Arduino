#include "hidspacenavigatorrptparser.h"

SpaceNavigatorReportParser::SpaceNavigatorReportParser(SpaceNavigatorEvent *evt) :
spaceNavigatorEvent(evt)
{
}

void SpaceNavigatorReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {

    // Calling SpaceNavigator event handler
    spaceNavigatorEvent->OnSpaceNavigatorChanged((const SpaceNavigatorEventData*)buf);
}

void SpaceNavigatorEvent::OnSpaceNavigatorChanged(const SpaceNavigatorEventData *evt) {
//    Serial.print("report ID: ");
//    PrintHex<uint8_t > (evt->rptid, 0x80);
//    Serial.print("\txl: ");
//    PrintHex<uint8_t > (evt->xl, 0x80);
//    Serial.print("\txh: ");
//    PrintHex<uint8_t > (evt->xh, 0x80);
//    Serial.print("\tyl: ");
//    PrintHex<uint8_t > (evt->yl, 0x80);
//    Serial.print("\tyh: ");
//    PrintHex<uint8_t > (evt->yh, 0x80);
//    Serial.print("\tzl: ");
//    PrintHex<uint8_t > (evt->zl, 0x80);
//    Serial.print("\tzh: ");
//    PrintHex<uint8_t > (evt->zh, 0x80);

    // Translation vector
    if (evt->rptid == 1) {
      Tx = evt->xl+(evt->xh<<8);
      Ty = evt->yl+(evt->yh<<8);
      Tz = evt->zl+(evt->zh<<8);
    }

    // Rotation vector
    else if (evt->rptid == 2) {
      Rx = evt->xl+(evt->xh<<8);
      Ry = evt->yl+(evt->yh<<8);
      Rz = evt->zl+(evt->zh<<8);
    }

    // Buttons
    else if (evt->rptid == 3) {
    }
    
    Serial.print("\tT:( ");
    Serial.print(Tx);
    Serial.print(" , ");
    Serial.print(Ty);
    Serial.print(" , ");
    Serial.print(Tz);
    Serial.print(" )");

    Serial.print("\tR:( ");
    Serial.print(Rx);
    Serial.print(" , ");
    Serial.print(Ry);
    Serial.print(" , ");
    Serial.print(Rz);
    Serial.print(" )");

    Serial.println("");
}

void SpaceNavigatorEvent::OnButton(uint8_t but_id) {
    Serial.print("Button: ");
    Serial.println(but_id, DEC);
}

