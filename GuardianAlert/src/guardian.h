#ifndef GUARDIAN_H
#define GUARDIAN_H

void guardian_init(void);
void guardian_process(void);
void guardian_trigger_panic(void);
int get_sms_count(void);
void guardian_set_voice_activation(int enabled);

#endif