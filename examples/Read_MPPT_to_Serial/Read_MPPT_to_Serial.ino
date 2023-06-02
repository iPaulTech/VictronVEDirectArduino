/******************************************************************
 VEDirect Arduino

 Copyright 2018, 2019, Brendan McLearie
 Distributed under MIT license - see LICENSE.txt

 See README.md

 File: ReadVEDirect.ino / ReadVEDirect.cpp
 - Provides example use of the VEDirect library

 2020.04.10 - convert to SoftwareSerial
 2023.06.02 - edited by ipaultech for mppt support
******************************************************************/

#include "Arduino.h"
#include "VEDirect.h"

// Serial pins
#define rxPin 5
#define txPin 6

// 32 bit ints to collect the data from the device
int32_t VE_voltage, VE_current, VE_power_pv, VE_voltage_pv, VE_state, VE_yield_today, VE_yield_total, VE_yield_yesterday, VE_power_max_today, VE_error, VE_fw;
// Boolean to collect an ON/OFF value
uint8_t VE_alarm;

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
		VE_current = myve.read(VE_CURRENT);
    VE_power_pv = myve.read(VE_POWER_PV);
    VE_voltage_pv = myve.read(VE_VOLTAGE_PV);
    VE_state = myve.read(VE_STATE);
    VE_yield_today = myve.read(VE_YIELD_TODAY);
    VE_yield_total = myve.read(VE_YIELD_TOTAL);
    VE_yield_yesterday = myve.read(VE_YIELD_YESTERDAY);
    VE_power_max_today = myve.read(VE_POWER_MAX_TODAY);
    VE_error = myve.read(VE_ERROR);
    VE_alarm = myve.read(VE_ALARM);
    VE_fw = myve.read(VE_FW);
	} else {
		Serial.println("Could not open serial port to VE device");
		while (1);
	}

	// Print each of the values
	Serial.print("Voltage                ");
	Serial.println(VE_voltage, DEC);
	Serial.print("Current                ");
	Serial.println(VE_current, DEC);
  Serial.print("Power PV               ");
  Serial.println(VE_power_pv, DEC);
  Serial.print("Voltage PV             ");
  Serial.println(VE_voltage_pv, DEC);
  Serial.print("Operation State        ");
  Serial.println(VE_state, DEC);
  Serial.print("Today Yield            ");
  Serial.println(VE_yield_today, DEC);
  Serial.print("Total Yield            ");
  Serial.println(VE_yield_total, DEC);
  Serial.print("Yesterday Yield        ");
  Serial.println(VE_yield_yesterday, DEC);
  Serial.print("Max Power Today        ");
  Serial.println(VE_power_max_today, DEC);
  Serial.print("MPPT Error Code        ");
  Serial.println(VE_error, DEC);
  Serial.print("Alarm                  ");
	Serial.println(VE_alarm, DEC);
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
