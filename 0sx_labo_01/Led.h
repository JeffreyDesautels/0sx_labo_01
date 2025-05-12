#pragma once

enum LedState { ON,
                BLINK,
                FADE,
                OFF };

class Led {

public:

  Led(int ledPin);

  void begin();

  void update();

private:

  int _ledPin;


  int _brightness;

  int _fadeAmount;

  int _blinkCount;

  int _ledState;


  unsigned long _onDuration;

  unsigned long _blinkRate;

  unsigned long _fadeRate;

  unsigned long _offDuration;

  unsigned long _previousTimeOn;

  unsigned long _previousTimeBlink;

  unsigned long _previousTimeFade;

  unsigned long _previousTimeOff;

  unsigned long _currentTime;


  bool _firstTimeOn;

  bool _firstTimeBlink;

  bool _firstTimeFade;

  bool _firstTimeOff;


  LedState _state;


  void _onState();

  void _blinkState();

  void _fadeState();

  void _offState();
};