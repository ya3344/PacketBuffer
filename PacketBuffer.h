#pragma once
class PacketBuffer
{

public:
	PacketBuffer() = default;
	virtual	~PacketBuffer();

public:
	enum PACKET_BUFFER_INDEX
	{
		BUFFER_SIZE_DEFAULT = 1400		// 패킷의 기본 버퍼 사이즈.
	};

public:
	void Initialize(const unsigned int bufferSize = BUFFER_SIZE_DEFAULT);
	void Release(void);
	void Clear(void);

public:
	// 버퍼 사이즈 얻기
	int	GetBufferSize(void) const { return mBufferSize; }
	// 현재 사용중인 사이즈 얻기. 
	int	GetDataSize(void) const { return mWritePos; }

public:
	// 버퍼 포인터 얻기
	char* GetBufferPtr(void) const { return mStreamBuffer; }

public:
	bool MoveWritePos(const int size);
	bool MoveReadPos(const int size);


public:
	/* ============================================================================= */
	// 연산자 오버로딩
	/* ============================================================================= */
	PacketBuffer& operator = (const PacketBuffer& srcPacket);

	//////////////////////////////////////////////////////////////////////////
	// 넣기.	각 변수 타입마다 모두 만듬.
	//////////////////////////////////////////////////////////////////////////
	PacketBuffer& operator << (const unsigned char value);
	PacketBuffer& operator << (const char value);

	PacketBuffer& operator << (const short value);
	PacketBuffer& operator << (const unsigned short value);

	PacketBuffer& operator << (const int value);
	PacketBuffer& operator << (const unsigned int value);

	PacketBuffer& operator << (const long value);
	PacketBuffer& operator << (const unsigned long value);

	PacketBuffer& operator << (const __int64 value);
	PacketBuffer& operator << (const unsigned __int64 value);

	PacketBuffer& operator << (const float value);
	PacketBuffer& operator << (const double value);

	//////////////////////////////////////////////////////////////////////////
	// 빼기.	각 변수 타입마다 모두 만듬.
	//////////////////////////////////////////////////////////////////////////
	PacketBuffer& operator >> (unsigned char& value);
	PacketBuffer& operator >> (char& value);

	PacketBuffer& operator >> (short& value);
	PacketBuffer& operator >> (unsigned short& value);

	PacketBuffer& operator >> (int& value);
	PacketBuffer& operator >> (unsigned int& value);

	PacketBuffer& operator >> (long& value);
	PacketBuffer& operator >> (unsigned long& value);

	PacketBuffer& operator >> (__int64& value);
	PacketBuffer& operator >> (unsigned __int64& value);

	PacketBuffer& operator >> (float& value);
	PacketBuffer& operator >> (double& value);


public:
	// 데이터 출력 함수
	int	GetData(char* dest, int dataSize);
	// 데이터 삽입 함수
	int	PutData(const char* src, int dataSize);


protected:
	// 현재 버퍼 사이즈 
	int mBufferSize = 0;
	//현재 버퍼에 사용중인 사이즈
	int mUseSize = 0;
	char* mStreamBuffer = nullptr;

private:
	int mWritePos = 0;
	int mReadPos = 0;
};

