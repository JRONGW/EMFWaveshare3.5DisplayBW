#pragma once
#include <Arduino.h>

// Parses an incoming MQTT payload for the given topic and pushes it into
// the matching ui_data_update_*() call. Returns true if the topic was
// recognized.
bool sensor_parse_and_update(const char* topic, const uint8_t* payload, unsigned int length);
