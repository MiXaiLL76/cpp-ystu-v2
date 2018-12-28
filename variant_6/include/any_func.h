#pragma once
#ifndef ANY_FUNC_H
#define ANY_FUNC_H
#include <algorithm>
#include <string>

// Честно стырено отсюда: https://stackoverflow.com/a/24315631/10704838
std::string ReplaceAll(std::string str, const std::string &from, const std::string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

#endif