#pragma once
#include "PackageSize.h" 

enum DeleteRespCodes
{
    DELETE_SUCCESS,
    DELETE_FAILED
};


struct DeleteRespBody
{
    DeleteRespCodes code;
    char Session[SessionLength];
};
