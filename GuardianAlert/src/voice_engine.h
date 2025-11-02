#ifndef VOICE_ENGINE_H
#define VOICE_ENGINE_H

#include <portaudio.h>
#include <stdbool.h>

// Real voice detection functions
bool voice_engine_init(void);
void voice_engine_cleanup(void);
bool start_voice_listening(void);
void stop_voice_listening(void);
bool check_voice_trigger(void);

// Trigger phrases
extern const char* TRIGGER_PHRASES[];
extern int TRIGGER_COUNT;

#endif