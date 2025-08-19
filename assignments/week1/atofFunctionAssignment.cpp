#include<iostream>
#include<cmath>
#include<string>
#include <cstring>

int check_sign(const char*& input)
{   
    int sign = 1;
    if(*input == '+')
    {
        input++;
    }
    else if(*input == '-')
    {
        sign = -1;
        input++;
    }
    return sign;
}

double find_power(const char* input){
    double pow = 1;
    int pow_num = 0;
    int sign = check_sign(input);
    while(*input != '\0')
    {
        if(*input >= '0' && *input <= '9')
        {
            pow_num = (10 * (*input) - '0');
        }
        else
        {
            break;
        }
    }
    pow = std::pow(2, pow_num * sign);
    return pow;
}

double find_exponent(const char* input){
    double exp = 1;
    int index = 0;
    int exp_num = 0;
    int sign = check_sign(input);
    while(*input != '\0')
    {
        if((*input >= '0') && (*input <= '9'))
        {
            exp_num = 10 * exp_num + (*input - '0');
        }
        else
        {
            break;
        }
        input++;
    }
    exp = std::pow(10, (exp_num * sign));
    return exp;
}

bool checkInf(std::string input)
{
    return (input == "inf") ? true : false;
}

bool checkNan(std::string input)
{
    return (input == "nan") ? true : false;
}

double hexa_val(const char* input)
{
    double hex_val = 0;
    double deci = 1;
    int flag = 0;
    double power = 1;
    while(*input != '\n')
    { 
        if(*input >= '0' && *input <= '9')
        {
            hex_val = 16 * hex_val + (*input - '0');
            deci = (flag == 1) ? deci * 16 : deci;
        }
        else if(*input >= 'a' && *input <= 'f')
        {
            hex_val = 16 * hex_val + ((*input - 'a')+10);
            deci = (flag==1) ? deci * 16 : deci;
        }
        else if(*input == 'p')
        {
            input++;
            power = find_power(input);
            break;
        }
        else if(*input == '.' && (flag == 0))
        {
            flag = 1;
        }
        else
        {
            break;
        }
        input++;
    }
    double atof_val = (hex_val / deci) * power;
    return atof_val;
}

double decimal_val(const char* input)
{
    double integer = 0;
    double deci = 1;
    int flag = 0;
    double exponential = 1;
    while(*input != '\0')
    {
        if(*input >= '0' && *input <= '9')
        {
            integer = 10 * integer + (*input - '0');
            deci = (flag == 1) ? (deci * 10) : deci;
        }
        else if(*input == 'e')
        {
            input++;
            exponential = find_exponent(input);
            break;
        }
        else if(*input == '.' && (flag == 0))
        {
            flag = 1;
        }
        else
        {
            break;
        }
        input++;
    }
    double atof_val = (integer / deci) * exponential;
    return atof_val;
}

double my_atof(const char* input)
{
    int sign=1;
    sign = check_sign(input);
    double atof_val;
    std::string str=input;
    bool hexa = str.substr(0,2) == "0x" ? true : false;
    bool nan = checkNan(str.substr(0,3));
    bool inf = checkInf(str.substr(0,3));
    if(nan)
    {
        atof_val = NAN;
    }
    else if(inf)
    {
        atof_val = INFINITY;
    }
    else if(hexa)
    {
        atof_val = hexa_val(str.substr(2,str.length()).c_str());
    }
    else{
        atof_val = decimal_val(input);
    }
    return atof_val*sign;
}

std::string to_lower(std::string input)
{
    for(auto c : input)
    {
        c = std::tolower(c);
    }
    return input;
}

int main()
{
    bool run=1;
    while(run)
    {
        std::cout << "enter string for conversion :" << std::endl;
        std::string input;
        std::getline(std::cin >> std::ws, input); 
        input = to_lower(input);
        double output = my_atof(input.c_str());
        double original_output = std::atof(input.c_str());
        std::cout << "string input value is : " << input 
        << "\noutput from my_atof function is : " << output 
        << "\noutput from original atof function is : " <<original_output << std::endl;
        std::cout << "enter 1 to continue or type anything to close\n";
        std::cin >> run;
    }
    return 0;
}
