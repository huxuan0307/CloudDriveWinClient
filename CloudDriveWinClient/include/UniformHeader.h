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
    SIGNIN,         // ��½
    SIGNIN_RES,     // ��½���ؽ��

    SIGNUP,         // ע��
    SIGNUP_RES,     // ע�᷵�ؽ��

    UPLOAD_REQ,     // �ϴ��ļ��ź� ��һ�θ�֪�������ļ�·������С������
    UPLOAD_RESP,    // �ϴ��ļ��Ľ��
    UPLOAD_FETCH,   // ��������Ҫ���ϴ�ĳһ�����ļ���
    UPLOAD_PUSH,    // �ͻ��˴�������������Ҫ�����ݿ�
 
    DOWNLOAD_REQ,   // �����ļ����ź� ��һ�θ�֪��������Ҫ���ص��ļ���·��������
    DOWNLOAD_RESP,  // �����ļ��Ľ��
    DOWNLOAD_PUSH,  // �������˸��ͻ���ĳһ����

    SYN_REQ,         // ͬ���ź� �ͻ�������ͬ��ĳһ·�����ļ�
    SYN_RESP,        // ͬ���ź� ��Ӧͬ����� �����ļ��µ��ļ�����
    SYN_PUSH,        // ͬ���ź� ����һ��Ŀ¼�µ���Ϣ

    COPY,            // �����ļ�
    COPY_RES,
    MOVE,            // �����ļ�
    MOVE_RES,
    DELETE,          // ɾ���ļ�
    DELETE_RES
    // MKDIR,          // �½��ļ���
};

// ���ڲ�ָͬ����Ĵ�С��ӳ��� const���� �����Ը��� ֻ�ܳ�ʼ����ֵ
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

// ͳһ��ͷ�� ÿ��ָ���ǰ��Ҫ�е�
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
    // �����Ĵ�С
    len = PackageSizeMap.at(p);
}
