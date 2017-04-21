#if !defined(__HIDSPACENAVIGATORRPTPARSER_H__)
#define __HIDSPACENAVIGATORRPTPARSER_H__

#include <usbhid.h>

struct SpaceNavigatorEventData {
    uint8_t rptid, xl, xh, yl, yh, zl, zh;
};

class SpaceNavigatorEvent {
public:
    SpaceNavigatorEvent() { Tx=Ty=Tz=Rx=Ry=Rz=0; };
    virtual void OnSpaceNavigatorChanged(const SpaceNavigatorEventData *evt);
    virtual void OnButton(uint8_t but_id);

    int16_t Tx, Ty, Tz, Rx, Ry, Rz;
};

class SpaceNavigatorReportParser : public HIDReportParser {
    SpaceNavigatorEvent *spaceNavigatorEvent;
    
public:
    SpaceNavigatorReportParser(SpaceNavigatorEvent *evt);
    
    virtual void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
};

#endif // __HIDSPACENAVIGATORRPTPARSER_H__
