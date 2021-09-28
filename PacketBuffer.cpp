#include "pch.h"
#include "PacketBuffer.h"


PacketBuffer::~PacketBuffer()
{
	Release();
}

void PacketBuffer::Initialize(const unsigned int bufferSize)
{
	mStreamBuffer = new char[bufferSize];
	_ASSERT(mStreamBuffer != nullptr);

	mBufferSize = bufferSize;
}

void PacketBuffer::Release(void)
{
	if (mStreamBuffer)
	{
		delete mStreamBuffer;
		mStreamBuffer = nullptr;
	}
}

void PacketBuffer::Clear(void)
{
	mWritePos = 0;
	mReadPos = 0;
}

bool PacketBuffer::MoveWritePos(const int size)
{
	if (mWritePos >= mBufferSize)
	{
		return false;
	}
	mWritePos += size;

	return true;
}

bool PacketBuffer::MoveReadPos(const int size)
{
	if (mReadPos >= mBufferSize)
	{
		return false;
	}

	mReadPos += size;
	return true;
}

int PacketBuffer::GetData(char* dest, int dataSize)
{
	int count = 0;

	while (dataSize != 0)
	{
		// µ¥ÀÌÅÍ ²Ë Âü
		if (mReadPos >= mBufferSize)
		{
			_ASSERT(mWritePos < mBufferSize);
			return count;
		}
		*(dest + count) = mStreamBuffer[mReadPos];

		++mReadPos;
		++count;
		--dataSize;
	}

	return count;
}

int PacketBuffer::PutData(const char* src, int dataSize)
{
	int count = 0;

	while (dataSize != 0)
	{
		// µ¥ÀÌÅÍ ²Ë Âü
		if (mWritePos >= mBufferSize)
		{
			_ASSERT(mWritePos < mBufferSize);
			return count;
		}
		mStreamBuffer[mWritePos] = *(src + count);

		++mWritePos;
		++count;
		--dataSize;
	}

	return count;
}

PacketBuffer& PacketBuffer::operator=(const PacketBuffer& srcPacket)
{
	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const unsigned char value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	mStreamBuffer[mWritePos] = value;
	mWritePos += sizeof(unsigned char);

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const char value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	mStreamBuffer[mWritePos] = value;
	mWritePos += sizeof(char);

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const short value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(short); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const unsigned short value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(unsigned short); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const int value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(int); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const unsigned int value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(long); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const __int64 value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(__int64); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const unsigned __int64 value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(unsigned __int64); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const float value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(float); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator<<(const double value)
{
	if (mWritePos >= mBufferSize)
	{
		_ASSERT(mWritePos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(double); ++i)
	{
		mStreamBuffer[mWritePos] = *((char*)&value + i);
		++mWritePos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(unsigned char& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	value = mStreamBuffer[mReadPos];
	mReadPos += sizeof(unsigned char);

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(char& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	value = mStreamBuffer[mReadPos];
	mReadPos += sizeof(char);

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(short& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(short); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(unsigned short& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(unsigned short); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(int& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(int); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(unsigned int& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(unsigned int); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(__int64& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(__int64); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(unsigned __int64& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(unsigned __int64); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(float& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(float); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}

PacketBuffer& PacketBuffer::operator>>(double& value)
{
	if (mReadPos >= mBufferSize)
	{
		_ASSERT(mReadPos < mBufferSize);
		return *this;
	}

	for (int i = 0; i < sizeof(double); ++i)
	{
		*((char*)&value + i) = mStreamBuffer[mReadPos];
		++mReadPos;
	}

	return *this;
}
