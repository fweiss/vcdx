# vcdx
Voice Codex

- SYN6988 board
- XFS5152C chip

## Build and run
This is a PlatformIO project developed with Visual Studio Code.

> The src/main.c file will probably compile and link in an Arduino IDE with the ESP32 platform.

## codes
0x4A 'J' initialization successful
0x41 'A' received the correct command frame
0x45 'E' received incorrect command frame
0x4E 'N' chip busy
0x4F 'O' chip idle

synthesis
0xFD MSB LSB data...
- 0x01 start
- 0x02 stop
- 0x03 pause
- 0x04 resume
- ...

### Encoding
- 0x00 GB2312
- 0x01 GBK
- 0x02 BIG5
- 0x03 UNICODE

### Speech sysnthesis
0xFD
0x00 0x0A length = 10
0x01 start
0x03 unicode
0xD1 0x79 0x27 0x59 0xAF 0x8B 0xDE 0x98
11010001 01111001

### stop synthesis commnand
0xFD 0x00 0x01 0x02

## Text control mark
- escaped with '[' and ']'
- control code alphabetic
- parameter numeric
- boolean 1 or 0

### control codes
- f syllable stress
- g units of measure
- h pronounce as letters
- i pinyi
- m select speaker voice
- n read out digial
- o read "zero"
- p pause (msec)
- r surname pronounciation, cha vs zha
- s speed
- t tone
- v volume
- x use of ring tone, beep
- y synthesis numer '1'
- *, # rhythm
- = front mark tone
- d restore default

## Tones
- message tone (sound101-sound125)
- ringing tone (sound201-sound225)
- alarm tone (sound301-sound330)
- customizable

## Voice recognition
- 30 built-in
- cusomizable

## Links and references
[translated datasheet](https://cdn.hackaday.io/files/1907328160277888/XFS5152CE_en.pdf)

[tutorial with code and wiring diagrams](XFS5152CE Speech Synthesis Module)

DFRobot SEN0539

[DFRobot DFR0760 schematic](https://dfimg.dfrobot.com/nobody/wiki/b771a393b1482b63492b9f994a532a2b.pdf)

