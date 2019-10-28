#include "minimal_fighter.h"

MinimalFighter::MinimalFighter(){
    mHp = 0;
    mPower = 0;
    mStatus = Invalid;
}
MinimalFighter::MinimalFighter(int _hp,int _mpower){
    mHp = _hp;
    mPower = _mpower;
    mStatus = status();
}
int MinimalFighter::hp ()const{
    return mHp;
}
int MinimalFighter::power () const{
    return mPower;
}
FighterStatus MinimalFighter::status ()const{
    FighterStatus status;
    if(mHp <= 0)
        status = Dead;
    else
        status = Alive;
    return status;
}
void MinimalFighter::setHp(int _hp){
    mHp = _hp;
}
void MinimalFighter::hit(MinimalFighter *_enemy){
    
    setHp(mHp - _enemy->power());
    _enemy->setHp(_enemy->hp()-mPower);
}
void MinimalFighter::attack(MinimalFighter *_target){
    int targetHp = _target->hp();
    _target->setHp(targetHp - mPower);
    mPower = 0;
}
void MinimalFighter::fight(MinimalFighter *_enemy){
    while(status() == Dead || _enemy->status() == Dead){
       setHp(mHp - _enemy->power());
       _enemy->setHp(_enemy->hp()-mPower);
    }    
}
