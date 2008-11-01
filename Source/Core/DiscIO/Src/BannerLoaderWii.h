// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef _BANNER_LOADER_WII_H_
#define _BANNER_LOADER_WII_H_

#include "BannerLoader.h"

namespace DiscIO
{
class CBannerLoaderWii
	: public IBannerLoader
{
	public:

		CBannerLoaderWii(DiscIO::IFileSystem& _rFileSystem);

		virtual ~CBannerLoaderWii();

		virtual bool IsValid();

		virtual bool GetBanner(u32* _pBannerImage);

		virtual bool GetName(std::string& _rName, int language);

		virtual bool GetCompany(std::string& _rCompany);

		virtual bool GetDescription(std::string& _rDescription);


	private:
		
		#define WII_BANNER_TEXTURE_SIZE (192 * 64 * 2)
		#define WII_BANNER_ICON_SIZE    ( 48 * 48 * 2)
		#define WII_BANNER_COMMENT_SIZE 32

		struct SWiiBanner
		{
			u32 ID;

			u32 m_Flag;
			u16 m_Speed;
			u8  m_Unknown[22];

			u16 m_Comment[2][WII_BANNER_COMMENT_SIZE]; 
			u8  m_BannerTexture[WII_BANNER_TEXTURE_SIZE]; 
			u8  m_IconTexture[8][WII_BANNER_ICON_SIZE]; 
		} ;

		// for banner decoding
		int lut3to8[8];
		int lut4to8[16];
		int lut5to8[32];

		std::string m_Name;

		u8* m_pBannerFile;

		bool m_IsValid;

		void InitLUTTable();
		u32 decode5A3(u16 val);
		void decode5A3image(u32* dst, u16* src, int width, int height);

		std::string StupidWideCharToString(u16* _pSrc, size_t _max);
};
} // namespace

#endif

