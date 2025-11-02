#ifndef ALERT_SYSTEM_H
#define ALERT_SYSTEM_H

#include "live_data.h"

void send_emergency_alerts(LiveLocationData* data, int trigger_id);

#endif