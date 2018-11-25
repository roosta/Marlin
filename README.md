# Marlin 3D Printer Firmware for Wanhao Duplicator i3 v2.1
This is a fork of [Marlin](http://marlinfw.org/) that I use to upgrade my Wanhao
Duplicator i3 3d printer firmware. All parts that matter is stock, no custom parts.

## Disclaimer
I am by no means an expert and the changes done to Marlin is based on mostly on
a lot of googling and trial and error. If you find something that you'd want to
change, please make an [issue](https://github.com/roosta/Marlin/issues/new) or
[pull request](https://github.com/roosta/Marlin/pulls).

## Burning a bootloader
To be able to flash this firmware a bootloader needs to be burned to your Melzi
card inside the 3d printer, I used an [Arduino
Uno](https://store.arduino.cc/arduino-uno-rev3) as ISP as detailed
[here](https://www.arduino.cc/en/Tutorial/ArduinoISP). I followed [this
guide](https://www.instructables.com/id/Using-an-Arduino-to-Flash-the-Melzi-Board-Wanhao-I/)
for the most part, but had to change a few things:

In step 8, part 2 the author says:
> Go to Tools -> Port -> select the port corresponding to the Melzi board, not our Arduino.

Its in actuality the Arduino port that should be used, the Melzi port is used
later when flashing Marlin, after having burned the bootloader.

The other thing I had to do to successfully burn the bootloader is place a 10µF
electrolytic capacitor connected to RESET and GND with the positive (long leg)
connected to RESET.

## When the bootloader is installed

Open this project in Arduino IDE. Ensure that the power jumper on the board is
still set to USB, connect the USB in the printer to your PC. Ensure that the
port in Arduino IDE is set to the printers USB port, and that the board is
[Sanguino](https://github.com/Lauszus/Sanguino), processor is "ATmega1284p
(16MHz)", then upload.

## Resources

- [Using an Arduino to Flash the Melzi Board (Wanhao I3) and Upgrade Firmware: 3 Steps](https://www.instructables.com/id/Using-an-Arduino-to-Flash-the-Melzi-Board-Wanhao-I/)
- [Lauszus/Sanguino: Sanguino add-on for the Arduino IDE, based on http://code.google.com/p/sanguino/](https://github.com/Lauszus/Sanguino)
- [Arduino - ArduinoISP](https://www.arduino.cc/en/Tutorial/ArduinoISP)
- Visit [marlinfw.org](http://marlinfw.org/) for complete documentation on [configuration](http://marlinfw.org/docs/configuration/configuration.html), [installation](http://marlinfw.org/docs/basics/install.html), [features](http://marlinfw.org/meta/features/), and the many [G-codes](http://marlinfw.org/meta/gcode/) that Marlin supports.
- [Wanhao Duplicator i3 Marlin by Nitrogen777 - Thingiverse](https://www.thingiverse.com/thing:2450111)
- [garychen99/Duplicator-i3-firmware: Wanhao Duplicator i3 firmware with 4 points leveling](https://github.com/garychen99/Duplicator-i3-firmware)
