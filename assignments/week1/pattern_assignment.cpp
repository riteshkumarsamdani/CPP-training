#include<iostream>
#include<limits>

void print_line(int length)
{
    const char even = '1';
    const char odd = '0';
    int index = 0;
    while(index <= length)
    {
        if(index % 2 == 0)
        {
            std::cout << even << " ";
        }
        else
        {
            std::cout << odd << " ";
        }
        index++;
    }
}

void print_space(int space)
{
    while(space > 0)
    {
        std::cout << "  ";
        space--;
    }
}

void print_pattern(int &number)
{
    bool is_even = number % 2 == 0 ? true : false;
    int column = is_even ? (number * 2 + 1) : (2 * (number + 1));
    int index = 0;
    int length = 0;
    while(index < (2 * number + 1))
    {
        if(is_even && index == number)
        {
            print_line(length - 1);
        }
        else
        {
            print_line(length);
        }
        if(length < number)
        {
            print_space(column-2*(length+1));
        }
        print_line(length);
        std::cout << std::endl;
        index++;
        if(index <= number)
        {
            length = index;
        }
        else if(is_even)
        {
            length = column - index - 1;
        }
        else 
        {
            length = column - index - 2;
        }
    }
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(0);
        }
        std::cin.clear();
        ignoreLine();
        return true;
    }
    return false;
}

int getInteger()
{
    while (true)
    {
        std::cout << "Enter a integer number: ";
        int x{};
        std::cin >> x;
        if (clearFailedExtraction())
        {
            std::cout << "That input is invalid.  Please try again.\n";
            continue;
        }
        ignoreLine(); 
        return x; 
    }
}

int main()
{
    int number;
    number=getInteger();
    while(number > 0)
    {
        print_pattern(number);
        number=getInteger();
    }
    return 0;
}
