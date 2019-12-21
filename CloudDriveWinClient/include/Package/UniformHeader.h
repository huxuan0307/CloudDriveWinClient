#pragma once

#include <map>
#include "Package.h"

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
    UPLOAD_DONE,    // ����˴����ͻ��˵�����ź�

    DOWNLOAD_REQ,   // �����ļ����ź� ��һ�θ�֪��������Ҫ���ص��ļ���·��������
    DOWNLOAD_RESP,  // �����ļ��Ľ��
    DOWNLOAD_PUSH,  // �������˸��ͻ���ĳһ����
    DOWNLOAD_FETCH, // �ͻ��������ĳһ��
    DOWNLOAD_DONE,  // �ͻ���֪ͨ������������

    SYN_REQ,         // ͬ���ź� �ͻ�������ͬ��ĳһ·�����ļ�
    SYN_RESP,        // ͬ���ź� ��Ӧͬ����� �����ļ��µ��ļ�����
    SYN_PUSH,        // ͬ���ź� ����һ��Ŀ¼�µ���Ϣ

    FILEINFO,        // �ļ���Ϣ������hash��exist��completed��size(MB)

    COPY,            // �����ļ�
    COPY_RES,

    MOVE,            // �����ļ�
    MOVE_RES,
    
    DELETE,          // ɾ���ļ�
    DELETE_RES,
    
    MKDIR,          // �½��ļ���
    MKDIR_RES

};

// ���ڲ�ָͬ����Ĵ�С��ӳ��� const���� �����Ը��� ֻ�ܳ�ʼ����ֵ
const static std::map<PackageType, uint64_t> PackageSizeMap{
    {PackageType::SIGNIN, sizeof (SigninBody)},
    {PackageType::SIGNIN_RES, sizeof (SigninresBody)},

    {PackageType::SIGNUP, sizeof (SignupBody)},
    {PackageType::SIGNUP_RES, sizeof (SignupresBody)},

    {PackageType::UPLOAD_REQ, sizeof (UploadReqBody)},
    {PackageType::UPLOAD_RESP, sizeof (UploadRespBody)},
    {PackageType::UPLOAD_FETCH, sizeof (UploadFetchBody)},
    {PackageType::UPLOAD_PUSH, sizeof (UploadPushBody)},
    {PackageType::UPLOAD_DONE, sizeof (UploadDoneBody)},
    {PackageType::DOWNLOAD_REQ, sizeof (DownloadReqBody)},
    {PackageType::DOWNLOAD_RESP, sizeof (DownloadRespBody)},
    {PackageType::DOWNLOAD_PUSH, sizeof (DownloadPushBody)},
    {PackageType::DOWNLOAD_FETCH, sizeof (DownloadFetchBody)},
    {PackageType::DOWNLOAD_DONE, sizeof (DownloadDoneBody)},
    {PackageType::SYN_REQ, sizeof (SYNReqBody)},
    {PackageType::SYN_RESP, sizeof (SYNRespBody)},
    {PackageType::SYN_PUSH, sizeof (SYNPushBody)},

    {PackageType::COPY, sizeof (CopyBody)},
    {PackageType::COPY_RES,sizeof (CopyRespBody)},
    {PackageType::MOVE, sizeof (MoveBody)},
    {PackageType::MOVE_RES,sizeof (MoveRespBody)},
    {PackageType::DELETE, sizeof (DeleteBody)},
    {PackageType::DELETE_RES, sizeof (DeleteRespBody)},

    {PackageType::MKDIR, sizeof(MkdirRespBody)},
    {PackageType::MKDIR_RES, sizeof(MkdirRespBody)},  

    {PackageType::FILEINFO, 0}                      //�����㣬��������������Ҫ��ֵsizeof(FileInfoBody+size)
};

// ͳһ��ͷ�� ÿ��ָ���ǰ��Ҫ�е�
struct UniformHeader
{
    PackageType p;
    uint16_t len;
    UniformHeader();
    UniformHeader(const PackageType &pIn);
};
