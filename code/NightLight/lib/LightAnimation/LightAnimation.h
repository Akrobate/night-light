#pragma once

#include <FastLED.h>
#include <Arduino.h>

#include <configurations.h>


class LightAnimation {
    
    public:
        static constexpr int ANIMATION_NO_ANIMATION = 0;
        static constexpr int ANIMATION_START_DEVICE = 1;
        static constexpr int ANIMATION_LOADING = 2;

        static constexpr int ANIMATION_ALL_BLINKING = 4;

        static constexpr int ANIMATION_INDEXING = 5;
        static constexpr int ANIMATION_WARNING = 6;
        static constexpr int ANIMATION_ALL_BLINKING_WITH_COLOR_CHANGE = 7;

        static constexpr int ANIMATION_PATTERN_0 = 10;
        static constexpr int ANIMATION_PATTERN_1 = 11;
        static constexpr int ANIMATION_PATTERN_2 = 12;
        static constexpr int ANIMATION_PATTERN_3 = 13;
        static constexpr int ANIMATION_PATTERN_4 = 13;

        bool disabled = false;
        unsigned int animation = 0;
        

        LightAnimation();
        void init();
        void update();
        
        void resetAnimation(); // no animation, turn off LEDs
        void triggerAnimationStartDevice();
        void triggerAnimationLoading();
        void triggerAnimationFatalError();
        void triggerAnimationIndexing();
        void triggerAnimationWarning();
        void triggerAnimationDelay();

        void triggerAnimationPattern(int animation_pattern, int period_duration, bool loop_animation);

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
        void animationAllBlinking();
        void animationAllBlinkingWithColorChange();
        void animationWarning();

};
