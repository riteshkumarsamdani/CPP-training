#ifndef ICALC_H
#define ICALC_H

class ICalc
{
    public:
        virtual ~ICalc();
        virtual int add(int, int) = 0;
        virtual int sub(int, int) = 0;
        virtual int multiply(int, int) = 0;
        virtual int division(int, int) = 0;
};

#endif
