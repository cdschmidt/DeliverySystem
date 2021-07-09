#include "BatteryLifeDecorator.h"


namespace csci3081 {

void BatteryLifeDecorator::MoveToPoints(float dt) {
    
    entity->MoveToPoints(dt);

    Battery* battery = entity->GetBattery();

    
    BatteryPercentage = battery->GetCharge() / battery->GetChargeSize();

    /*if(!isGreen){
        UpdateColor("58D68D");
        isGreen = true;
    }
    else if(entity->IsBatteryEmpty() && !isRed){
        UpdateColor("FF0000");
        isRed = true;
    }*/

    /*if(BatteryPercentage > 0.75 && !isGreen) {
        UpdateColor("58D68D"); //green
        isGreen = true;
    }
    else if(BatteryPercentage > 0.50 && BatteryPercentage < 0.75 && !isYellow) {
        UpdateColor("FFFF00"); //yellow
        isYellow = true;
    }
    else if(BatteryPercentage > 0.25 && BatteryPercentage < 0.50 && !isOrange) {
        UpdateColor("FFA500"); // orange
        isOrange = true;
    }
    else if(BatteryPercentage > 0.1 && BatteryPercentage < 0.25 && !isRed) {
        UpdateColor("FF0000"); // red
        isRed = true;
    }
    else if(entity->IsBatteryEmpty() && !isBlack){
        UpdateColor("000000"); // black
        isBlack = true;
    }*/

    if(BatteryPercentage > 0.75 && color != Color::green) {
        UpdateColor("58D68D"); //green
        color = Color::green;
    }
    else if(BatteryPercentage > 0.50 && BatteryPercentage < 0.75 && color != Color::yellow) {
        UpdateColor("FFFF00"); //yellow
        color = Color::yellow;
    }
    else if(BatteryPercentage > 0.25 && BatteryPercentage < 0.50 && color != Color::orange) {
        UpdateColor("FFA500"); // orange
        color = Color::orange;
    }
    else if(BatteryPercentage > 0.1 && BatteryPercentage < 0.25 && color != Color::red) {
        UpdateColor("FF0000"); // red
        color = Color::red;
    }
    else if(entity->IsBatteryEmpty() && color != Color::black){
        UpdateColor("000000"); // black
        color = Color::black;
    }
    
}

void BatteryLifeDecorator::UpdateColor(std::string color) {
  AEntitySubject* entitySubject = entity->GetSubject();
  picojson::value val;
  std::string json = "{\"details\": {\"color\": \"" + color + "\"},\"type\": \"notify\", \"value\": \"updateDetails\"}";
  picojson::parse(val, json);
  IEntity* ent = dynamic_cast<IEntity*>(entity);
  entitySubject->Notify(val, *ent);
}

}
