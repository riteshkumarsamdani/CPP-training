#include "Person.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockVehicle : public IVehicle
{
public:
    MOCK_METHOD(std::string, getName, (), (override));
};

class PersonTest : public ::testing::Test
{
    protected:
        std::vector<IVehicle*> vehicles;
        Person person{vehicles};

};

TEST_F(PersonTest, DeleteVehicleRemovesCorrectVehicle)
{
    MockVehicle* vehicle1 = new MockVehicle();
    MockVehicle* vehicle2 = new MockVehicle();
    EXPECT_CALL(*vehicle1, getName()).WillRepeatedly(::testing::Return("mockCar"));
    EXPECT_CALL(*vehicle2, getName()).WillRepeatedly(::testing::Return("mockBike"));
    bool added = person.addVehicle(vehicle1);
    bool added1 = person.addVehicle(vehicle2);
    ASSERT_TRUE(added1);
    ASSERT_TRUE(added);
    bool deleted = person.deleteVehicle("mockCar");
    EXPECT_TRUE(deleted);
    delete vehicle2;
    delete vehicle1;
}
