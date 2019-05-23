#ifndef __LIME_NETFMT_H__
#define __LIME_NETFMT_H__

#include "player.hpp"

class NetfmtDecoder : public Decoder {
	public:
		NetfmtDecoder(const char* url);
		
		~NetfmtDecoder(void);
		
		bool IsInit(void) override;
		
		void Info(musinfo_t* Meta) override;
		
		uint32_t Position(void) override;
		
		uint32_t Length(void) override;
		
		void Seek(uint32_t location) override;
		
		uint32_t Decode(void* buffer) override;
		
		uint32_t Samplerate(void) override;

		uint32_t Spf(void* buffer) override;
		
		uint32_t Buffsize(void) override;
		
		int Channels(void) override;
	private:
		httpcContext httpc;

		uint8_t *dbuf;

		uint32_t readsize;
};

#endif
