#include <iostream>
#include <vector>

void display(const std::vector<std::vector<char>>& tic)
{
    std::cout << "play status!\n";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << tic[i][j];
            if(j < 2)
            {
                std::cout << " | ";
            }
            else
            {
                std::cout << "\n";
            }
        }
        std::cout << "----------\n";
    }
}

bool check(const std::vector<std::vector<char>>& tic)
{
    for(int i = 0; i < 3; i++) {
        if(tic[i][0] != '-' && tic[i][0] == tic[i][1] && tic[i][1] == tic[i][2]) {
            std::cout << "Player " << (tic[i][0] == 'X' ? "1" : "2") << " wins!\n";
            return false;
        }
    }

    for(int j = 0; j < 3; j++) {
        if(tic[0][j] != '-' && tic[0][j] == tic[1][j] && tic[1][j] == tic[2][j]) {
            std::cout << "Player " << (tic[0][j] == 'X' ? "1" : "2") << " wins!\n";
            return false;
        }
    }

    if(tic[0][0] != '-' && tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2]) {
        std::cout << "Player " << (tic[0][0] == 'X' ? "1" : "2") << " wins!\n";
        return false;
    }

    if(tic[0][2] != '-' && tic[0][2] == tic[1][1] && tic[1][1] == tic[2][0]) {
        std::cout << "Player " << (tic[0][2] == 'X' ? "1" : "2") << " wins!\n";
        return false;
    }

    bool emptyFound = false;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tic[i][j] == '-') {
                emptyFound = true;
            }
        }
    }
    
    if(!emptyFound) {
        std::cout << "It's a draw!\n";
        return false;
    }

    return true;
}

int main()
{
    bool run = true;
    bool player1 = true;
    std::vector<std::vector<char>> tic(3,std::vector<char>(3,'-'));
    int n;
    do
    {
        display(tic);
        if(player1)
        {
            std::cout << "player 1\n";
            std::cout << "enter number to place x : ";
            std::cin >> n;
            if(n >= 0 && n < 9 && tic[n/3][n%3] == '-')
            {
                tic[n/3][n%3] = 'X';
                player1 = false;
            }
            else
            {
                std::cout << "entered wrong number!! re-enter!";
            }
        }
        else
        {
            std::cout << "player 2\n";
            std::cout << "enter number to place O : ";
            std::cin >> n;
            if(n >= 0 && n < 9 && tic[n/3][n%3] == '-')
            {
                tic[n/3][n%3] = 'O';
                player1 = true;
            }
            else
            {
                std::cout << "entered wrong number!! re-enter!";
            }
        }
        run = check(tic);
    } while (run);
    display(tic);
    return 0;
}
