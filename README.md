# Repo moved to https://codeberg.org/berzdev/arduino-victron-vedirect

# VictronVEDirectArduino
Lightweight Arduino library to read data using the VE.Direct protocol from Victron Energy devices.

Using Arduino's **Software Serial!**

## What does this Fork do?

- It implements SoftwareSerial
	+ So you can use any Pin you want :)
	+ Defined in the sketch
- Include all relevant options for your MPPT charging controller (see example)
- Include options for Victron Inverters (see example)
- Successfully tested with an Arduino Nano

## Usage:
- Import the Library
- Use an example

## Arduino Wiring

### For Production is a Opto-isolator highly recommended!
### Your Devices can be destroyed! Without isolation.
[Recommended Tutorial for this](https://www.tarthorst.net/victron-ve-direct/)

![Arduino Nano](wiring.png)

| Arduino  | Victron  |
| -------- | -------- |
| GND      | GND      |
| RX       | TX       |

## Reference / Recommendations
See the /docs folder for the protocol pdf!

[Many Victron Datasheets](https://www.victronenergy.com/support-and-downloads/technical-information)

[VE.Direct Protocol](https://www.victronenergy.com/upload/documents/VE.Direct-Protocol-3.32.pdf)

[Good wiring, production ready](https://www.tarthorst.net/victron-ve-direct/)

[YouTube DE: DIY Inverter Display 3D Printed](https://www.youtube.com/watch?v=qiQN1vB1IKI)

## Original README contents
Setup:
 - An Arduino(ish) board 
 - A Victron Energy device that sends serial data using the text version of the VE.Direct protocol
 - A 5v to 3.3v serial converter (BMV is 3.3v - don't plug it directly into a 5v Arduino!)
 - Plugged into the Arduino on a serial port (eg Serial1, Serial2, Serial3 etc)
 - See also: https://www.victronenergy.com/live/vedirect_protocol:faq
 - Developed and tested with a BMV-700 battery monitor, should work with any that talk VE.Direct
 - Distributed under an MIT license - see LICENCE.txt

Provides:
 - Read access to VE.Direct statistics and settings
 - Defaults set to read Volts, Power, Current, State of Charge (SOC), Alarm
 - Easily extendible by adding labels for any other stats and settings of interest
 - A diagnostic "full dump" of everything coming from the device  

