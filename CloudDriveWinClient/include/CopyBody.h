#pragma once
#include "PackageSize.h" 

struct CopyBody
{
    char fileName[fileNameLength];
    char path[pathLength];
    char fileNameTo[fileNameLength];
    char pathTo[pathLength];
    char Session[SessionLength];
};
