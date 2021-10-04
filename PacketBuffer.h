#pragma once
class PacketBuffer
{

public:
	PacketBuffer() = default;
	virtual	~PacketBuffer();

public:
	enum PACKET_BUFFER_INDEX
	{
		BUFFER_SIZE_DEFAULT = 1400		// ��Ŷ�� �⺻ ���� ������.
	};

public:
	void Initialize(const unsigned int bufferSize = BUFFER_SIZE_DEFAULT);
	void Release(void);
	void Clear(void);

public:
	// ���� ������ ���
	int	GetBufferSize(void) const { return mBufferSize; }
	// ���� ������� ������ ���. 
	int	GetDataSize(void) const { return mWritePos; }

public:
	// ���� ������ ���
	char* GetBufferPtr(void) const { return mStreamBuffer; }

public:
	bool MoveWritePos(const int size);
	bool MoveReadPos(const int size);


public:
	/* ============================================================================= */
	// ������ �����ε�
	/* ============================================================================= */
	PacketBuffer& operator = (const PacketBuffer& srcPacket);

	//////////////////////////////////////////////////////////////////////////
	// �ֱ�.	�� ���� Ÿ�Ը��� ��� ����.
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
	// ����.	�� ���� Ÿ�Ը��� ��� ����.
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
	// ������ ��� �Լ�
	int	GetData(char* dest, int dataSize);
	// ������ ���� �Լ�
	int	PutData(const char* src, int dataSize);


protected:
	// ���� ���� ������ 
	int mBufferSize = 0;
	//���� ���ۿ� ������� ������
	int mUseSize = 0;
	char* mStreamBuffer = nullptr;

private:
	int mWritePos = 0;
	int mReadPos = 0;
};

