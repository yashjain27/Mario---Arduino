#include <SimpleTimer.h>
SimpleTimer timer;
SimpleTimer timer1;

const int  vrow1=2;
const int  vrow2=3;
const int  vrow3=4;
const int  vrow4=5;
const int  vrow5=6;
const int  vrow6=7;
const int  vrow7=8;
const int  vrow8=9;
const int  gcolumn1=10;
const int  gcolumn2=11;
const int  gcolumn3=12;
const int  gcolumn4=13;
const int  gcolumn5=14;
const int  gcolumn6=15;
const int  gcolumn7=16;
const int  gcolumn8=17;

unsigned int voltage=0;
unsigned int ground=0;

int horizposition=11;//10 refers to position referencing gcolumn1 with pin 10
int Enemy=8;
int _position=8;
int Jump=_position;
int Fall=Jump-3;
int ceilingfall=Jump-1;
int walk=18;
int JUMP=19;

int x=0;
int y=18;
int buttonState;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;
int buttonState1;
int lastButtonState1=LOW;
long Time;
int interval=100;
long previousTime=0;

bool coin;
bool coin1;
bool coin2;
bool coin3;
bool coin4;
bool coin5;
bool coin6;
bool coin7;
bool death;
bool kill;
bool Move=true;
bool attack;
bool enemy_dead;

void setup() {  
  Serial.begin(9600);
  pinMode(vrow1,OUTPUT);
  pinMode(vrow2,OUTPUT);
  pinMode(vrow3,OUTPUT);
  pinMode(vrow4,OUTPUT);
  pinMode(vrow5,OUTPUT);
  pinMode(vrow6,OUTPUT);
  pinMode(vrow7,OUTPUT);
  pinMode(vrow8,OUTPUT);
  pinMode(gcolumn1,OUTPUT);
  pinMode(gcolumn2,OUTPUT);
  pinMode(gcolumn3,OUTPUT);
  pinMode(gcolumn4,OUTPUT);
  pinMode(gcolumn5,OUTPUT);
  pinMode(gcolumn6,OUTPUT);
  pinMode(gcolumn7,OUTPUT);
  pinMode(gcolumn8,OUTPUT);   
  pinMode(walk,INPUT);
  pinMode(JUMP,INPUT);
  timer.setInterval(25,coins);
  timer1.setInterval(250,enemyposition);
  }
  
 //*******************GAME OVER********************
 void gameover(){
  while(1){
   for(ground=10;ground<=17;ground++){
    digitalWrite(ground,LOW);
   }
   for(voltage=2;voltage<=10;voltage++){
    digitalWrite(voltage,HIGH);
   }
  }
 }

 //*******************Coins***********************
 void coins(){
   //Coins
   if((x<6)&&(coin==false)){
    for(ground=10;ground<=17;ground++){
      if((ground == (15-x))){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
   }
   //coin 1
   if((x<8)&&(coin1==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (17-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
   }
   //coin 2
    if((x<18&&x>10)&&(coin2==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (27-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
   }
   //coin 3
    if((x<20&&x>12)&&(coin3==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (29-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
   }
   //coin 4
    if((x<35&&x>27)&&(coin4==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (44-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
  }
   //coin 5
    if((x<37&&x>29)&&(coin5==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (46-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
  }
   //coin 6
    if((x<56&&x>48)&&(coin6==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (65-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
  }
   //coin 7
    if((x<58&&x>50)&&(coin7==false)){
     for(ground=10;ground<=17;ground++){
      if(ground == (67-x)){
        digitalWrite(ground,LOW);
        }
      else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow5,HIGH);
        delay(1);
        digitalWrite(vrow5,LOW);
  }
 }

 
 //*******************Enemies*****************
 void enemyposition(){
  if(0<=x<=7){
    y--;
  }
    if(y==0){
    y=17;
  }
 }
 
 void enemies(){
  for(ground=10;ground<=17;ground++){
  if(ground == y){
    digitalWrite(ground,LOW);
  }
  else{
  digitalWrite(ground,HIGH);  
  }
 } 
 voltage=Enemy;
 digitalWrite(voltage,HIGH);
 delay(1);//On/off
 digitalWrite(voltage,LOW);
 
 if((vrow7==8)&&(y==11)){
  kill=true;
  }
 else{
  kill=false;
  }
 }
 
 //*******************Walk********************
 void Position(){
  if(Move==true){
     x++;
   }
 }
 
 //*******************JUMP*********************
 void jump(){  
//Full jump
 if(!(Jump>=9)){
  if((Jump>=Fall)&&((x!=4)&&(x!=6)&&(x!=16)&&(x!=18)&&(x!=33)&&(x!=35)&&(x!=54)&&(x!=56))){
    Jump--;
    }
  if((Jump<Fall)&&((x!=4)&&(x!=6)&&(x!=16)&&(x!=18)&&(x!=33)&&(x!=35)&&(x!=54)&&(x!=56))){
    Fall++;
    Jump++;
  if(Fall==_position+1){
        Fall=Jump-3;
        Serial.println(Fall);
     }
   }
 }
//Limited jump because of celiling
  if((Jump>=ceilingfall)&&((x==4)||(x==6)||(x==16)||(x==18)||(x==33)||(x==35)||(x==54)||(x==56))){
    Jump--;
  if(((x==4))){
    coin=true;
  }
  else if((x!=4)&&(x<=4)){
    coin=false;
  }
  if(((x==6))){
    coin1=true;
  }
  else if((x!=6)&&(x<=6)){
    coin1=false;
  }
   if(((x==16))){
    coin2=true;
  }
  else if((x!=16)&&(x<=16)){
    coin2=false;
  }
   if(((x==18))){
    coin3=true;
  }
  else if((x!=18)&&(x<=18)){
    coin3=false;
  }
   if(((x==33))){
    coin4=true;
  }
  else if((x!=33)&&(x<=33)){
    coin4=false;
  }
   if(((x==35))){
    coin5=true;
  }
  else if((x!=35)&&(x<=35)){
    coin5=false;
  }
   if(((x==54))){
    coin6=true;
  }
  else if((x!=54)&&(x<=54)){
    coin6=false;
  }
   if(((x==56))){
    coin7=true;
  }
  else if((x!=56)&&(x<=56)){
    coin7=false;
  }
 }
  if((Jump<ceilingfall)&&((x==4)||(x==6)||(x==16)||(x==18)||(x==33)||(x==35)||(x==54)||(x==56))){
  ceilingfall++;
  Jump++;
   if(ceilingfall==vrow8){ 
        ceilingfall=Jump-1;
      }
  }
 } 

//*********************Mario**********************
 void mario(){  
//*JUMP*
//Code for debouncing pushbutton and button to ***jump
Time=millis();
if((long)(Time-previousTime)>=interval){
 int reading1=digitalRead(JUMP);
 if(reading1!=lastButtonState1){ 
  lastDebounceTime=millis();
 }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading1 != buttonState1||((Jump!=_position)&&((x!=8)&&(x!=9)&&(x!=20)&&(x!=21)&&(x!=30)&&(x!=31)&&(x!=43)&&(x!=44)&&(x!=50)&&(x!=51)||(Jump!=6)))) {
      buttonState1 = reading1;
      if ((buttonState1 == HIGH||Jump!=_position)) { //If button pressed go to void Position()
        jump();
        previousTime=Time;
      }
    }
  }
  lastButtonState1 = reading1;
}
 //*Position*
 //Code for debouncing pushbutton and button to ***walk
 int reading=digitalRead(walk);
 if(reading!=lastButtonState){ 
  lastDebounceTime=millis();
 }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) { //If button pressed go to void Position()
        Position();
      }
    }
  }
  lastButtonState = reading;
  
 //*DEATH*
 if((Jump==8)&&(horizposition==11)){
  death=true;
 }
 else{
  death=false;
 }
//*Attack*
 if((Jump==7)&&(horizposition==11)){
  attack=true;
 }
 else{
  attack=false;
 }
 
//*ACTUAL 2D POSITION*
 for(ground=10;ground<=17;ground++){
  if(ground == horizposition){
    digitalWrite(ground,LOW);
  }
  else{
  digitalWrite(ground,HIGH);  
  }
 } 
 voltage=Jump;
 digitalWrite(voltage,HIGH);
 delay(1);//On/off
 digitalWrite(voltage,LOW); 
}


//**********************GAME*************************
void loop() {   
 //*Floor*
 for(ground=10;ground<=17;ground++){
  //if(
  if(ground==(22-x)||ground==(23-x)||ground==(38-x)||ground==(39-x)||ground==(58-x)||ground==(59-x)){
  digitalWrite(ground,HIGH); 
    if(((voltage==8)||(voltage==9))&&(x==11||(x==12)||(x==27)||(x==28)||(x==47)||(x==48))){
      Jump++; 
    }
  }
 else{
 digitalWrite(ground,LOW);
  }
 }
 digitalWrite(vrow8,HIGH);
 delay(1);//Important
 digitalWrite(vrow8,LOW);
 
 //Coins
 timer.run();

 //*Clouds*
 //Cloud 
   for(ground=10;ground<=17;ground++){
    if(ground == (19-x)||ground==(20-x)||ground == (31-x)||ground==(32-x)||ground == (47-x)||ground==(48-x)||ground == (52-x)||ground==(53-x)||ground == (64-x)||ground==(65-x)){
      digitalWrite(ground,LOW);
    }
    else{
      digitalWrite(ground,HIGH);  
    }
   }
   digitalWrite(vrow1,HIGH);
   delay(1);
   digitalWrite(vrow1,LOW);
  for(ground=10;ground<=17;ground++){
   if(ground == (18-x) || ground==(19-x) || ground==(20-x)||ground==(21-x)||ground == (30-x) || ground==(31-x) || ground==(32-x)||ground==(33-x)||ground == (46-x) || ground==(47-x) || ground==(48-x)||ground==(49-x)||ground == (51-x) || ground==(52-x) || ground==(53-x)||ground==(54-x)||ground == (63-x) || ground==(64-x) || ground==(65-x)||ground==(66-x)){
    digitalWrite(ground,LOW);
       }
   else{
    digitalWrite(ground,HIGH);  
     }
   }
    digitalWrite(vrow2,HIGH);  
    delay(1);
    digitalWrite(vrow2,LOW);

 //Cloud 
   for(ground=10;ground<=17;ground++){
     if(ground==(13-x)||ground == (25-x)||ground == (36-x)||ground == (41-x)||ground == (58-x)){
        digitalWrite(ground,LOW);
        }
     else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow1,HIGH);
        delay(1);
        digitalWrite(vrow1,LOW);
    for(ground=10;ground<=17;ground++){
      if(ground == (12-x) || ground==(13-x) || ground==(14-x)||ground == (24-x) || ground==(25-x) || ground==(26-x)||ground == (35-x) || ground==(36-x) || ground==(37-x)||ground == (40-x) || ground==(41-x) || ground==(42-x)||ground == (57-x) || ground==(58-x) || ground==(59-x)){
        digitalWrite(ground,LOW);
      }
      else{
        digitalWrite(ground,HIGH);  
      }
      }
        digitalWrite(vrow2,HIGH);  
        delay(1);
        digitalWrite(vrow2,LOW);
   
 //obstacles 
    //Cylinders
  for(ground=10;ground<=17;ground++){
     if(ground==(19-x)||ground == (20-x)||ground == (31-x)||ground == (32-x)||ground == (41-x)||ground == (42-x)||ground == (54-x)||ground == (55-x)||ground == (61-x)||ground == (62-x)){
        digitalWrite(ground,LOW);
        if(((x==7)||(x==19)||(x==29)||(x==42)||(x==49))&&((Jump==8)||(Jump==7))){//12
          Move=false;
        }
        else{
          Move=true;          
          }
        }
     else{
        digitalWrite(ground,HIGH);  
        }
      }
        digitalWrite(vrow6,HIGH);
        digitalWrite(vrow7,HIGH);
        delay(1);
        digitalWrite(vrow6,LOW); 
        digitalWrite(vrow7,LOW);
        
  if(((x==8)||(x==9)||(x==20)||(x==21)||(x==30)||(x==31)||(x==43)||(x==44)||(x==50)||(x==51))&&((Jump==8)||(Jump==7))){
         Jump=vrow5;
         Fall=Jump-3;
    }   
     
 //Mario
  mario();

 //Enemies
 if((attack==true)&&(kill==true)){
   enemy_dead=true;
   kill=false;
 }
if(enemy_dead==false){
   if(Time<=2250){
      enemies();
      timer1.run();
    }
 }
 
 //*Game Over*
  if(Jump>=9){
       gameover();
    }
  if((kill==true)&&(death==true)){
       gameover();//enemy attacked you
    }
 }
 
