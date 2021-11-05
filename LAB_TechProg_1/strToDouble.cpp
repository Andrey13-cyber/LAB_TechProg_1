#include "strToDouble.h"

bool checkStringToDouble(std::string s)
{
    bool flagPoint = false;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] < '0' || s[i] > '9') && (s[i] == '.' && i == 0 || flagPoint))
            return false;
        if (s[i] == '.')
            flagPoint = true;
    }

    return true;
}