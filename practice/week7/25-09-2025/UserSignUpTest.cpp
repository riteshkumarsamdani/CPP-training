#include "UserSignUpService.h"
#include "IEmailSender.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class MockEmailSender : public IEmailSender {
public:
    MOCK_METHOD(void, SendWelcomeEmail, (const std::string& email), (override));
};

TEST(MockTest, SendsWelcomeEmailOnSignup) {
    MockEmailSender mock;
    UserSignupService service(&mock);

    EXPECT_CALL(mock, SendWelcomeEmail("alice@example.com"));
    service.Signup("alice@example.com");
}
