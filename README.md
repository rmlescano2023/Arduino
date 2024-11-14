# Arduino

### This is a repository for Logic Design and Digital Computer Circuits (CMSC 130) laboratory exercises using Arduino with VHDL.

<br>

## LAB 1

Create / Define system called PrimeDetector with one (1) input port (SW). The system also has only one (1) output port named Prime. Input port is a 4-bit type and output port is of type bit.

You are going to design a prime number detector which will take in numbers between 010 and 1510. This will require the detector to have a four binary inputs (00002 to 11112). The detector will be designed in VHDL using GHDL and GTKWAVE. The design will be simulated using the test bench provided by your instructor. Correct waveforms from simulation of the design will be provided also for your reference.

We are going to make use of this definition of prime numbers, “A Prime Number can be divided evenly only by 1 or itself and it must be a whole number greater than 1.” By this definition, the prime numbers between 010 and 1510 are: 2, 3, 5, 7, 11 and 13.

<br>

## LAB 2

Create / Define system called SevenSegDecoder with one (1) input port (SW). The system also has one (1) output port named Prime and one (1) output port named SevenSeg. Input port is a 4-bit type, Prime output port is of type bit, and SevenSeg output port is of type bitvector.

You are going to design a 7-segment display decoder in VHD which will take in numbers between 010 and 1510. This will require the detector to have a four binary inputs (00002 to 11112). The design should be able to display characters 016 to F16 corresponding to the 4-bit inputs. You will be re-using your codes in prime number detector to detect if the input number is prime or not. The decoder will be designed in VHDL using GHDL and GTKWAVE. The design will be simulated using the test bench provided by your instructor. Correct waveforms from simulation of the design will be provided also for your reference.

We are going to make use of this definition of prime numbers, “A Prime Number can be divided evenly only by 1 or itself and it must be a whole number greater than 1.” By this definition, the prime numbers between 010 and 1510 are: 2, 3, 5, 7, 11 and 13.

<br>

## LAB 3

No laboratory exercise for LAB 3.

<br>

## LAB 4

Install the Arduino Software from this link: https://www.arduino.cc/

Familiarize and learn coding from this link: https://www.arduino.cc/en/Guide

Write a program and wire the Arduino to ask an input from a push button. When the button is pressed, the LED should turn on. The next press of the button will turn off the LED. The LED will continue to alternately turn on and off for every press of the button. Search on how to debounce the circuit using the hardware. Implement also debouncing of the pushbutton using the software.

Another feature of your Arduino circuit is to detect long press of the pushbutton. If the user presses the pushbutton for more than 5 seconds, the LED will blink automatically. The interval of on and off states of the LED will be 1 second.

<br>

## LAB 5

Install the Arduino Software from this link: https://www.arduino.cc/

Familiarize and learn coding from this link: https://www.arduino.cc/en/Guide

Write a program that will turn on the LED if the voltage in the potentiometer is 2 volts. The LED will blink in proportion to the voltage readings in the potentiometer. The frequency of the LED blinking is linearly dependent to the potentiometer voltage and can be seen below: <br>

**Potentiometer Voltage (Volts), Interval in seconds**
* 2, 4
* 3, 3
* 4, 2
* 5, 1

The program should always output these values to the Serial Monitor:
1. Voltage in potentiometer in Volts
2. Interval of LED blinking in seconds

<br>

## LAB 5

Install the Arduino Software from this link: https://www.arduino.cc/

Familiarize and learn coding from this link: https://www.arduino.cc/en/Guide

In this laboratory exercise, you are going to make codes for an 8-bit binary counter. Wire-up your Arduino as seen in the figure below. Use the convention of binary 1 equivalent to an “on” state of the LED, binary 0 to “off” state of the LED. As you can see also in the diagram below, you will be using pins 5-12 of your Arduino Uno board. The most significant bit (MSB) is pin 12 and the least significant bit (LSB) is pin 5. The behavior of the circuit based on the push button is summarized below.

**Push Button Event | Current State of Circuit | Circuit Response**
* 5-sec press | off | Start counting at 0 up to max value in a default 1-sec interval between counts. It will reset to 0 automatically when it reaches the maximum value and start counting again.
* 5-sec press | on | Turn off the circuit
* 1 push | on | Reset the counter to 0 and start counting again.
* 1 push | off | Flash all LED at once for 2 seconds and do nothing after that
