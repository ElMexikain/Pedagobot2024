cd %HOMEPATH%\mblock-avr\temp\build
:: Supprime le dossier CodeArduino s'il existait déjà
IF exist CodeArduino\ ( cd CodeArduino\ && rm CodeArduino.ino && cd .. && rmdir CodeArduino\ ) 
:: Ajoute l'include pour la librairie des servomoteurs en début de fichier
echo #include ^<ESP32Servo.h^> > CodeArduino.ino 
:: Rajoute le reste du code mBlock converti en textuel
findstr /v "Wire.h SoftwareSerial.h Servo.h" code.cpp >> CodeArduino.ino 
mkdir "CodeArduino" 
mv CodeArduino.ino CodeArduino/
cd CodeArduino/
arduino-cli board list > temp.txt
:: Récupère l'id du port sur lequel l'Arduino est branchée
:: Attention, sur Linux/MAC OS, les ports ne s'appellent pas forcément COM, à réadapter
type temp.txt | findstr /b /r /c:^COM | findstr Arduino > temp2.txt
:: Assignation de l'id trouvé à la variable portUSB
set /p portUSB=<temp2.txt
arduino-cli compile -b arduino:esp32:nano_nora -v
arduino-cli upload -b arduino:esp32:nano_nora -p %portUSB:~0,4% -v
:: Supression des fichiers temporaires
rm temp*

