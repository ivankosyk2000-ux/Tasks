#include "Task.h"

void Car::TurnEngineOn() {
    engine_is_on_ = true;
}

bool Car::TurnEngineOff() {
    if (gear_ != Gear::PARKED || speed_ != 0) {
        return false;
    }
    engine_is_on_ = false;
    return true;
}


bool Car::IsEngineOn() const{
    return engine_is_on_;
}

bool Car::SetGear(Gear new_gear) {
    if (gear_ == new_gear) {
        return true;
    }
    if (!engine_is_on_) {
        return false;
    }
    if (speed_ != 0) {
        return false;
    }
    gear_ = new_gear;
    return true;
}

Gear Car::GetGear() const{
    return gear_;
}

int Car::GetSpeed() const{
    return speed_;
}

bool Car::SetSpeed(int new_speed) {
    if (!engine_is_on_ || new_speed < 0) {
        return false;
    }
    switch (gear_){

    case Gear::PARKED:
        if (new_speed != 0) {
            return false;
        }
        break;

    case Gear::DRIVE:
        if (new_speed > MAX_SPEED) {
            return false;
        }
        break;

    case Gear::REVERSE:
        if (new_speed > MAX_REVERSE_SPEED) {
            return false;
        }
        break;
    }
    speed_ = new_speed;
    return true;
}

Direction Car::GetDirection() const{
    switch (gear_){
    case Gear::PARKED:
        return Direction::STOPPED;
    case Gear::DRIVE:
        if (speed_ == 0) {
            return Direction::STOPPED;
        }
        return Direction::FORWARD;

    case Gear::REVERSE:
        if (speed_ == 0) {
            return Direction::STOPPED;
        }
        return Direction::BACKWARD;
    }
    return Direction::STOPPED;
}
bool Car::IsSpeedValidForGear(int speed, Gear gear) {
    if (speed < 0) {
        return false;
    }
    return speed <= GetMaxSpeedForGear(gear);
}

int Car::GetMaxSpeedForGear(Gear gear) {
    switch (gear) {
    case Gear::DRIVE:
        return Car::MAX_SPEED;
    case Gear::REVERSE:
        return Car::MAX_REVERSE_SPEED;
    case Gear::PARKED:
        return 0;
    }
    return 0;
}