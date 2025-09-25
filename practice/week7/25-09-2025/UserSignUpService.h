#pragma once
#include "IEmailSender.h"
#include <string>

class UserSignupService {
public:
    UserSignupService(IEmailSender* sender) : sender_(sender) {}

    void Signup(const std::string& email) {
        // ... signup logic ...
        sender_->SendWelcomeEmail(email);
    }

private:
    IEmailSender* sender_;
};
