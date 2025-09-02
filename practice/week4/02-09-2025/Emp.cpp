#include <iostream>
#include <string>

class Accounts{
   int empId;
   double salary, basic, allowances, deductions;
public:
   Accounts(int empId):empId(empId){}
   void readEmployeeInfo(int empId){
      std::cout << "Enter basic for the employee" << ":"; 
      std::cin >> basic;
      std::cout << "allowances:"; 
      std::cin >> allowances;
      std::cout << "deductions:"; 
      std::cin >> deductions;
  
   }

   double calculateSalary()
   {
      salary = basic + allowances - deductions;
      return salary;
   }

   void display()
   {
   salary = calculateSalary();
   std::cout << "Employee: " << empId << "\n" << "Salary: " << salary << "\n";
   }
};

int main()
{
  
   Accounts acc(1);
   acc.readEmployeeInfo(1);
   acc.display();
}