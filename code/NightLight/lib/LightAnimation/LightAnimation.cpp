#include "LightAnimation.h"


LightAnimation::LightAnimation() {
    this->setAllLedsToBlack();
}


void LightAnimation::init() {
    pinMode(PIN_NEOPIXEL, OUTPUT);
    digitalWrite(PIN_NEOPIXEL, LOW);

    this->setAllLedsToBlack();

    FastLED.addLeds<NEOPIXEL, PIN_NEOPIXEL>(this->leds, 4);
    delay(50);
    FastLED.show();
    delay(50); // Wait for the LEDs to initialize

}



void LightAnimation::update() {
    if (this->disabled) {
        return;
    }
    switch (this->animation) {
        case ANIMATION_START_DEVICE:
            this->animationStartDevice();
            break;
        case ANIMATION_LOADING:
            this->animationRollingWheel();
            break;
        case ANIMATION_INDEXING:
            this->animationRollingWheel();
            break;
        case ANIMATION_ALL_BLINKING:
            this->animationAllBlinking();
            break;
        case ANIMATION_WARNING:
            this->animationAllBlinking();
            break;
        case ANIMATION_ALL_BLINKING_WITH_COLOR_CHANGE:
            this->animationAllBlinkingWithColorChange();
            break;
        case ANIMATION_PATTERN_0:
            this->animationPattern0();
            break;
        case ANIMATION_PATTERN_1:
            this->animationPattern1();
            break;
        default:
            break;
    }
}


void LightAnimation::animationPattern0() {


}



void LightAnimation::animationPattern1() {


}


void LightAnimation::animationStartDevice() {
    if (this->shouldExecuteCurrentAnimation()) {
        unsigned long _millis = this->current_animation_millis;
        int value = 48;
        int color_offset = map(_millis - this->last_time, 0, this->period_duration, 0, 255);

        this->leds[0] = CHSV(160 + color_offset, 255, value);
        this->leds[1] = CHSV(64 + color_offset, 255, value);
        this->leds[2] = CHSV(128 + color_offset, 255, value);
        this->leds[3] = CHSV(192 + color_offset, 255, value);
        FastLED.show();
    }
}


void LightAnimation::animationAllBlinkingWithColorChange() {
    unsigned long _millis = millis();

    int brightness_max = 64;

    if (_millis < this->last_time + this->period_duration) {

        if (_millis < this->last_time + this->period_duration / 2) {
            for (int i = 0; i < 4; i++) {
                this->leds[i] = CHSV(
                    (this->hue - (this->loop_count * 3)) % 255,
                    255,
                    map(_millis - (this->last_time), 0, this->period_duration / 2, 0, brightness_max - 1) % brightness_max
                );
            }
        } else {
            for (int i = 0; i < 4; i++) {
                this->leds[i] = CHSV(
                    (this->hue - (this->loop_count * 3)) % 255,
                    255,
                    (brightness_max - map(_millis - this->last_time - this->period_duration / 2, 0, this->period_duration / 2, 0, brightness_max - 1)) % brightness_max
                );
            }
        }
        FastLED.show();

    } else {
        if (this->loop_animation) {
            this->last_time = _millis;
            this->loop_count++;
        } else {
            this->resetAnimation();
        }
    }
}


void LightAnimation::animationAllBlinking() {
    
    unsigned long _millis = millis();
    if (_millis < this->last_time + this->period_duration) {
        
        int brightness_max = 64;
        if (_millis < this->last_time + this->period_duration / 2) {
            for (int i = 0; i < 4; i++) {
                this->leds[i] = CHSV(
                    this->hue,
                    255,
                    map(_millis - (this->last_time), 0, this->period_duration / 2, 0, brightness_max - 1) % brightness_max
                );
            }
        } else {
            for (int i = 0; i < 4; i++) {
                this->leds[i] = CHSV(
                    this->hue,
                    255,
                    (brightness_max - map(_millis - this->last_time - this->period_duration / 2, 0, this->period_duration / 2, 0, brightness_max - 1)) % brightness_max
                );
            }
        }
        FastLED.show();

    } else {
        if (this->loop_animation) {
            this->last_time = _millis;
        } else {
            this->resetAnimation();
        }
    }
}


void LightAnimation::animationRollingWheel() {
    unsigned long _millis = millis();

    int brightness_max = 64;

    const uint8_t led_order[4] = {0, 1, 3, 2}; // Ordre physique
    const int led_count = 4;

    // Durée totale d'un cycle complet
    unsigned long wave_duration = this->period_duration;
    unsigned long led_spacing = wave_duration / led_count;

    // Position relative dans le cycle (de 0 à wave_duration)
    unsigned long t = (_millis - this->last_time) % wave_duration;

    for (int i = 0; i < led_count; i++) {
        int led_index = led_order[i];

        // Centre du passage de la "vague" pour cette LED
        long led_center = i * led_spacing;

        // Décalage par rapport à la tête de la vague
        long time_offset = (long)t - (long)led_center;

        // Gère le wrap-around en fin de cycle (pour boucle fluide)
        if (time_offset < -((long)wave_duration / 2)) time_offset += wave_duration;
        if (time_offset >  ((long)wave_duration / 2)) time_offset -= wave_duration;

        // Triangle inversé : max au centre, 0 sur les bords
        int brightness = 0;
        //long fade_zone = led_spacing * 1.5; // 3 leds allumés au maximum
        long fade_zone = led_spacing * 1.1;

        if (abs(time_offset) <= fade_zone) {
            brightness = map(abs(time_offset), 0, fade_zone, brightness_max, 0);
        } else {
            brightness = 0;
        }

        this->leds[led_index] = CHSV(this->hue, 255, brightness);
    }

    FastLED.show();
}



void LightAnimation::animationIndexing() {
    this->animationRollingWheel();
}


void LightAnimation::triggerAnimationStartDevice() {
    this->last_time = millis();
    this->period_duration = 10000;
    this->animation = ANIMATION_START_DEVICE;
    this->loop_animation = true;
}


void LightAnimation::triggerAnimationFatalError() {
    this->last_time = millis();
    this->period_duration = 500;
    this->animation = ANIMATION_ALL_BLINKING;
    this->hue = 0; // Red
    this->loop_animation = true;
}


void LightAnimation::triggerAnimationDelay() {
    this->last_time = millis();
    this->period_duration = 500;
    this->animation = ANIMATION_ALL_BLINKING_WITH_COLOR_CHANGE;
    this->hue = 64; // Yellow
    this->loop_animation = true;
    this->loop_count = 0; // Reset loop count for delay animation
}


void LightAnimation::triggerAnimationLoading() {
    this->last_time = millis();
    this->period_duration = 1000;
    this->animation = ANIMATION_LOADING;
    this->hue = 160; // Blue
    this->loop_animation = true;
}


void LightAnimation::resetAnimation() {
    this->animation = ANIMATION_NO_ANIMATION;
    this->hue = 0;
    this->setAllLedsToBlack();
    FastLED.show();
}


void LightAnimation::triggerAnimationIndexing() {
    this->last_time = millis();
    this->period_duration = 1000;
    this->animation = ANIMATION_INDEXING;
    this->hue = 224; // Violet
    this->loop_animation = true;
}


void LightAnimation::triggerAnimationWarning() {
    this->last_time = millis();
    this->period_duration = 500;
    this->animation = ANIMATION_WARNING;
    this->hue = 32; // Orange
    this->loop_animation = true;
}


void LightAnimation::triggerAnimationPattern(int animation_pattern, int period_duration, bool loop_animation) {
    this->last_time = millis();
    this->period_duration = period_duration;
    this->animation = animation_pattern;
    this->loop_animation = loop_animation;
}



void LightAnimation::setAllLedsToBlack() {
    this->leds[0] = CRGB::Black;
    this->leds[1] = CRGB::Black;
    this->leds[2] = CRGB::Black;
    this->leds[3] = CRGB::Black;
}


void LightAnimation::disable() {
    this->disabled = true;
    this->setAllLedsToBlack();
    FastLED.show();
}


void LightAnimation::enable() {
    this->disabled = false;
}


bool LightAnimation::shouldExecuteCurrentAnimation() {
    this->current_animation_millis = millis();
    if (current_animation_millis < this->last_time + this->period_duration) {
        return true;
    } else {
        if (this->loop_animation) {
            this->last_time = current_animation_millis;
        } else {
            this->animation = ANIMATION_NO_ANIMATION;
        }
    }
    return false;
}