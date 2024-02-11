

void stylo_1()
{

  //digitalWrite(ledVertePin,HIGH);//On allume la led Verte
  //digitalWrite(ledJaunePin,LOW);//On éteind la led Jaune
  //digitalWrite(ledRougePin,LOW);//On éteind la led Rouge

  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 1
    for(pos=0;pos>-60;pos-=1){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==60){ //Si le stylo 2 fonctionnait, on le raméne à la position du stylo 1
    for(pos=60;pos>-60;pos-=1){
      myservo.write(pos);
      delay(15);
    }  
  }

}

void stylo_2()
{

  //digitalWrite(ledRougePin,HIGH);//On allume la led Rouge
  //digitalWrite(ledJaunePin,LOW);//On éteind la led Jaune
  //digitalWrite(ledVertePin,LOW);//On éteind la led Verte

  if(pos==0){ //Si aucun des stylos ne fonctionnait, on le raméne à la position du stylo 2
    for(pos=0;pos<60;pos+=1){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==-60){ //Si le stylo 1 fonctionnait, on le raméne à la position du stylo 2
    for(pos=-60;pos<60;pos+=1){
      myservo.write(pos);
      delay(15);
    }  
  }

}

void non_stylo()
{

  //digitalWrite(ledJaunePin,HIGH);//On allume la led Jaune
  //digitalWrite(ledVertePin,LOW);//On éteind la led Verte
  //digitalWrite(ledRougePin,LOW);//On éteind la led Rouge

  if(pos==-60){ //Si le stylo 1 fonctionnait, on le remonte
    for(pos=-60;pos<0;pos+=1){
      myservo.write(pos);
      delay(15);
    }
  }

  if(pos==60){ //Si le stylo 2 fonctionnait, on le remonte
    for(pos=-60;pos>0;pos-=1){
      myservo.write(pos);
      delay(15);
    }  
  }

}
