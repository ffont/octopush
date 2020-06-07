/*
  ==============================================================================

    definitions.h
    Created: 27 Oct 2019 9:47:17am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#define DEFAULT_PUSH_DISPLAY_FRAME_RATE 60
#define DEFAULT_STATE_UPDATE_RATE 10
#define DEFAULT_ENCODER_ROTATION_MAX_MESSAGE_RATE_HZ 15

#define DEFAULT_PLAY_ON_START true

#define N_AUDIO_TRACKS 7

#define DEFAULT_INITIALIZE_PUSH true

#define DEFAULT_INITIALIZE_AUDIO_ENGINE true

#define DEFAULT_USE_MIDI_BRIDGE false

#define ACTION_INIT_PUSH "init_push"

#define MIDI_BRIDGE_SEND_TO_PUSH_OSC_PATH "/topush"
#define MIDI_BRIDGE_SEND_TO_PUSH_HOST "127.0.0.1"
#define MIDI_BRIDGE_SEND_TO_PUSH_PORT 9001

#define MIDI_BRIDGE_RECEIVE_FROM_PUSH_OSC_PATH "/frompush"
#define MIDI_BRIDGE_RECEIVE_FROM_PUSH_HOST "127.0.0.1"
#define MIDI_BRIDGE_RECEIVE_FROM_PUSH_PORT 9002
