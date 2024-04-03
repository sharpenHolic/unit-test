//
// Created by gqxiong on 2024/1/11.
//

#include "gtest/gtest.h"


std::string get()
{
    std::string a{"test"};
    return std::move(a);
}

TEST(STRING, find1)
{
    std::string cmdLine = "issue_message -puts_tolog";
    std::string ignore = "issue_message -puts_tolog";

    if (cmdLine.find(ignore) != std::string::npos) {
        std::cout << "ignore: " << std::endl;
    }

    std::cout << get() << std::endl;
}
