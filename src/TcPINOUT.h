#ifndef TcPINOUT_h
#define TcPINOUT_h

#include "Arduino.h"

class TcPINOUT {
protected:
    uint8_t pin;
    bool _state = false;         // Current state of the pin
    bool _previousState = false; // Previous state for change detection
    bool _invert = false;        // Invert output logic
    void (*_callback)(bool);     // Callback function for state changes

private:
    uint32_t _lastTime = 0;      // Last time update was triggered
    uint16_t _duration = 0;      // Duration for timed operations (ms)
    uint8_t _toggleCount = 0;    // Number of toggles remaining

public:
    TcPINOUT(uint8_t pin, void (*callback)(bool) = nullptr, bool invert = false);

    void begin();                // Initialize the pin
    void on();                   // Turn the pin ON
    void off();                  // Turn the pin OFF
    void toggle();               // Toggle the pin state
    void setState(bool state);   // Set pin state explicitly
    bool getState();             // Get current pin state
    bool isOn();                 // Check if pin is ON

    void onFor(uint16_t ms);     // Turn ON for a specific duration
    void toggleFor(uint8_t count, uint16_t ms = 100); // Toggle for a number of times
    void stopToggle();           // Stop toggling and turn OFF
    uint8_t getToggleCount();    // Get remaining toggle count
    void update();               // Update timed operations
    void setCallback(void (*callback)(bool)); // Set callback function
};

#endif