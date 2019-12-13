#pragma once

#include <map>
#include "PackageSize.h"
#include "SYNReqBody.h"
#include "SYNRespBody.h" 
#include "SYNPushBody.h"
#include "MoveBody.h"
#include "MoveRespBody.h"
#include "CopyBody.h"
#include "CopyRespBody.h"
#include "DeleteBody.h"
#include "DeleteRespBody.h"

struct SigninBody
{
    char Username[UsernameLength];
    char Password[PasswordLength];
    char IP[IPLength];
    char Session[SessionLength];
};
enum SigninCodes
{
    SIGNIN_SUCCESS,
    SIGNIN_INCORRECT_PASSWORD,
    SIGNIN_UNEXIST_USERNAME
};
struct SigninresBody
{
    SigninCodes code;
    char Session[SessionLength];
    char ExternInformation[ExternInformationLength];
};

struct SignupBody
{
    char Username[UsernameLength];
    char Password[PasswordLength];
    char IP[IPLength];
};
enum SignupCodes
{
    SIGNUP_SUCCESS,
    SIGNUP_PASSWORD_SHORT,
    SIGNUP_PASSWORD_LONG,
    SIGNUP_EXISTED_USERNAME,
    SIGNUP_USERNAME_LONG
};
struct SignupresBody
{

    SignupCodes code;
    char Session[SessionLength];
    char ExternInformation[ExternInformationLength];
};

struct UploadReqBody
{
    char fileName[fileNameLength];
    uint32_t fileSize;
    bool isDir;
    char MD5[MD5Length];
    char path[pathLength];
    char Session[SessionLength];
};

enum UploadRespCodes
{
    UPLOAD_SUCCESS,
    UPLOAD_ALREADY_HAS,
    UPLOAD_TO_LARGE
};

struct UploadRespBody
{
    UploadRespCodes code;
    uint16_t chunkNum;
    char Session[SessionLength];
    char ExternInformation[ExternInformationLength];
};

struct UploadFetchBody
{
    char fileName[fileNameLength];
    char path[pathLength];
    uint16_t id;
    char Session[SessionLength];
};

struct UploadPushBody
{
    char fileName[fileNameLength];
    char path[pathLength];
    uint16_t id;
    char content[ChunkSize];
    char Session[SessionLength];
};

struct DownloadReqBody
{
    char fileName[fileNameLength];
    char path[pathLength];
    char Session[SessionLength];
};
enum DownloadRespCodes
{
    DOWNLOAD_SUCCESS,
    DOWNLOAD_UNEXIST_FILE
};
struct DownloadRespBody
{

    DownloadRespCodes code;
    uint16_t chunkNum;
    char Session[SessionLength];
    char ExternInformation[ExternInformationLength];
};

struct DownloadPushBody
{
    char fileName[fileNameLength];
    char path[pathLength];
    uint16_t id;
    char content[ChunkSize];
    char Session[SessionLength];
};






enum PackageType
{
    SIGNIN,         // 登陆
    SIGNIN_RES,     // 登陆返回结果

    SIGNUP,         // 注册
    SIGNUP_RES,     // 注册返回结果

    UPLOAD_REQ,     // 上传文件信号 第一次告知服务器文件路径、大小、名称
    UPLOAD_RESP,    // 上传文件的结果
    UPLOAD_FETCH,   // 服务器端要求上传某一特殊文件块
    UPLOAD_PUSH,    // 客户端传给服务器端需要的数据块
 
    DOWNLOAD_REQ,   // 下载文件的信号 第一次告知服务器需要下载的文件的路径、名称
    DOWNLOAD_RESP,  // 下载文件的结果
    DOWNLOAD_PUSH,  // 服务器端给客户端某一个块

    SYN_REQ,         // 同步信号 客户端请求同步某一路径的文件
    SYN_RESP,        // 同步信号 回应同步结果 包括文件下的文件个数
    SYN_PUSH,        // 同步信号 发送一个目录下的信息

    COPY,            // 拷贝文件
    COPY_RES,
    MOVE,            // 复制文件
    MOVE_RES,
    DELETE,          // 删除文件
    DELETE_RES
    // MKDIR,          // 新建文件夹
};

// 对于不同指令交互的大小的映射表 const类型 不可以更改 只能初始化赋值
const std::map<PackageType, uint16_t> PackageSizeMap{
    {PackageType::SIGNIN, sizeof(SigninBody)},
    {PackageType::SIGNIN_RES, sizeof(SigninresBody)},

    {PackageType::SIGNUP, sizeof(SignupBody)},
    {PackageType::SIGNUP_RES, sizeof(SignupresBody)},

    {PackageType::UPLOAD_REQ, sizeof(UploadReqBody)},
    {PackageType::UPLOAD_RESP, sizeof(UploadRespBody)},
    {PackageType::UPLOAD_FETCH, sizeof(UploadFetchBody)},
    {PackageType::UPLOAD_PUSH, sizeof(UploadPushBody)},
    
    {PackageType::DOWNLOAD_REQ, sizeof(DownloadReqBody)},
    {PackageType::DOWNLOAD_RESP, sizeof(DownloadRespBody)},
    {PackageType::DOWNLOAD_PUSH, sizeof(DownloadPushBody)},

    {PackageType::SYN_REQ, sizeof(SYNReqBody)},
    {PackageType::SYN_RESP, sizeof(SYNRespBody)},
    {PackageType::SYN_PUSH, sizeof(SYNPushBody)},
    
    {PackageType::COPY, sizeof(CopyBody)},
    {PackageType::COPY_RES,sizeof(CopyRespBody)},
    {PackageType::MOVE, sizeof(MoveBody)},
    {PackageType::MOVE_RES,sizeof(MoveRespBody)},
    {PackageType::DELETE, sizeof(DeleteBody)},
    {PackageType::DELETE_RES, sizeof(DeleteRespBody)},
};

// 统一的头包 每个指令发送前都要有的
struct UniformHeader
{
    PackageType p;
    uint16_t len;
    UniformHeader();
    UniformHeader(const PackageType &pIn);
};

UniformHeader::UniformHeader()
{
    len = 0;
}

UniformHeader::UniformHeader(const PackageType &pIn) : p(pIn)
{
    // 填充包的大小
    len = PackageSizeMap.at(p);
}
