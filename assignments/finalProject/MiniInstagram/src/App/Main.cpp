#include <iostream>
#include "InstaController.h"

int main(int argc, char* argv[])
{
    int status = 0;
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <user_file_path> <post_file_path>\n";
        status = 1;
    }
    else
    {
        std::string userFilePath = argv[1];
        std::string postFilePath = argv[2];
        InstaController app(userFilePath, postFilePath);
        app.run();
    }
    return status;
}
