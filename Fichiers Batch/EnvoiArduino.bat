cd %HOMEPATH%\mblock-avr\temp\build
:: Supprime le dossier CodeArduino s'il existait déjà
IF exist CodeArduino\ ( cd CodeArduino\ && rm * && cd .. && rmdir CodeArduino\ )
cd %HOMEPATH%\mblock-avr\temp\build
:: Ajoute l'include pour la librairie des servomoteurs en début de fichier
echo #include ^<ESP32Servo.h^> > CodeArduino.ino
:: Rajoute le reste du code mBlock converti en textuel
findstr /v "SoftwareSerial.h Servo.h" code.cpp >> CodeArduino.ino
powershell -Command "(gc CodeArduino.ino) -replace '_delay', 'delay' | Out-File -encoding ASCII CodeArduino.ino"
::mkdir "CodeArduino" 
::mv CodeArduino.ino CodeArduino/
::cd CodeArduino/
::arduino-cli compile -b arduino:esp32:nano_nora -v
::arduino-cli upload -b arduino:esp32:nano_nora -v
:: Supression des fichiers temporaires
::rm temp*

