K64F-mbed-KDS-Template
======================

Working Freescale Kinetis Design Studio 1.1.0 Project with mbed Libraries for K64F Freedom Board

Must reconfigure KDS to use the ARM Inc. supported toolchain on launchpad (GCC ARM Embedded) as described:

http://mcuoneclipse.com/2014/07/11/switching-arm-gnu-tool-chain-and-libraries-in-kinetis-design-studio/

As of July 2014 mbed does not have a standard USBHost library for K64F, see:

https://mbed.org/questions/3940/USBHostSerial-library-compatible-with-K6/

Don't forget to set up a debug configuration - device name is MK64FN1M0xxx12