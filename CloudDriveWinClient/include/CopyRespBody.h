#pragma once
#include "PackageSize.h" 

enum CopyRespCodes
{
    COPY_SUCCESS,
    COPY_FAILED
};


struct CopyRespBody
{
    CopyRespCodes code;
    char Session[SessionLength];
};
