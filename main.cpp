
#include "pch.h"
#include <iostream>
#include "PacketBuffer.h"
using namespace std;

int main(void)
{
	PacketBuffer packetBuffer;
	packetBuffer.Initialize(3000);
	char text[100] = { "abcdefghhijklmnopq" };
	char text2[100];

	char charVar = CHAR_MIN;
	unsigned char unsignedCharVar = UCHAR_MAX;
	short shortVar = SHRT_MAX;
	unsigned short unsignedShortVar = USHRT_MAX;
	int intVar = INT_MIN;
	unsigned int unsignedintVar = UINT_MAX;
	__int64 int64Var = INT64_MIN;
	unsigned __int64 unsignedInt64Var = UINT64_MAX;
	float floatVar = 3.4f;
	double doubleVar = 3.44444444;

	char charVar_ = 0;
	unsigned char unsignedCharVar_ = 0;
	short shortVar_ = 0;
	unsigned short unsignedShortVar_ = 0;
	int intVar_ = 0;
	unsigned int unsignedintVar_ = 0;
	__int64 int64Var_ = 0;
	unsigned __int64 unsignedInt64Var_ = 0;
	float floatVar_ = 0;
	double doubleVar_ = 0;

	packetBuffer << charVar;
	packetBuffer << unsignedCharVar;
	packetBuffer << shortVar;
	packetBuffer << unsignedShortVar;
	packetBuffer << intVar;
	packetBuffer << unsignedintVar;
	packetBuffer << int64Var;
	packetBuffer << unsignedInt64Var;
	packetBuffer << floatVar;
	packetBuffer << doubleVar;

	packetBuffer >> charVar_;
	packetBuffer >> unsignedCharVar_;
	packetBuffer >> shortVar_;
	packetBuffer >> unsignedShortVar_;
	packetBuffer >> intVar_;
	packetBuffer >> unsignedintVar_;
	packetBuffer >> int64Var_;
	packetBuffer >> unsignedInt64Var_;
	packetBuffer >> floatVar_;
	packetBuffer >> doubleVar_;

	packetBuffer.PutData(text, strlen(text) + 1);
	packetBuffer.GetData(text2, strlen(text) + 1);
	return 0;
}