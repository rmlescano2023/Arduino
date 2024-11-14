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
