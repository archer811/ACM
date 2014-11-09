#include<cstdio> 
#include<rpc.h> 
#include<rpcdce.h> 
#include<iostream>
#include<windows.h>
#pragma comment(lib, "rpcrt4.lib")
using namespace std;
class GetMACid
{
public:
    GetMACid();
    virtual ~GetMACid();
    char* GetMACaddress(void);
private:
    unsigned char MACData[6];
    char Mac[6];

};

GetMACid::GetMACid()
{

}
GetMACid::~GetMACid()
{

}
char* GetMACid::GetMACaddress(void)
{

//unsigned char MACData[6];
    UUID uuid;
    UuidCreate( &uuid ); // Ask OS to create UUID

    for (int i=2; i<8; i++)
    {
        MACData[i - 2] = uuid.Data4[i];// Bytes 2 through 7 inclusive are MAC address
    }

    sprintf(Mac,"%02X%02X%02X%02X%02X%02X",MACData[0], MACData[1], MACData[2], MACData[3], MACData[4], MACData[5]);
    return Mac;
}
int main(int argc,char** argv)
{

GetMACid * mac = new GetMACid;
char *macNumber = mac->GetMACaddress();//获取mac
std::cout<<macNumber<<std::endl;



return 0;
}

