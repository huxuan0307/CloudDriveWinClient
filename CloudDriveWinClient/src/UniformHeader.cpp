#include <Package/UniformHeader.h>

UniformHeader::UniformHeader()
{
    len = 0;
}

UniformHeader::UniformHeader(const PackageType &pIn) : p(pIn)
{
    // �����Ĵ�С
    len = pMap.at(p);
}
