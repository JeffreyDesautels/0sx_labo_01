#include "Led.h"
#include <Arduino.h>

Led::Led(int ledPin)
  : _ledPin(ledPin) {
  _state = LedState::ON;

  _firstTimeOn = true;
  _onDuration = 2000;
  _previousTimeOn = 0;

  _firstTimeBlink = true;
  _blinkRate = 750;
  _previousTimeBlink = 0;
  _blinkCount = 0;
  _ledState = LOW;

  _firstTimeFade = true;
  _fadeRate = 40;
  _previousTimeFade = 0;
  _brightness = 255;
  _fadeAmount = 5;

  _firstTimeOff = true;
  _offDuration = 2000;
  _previousTimeOff = 0;
}

void Led::begin() {
  pinMode(_ledPin, OUTPUT);
  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  Serial.println("Refactorisation du code du labo 1 en Arduino.");
  delay(2000);
}

void Led::update() {
  _currentTime = millis();

  switch (_state) {
    case LedState::ON:
      _onState();
      break;
    case LedState::BLINK:
      _blinkState();
      break;
    case LedState::FADE:
      _fadeState();
      break;
    case LedState::OFF:
      _offState();
      break;
  }
}

void Led::_onState() {
  if (_firstTimeOn) {
    _firstTimeOn = false;
    _previousTimeOn = _currentTime;
    Serial.println("Allume – 2255309");
  }

  digitalWrite(_ledPin, HIGH);

  if (_currentTime - _previousTimeOn >= _onDuration) {
    _firstTimeOn = true;
    _state = LedState::BLINK;
  }
}

void Led::_blinkState() {
  if (_firstTimeBlink) {
    _firstTimeBlink = false;
    Serial.println("Clignotement – 2255309");
  }

  if (_currentTime - _previousTimeBlink >= _blinkRate) {
    _previousTimeBlink = _currentTime;

    _ledState = !_ledState;

    if (_ledState == HIGH) {
      _blinkCount++;
    }

    digitalWrite(_ledPin, _ledState);
  }

  if (_blinkCount == 5) {
    _firstTimeBlink = true;
    _blinkCount = 0;
    _state = LedState::FADE;
  }
}

void Led::_fadeState() {
  if (_firstTimeFade) {
    Serial.println("Variation – 2255309");
    _firstTimeFade = false;
    _previousTimeFade = 0;
    _brightness = 255;
  }

  if (_currentTime - _previousTimeFade >= _fadeRate) {
    _previousTimeFade = _currentTime;

    analogWrite(_ledPin, _brightness);
    _brightness -= _fadeAmount;

    if (_brightness <= 0) {
      analogWrite(_ledPin, 0);
      _firstTimeFade = true;
      _state = LedState::OFF;
    }
  }
}

void Led::_offState() {
  if (_firstTimeOff) {
    _firstTimeOff = false;
    _previousTimeOff = _currentTime;
    Serial.println("Éteint – 2255309\n");
  }

  digitalWrite(_ledPin, LOW);

  if (_currentTime - _previousTimeOff >= _offDuration) {
    _firstTimeOff = true;
    _state = LedState::ON;
  }
}