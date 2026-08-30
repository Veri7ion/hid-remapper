#include <cstring>

#include "globals.h"
#include "our_descriptor.h"
#include "ps_auth.h"
#include "remapper.h"

const uint8_t REPORT_ID_MOUSE = 1;
const uint8_t REPORT_ID_KEYBOARD = 2;
const uint8_t REPORT_ID_CONSUMER = 3;

const uint8_t our_report_descriptor_kb_mouse[] = {
    0x05, 0x01,                // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,                // Usage (Keyboard)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_KEYBOARD,  //   Report ID (REPORT_ID_KEYBOARD)
    0x05, 0x07,                //   Usage Page (Kbrd/Keypad)
    0x19, 0xE0,                //   Usage Minimum (0xE0)
    0x29, 0xE7,                //   Usage Maximum (0xE7)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x08,                //   Report Count (8)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x19, 0x04,                //   Usage Minimum (0x04)
    0x29, 0x73,                //   Usage Maximum (0x73)
    0x95, 0x70,                //   Report Count (112)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x19, 0x87,                //   Usage Minimum (0x87)
    0x29, 0x8B,                //   Usage Maximum (0x8B)
    0x95, 0x05,                //   Report Count (5)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0x90,                //   Usage (0x90)
    0x09, 0x91,                //   Usage (0x91)
    0x95, 0x02,                //   Report Count (2)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x95, 0x01,                //   Report Count (1)
    0x81, 0x03,                //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x85, REPORT_ID_LEDS,      //   Report ID (REPORT_ID_LEDS)
    0x05, 0x08,                //   Usage Page (LEDs)
    0x95, 0x05,                //   Report Count (5)
    0x19, 0x01,                //   Usage Minimum (Num Lock)
    0x29, 0x05,                //   Usage Maximum (Kana)
    0x91, 0x02,                //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x95, 0x01,                //   Report Count (1)
    0x75, 0x03,                //   Report Size (3)
    0x91, 0x03,                //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,                      // End Collection

    0x05, 0x01,                   // Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                   // Usage (Mouse)
    0xA1, 0x01,                   // Collection (Application)
    0x05, 0x01,                   //   Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                   //   Usage (Mouse)
    0xA1, 0x02,                   //   Collection (Logical)
    0x85, REPORT_ID_MOUSE,        //     Report ID (REPORT_ID_MOUSE)
    0x09, 0x01,                   //     Usage (Pointer)
    0xA1, 0x00,                   //     Collection (Physical)
    0x05, 0x09,                   //       Usage Page (Button)
    0x19, 0x01,                   //       Usage Minimum (0x01)
    0x29, 0x08,                   //       Usage Maximum (0x08)
    0x95, 0x08,                   //       Report Count (8)
    0x75, 0x01,                   //       Report Size (1)
    0x25, 0x01,                   //       Logical Maximum (1)
    0x81, 0x02,                   //       Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,                   //       Usage Page (Generic Desktop Ctrls)
    0x09, 0x30,                   //       Usage (X)
    0x09, 0x31,                   //       Usage (Y)
    0x95, 0x02,                   //       Report Count (2)
    0x75, 0x10,                   //       Report Size (16)
    0x16, 0x00, 0x80,             //       Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //       Logical Maximum (32767)
    0x81, 0x06,                   //       Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xA1, 0x02,                   //       Collection (Logical)
    0x85, REPORT_ID_MULTIPLIER,   //         Report ID (REPORT_ID_MULTIPLIER)
    0x09, 0x48,                   //         Usage (Resolution Multiplier)
    0x95, 0x01,                   //         Report Count (1)
    0x75, 0x02,                   //         Report Size (2)
    0x15, 0x00,                   //         Logical Minimum (0)
    0x25, 0x01,                   //         Logical Maximum (1)
    0x35, 0x01,                   //         Physical Minimum (1)
    0x45, RESOLUTION_MULTIPLIER,  //         Physical Maximum (RESOLUTION_MULTIPLIER)
    0xB1, 0x02,                   //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, REPORT_ID_MOUSE,        //         Report ID (REPORT_ID_MOUSE)
    0x09, 0x38,                   //         Usage (Wheel)
    0x35, 0x00,                   //         Physical Minimum (0)
    0x45, 0x00,                   //         Physical Maximum (0)
    0x16, 0x00, 0x80,             //         Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //         Logical Maximum (32767)
    0x75, 0x10,                   //         Report Size (16)
    0x81, 0x06,                   //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                         //       End Collection
    0xA1, 0x02,                   //       Collection (Logical)
    0x85, REPORT_ID_MULTIPLIER,   //         Report ID (REPORT_ID_MULTIPLIER)
    0x09, 0x48,                   //         Usage (Resolution Multiplier)
    0x75, 0x02,                   //         Report Size (2)
    0x15, 0x00,                   //         Logical Minimum (0)
    0x25, 0x01,                   //         Logical Maximum (1)
    0x35, 0x01,                   //         Physical Minimum (1)
    0x45, RESOLUTION_MULTIPLIER,  //         Physical Maximum (RESOLUTION_MULTIPLIER)
    0xB1, 0x02,                   //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x35, 0x00,                   //         Physical Minimum (0)
    0x45, 0x00,                   //         Physical Maximum (0)
    0x75, 0x04,                   //         Report Size (4)
    0xB1, 0x03,                   //         Feature (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, REPORT_ID_MOUSE,        //         Report ID (REPORT_ID_MOUSE)
    0x05, 0x0C,                   //         Usage Page (Consumer)
    0x16, 0x00, 0x80,             //         Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //         Logical Maximum (32767)
    0x75, 0x10,                   //         Report Size (16)
    0x0A, 0x38, 0x02,             //         Usage (AC Pan)
    0x81, 0x06,                   //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                         //       End Collection
    0xC0,                         //     End Collection
    0xC0,                         //   End Collection
    0xC0,                         // End Collection

    0x05, 0x0C,                // Usage Page (Consumer)
    0x09, 0x01,                // Usage (Consumer Control)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_CONSUMER,  //   Report ID (REPORT_ID_CONSUMER)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x09, 0xB5,                //   Usage (Scan Next Track)
    0x09, 0xB6,                //   Usage (Scan Previous Track)
    0x09, 0xB7,                //   Usage (Stop)
    0x09, 0xCD,                //   Usage (Play/Pause)
    0x09, 0xE2,                //   Usage (Mute)
    0x09, 0xE9,                //   Usage (Volume Increment)
    0x09, 0xEA,                //   Usage (Volume Decrement)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x07,                //   Report Count (7)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x0B,                //   Usage Page (Telephony)
    0x09, 0x2F,                //   Usage (Phone Mute)
    0x95, 0x01,                //   Report Count (1)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                      // End Collection
};

const uint8_t our_report_descriptor_absolute[] = {
    0x05, 0x01,                // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,                // Usage (Keyboard)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_KEYBOARD,  //   Report ID (REPORT_ID_KEYBOARD)
    0x05, 0x07,                //   Usage Page (Kbrd/Keypad)
    0x19, 0xE0,                //   Usage Minimum (0xE0)
    0x29, 0xE7,                //   Usage Maximum (0xE7)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x08,                //   Report Count (8)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x19, 0x04,                //   Usage Minimum (0x04)
    0x29, 0x73,                //   Usage Maximum (0x73)
    0x95, 0x70,                //   Report Count (112)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x19, 0x87,                //   Usage Minimum (0x87)
    0x29, 0x8B,                //   Usage Maximum (0x8B)
    0x95, 0x05,                //   Report Count (5)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0x90,                //   Usage (0x90)
    0x09, 0x91,                //   Usage (0x91)
    0x95, 0x02,                //   Report Count (2)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x95, 0x01,                //   Report Count (1)
    0x81, 0x03,                //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x85, REPORT_ID_LEDS,      //   Report ID (REPORT_ID_LEDS)
    0x05, 0x08,                //   Usage Page (LEDs)
    0x95, 0x05,                //   Report Count (5)
    0x19, 0x01,                //   Usage Minimum (Num Lock)
    0x29, 0x05,                //   Usage Maximum (Kana)
    0x91, 0x02,                //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x95, 0x01,                //   Report Count (1)
    0x75, 0x03,                //   Report Size (3)
    0x91, 0x03,                //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,                      // End Collection

    0x05, 0x01,                   // Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                   // Usage (Mouse)
    0xA1, 0x01,                   // Collection (Application)
    0x05, 0x01,                   //   Usage Page (Generic Desktop Ctrls)
    0x09, 0x02,                   //   Usage (Mouse)
    0xA1, 0x02,                   //   Collection (Logical)
    0x85, REPORT_ID_MOUSE,        //     Report ID (REPORT_ID_MOUSE)
    0x09, 0x01,                   //     Usage (Pointer)
    0xA1, 0x00,                   //     Collection (Physical)
    0x05, 0x09,                   //       Usage Page (Button)
    0x19, 0x01,                   //       Usage Minimum (0x01)
    0x29, 0x08,                   //       Usage Maximum (0x08)
    0x95, 0x08,                   //       Report Count (8)
    0x75, 0x01,                   //       Report Size (1)
    0x25, 0x01,                   //       Logical Maximum (1)
    0x81, 0x02,                   //       Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,                   //       Usage Page (Generic Desktop Ctrls)
    0x09, 0x30,                   //       Usage (X)
    0x09, 0x31,                   //       Usage (Y)
    0x95, 0x02,                   //       Report Count (2)
    0x75, 0x10,                   //       Report Size (16)
    0x16, 0x00, 0x00,             //       Logical Minimum (0)
    0x26, 0xFF, 0x7F,             //       Logical Maximum (32767)
    0x81, 0x02,                   //       Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xA1, 0x02,                   //       Collection (Logical)
    0x85, REPORT_ID_MULTIPLIER,   //         Report ID (REPORT_ID_MULTIPLIER)
    0x09, 0x48,                   //         Usage (Resolution Multiplier)
    0x95, 0x01,                   //         Report Count (1)
    0x75, 0x02,                   //         Report Size (2)
    0x15, 0x00,                   //         Logical Minimum (0)
    0x25, 0x01,                   //         Logical Maximum (1)
    0x35, 0x01,                   //         Physical Minimum (1)
    0x45, RESOLUTION_MULTIPLIER,  //         Physical Maximum (RESOLUTION_MULTIPLIER)
    0xB1, 0x02,                   //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, REPORT_ID_MOUSE,        //         Report ID (REPORT_ID_MOUSE)
    0x09, 0x38,                   //         Usage (Wheel)
    0x35, 0x00,                   //         Physical Minimum (0)
    0x45, 0x00,                   //         Physical Maximum (0)
    0x16, 0x00, 0x80,             //         Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //         Logical Maximum (32767)
    0x75, 0x10,                   //         Report Size (16)
    0x81, 0x06,                   //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                         //       End Collection
    0xA1, 0x02,                   //       Collection (Logical)
    0x85, REPORT_ID_MULTIPLIER,   //         Report ID (REPORT_ID_MULTIPLIER)
    0x09, 0x48,                   //         Usage (Resolution Multiplier)
    0x75, 0x02,                   //         Report Size (2)
    0x15, 0x00,                   //         Logical Minimum (0)
    0x25, 0x01,                   //         Logical Maximum (1)
    0x35, 0x01,                   //         Physical Minimum (1)
    0x45, RESOLUTION_MULTIPLIER,  //         Physical Maximum (RESOLUTION_MULTIPLIER)
    0xB1, 0x02,                   //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x35, 0x00,                   //         Physical Minimum (0)
    0x45, 0x00,                   //         Physical Maximum (0)
    0x75, 0x04,                   //         Report Size (4)
    0xB1, 0x03,                   //         Feature (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, REPORT_ID_MOUSE,        //         Report ID (REPORT_ID_MOUSE)
    0x05, 0x0C,                   //         Usage Page (Consumer)
    0x16, 0x00, 0x80,             //         Logical Minimum (-32768)
    0x26, 0xFF, 0x7F,             //         Logical Maximum (32767)
    0x75, 0x10,                   //         Report Size (16)
    0x0A, 0x38, 0x02,             //         Usage (AC Pan)
    0x81, 0x06,                   //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                         //       End Collection
    0xC0,                         //     End Collection
    0xC0,                         //   End Collection
    0xC0,                         // End Collection

    0x05, 0x0C,                // Usage Page (Consumer)
    0x09, 0x01,                // Usage (Consumer Control)
    0xA1, 0x01,                // Collection (Application)
    0x85, REPORT_ID_CONSUMER,  //   Report ID (REPORT_ID_CONSUMER)
    0x15, 0x00,                //   Logical Minimum (0)
    0x25, 0x01,                //   Logical Maximum (1)
    0x09, 0xB5,                //   Usage (Scan Next Track)
    0x09, 0xB6,                //   Usage (Scan Previous Track)
    0x09, 0xB7,                //   Usage (Stop)
    0x09, 0xCD,                //   Usage (Play/Pause)
    0x09, 0xE2,                //   Usage (Mute)
    0x09, 0xE9,                //   Usage (Volume Increment)
    0x09, 0xEA,                //   Usage (Volume Decrement)
    0x75, 0x01,                //   Report Size (1)
    0x95, 0x07,                //   Report Count (7)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x0B,                //   Usage Page (Telephony)
    0x09, 0x2F,                //   Usage (Phone Mute)
    0x95, 0x01,                //   Report Count (1)
    0x81, 0x02,                //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                      // End Collection
};

const uint8_t our_report_descriptor_horipad[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x35, 0x00,        //   Physical Minimum (0)
    0x45, 0x01,        //   Physical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x0E,        //   Report Count (14)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (0x01)
    0x29, 0x0E,        //   Usage Maximum (0x0E)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x95, 0x02,        //   Report Count (2)
    0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
    0x25, 0x07,        //   Logical Maximum (7)
    0x46, 0x3B, 0x01,  //   Physical Maximum (315)
    0x75, 0x04,        //   Report Size (4)
    0x95, 0x01,        //   Report Count (1)
    0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
    0x09, 0x39,        //   Usage (Hat switch)
    0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
    0x65, 0x00,        //   Unit (None)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x46, 0xFF, 0x00,  //   Physical Maximum (255)
    0x09, 0x30,        //   Usage (X)
    0x09, 0x31,        //   Usage (Y)
    0x09, 0x32,        //   Usage (Z)
    0x09, 0x35,        //   Usage (Rz)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x04,        //   Report Count (4)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,              // End Collection
};

// Genuine DualShock 4 report descriptor, copied from the OpenPuck HIDGYRO implementation.
// This is the descriptor that makes Windows / SDL / DS4Windows recognize the emulated pad as a DS4,
// with the feature reports needed for MAC/device inspection and firmware metadata.
const uint8_t our_report_descriptor_ds4_hidgyro[] = {
    0x05, 0x01, 0x09, 0x05, 0xA1, 0x01, 0x85, 0x01, 0x09, 0x30, 0x09, 0x31,
    0x09, 0x32, 0x09, 0x35, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95,
    0x04, 0x81, 0x02, 0x09, 0x39, 0x15, 0x00, 0x25, 0x07, 0x35, 0x00, 0x46,
    0x3B, 0x01, 0x65, 0x14, 0x75, 0x04, 0x95, 0x01, 0x81, 0x42, 0x65, 0x00,
    0x05, 0x09, 0x19, 0x01, 0x29, 0x0E, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01,
    0x95, 0x0E, 0x81, 0x02, 0x06, 0x00, 0xFF, 0x09, 0x20, 0x75, 0x06, 0x95,
    0x01, 0x15, 0x00, 0x25, 0x7F, 0x81, 0x02, 0x05, 0x01, 0x09, 0x33, 0x09,
    0x34, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95, 0x02, 0x81, 0x02,
    0x06, 0x00, 0xFF, 0x09, 0x21, 0x95, 0x36, 0x81, 0x02, 0x85, 0x05, 0x09,
    0x22, 0x95, 0x1F, 0x91, 0x02, 0x85, 0x04, 0x09, 0x23, 0x95, 0x24, 0xB1,
    0x02, 0x85, 0x02, 0x09, 0x24, 0x95, 0x24, 0xB1, 0x02, 0x85, 0x08, 0x09,
    0x25, 0x95, 0x03, 0xB1, 0x02, 0x85, 0x10, 0x09, 0x26, 0x95, 0x04, 0xB1,
    0x02, 0x85, 0x11, 0x09, 0x27, 0x95, 0x02, 0xB1, 0x02, 0x85, 0x12, 0x06,
    0x02, 0xFF, 0x09, 0x21, 0x95, 0x0F, 0xB1, 0x02, 0x85, 0x13, 0x09, 0x22,
    0x95, 0x16, 0xB1, 0x02, 0x85, 0x14, 0x06, 0x05, 0xFF, 0x09, 0x20, 0x95,
    0x10, 0xB1, 0x02, 0x85, 0x15, 0x09, 0x21, 0x95, 0x2C, 0xB1, 0x02, 0x06,
    0x80, 0xFF, 0x85, 0x80, 0x09, 0x20, 0x95, 0x06, 0xB1, 0x02, 0x85, 0x81,
    0x09, 0x21, 0x95, 0x06, 0xB1, 0x02, 0x85, 0x82, 0x09, 0x22, 0x95, 0x05,
    0xB1, 0x02, 0x85, 0x83, 0x09, 0x23, 0x95, 0x01, 0xB1, 0x02, 0x85, 0x84,
    0x09, 0x24, 0x95, 0x04, 0xB1, 0x02, 0x85, 0x85, 0x09, 0x25, 0x95, 0x06,
    0xB1, 0x02, 0x85, 0x86, 0x09, 0x26, 0x95, 0x06, 0xB1, 0x02, 0x85, 0x87,
    0x09, 0x27, 0x95, 0x23, 0xB1, 0x02, 0x85, 0x88, 0x09, 0x28, 0x95, 0x22,
    0xB1, 0x02, 0x85, 0x89, 0x09, 0x29, 0x95, 0x02, 0xB1, 0x02, 0x85, 0x90,
    0x09, 0x30, 0x95, 0x05, 0xB1, 0x02, 0x85, 0x91, 0x09, 0x31, 0x95, 0x03,
    0xB1, 0x02, 0x85, 0x92, 0x09, 0x32, 0x95, 0x03, 0xB1, 0x02, 0x85, 0x93,
    0x09, 0x33, 0x95, 0x0C, 0xB1, 0x02, 0x85, 0xA0, 0x09, 0x40, 0x95, 0x06,
    0xB1, 0x02, 0x85, 0xA1, 0x09, 0x41, 0x95, 0x01, 0xB1, 0x02, 0x85, 0xA2,
    0x09, 0x42, 0x95, 0x01, 0xB1, 0x02, 0x85, 0xA3, 0x09, 0x43, 0x95, 0x30,
    0xB1, 0x02, 0x85, 0xA4, 0x09, 0x44, 0x95, 0x0D, 0xB1, 0x02, 0x85, 0xA5,
    0x09, 0x45, 0x95, 0x15, 0xB1, 0x02, 0x85, 0xA6, 0x09, 0x46, 0x95, 0x15,
    0xB1, 0x02, 0x85, 0xF0, 0x09, 0x47, 0x95, 0x3F, 0xB1, 0x02, 0x85, 0xF1,
    0x09, 0x48, 0x95, 0x3F, 0xB1, 0x02, 0x85, 0xF2, 0x09, 0x49, 0x95, 0x0F,
    0xB1, 0x02, 0x85, 0xA7, 0x09, 0x4A, 0x95, 0x01, 0xB1, 0x02, 0x85, 0xA8,
    0x09, 0x4B, 0x95, 0x01, 0xB1, 0x02, 0x85, 0xA9, 0x09, 0x4C, 0x95, 0x08,
    0xB1, 0x02, 0x85, 0xAA, 0x09, 0x4E, 0x95, 0x01, 0xB1, 0x02, 0x85, 0xAB,
    0x09, 0x4F, 0x95, 0x39, 0xB1, 0x02, 0x85, 0xAC, 0x09, 0x50, 0x95, 0x39,
    0xB1, 0x02, 0x85, 0xAD, 0x09, 0x51, 0x95, 0x0B, 0xB1, 0x02, 0x85, 0xAE,
    0x09, 0x52, 0x95, 0x01, 0xB1, 0x02, 0x85, 0xAF, 0x09, 0x53, 0x95, 0x02,
    0xB1, 0x02, 0x85, 0xB0, 0x09, 0x54, 0x95, 0x3F, 0xB1, 0x02, 0xC0
};

uint8_t const our_report_descriptor_ps4[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)
    0x85, 0x01,        //   Report ID (1)
    0x09, 0x30,        //   Usage (X)
    0x09, 0x31,        //   Usage (Y)
    0x09, 0x32,        //   Usage (Z)
    0x09, 0x35,        //   Usage (Rz)
    0x15, 0x00,        //   Logical Minimum (0)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x04,        //   Report Count (4)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0x39,        //   Usage (Hat switch)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x07,        //   Logical Maximum (7)
    0x35, 0x00,        //   Physical Minimum (0)
    0x46, 0x3B, 0x01,  //   Physical Maximum (315)
    0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
    0x75, 0x04,        //   Report Size (4)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
    0x65, 0x00,        //   Unit (None)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (0x01)
    0x29, 0x0E,        //   Usage Maximum (0x0E)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x0E,        //   Report Count (14)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x06, 0x00, 0xFF,  //   Usage Page (Vendor Defined 0xFF00)
    0x09, 0x20,        //   Usage (0x20)
    0x75, 0x06,        //   Report Size (6)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
    0x09, 0x33,        //   Usage (Rx)
    0x09, 0x34,        //   Usage (Ry)
    0x15, 0x00,        //   Logical Minimum (0)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x02,        //   Report Count (2)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x06, 0x00, 0xFF,  //   Usage Page (Vendor Defined 0xFF00)
    0x09, 0x21,        //   Usage (0x21)
    0x95, 0x36,        //   Report Count (54)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x85, 0x05,        //   Report ID (5)
    0x09, 0x22,        //   Usage (0x22)
    0x95, 0x1F,        //   Report Count (31)
    0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, 0x03,        //   Report ID (3)
    0x0A, 0x21, 0x27,  //   Usage (0x2721)
    0x95, 0x2F,        //   Report Count (47)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x06, 0x80, 0xFF,  //   Usage Page (Vendor Defined 0xFF80)
    0x85, 0xE0,        //   Report ID (-32)
    0x09, 0x57,        //   Usage (0x57)
    0x95, 0x02,        //   Report Count (2)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,              // End Collection
    0x06, 0xF0, 0xFF,  // Usage Page (Vendor Defined 0xFFF0)
    0x09, 0x40,        // Usage (0x40)
    0xA1, 0x01,        // Collection (Application)
    0x85, 0xF0,        //   Report ID (-16)
    0x09, 0x47,        //   Usage (0x47)
    0x95, 0x3F,        //   Report Count (63)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, 0xF1,        //   Report ID (-15)
    0x09, 0x48,        //   Usage (0x48)
    0x95, 0x3F,        //   Report Count (63)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, 0xF2,        //   Report ID (-14)
    0x09, 0x49,        //   Usage (0x49)
    0x95, 0x0F,        //   Report Count (15)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x85, 0xF3,        //   Report ID (-13)
    0x0A, 0x01, 0x47,  //   Usage (0x4701)
    0x95, 0x07,        //   Report Count (7)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,              // End Collection
};

uint8_t const our_report_descriptor_stadia[] = {
    0x05, 0x01,                    // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,                    // Usage (Game Pad)
    0xA1, 0x01,                    // Collection (Application)
    0x85, 0x03,                    //   Report ID (3)
    0x05, 0x01,                    //   Usage Page (Generic Desktop Ctrls)
    0x75, 0x04,                    //   Report Size (4)
    0x95, 0x01,                    //   Report Count (1)
    0x25, 0x07,                    //   Logical Maximum (7)
    0x46, 0x3B, 0x01,              //   Physical Maximum (315)
    0x65, 0x14,                    //   Unit (System: English Rotation, Length: Centimeter)
    0x09, 0x39,                    //   Usage (Hat switch)
    0x81, 0x42,                    //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
    0x45, 0x00,                    //   Physical Maximum (0)
    0x65, 0x00,                    //   Unit (None)
    0x75, 0x01,                    //   Report Size (1)
    0x95, 0x04,                    //   Report Count (4)
    0x81, 0x01,                    //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x09,                    //   Usage Page (Button)
    0x15, 0x00,                    //   Logical Minimum (0)
    0x25, 0x01,                    //   Logical Maximum (1)
    0x75, 0x01,                    //   Report Size (1)
    0x95, 0x0F,                    //   Report Count (15)
    0x09, 0x12,                    //   Usage (0x12)
    0x09, 0x11,                    //   Usage (0x11)
    0x09, 0x14,                    //   Usage (0x14)
    0x09, 0x13,                    //   Usage (0x13)
    0x09, 0x0D,                    //   Usage (0x0D)
    0x09, 0x0C,                    //   Usage (0x0C)
    0x09, 0x0B,                    //   Usage (0x0B)
    0x09, 0x0F,                    //   Usage (0x0F)
    0x09, 0x0E,                    //   Usage (0x0E)
    0x09, 0x08,                    //   Usage (0x08)
    0x09, 0x07,                    //   Usage (0x07)
    0x09, 0x05,                    //   Usage (0x05)
    0x09, 0x04,                    //   Usage (0x04)
    0x09, 0x02,                    //   Usage (0x02)
    0x09, 0x01,                    //   Usage (0x01)
    0x81, 0x02,                    //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x75, 0x01,                    //   Report Size (1)
    0x95, 0x01,                    //   Report Count (1)
    0x81, 0x01,                    //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x01,                    //   Usage Page (Generic Desktop Ctrls)
    0x15, 0x01,                    //   Logical Minimum (1)
    0x26, 0xFF, 0x00,              //   Logical Maximum (255)
    0x09, 0x01,                    //   Usage (Pointer)
    0xA1, 0x00,                    //   Collection (Physical)
    0x09, 0x30,                    //     Usage (X)
    0x09, 0x31,                    //     Usage (Y)
    0x75, 0x08,                    //     Report Size (8)
    0x95, 0x02,                    //     Report Count (2)
    0x81, 0x02,                    //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                          //   End Collection
    0x09, 0x01,                    //   Usage (Pointer)
    0xA1, 0x00,                    //   Collection (Physical)
    0x09, 0x32,                    //     Usage (Z)
    0x09, 0x35,                    //     Usage (Rz)
    0x75, 0x08,                    //     Report Size (8)
    0x95, 0x02,                    //     Report Count (2)
    0x81, 0x02,                    //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                          //   End Collection
    0x05, 0x02,                    //   Usage Page (Sim Ctrls)
    0x75, 0x08,                    //   Report Size (8)
    0x95, 0x02,                    //   Report Count (2)
    0x15, 0x00,                    //   Logical Minimum (0)
    0x26, 0xFF, 0x00,              //   Logical Maximum (255)
    0x09, 0xC5,                    //   Usage (Brake)
    0x09, 0xC4,                    //   Usage (Accelerator)
    0x81, 0x02,                    //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x0C,                    //   Usage Page (Consumer)
    0x15, 0x00,                    //   Logical Minimum (0)
    0x25, 0x01,                    //   Logical Maximum (1)
    0x09, 0xE9,                    //   Usage (Volume Increment)
    0x09, 0xEA,                    //   Usage (Volume Decrement)
    0x75, 0x01,                    //   Report Size (1)
    0x95, 0x02,                    //   Report Count (2)
    0x81, 0x02,                    //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0xCD,                    //   Usage (Play/Pause)
    0x95, 0x01,                    //   Report Count (1)
    0x81, 0x02,                    //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x95, 0x05,                    //   Report Count (5)
    0x81, 0x01,                    //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x85, 0x05,                    //   Report ID (5)
    0x06, 0x0F, 0x00,              //   Usage Page (PID Page)
    0x09, 0x97,                    //   Usage (0x97)
    0x75, 0x10,                    //   Report Size (16)
    0x95, 0x02,                    //   Report Count (2)
    0x27, 0xFF, 0xFF, 0x00, 0x00,  //   Logical Maximum (65535)
    0x91, 0x02,                    //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,                          // End Collection
};

uint8_t const our_report_descriptor_xac_compat[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)
    0x09, 0x30,        //   Usage (X)
    0x09, 0x31,        //   Usage (Y)
    0x09, 0x32,        //   Usage (Z)
    0x09, 0x35,        //   Usage (Rz)
    0x15, 0x00,        //   Logical Minimum (0)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x04,        //   Report Count (4)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x09, 0x39,        //   Usage (Hat switch)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x07,        //   Logical Maximum (7)
    0x35, 0x00,        //   Physical Minimum (0)
    0x46, 0x3B, 0x01,  //   Physical Maximum (315)
    0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
    0x75, 0x04,        //   Report Size (4)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
    0x65, 0x00,        //   Unit (None)
    0x45, 0x00,        //   Physical Maximum (0)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (0x01)
    0x29, 0x0C,        //   Usage Maximum (0x0C)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x0C,        //   Report Count (12)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,              // End Collection
};

void kb_mouse_handle_set_report(uint8_t report_id, const uint8_t* buffer, uint16_t reqlen) {
    if (report_id == REPORT_ID_MULTIPLIER && reqlen >= 1) {
        memcpy(&resolution_multiplier, buffer, 1);
    } else if (boot_protocol_keyboard || (report_id == REPORT_ID_LEDS)) {
        handle_received_report(buffer, reqlen, OUR_OUT_INTERFACE, report_id);
    }
}

bool kb_mouse_set_report_synchronous(uint8_t report_id) {
    return (report_id == REPORT_ID_MULTIPLIER);
}

uint16_t kb_mouse_handle_get_report(uint8_t report_id, uint8_t* buffer, uint16_t reqlen) {
    if (report_id == REPORT_ID_MULTIPLIER && reqlen >= 1) {
        memcpy(buffer, &resolution_multiplier, 1);
        return 1;
    }
    return 0;
}

bool kb_mouse_should_cause_wakeup(uint8_t report_id, const uint8_t* buffer, uint16_t len) {
    if ((report_id == REPORT_ID_KEYBOARD) || (report_id == REPORT_ID_CONSUMER)) {
        for (uint16_t i = 0; i < len; i++) {
            if (buffer[i] != 0) {
                return true;
            }
        }
        return false;
    }

    if (report_id == REPORT_ID_MOUSE) {
        if ((len > 0) && (buffer[0] != 0)) {
            return true;
        }
        return false;
    }

    return false;
}

static const uint8_t horipad_neutral[] = { 0x00, 0x00, 0x0F, 0x80, 0x80, 0x80, 0x80, 0x00 };

void horipad_clear_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    memcpy(report, horipad_neutral, sizeof(horipad_neutral));
}

void ps4_clear_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    memset(report, 0, len);
    report[0] = report[1] = report[2] = report[3] = 0x80;
    report[4] = 0x08;
    report[34] = report[38] = 0b10000000;  // touchpad, 1 means finger not touching
}

static const uint8_t stadia_neutral[] = { 0x08, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00 };

void stadia_clear_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    memcpy(report, stadia_neutral, sizeof(stadia_neutral));
}

static const uint8_t xac_compat_neutral[] = { 0x80, 0x80, 0x80, 0x80, 0x08, 0x00 };

void xac_compat_clear_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    memcpy(report, xac_compat_neutral, sizeof(xac_compat_neutral));
}

static const uint8_t ds4_mac_base[] = { 0x00, 0x1B, 0xDC, 0x4F, 0x55 };
static uint8_t ds4_mac[6] = { 0x00, 0x1B, 0xDC, 0x4F, 0x55, 0x50 };

static void ds4_fill_calibration(uint8_t* buf) {
    memset(buf, 0, 36);
    buf[0] = 0x00;
    buf[6] = 0x00;
    buf[7] = 0x10;
    buf[8] = 0x00;
    buf[9] = 0xF0;
    buf[10] = 0x00;
    buf[11] = 0x10;
    buf[12] = 0x00;
    buf[13] = 0xF0;
    buf[14] = 0x00;
    buf[15] = 0x10;
    buf[16] = 0x00;
    buf[17] = 0xF0;
    buf[18] = 0x00;
    buf[19] = 0x01;
    buf[20] = 0x00;
    buf[21] = 0x01;
    buf[22] = 0x20;
    buf[23] = 0x00;
    buf[24] = 0x20;
    buf[25] = 0x00;
    buf[26] = 0x20;
    buf[27] = 0x00;
    buf[28] = 0x20;
    buf[29] = 0x00;
    buf[30] = 0x20;
    buf[31] = 0x00;
    buf[32] = 0x20;
    buf[33] = 0x00;
    buf[34] = 0x20;
    buf[35] = 0x00;
}

uint16_t ds4_handle_get_report(uint8_t report_id, uint8_t* buffer, uint16_t reqlen) {
    switch (report_id) {
        case 0x02: {
            if (reqlen < 36) {
                return 0;
            }
            ds4_fill_calibration(buffer);
            return 36;
        }
        case 0x12: {
            if (reqlen < 15) {
                return 0;
            }
            memcpy(buffer, ds4_mac, 6);
            memset(buffer + 6, 0, reqlen - 6);
            return 15;
        }
        case 0x81: {
            if (reqlen < 6) {
                return 0;
            }
            memcpy(buffer, ds4_mac, 6);
            return 6;
        }
        case 0xA3: {
            if (reqlen < 48) {
                return 0;
            }
            memset(buffer, 0, reqlen);
            buffer[0] = 0x01;
            return 48;
        }
        default:
            return 0;
    }
}

void ds4_handle_set_report(uint8_t report_id, const uint8_t* buffer, uint16_t reqlen) {
    if (report_id == 0x05 && reqlen >= 5) {
        // Rumble packets are accepted, but this firmware does not route them to a local haptics engine.
        // The host still sees a valid DS4 output endpoint, which is enough for compatibility.
    }
}

// ============================================================================
// DS4 Report Building Helpers (adapted from OpenPuck gamepad_util)
// ============================================================================

#define DS4_TOUCH_PAD_W 1920u
#define DS4_TOUCH_PAD_H 942u
#define DS4_STATUS_USB_CONNECTED 0x1B  // cable + battery level 11 (full)

// Convert Steam stick value (int16, center=0) to DS4 format (uint8, center=0x80).
// invert: true for Y axis to flip direction per HID convention.
static uint8_t ds4_stick_pack(int16_t v, bool invert) {
    int32_t scaled = 0x80 + (invert ? -((int32_t)v >> 8) : ((int32_t)v >> 8));
    if (scaled < 0) scaled = 0;
    if (scaled > 255) scaled = 255;
    return (uint8_t)scaled;
}

// Write a signed 16-bit value in little-endian format.
static void ds4_le16(uint8_t *p, int16_t v) {
    p[0] = (uint8_t)(v & 0xFF);
    p[1] = (uint8_t)((v >> 8) & 0xFF);
}

// Pack gyro and accelerometer data.
// Gyro: X/Y/Z; Accel: X/Y/Z (6 little-endian int16s, total 12 bytes).
// Axes are permuted and scaled to match PlayStation conventions (SDL's hid_hidapi_steam_triton.c).
static void ds4_pack_imu(uint8_t *out, int16_t gx, int16_t gy, int16_t gz,
                          int16_t ax, int16_t ay, int16_t az) {
    // Steam Controller to DS4 axis mapping: X <- gx, Y <- gz, Z <- -gy
    ds4_le16(out + 0, gx);
    ds4_le16(out + 2, gz);
    ds4_le16(out + 4, (int16_t)(-gy));
    // Accel: same frame permutation; halve because SC2 is 2g full-scale (~16384 counts/g)
    // and DS4 is 8192 counts/g
    ds4_le16(out + 6, (int16_t)(ax / 2));
    ds4_le16(out + 8, (int16_t)(az / 2));
    ds4_le16(out + 10, (int16_t)(-(ay / 2)));
}

// Map Steam trackpad coordinate (s16, -32768..32767) to touchpad coordinate in range [0..max).
static uint16_t ds4_pad_norm_u16(int16_t v, uint16_t maxv) {
    int32_t t = ((int32_t)v + 32768);
    if (t < 0) t = 0;
    if (t > 65535) t = 65535;
    return (uint16_t)((t * (int32_t)maxv) / 65535);
}

// Map trackpad X to left/right half of DS4 touch surface.
static uint16_t ds4_touch_x(int16_t v, bool right_half) {
    uint16_t half_max = DS4_TOUCH_PAD_W / 2 - 1;
    uint16_t x = ds4_pad_norm_u16(v, half_max);
    return right_half ? (uint16_t)(DS4_TOUCH_PAD_W / 2 + x) : x;
}

// Map trackpad Y, inverted (higher Steam Y -> lower DS4 Y).
static uint16_t ds4_touch_y(int16_t v) {
    uint16_t maxy = DS4_TOUCH_PAD_H - 1;
    return (uint16_t)(maxy - ds4_pad_norm_u16(v, maxy));
}

// Pack a single touch point (contact) into DS4 format (4 bytes per contact).
// Contacts: 2 slots, 4 bytes each at offset 34+ in the input report.
static void ds4_pack_touch_point(uint8_t *base, int finger, bool touch, uint16_t x, uint16_t y) {
    uint8_t *f = base + finger * 4;
    if (!touch) {
        f[0] = 0x80;  // not touching
        f[1] = 0;
        f[2] = 0;
        f[3] = 0;
        return;
    }
    f[0] = (uint8_t)(finger & 0x7F);  // finger ID, bit 7 = 0 means touching
    f[1] = (uint8_t)(x & 0xFF);
    f[2] = (uint8_t)(((x >> 8) & 0x0F) | ((y & 0x0F) << 4));
    f[3] = (uint8_t)((y >> 4) & 0xFF);
}

// Helper to extract dpad and button nibbles from generic button bits.
// These are simplified versions; in production you'd map from controller input.
static uint8_t ds4_hat_nibble(uint32_t hat_state) {
    // hat_state encodes up/down/left/right directional bits
    // For now, return 0x08 (neutral) -- actual mapping depends on input parsing
    return 0x08;
}

static uint8_t ds4_face_nibble(uint32_t face_state) {
    // face_state encodes A/B/X/Y button bits
    // Nibble format: bit7=Y, bit6=B, bit5=A, bit4=X (PS layout)
    return 0x00;  // All buttons released by default
}

// Pack DS4 input report from Steam Controller state.
// Called after normal descriptor remapping fills in basic button/stick/trigger data.
// This function adds motion (gyro/accel) and touchpad data.
static void ds4_build_report(uint8_t* report, uint8_t report_id, uint16_t len) {
    if (report_id != 0x01 || len < 64) {
        return;  // Only handle report ID 0x01, minimum 64 bytes
    }

    // Note: The descriptor-based remapping will have already filled in:
    // - Sticks at bytes 0-3
    // - Hat/face at byte 4
    // - Shoulders at byte 5
    // - L2/R2 at bytes 7-8
    
    // We add:
    // - Counter and touch indicator at byte 6
    // - Motion (gyro+accel) at bytes 12-23
    // - Status byte at byte 29
    // - Touchpad header and contacts at bytes 32-49
    
    // Static counters for sequencing.
    static uint8_t report_counter = 0;
    static uint8_t touch_counter = 0;
    
    // Byte 6: counter nibble (4 bits) + touch flags (4 bits)
    // The counter increments each frame for frame sequencing.
    report[6] = ((report_counter++ & 0x0F) << 4) | 0x02;  // 0x02 = touchpad data valid
    
    // Bytes 7-8: L2/R2 triggers (already filled by remapping if mapped correctly)
    // Bytes 9-11: reserved/padding
    
    // Bytes 12-23: Gyro and accelerometer (6 x int16, little-endian)
    // For now, fill with neutral calibration (zeros).
    // In a full implementation, would read from Steam Controller IMU via their_usages.
    memset(report + 12, 0, 12);
    
    // Bytes 24-28: reserved/padding
    // Byte 29: Status byte (battery + connection status)
    report[29] = DS4_STATUS_USB_CONNECTED;
    
    // Bytes 30-31: reserved
    
    // Bytes 32-49: Touchpad data (header + 2 contact slots)
    // For now, all touches inactive.
    report[32] = 0;  // Touchpad number (always 0)
    report[33] = touch_counter++;  // Timestamp
    
    // Contact slots: 2 contacts, 4 bytes each
    ds4_pack_touch_point(report + 34, 0, false, 0, 0);
    ds4_pack_touch_point(report + 34, 1, false, 0, 0);
    
    // Bytes 50-63: reserved/padding
}

int32_t horipad_default_value(uint32_t usage) {
    switch (usage) {
        case 0x00010039:
            return 15;
        case 0x00010030:
        case 0x00010031:
        case 0x00010032:
        case 0x00010035:
            return 0x80;
        default:
            return 0;
    }
}

int32_t ps4_stadia_default_value(uint32_t usage) {
    switch (usage) {
        case 0x00010039:
            return 8;
        case 0x00010030:
        case 0x00010031:
        case 0x00010032:
        case 0x00010035:
            return 0x80;
        default:
            return 0;
    }
}

void stadia_sanitize_report(uint8_t report_id, uint8_t* buffer, uint16_t len) {
    if (buffer[3] == 0) {
        buffer[3] = 1;
    }
    if (buffer[4] == 0) {
        buffer[4] = 1;
    }
    if (buffer[5] == 0) {
        buffer[5] = 1;
    }
    if (buffer[6] == 0) {
        buffer[6] = 1;
    }
}

const our_descriptor_def_t our_descriptors[] = {
    {
        .idx = 0,
        .descriptor = our_report_descriptor_kb_mouse,
        .descriptor_length = sizeof(our_report_descriptor_kb_mouse),
        .handle_received_report = do_handle_received_report,
        .handle_get_report = kb_mouse_handle_get_report,
        .handle_set_report = kb_mouse_handle_set_report,
        .set_report_synchronous = kb_mouse_set_report_synchronous,
        .should_cause_wakeup = kb_mouse_should_cause_wakeup,
    },
    {
        .idx = 1,
        .descriptor = our_report_descriptor_absolute,
        .descriptor_length = sizeof(our_report_descriptor_absolute),
        .handle_received_report = do_handle_received_report,
        .handle_get_report = kb_mouse_handle_get_report,
        .handle_set_report = kb_mouse_handle_set_report,
        .set_report_synchronous = kb_mouse_set_report_synchronous,
        .should_cause_wakeup = kb_mouse_should_cause_wakeup,
    },
    {
        .idx = 2,
        .descriptor = our_report_descriptor_horipad,
        .descriptor_length = sizeof(our_report_descriptor_horipad),
        .vid = 0x0F0D,
        .pid = 0x00C1,
        .handle_received_report = do_handle_received_report,
        .clear_report = horipad_clear_report,
        .default_value = horipad_default_value,
    },
    {
        .idx = 3,
        .descriptor = our_report_descriptor_ps4,
        .descriptor_length = sizeof(our_report_descriptor_ps4),
        .vid = 0x054C,
        .pid = 0x1234,
        .device_connected = ps4_device_connected,
        .device_disconnected = ps4_device_disconnected,
        .main_loop_task = ps4_main_loop_task,
        .handle_received_report = ps4_handle_received_report,
        .handle_get_report = ps4_handle_get_report,
        .handle_set_report = ps4_handle_set_report,
        .handle_get_report_response = ps4_handle_get_report_response,
        .handle_set_report_complete = ps4_handle_set_report_complete,
        .clear_report = ps4_clear_report,
        .default_value = ps4_stadia_default_value,
    },
    {
        .idx = 4,
        .descriptor = our_report_descriptor_stadia,
        .descriptor_length = sizeof(our_report_descriptor_stadia),
        .vid = 0x18D1,
        .pid = 0x9400,
        .handle_received_report = do_handle_received_report,
        .clear_report = stadia_clear_report,
        .default_value = ps4_stadia_default_value,
        .sanitize_report = stadia_sanitize_report,
    },
    {
        .idx = 5,
        .descriptor = our_report_descriptor_xac_compat,
        .descriptor_length = sizeof(our_report_descriptor_xac_compat),
        .handle_received_report = do_handle_received_report,
        .clear_report = xac_compat_clear_report,
        .default_value = ps4_stadia_default_value,  // sic
    },
    {
        .idx = 6,
        .descriptor = our_report_descriptor_ds4_hidgyro,
        .descriptor_length = sizeof(our_report_descriptor_ds4_hidgyro),
        .vid = 0x054C,
        .pid = 0x05C4,
        .handle_received_report = do_handle_received_report,
        .handle_get_report = ds4_handle_get_report,
        .handle_set_report = ds4_handle_set_report,
        .clear_report = ps4_clear_report,
        .default_value = ps4_stadia_default_value,
        .build_report = ds4_build_report,
    },
};

const uint8_t config_report_descriptor[] = {
    0x06, 0x00, 0xFF,        // Usage Page (Vendor Defined 0xFF00)
    0x09, 0x20,              // Usage (0x20)
    0xA1, 0x01,              // Collection (Application)
    0x09, 0x20,              //   Usage (0x20)
    0x85, REPORT_ID_CONFIG,  //   Report ID (REPORT_ID_CONFIG)
    0x75, 0x08,              //   Report Size (8)
    0x95, CONFIG_SIZE,       //   Report Count (CONFIG_SIZE)
    0xB1, 0x02,              //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,                    // End Collection

    0x09, 0x21,               // Usage (0x21)
    0xA1, 0x01,               // Collection (Application)
    0x09, 0x21,               //   Usage (0x21)
    0x85, REPORT_ID_MONITOR,  //   Report ID (REPORT_ID_MONITOR)
    0x75, 0x08,               //   Report Size (8)
    0x95, 0x3F,               //   Report Count (63)
    0x81, 0x02,               //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0xC0,                     // End Collection
};

const uint32_t config_report_descriptor_length = sizeof(config_report_descriptor);

// This isn't sent to the host.
uint8_t const boot_kb_report_descriptor[] = {
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x06,        // Usage (Keyboard)
    0xA1, 0x01,        // Collection (Application)
    0x05, 0x07,        //   Usage Page (Kbrd/Keypad)
    0x19, 0xE0,        //   Usage Minimum (0xE0)
    0x29, 0xE7,        //   Usage Maximum (0xE7)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x08,        //   Report Count (8)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x07,        //   Usage Page (Kbrd/Keypad)
    0x19, 0x00,        //   Usage Minimum (0x00)
    0x2A, 0x91, 0x00,  //   Usage Maximum (0x91)
    0x15, 0x00,        //   Logical Minimum (0)
    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x95, 0x06,        //   Report Count (6)
    0x81, 0x00,        //   Input (Data,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x08,        //   Usage Page (LEDs)
    0x19, 0x01,        //   Usage Minimum (Num Lock)
    0x29, 0x03,        //   Usage Maximum (Scroll Lock)
    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x03,        //   Report Count (3)
    0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0x95, 0x05,        //   Report Count (5)
    0x91, 0x03,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,              // End Collection
};

const uint32_t boot_kb_report_descriptor_length = sizeof(boot_kb_report_descriptor);
