cd %HOMEPATH%\mblock-avr\temp\build

IF exist CodeArduino\ ( cd CodeArduino\ && rm CodeArduino.ino && cd .. && rmdir CodeArduino\ ) 
echo #include ^<ESP32Servo.h^> > CodeArduino.ino 
findstr /v "Wire.h SoftwareSerial.h Servo.h" code.cpp >> CodeArduino.ino 

mkdir "CodeArduino" 
mv CodeArduino.ino CodeArduino/
cd CodeArduino/
arduino-cli board list > temp.txt
type temp.txt | findstr /b /r /c:^COM | findstr Arduino > temp2.txt
set /p portUSB=<temp2.txt
arduino-cli compile -b arduino:esp32:nano_nora -v
arduino-cli upload -b arduino:esp32:nano_nora -p %portUSB:~0,4% -v
rm temp*

