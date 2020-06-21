# esp8266at

# OVERVIEW OF ESP8266 WiFi chips
Library for esp8266 using AT commands with both  AVR Embedded c Programing and Arduino Ide 
ESP8266/ESP32  can be used as standalone controllers as well as can be interfaced with another controller to use its WiFi compatibility 


ESP8266/32 are WiFi SoC’s produced by Espressif  systems and these WiFi SoC’s are Used as WiFi modules or in WiFi development boards.
The Modules of these WiFi chips are released by two Parties , Espressif Systems and AI thinker labs . For More details on this , refer here https://en.wikipedia.org/wiki/ESP8266#Espressif_modules
These wifi modules have two layers in memory for programming them . Firmware code( like a bootloader)  and application Code . Depending on the Firmware code , Application Code can be programmed . Firmware Code is different for different SDK’s.
 Espriff Systems releases its official SDK . Company releases its 2 official SDK that are Non-OS SDK and RTOS SDK.   RTOS SDK runs on Linux FreeRTOS, so windows users if want to use official SDK then Virtual Machine can be Used . NON-OS SDK Supports the IOT_Demo application code and AT Version.
To refer to official SDK refer this link https://www.espressif.com/sites/default/files/documentation/2a-esp8266-sdk_getting_started_guide_en.pdf
The ESP8266 can be programmed in C++ and python both . Many third party users have Released its SDK which has different firmware code in python language as well.
https://en.wikipedia.org/wiki/ESP8266#SDKs
These modules also can be programmed using the ARDUINO IDE platform. Many libraries have been developed by People to program these Modules directly Using Arduino IDE. These libraries have both Application code and Firmware Code . Firmware Code is uploaded every time with the Application Code when using it with Arduino IDE.

# AT commands
AT commands are like instructions which can be given to these WiFi chips from the host through Serial Communication . Host here can be laptop, any microcontroller which send the At commands through UART serial communication and ESP8266 give the responses for these commands in the same Communication channel and session. 
AT commands Firmware is released by two companies. Espriff Systems and AI thinker lab.
So Esp8266 can be interfaced to any controller through Serial Communication UART which sends the AT commands to these chips and Esp8266 give the responses of these commands back to HOST.

