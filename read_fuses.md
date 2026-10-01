venv/bin/pymcuprog read --tool uart --device attiny414 --uart /dev/ttyUSB1 --clk 115200
venv/bin/pymcuprog read --tool uart --device attiny814 --uart /dev/ttyUSB2 --clk 115200

Memory type: fuses
------------

0x001280: 00  WDTCFG 7:0 WINDOW[3:0] PERIOD[3:0]
0x001281: 00  BODCFG 7:0 LVL[2:0] SAMPFREQ ACTIVE[1:0] SLEEP[1:0]
0x001282: 02  OSCCFG 7:0 OSCLOCK FREQSEL[1:0]
0x001283: FF  Reserved
0x001284: 00  TCD0CFG 7:0 CMPDEN CMPCEN CMPBEN CMPAEN CMPD CMPC CMPB CMPA
0x001285: F6  SYSCFG0 7:0 CRCSRC[1:0] RSTPINCFG[1:0] EESAVE
0x001286: 07  SYSCFG1 7:0 SUT[2:0]
0x001287: 00  APPEND 7:0 APPEND[7:0]
0x001288: 00  BOOTEND 7:0 BOOTEND[7:0]
0x001289: FF  Reserved
0x00128A: C5  LOCKBIT 7:0 LOCKBIT[7:0]

0x001282: 02  OSCCFG 7:0 OSCLOCK FREQSEL[1:0]
0b00000010
0 Calibration registers of the 20 MHz oscillator are accessible
0 N/A
0 N/A
0 N/A
0 N/A
0 N/A
1 \
0 -- Run at 20MHz with corresponding factory calibration

