#pragma once

#include <FastLED.h>
#include <Arduino.h>

#include <configurations.h>


class LightAnimation {
    
    public:
        static constexpr int ANIMATION_NO_ANIMATION = 0;
        static constexpr int ANIMATION_START_DEVICE = 1;
        static constexpr int ANIMATION_LOADING = 2;
        static constexpr int ANIMATION_FLASH_FADE_OUT = 3;
        static constexpr int ANIMATION_ALL_BLINKING = 4;
        static constexpr int ANIMATION_INDEXING = 5;
        static constexpr int ANIMATION_WARNING = 6;
        static constexpr int ANIMATION_ALL_BLINKING_WITH_COLOR_CHANGE = 7;

        bool disabled = false;
        unsigned int animation = 0;
        

        LightAnimation();
        void init();
        void update();
        
        void resetAnimation(); // no animation, turn off LEDs
        void triggerAnimationStartDevice();
        void triggerAnimationLoading();
        void triggerAnimationFlashFadeOut();
        void triggerAnimationFatalError();
        void triggerAnimationIndexing();
        void triggerAnimationWarning();
        void triggerAnimationDelay();

        void setAllLedsToBlack();

        void disable();
        void enable();

    private:

        CRGB leds[4];

        unsigned long last_time = 0;
        unsigned int period_duration = 1000;
        boolean loop_animation = false;
        unsigned long loop_count = 0;

        int hue = 0;

        void animationStartDevice();
        void animationRollingWheel();
        void animationIndexing();
        void animationFlashFadeOut();
        void animationAllBlinking();
        void animationAllBlinkingWithColorChange();
        void animationWarning();

};
