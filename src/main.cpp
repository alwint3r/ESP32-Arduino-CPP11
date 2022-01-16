#include <Arduino.h>
#include <FunctionalInterrupt.h>
#include <functional>

static constexpr uint8_t button = 0;

using InterruptFn = std::function<void(void)>;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(button, INPUT_PULLUP);

    InterruptFn interruptFunction{
        []()
        {
            auto state = digitalRead(button);
            digitalWrite(LED_BUILTIN, !state);
        }
    };

    attachInterrupt(button, interruptFunction, CHANGE);
}

void loop()
{
}