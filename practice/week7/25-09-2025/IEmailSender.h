#pragma once
#include <string>

class IEmailSender {
public:
    virtual void SendWelcomeEmail(const std::string& email) = 0;
    virtual ~IEmailSender() = default;
};
