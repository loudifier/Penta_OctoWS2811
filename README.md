# Penta_OctoWS2811
Adapter board for driving 40 channels of WS2811-style addressable LED strips with a Teensy 4.1 microcontroller

This is a work in progress. A prototype board has been assembled, but I am waiting on parts to test Ethernet, and I am working on a sketch for testing that works better than the teensyduino examples for thousands of LEDs. Committing what I have so far.

[photo of board and LEDs]

The **Penta**_OctoWS2811 is effectively five of the [PJRC OctoWS2811 adapter](https://www.pjrc.com/store/octo28_adaptor.html) squished into a single board for an easy way to take full advantage of the Teensy 4.1's ability to use any set of GPIO pins with the OctoWS2811 library. Penta_OctoWS2811 also adds an Ethernet connector for use with ArtNet or other networked light controller, and a voltage regulator so the board and Teensy can be powered from the LED power supply without USB.

[image of schematic]

## Features

The Penta_OctoWS2811 board has 10 RJ45 ports, for a total of 40 output channels driven from 5V buffers through 100Ω termination resistors. Teensy 4.0 can also be used with this board, supporting up to 24 output channels.

## Usage

The instructions and guidelines on the PJRC website and Teensyduino example scketches for using a Teensy and OctoWS2811 to drive addressible LED strips over CAT6 wires apply equally to the PJRC OctoWS2811 adapter and the Penta_OctoWS2811 board, except for a few key features noted below.

### Output Pins

Teensy 4.1 digital output pins are connected to the following RJ45 ports:  
 Port - GPIO pins  
  J2 - 1, 2, 3, 4  
  J3 - 5, 6, 7, 8  
  J4 - 25, 26, 27, 28  
  J5 - 29, 30, 31, 32  
  J6 - 23, 22, 21, 20  
  J7 - 17, 16, 15, 14  
  J8 - 40, 39, 38, 37  
  J9 - 36, 35, 34, 33  
  J10 - 13, 18, 19, 9  
  J11 - 11, 12, 41, 24

Teensy 4.0 is compatible with the board, and will be connected to J2, J3, J6, J7, J10, and J11. In order to get a full 24 channels of output with Teensy 4.0, GPIO 0 can be used instead of GPIO 41 and GPIO 12 can be used instead of GPIO 24 by shorting jumper pads on the bottom of the board.

A frame sync output is provided, if you somehow need even more output channels and need to maintain accurate timing between multiple boards. The connector can also be useful for connecting to a single 3.3V-compatible LED strip. If you need to use GPIO 12 for SPI communication, you can cut and jump the appropriate pads on the bottom of the board to use GPIO 0 instead.

### Power

Just like the PJRC OctoWS2811 adapter, the Penta_OctoWS2811 board can be powered from your LED power supply. The Penta_OctoWS2811 board adds a voltage regulator for compatibility with newer 12V LED strips. If you are using 5V LEDs, the voltage regulator should be bypassed using the jumper pads on top of the board.

**The Teensy VUSB jumper must be cut if you plan to power the board from the LED power supply.** If you cut the VUSB jumper you can add a single header pin connection fom the Teensy VUSB pad to a corresponding pad on the board, which will allow the Teensy and board to be powered from the LED power supply or USB via a diode.

### Ethernet

## Board Design, Pre-assembled Boards

## Testing