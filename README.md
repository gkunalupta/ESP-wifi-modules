# esp8266at

# OVERVIEW OF ESP8266 WiFi chips
Library for esp8266 using AT commands with both  AVR Embedded c Programing and Arduino Ide 
ESP8266/ESP32  can be used as standalone controllers as well as can be interfaced with another controller to use its WiFi compatibility 


ESP8266/32 are WiFi SoC’s produced by Espressif  systems and these WiFi SoC’s are Used as WiFi modules or in WiFi development boards.
The Modules of these WiFi chips are released by two Parties , Espressif Systems and AI thinker labs . For More details on this , refer here https://en.wikipedia.org/wiki/ESP8266#Espressif_modules


These wifi modules have two layers in memory for programming them . Firmware code( like a bootloader)  and application Code . Depending on the Firmware code , Application Code can be programmed . Firmware Code is different for different SDK’s.
 Espriff Systems releases its official SDK . Company releases its 2 official SDK that are Non-OS SDK and RTOS SDK.   RTOS SDK runs on Linux FreeRTOS, so windows users if want to use official SDK then Virtual Machine can be Used . NON-OS SDK Supports the IOT_Demo application code and AT Version.
 
 
To refer to official SDK  and upload AT version Firmware , refer this link https://www.espressif.com/sites/default/files/documentation/2a-esp8266-sdk_getting_started_guide_en.pdf

The ESP8266 can be programmed in C++ and python both . Many third party users have Released its SDK which has different firmware code in python language as well.
https://en.wikipedia.org/wiki/ESP8266#SDKs
These modules also can be programmed using the ARDUINO IDE platform. Many libraries have been developed by People to program these Modules directly Using Arduino IDE. These libraries have both Application code and Firmware Code . Firmware Code is uploaded every time with the Application Code when using it with Arduino IDE.


# AT commands
AT commands are like instructions which can be given to these WiFi chips from the host through Serial Communication . Host here can be laptop, any microcontroller which send the At commands through UART serial communication and ESP8266 give the responses for these commands in the same Communication channel and session. 
AT commands Firmware is released by two companies. Espriff Systems and AI thinker lab.
So Esp8266 can be interfaced to any controller through Serial Communication UART which sends the AT commands to these chips and Esp8266 give the responses of these commands back to HOST. 
Instruction Set of AT commands
https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf
AT firmware
https://www.electrodragon.com/w/ESP8266_Firmware
ESp8266  software Programmer 
https://github.com/nodemcu/nodemcu-flasher

Carriage return in c -

\b (backspace) Moves the active position to the previous position on the current line. If the active position is at the initial position of a line, the behavior of the display device is unspecified.
\n (new line) Moves the active position to the initial position of the next line.
\r (carriage return) Moves the active position to the initial position of the current line.



I have sent the AT commands to the terminal screen and the work perfectly.

so reading from the URL's which u provide i conclude i have some confusions which if you can make clear will be very grateful.
1) when sending AT commands in terminal window we opt for BOTH NL and CR ....so that means
      a) that when we send command "AT" from serial monitor it is sent as  "AT\r\n" and thus esp respond to it with "OK".
       b) or We also get the response from esp8266 with both NL and CR that is we get OK as "OK\r\n".
2) if a send AT command by selecting Carriage return (CR) only then no response is received from esp8266 on serial monitor ... so does that mean when sending AT commands i have to send both  \r and \n with the command. So that command is recognised by the esp8266


# My objective

So my concern is to Develop My own library for interacting with ESP32/8266 in embedded c language Using UART Registers   of AVR controllers and in Arduino language using Hardware Serial library For UART Serial communication for sharpening my skills in firmware development and embedded c Programing .

In doing so and getting to know the analogy of how these wifi microchips work , i get to know about computer networks,OSI model, TCP/IP stack, URL, DNS, IP address , MAC address, Network suite  and many such things related to computer network . I have made a doc also realted to all these things for my reference .
https://docs.google.com/document/d/1A9m5SwrN4m2vEBqYjRrNjNkvEkY6Z_rFtnfEwydu-BI/edit?usp=sharing





