#include <Arduino.h>
#include <unity.h>

#define LED_BUILTIN 2

void test_led_builtin_pin_number(void) {
    TEST_ASSERT_EQUAL(2, LED_BUILTIN);
}

void test_led_state_high(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void) {
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup() {
    // NOTE! wait 2 seconds for board reset..
    delay(2000);

    UNITY_BEGIN(); // start unit test

    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
    if (i < max_blinks) {
        RUN_TEST(test_led_state_high);
        delay(1000);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    } else if (i >= max_blinks) {
        UNITY_END(); // end unit test
    }
}