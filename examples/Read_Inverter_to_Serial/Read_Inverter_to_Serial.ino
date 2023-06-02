/******************************************************************
 VEDirect Arduino

 Copyright 2018, 2019, Brendan McLearie
 Distributed under MIT license - see LICENSE.txt

 See README.md

 File: ReadVEDirect.ino / ReadVEDirect.cpp
 - Provides example use of the VEDirect library

 2020.04.10 - convert to SoftwareSerial
 2023.06.02 - edited by ipaultech for inverter support
******************************************************************/

#include "Arduino.h"
#include "VEDirect.h"

// Serial pins
#define rxPin 5
#define txPin 6

// 32 bit ints to collect the data from the device
int32_t VE_voltage, VE_state, VE_ac_out_v, VE_ac_out_i, VE_ac_out_s, VE_ac_mode, VE_warn, VE_or, VE_ar, VE_relay, VE_fw;

// VEDirect instantiated with relevant serial object
VEDirect myve(rxPin, txPin);

void setup() {
	Serial.begin(9600);		// Adjust as needed - DEBUG serial port
}

void loop() {
	Serial.println("Reading values from Victron Energy device using VE.Direct text mode");
	Serial.println();

	// Read the data
	if(myve.begin()) {									// test connection
		VE_voltage = myve.read(VE_VOLTAGE);
    VE_state = myve.read(VE_STATE);
    VE_ac_out_v = myve.read(VE_AC_OUT_V);
    VE_ac_out_i = myve.read(VE_AC_OUT_I);
    VE_ac_out_s = myve.read(VE_AC_OUT_S);
    VE_ac_mode = myve.read(VE_AC_MODE);
    VE_warn = myve.read(VE_WARN);
    VE_or = myve.read(VE_OR);
    VE_ar = myve.read(VE_AR);
    VE_relay = myve.read(VE_RELAY);
    VE_fw = myve.read(VE_FW);
	} else {
		Serial.println("Could not open serial port to VE device");
		while (1);
	}

	// Print each of the values
	Serial.print("Source Voltage         ");
	Serial.println(VE_voltage, DEC);
  Serial.print("Operation State        ");
  Serial.println(VE_state, DEC);
  Serial.print("AC Out Voltage         ");
  Serial.println(VE_ac_out_v, DEC);
  Serial.print("AC Out Current         ");
  Serial.println(VE_ac_out_i, DEC);
  Serial.print("AC Out VA              ");
  Serial.println(VE_ac_out_s, DEC);
  Serial.print("Device Mode            ");
  Serial.println(VE_ac_mode, DEC);
  Serial.print("Warn reason            ");
  Serial.println(VE_warn, DEC);
  Serial.print("Off reason             ");
  Serial.println(VE_or, DEC);
  Serial.print("Alarm reason           ");
  Serial.println(VE_ar, DEC);
  Serial.print("Relay state            ");
  Serial.println(VE_relay, DEC);
  Serial.print("FW Version             ");
  Serial.println(VE_fw, DEC);
	Serial.println();

	// Copy the raw data stream (minus the \r) to Serial
	// Call read() with a token that won't match any VE.Direct labels
	Serial.println("All data from device:");
	myve.read(VE_DUMP);
	Serial.println();
	delay(10000);
}