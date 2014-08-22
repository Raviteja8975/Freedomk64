K64F-mbed-KDS-Template
======================

Working Freescale Kinetis Design Studio 1.1.0 Project with mbed Libraries for K64F Freedom Board

Steps to use:

Download the KDS installer from Freescale

Reconfigure KDS to use the ARM Inc. supported toolchain on launchpad (GCC ARM Embedded) as described:
http://mcuoneclipse.com/2014/07/11/switching-arm-gnu-tool-chain-and-libraries-in-kinetis-design-studio/

Configure the Segger/J-link OpenSDA firmware on the FRDM-K64F board.
https://segger.com/opensda.html

Set up a debug configuration in KDS - device name is MK64FN1M0xxx12


Notes:

As of July 2014 mbed does not have a standard USBHost library for K64F, see:
https://mbed.org/questions/3940/USBHostSerial-library-compatible-with-K6/
