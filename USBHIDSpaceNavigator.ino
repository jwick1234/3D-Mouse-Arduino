#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

#include "hidspacenavigatorrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
SpaceNavigatorEvent SpaceNavigatorEvent;
SpaceNavigatorReportParser SpaceNavigator(&SpaceNavigatorEvent);

void setup() {
Serial.begin(115200);  //  set the serial monitor at 115200 too
#if !defined(__MIPSEL__)
while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
Serial.println("Start");

if (Usb.Init() == -1)
Serial.println("OSC did not start.");

delay(200);

if (!Hid.SetReportParser(0, &SpaceNavigator))
ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
}

void loop() {
Usb.Task();
}
