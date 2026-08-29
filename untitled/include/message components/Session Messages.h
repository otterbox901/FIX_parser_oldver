//
// Created by alex on 2026-08-28.
//

#ifndef UNTITLED_SESSION_MESSAGES_H
#define UNTITLED_SESSION_MESSAGES_H

#include <unordered_map>
#include <string>

inline std::unordered_map<std::string, std::string> fix44SessionMsgTypes = {
    {"0", "Heartbeat"}, {"1", "Test Request"}, {"2", "Resend Request"}, {"3", "Reject"},
    {"4", "Sequence Reset"}, {"5", "Logout"}, {"A", "Logon"}
};

#endif //UNTITLED_SESSION_MESSAGES_H
