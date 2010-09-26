///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Image Copyright (c) 2008 - 2010 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-09-26
// Updated : 2010-09-26
// Licence : This source is under MIT License
// File    : gli/gtx/loader_dds10.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace gli{
namespace gtx{
namespace loader{
namespace detail
{
	// DDS Documentation
	/*
		http://msdn.microsoft.com/en-us/library/bb943991(VS.85).aspx#File_Layout1
		http://msdn.microsoft.com/en-us/library/bb943992.aspx
	*/

	#define GLI_MAKEFOURCC(ch0, ch1, ch2, ch3) \
	  (glm::uint32)( \
		(((glm::uint32)(glm::uint8)(ch3) << 24) & 0xFF000000) | \
		(((glm::uint32)(glm::uint8)(ch2) << 16) & 0x00FF0000) | \
		(((glm::uint32)(glm::uint8)(ch1) <<  8) & 0x0000FF00) | \
		 ((glm::uint32)(glm::uint8)(ch0)        & 0x000000FF) )

	enum DXGI_FORMAT 
	{
		DXGI_FORMAT_UNKNOWN                      = 0,
		DXGI_FORMAT_R32G32B32A32_TYPELESS        = 1,
		DXGI_FORMAT_R32G32B32A32_FLOAT           = 2,
		DXGI_FORMAT_R32G32B32A32_UINT            = 3,
		DXGI_FORMAT_R32G32B32A32_SINT            = 4,
		DXGI_FORMAT_R32G32B32_TYPELESS           = 5,
		DXGI_FORMAT_R32G32B32_FLOAT              = 6,
		DXGI_FORMAT_R32G32B32_UINT               = 7,
		DXGI_FORMAT_R32G32B32_SINT               = 8,
		DXGI_FORMAT_R16G16B16A16_TYPELESS        = 9,
		DXGI_FORMAT_R16G16B16A16_FLOAT           = 10,
		DXGI_FORMAT_R16G16B16A16_UNORM           = 11,
		DXGI_FORMAT_R16G16B16A16_UINT            = 12,
		DXGI_FORMAT_R16G16B16A16_SNORM           = 13,
		DXGI_FORMAT_R16G16B16A16_SINT            = 14,
		DXGI_FORMAT_R32G32_TYPELESS              = 15,
		DXGI_FORMAT_R32G32_FLOAT                 = 16,
		DXGI_FORMAT_R32G32_UINT                  = 17,
		DXGI_FORMAT_R32G32_SINT                  = 18,
		DXGI_FORMAT_R32G8X24_TYPELESS            = 19,
		DXGI_FORMAT_D32_FLOAT_S8X24_UINT         = 20,
		DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS     = 21,
		DXGI_FORMAT_X32_TYPELESS_G8X24_UINT      = 22,
		DXGI_FORMAT_R10G10B10A2_TYPELESS         = 23,
		DXGI_FORMAT_R10G10B10A2_UNORM            = 24,
		DXGI_FORMAT_R10G10B10A2_UINT             = 25,
		DXGI_FORMAT_R11G11B10_FLOAT              = 26,
		DXGI_FORMAT_R8G8B8A8_TYPELESS            = 27,
		DXGI_FORMAT_R8G8B8A8_UNORM               = 28,
		DXGI_FORMAT_R8G8B8A8_UNORM_SRGB          = 29,
		DXGI_FORMAT_R8G8B8A8_UINT                = 30,
		DXGI_FORMAT_R8G8B8A8_SNORM               = 31,
		DXGI_FORMAT_R8G8B8A8_SINT                = 32,
		DXGI_FORMAT_R16G16_TYPELESS              = 33,
		DXGI_FORMAT_R16G16_FLOAT                 = 34,
		DXGI_FORMAT_R16G16_UNORM                 = 35,
		DXGI_FORMAT_R16G16_UINT                  = 36,
		DXGI_FORMAT_R16G16_SNORM                 = 37,
		DXGI_FORMAT_R16G16_SINT                  = 38,
		DXGI_FORMAT_R32_TYPELESS                 = 39,
		DXGI_FORMAT_D32_FLOAT                    = 40,
		DXGI_FORMAT_R32_FLOAT                    = 41,
		DXGI_FORMAT_R32_UINT                     = 42,
		DXGI_FORMAT_R32_SINT                     = 43,
		DXGI_FORMAT_R24G8_TYPELESS               = 44,
		DXGI_FORMAT_D24_UNORM_S8_UINT            = 45,
		DXGI_FORMAT_R24_UNORM_X8_TYPELESS        = 46,
		DXGI_FORMAT_X24_TYPELESS_G8_UINT         = 47,
		DXGI_FORMAT_R8G8_TYPELESS                = 48,
		DXGI_FORMAT_R8G8_UNORM                   = 49,
		DXGI_FORMAT_R8G8_UINT                    = 50,
		DXGI_FORMAT_R8G8_SNORM                   = 51,
		DXGI_FORMAT_R8G8_SINT                    = 52,
		DXGI_FORMAT_R16_TYPELESS                 = 53,
		DXGI_FORMAT_R16_FLOAT                    = 54,
		DXGI_FORMAT_D16_UNORM                    = 55,
		DXGI_FORMAT_R16_UNORM                    = 56,
		DXGI_FORMAT_R16_UINT                     = 57,
		DXGI_FORMAT_R16_SNORM                    = 58,
		DXGI_FORMAT_R16_SINT                     = 59,
		DXGI_FORMAT_R8_TYPELESS                  = 60,
		DXGI_FORMAT_R8_UNORM                     = 61,
		DXGI_FORMAT_R8_UINT                      = 62,
		DXGI_FORMAT_R8_SNORM                     = 63,
		DXGI_FORMAT_R8_SINT                      = 64,
		DXGI_FORMAT_A8_UNORM                     = 65,
		DXGI_FORMAT_R1_UNORM                     = 66,
		DXGI_FORMAT_R9G9B9E5_SHAREDEXP           = 67,
		DXGI_FORMAT_R8G8_B8G8_UNORM              = 68,
		DXGI_FORMAT_G8R8_G8B8_UNORM              = 69,
		DXGI_FORMAT_BC1_TYPELESS                 = 70,
		DXGI_FORMAT_BC1_UNORM                    = 71,
		DXGI_FORMAT_BC1_UNORM_SRGB               = 72,
		DXGI_FORMAT_BC2_TYPELESS                 = 73,
		DXGI_FORMAT_BC2_UNORM                    = 74,
		DXGI_FORMAT_BC2_UNORM_SRGB               = 75,
		DXGI_FORMAT_BC3_TYPELESS                 = 76,
		DXGI_FORMAT_BC3_UNORM                    = 77,
		DXGI_FORMAT_BC3_UNORM_SRGB               = 78,
		DXGI_FORMAT_BC4_TYPELESS                 = 79,
		DXGI_FORMAT_BC4_UNORM                    = 80,
		DXGI_FORMAT_BC4_SNORM                    = 81,
		DXGI_FORMAT_BC5_TYPELESS                 = 82,
		DXGI_FORMAT_BC5_UNORM                    = 83,
		DXGI_FORMAT_BC5_SNORM                    = 84,
		DXGI_FORMAT_B5G6R5_UNORM                 = 85,
		DXGI_FORMAT_B5G5R5A1_UNORM               = 86,
		DXGI_FORMAT_B8G8R8A8_UNORM               = 87,
		DXGI_FORMAT_B8G8R8X8_UNORM               = 88,
		DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM   = 89,
		DXGI_FORMAT_B8G8R8A8_TYPELESS            = 90,
		DXGI_FORMAT_B8G8R8A8_UNORM_SRGB          = 91,
		DXGI_FORMAT_B8G8R8X8_TYPELESS            = 92,
		DXGI_FORMAT_B8G8R8X8_UNORM_SRGB          = 93,
		DXGI_FORMAT_BC6H_TYPELESS                = 94,
		DXGI_FORMAT_BC6H_UF16                    = 95,
		DXGI_FORMAT_BC6H_SF16                    = 96,
		DXGI_FORMAT_BC7_TYPELESS                 = 97,
		DXGI_FORMAT_BC7_UNORM                    = 98,
		DXGI_FORMAT_BC7_UNORM_SRGB               = 99,
		DXGI_FORMAT_FORCE_UINT                   = 0xffffffffUL 
	};

	enum D3D10_RESOURCE_DIMENSION 
	{
		D3D10_RESOURCE_DIMENSION_UNKNOWN     = 0,
		D3D10_RESOURCE_DIMENSION_BUFFER      = 1,
		D3D10_RESOURCE_DIMENSION_TEXTURE1D   = 2,
		D3D10_RESOURCE_DIMENSION_TEXTURE2D   = 3,
		D3D10_RESOURCE_DIMENSION_TEXTURE3D   = 4 
	};

	enum D3D10_RESOURCE_MISC_FLAG 
	{
		D3D10_RESOURCE_MISC_GENERATE_MIPS       = 0x1L,
		D3D10_RESOURCE_MISC_SHARED              = 0x2L,
		D3D10_RESOURCE_MISC_TEXTURECUBE         = 0x4L,
		D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX   = 0x10L,
		D3D10_RESOURCE_MISC_GDI_COMPATIBLE      = 0x20L 
	};

	enum dds_format
	{
		GLI_D3DFMT_R8G8B8               = 20,
		GLI_D3DFMT_A8R8G8B8             = 21,
		GLI_D3DFMT_X8R8G8B8             = 22,
		GLI_D3DFMT_A8                   = 28,
		GLI_D3DFMT_A2B10G10R10          = 31,
		GLI_D3DFMT_A8B8G8R8             = 32,
		GLI_D3DFMT_X8B8G8R8             = 33,
		GLI_D3DFMT_G16R16               = 34,
		GLI_D3DFMT_A2R10G10B10          = 35,
		GLI_D3DFMT_A16B16G16R16         = 36,

		GLI_D3DFMT_L8                   = 50,
		GLI_D3DFMT_A8L8                 = 51,

		GLI_D3DFMT_DXT1                 = GLI_MAKEFOURCC('D', 'X', 'T', '1'),
		GLI_D3DFMT_DXT2                 = GLI_MAKEFOURCC('D', 'X', 'T', '2'),
		GLI_D3DFMT_DXT3                 = GLI_MAKEFOURCC('D', 'X', 'T', '3'),
		GLI_D3DFMT_DXT4                 = GLI_MAKEFOURCC('D', 'X', 'T', '4'),
		GLI_D3DFMT_DXT5                 = GLI_MAKEFOURCC('D', 'X', 'T', '5'),
		GLI_D3DFMT_DX10                 = GLI_MAKEFOURCC('D', 'X', '1', '0'),

		GLI_D3DFMT_D32                  = 71,
		GLI_D3DFMT_D24S8                = 75,
		GLI_D3DFMT_D24X8                = 77,
		GLI_D3DFMT_D16                  = 80,
		GLI_D3DFMT_L16                  = 81,
		GLI_D3DFMT_D32F_LOCKABLE        = 82,
		GLI_D3DFMT_D24FS8               = 83,

		GLI_D3DFMT_R16F                 = 111,
		GLI_D3DFMT_G16R16F              = 112,
		GLI_D3DFMT_A16B16G16R16F        = 113,

		GLI_D3DFMT_R32F                 = 114,
		GLI_D3DFMT_G32R32F              = 115,
		GLI_D3DFMT_A32B32G32R32F        = 116
	};

	enum ddsCubemapflag
	{
		DDSCAPS2_CUBEMAP				= 0x00000200,
		DDSCAPS2_CUBEMAP_POSITIVEX		= 0x00000400,
		DDSCAPS2_CUBEMAP_NEGATIVEX		= 0x00000800,
		DDSCAPS2_CUBEMAP_POSITIVEY		= 0x00001000,
		DDSCAPS2_CUBEMAP_NEGATIVEY		= 0x00002000,
		DDSCAPS2_CUBEMAP_POSITIVEZ		= 0x00004000,
		DDSCAPS2_CUBEMAP_NEGATIVEZ		= 0x00008000,
		DDSCAPS2_VOLUME					= 0x00200000
	};

	enum ddsSurfaceflag
	{
		GLI_DDSCAPS_COMPLEX				= 0x00000008,
		GLI_DDSCAPS_MIPMAP				= 0x00400000,
		GLI_DDSCAPS_TEXTURE				= 0x00001000
	};

	struct ddsPixelFormat
	{
		glm::uint32 size; // 32
		glm::uint32 flags;
		glm::uint32 fourCC;
		glm::uint32 bpp;
		glm::uint32 redMask;
		glm::uint32 greenMask;
		glm::uint32 blueMask;
		glm::uint32 alphaMask;
	};

	struct ddsHeader
	{
		glm::uint32 size;
		glm::uint32 flags;
		glm::uint32 height;
		glm::uint32 width;
		glm::uint32 pitch;
		glm::uint32 depth;
		glm::uint32 mipMapLevels;
		glm::uint32 reserved1[11];
		ddsPixelFormat format;
		glm::uint32 surfaceFlags;
		glm::uint32 cubemapFlags;
		glm::uint32 reserved2[3];
	};

	struct ddsHeader10
	{
		DXGI_FORMAT					dxgiFormat;
		D3D10_RESOURCE_DIMENSION	resourceDimension;
		glm::uint32					miscFlag; // DDS_RESOURCE_MISC_TEXTURECUBE
		glm::uint32					arraySize;
		glm::uint32					reserved;
	};

	glm::uint32 const GLI_FOURCC_DXT1 = GLI_MAKEFOURCC('D', 'X', 'T', '1');
	glm::uint32 const GLI_FOURCC_DXT2 = GLI_MAKEFOURCC('D', 'X', 'T', '2');
	glm::uint32 const GLI_FOURCC_DXT3 = GLI_MAKEFOURCC('D', 'X', 'T', '3');
	glm::uint32 const GLI_FOURCC_DXT4 = GLI_MAKEFOURCC('D', 'X', 'T', '4');
	glm::uint32 const GLI_FOURCC_DXT5 = GLI_MAKEFOURCC('D', 'X', 'T', '5');
	glm::uint32 const GLI_FOURCC_ATI1 = GLI_MAKEFOURCC('A', 'T', 'I', '1');			// ATI1
	glm::uint32 const GLI_FOURCC_ATI2 = GLI_MAKEFOURCC('A', 'T', 'I', '2');			// ATI2 (AKA 3Dc)
	glm::uint32 const GLI_FOURCC_DX10 = GLI_MAKEFOURCC('D', 'X', '1', '0');
	glm::uint32 const GLI_FOURCC_BC4U = GLI_MAKEFOURCC('B', 'C', '4', 'U');
	glm::uint32 const GLI_FOURCC_BC4S = GLI_MAKEFOURCC('B', 'C', '4', 'S');
	glm::uint32 const GLI_FOURCC_BC5U = GLI_MAKEFOURCC('B', 'C', '5', 'U');
	glm::uint32 const GLI_FOURCC_BC5S = GLI_MAKEFOURCC('B', 'C', '5', 'S');
	glm::uint32 const GLI_FOURCC_BC6H = GLI_MAKEFOURCC('B', 'C', '6', 'H');
	glm::uint32 const GLI_FOURCC_BC7  = GLI_MAKEFOURCC('B', 'C', '7', 'U');

	glm::uint32 const GLI_FOURCC_R16F                          = 0x0000006f;         // 16-bit float Red
	glm::uint32 const GLI_FOURCC_G16R16F                       = 0x00000070;         // 16-bit float Red/Green
	glm::uint32 const GLI_FOURCC_A16B16G16R16F                 = 0x00000071;         // 16-bit float RGBA
	glm::uint32 const GLI_FOURCC_R32F                          = 0x00000072;         // 32-bit float Red
	glm::uint32 const GLI_FOURCC_G32R32F                       = 0x00000073;         // 32-bit float Red/Green
	glm::uint32 const GLI_FOURCC_A32B32G32R32F                 = 0x00000074;         // 32-bit float RGBA

	glm::uint32 const GLI_DDPF_ALPHAPIXELS							= 0x00000001; // The surface has alpha channel information in the pixel format.
	glm::uint32 const GLI_DDPF_ALPHA								= 0x00000002; // The pixel format contains alpha only information
	glm::uint32 const GLI_DDPF_FOURCC                               = 0x00000004; // The FourCC code is valid.
	glm::uint32 const GLI_DDPF_RGB									= 0x00000040; // The RGB data in the pixel format structure is valid.
	//glm::uint32 const GLI_DDPF_COMPRESSED							= 0x00000080; // The surface will accept pixel data in the format specified and compress it during the write.
	//glm::uint32 const GLI_DDPF_RGBTOYUV								= 0x00000100; // The surface will accept RGB data and translate it during the write to YUV data.
	glm::uint32 const GLI_DDPF_YUV                                  = 0x00000200; // Pixel format is YUV - YUV data in pixel format struct is valid.
	//glm::uint32 const GLI_DDPF_ZBUFFER                              = 0x00000400; // Pixel format is a z buffer only surface
	//glm::uint32 const GLI_DDPF_ZPIXELS                              = 0x00002000; // The surface contains Z information in the pixels
	//glm::uint32 const GLI_DDPF_STENCILBUFFER                        = 0x00004000; // The surface contains stencil information along with Z
	//glm::uint32 const GLI_DDPF_ALPHAPREMULT                         = 0x00008000; // Premultiplied alpha format -- the color components have been premultiplied by the alpha component.
	glm::uint32 const GLI_DDPF_LUMINANCE                            = 0x00020000; // Luminance data in the pixel format is valid.
	//glm::uint32 const GLI_DDPF_BUMPLUMINANCE                        = 0x00040000; // Use this flag for luminance-only or luminance+alpha surfaces, the bit depth is then ddpf.dwLuminanceBitCount.
	//glm::uint32 const GLI_DDPF_BUMPDUDV                             = 0x00080000; // Bump map dUdV data in the pixel format is valid.

	glm::uint32 const GLI_DDSD_CAPS				= 0x00000001;
	glm::uint32 const GLI_DDSD_HEIGHT			= 0x00000002;
	glm::uint32 const GLI_DDSD_WIDTH			= 0x00000004;
	glm::uint32 const GLI_DDSD_PITCH			= 0x00000008;
	glm::uint32 const GLI_DDSD_PIXELFORMAT		= 0x00001000;
	glm::uint32 const GLI_DDSD_MIPMAPCOUNT		= 0x00020000;
	glm::uint32 const GLI_DDSD_LINEARSIZE		= 0x00080000;
	glm::uint32 const GLI_DDSD_DEPTH			= 0x00800000;

	struct DDLoader
	{
		glm::uint32 DivSize;
		glm::uint32 BlockSize;
		gli::format Format;
	};

	enum format_type
	{
		FORMAT_TYPE_NULL,
		FORMAT_RGBA,
		FORMAT_FOURCC
	};

	inline glm::uint32 getFormatBlockSize(gli::image const & Image)
	{
		switch(Image.format())
		{
		default:
			return 0;
		case DXT1:
			return 8;
		case DXT3:
			return 16;
		case DXT5:
			return 16;
		case ATI1N:
			return 16;
		case ATI2N:
			return 32;
		case BP_FLOAT:
			return 32;
		case BP:
			return 32;
		case R16F:
			return 2;
		case RG16F:
			return 4;
		case RGBA16F:
			return 8;
		case R32F:
			return 4;
		case RG32F:
			return 8;
		case RGBA32F:
			return 16;
		}
	}

	inline glm::uint32 getFormatFlags(gli::image const & Image)
	{
		glm::uint32 Result = 0;

		switch(Image.format())
		{
		default: 
			break;
		case R8U:
		case RG8U:
		case RGB8U:
		case RGBA8U:
		case R16U:
		case RG16U:
		case RGB16U:
		case RGBA16U:
		case R32U:
		case RG32U:
		case RGB32U:
		case RGBA32U:
		case R8I:
		case RG8I:
		case RGB8I:
		case RGBA8I:
		case R16I:
		case RG16I:
		case RGB16I:
		case RGBA16I:
		case R32I:
		case RG32I:
		case RGB32I:
		case RGBA32I:
			Result |= GLI_DDPF_RGB;
			break;
		case R16F:
		case RG16F:
		case RGB16F:
		case RGBA16F:
		case R32F:
		case RG32F:
		case RGB32F:
		case RGBA32F:
		case RGBE8:
		case RGB9E5:
		case RG11B10F:
		case RGB565:
		case RGBA4:
		case RGB10A2:
		case D16:
		case D24X8:
		case D24S8:
		case D32F:
		case D32FS8X24:
		case DXT1:
		case DXT3:
		case DXT5:
		case ATI1N:
		case ATI2N:
		case BP_FLOAT:
		case BP:
			Result |= GLI_DDPF_FOURCC;
			break;
		};

		return Result;
	}

	inline glm::uint32 getFormatBPP(gli::image const & Image)
	{
		switch(Image.format())
		{
		default:
			return 0;
		case R8U:
		case R8I:
			return 8;
		case RG8U:
		case RG8I:
			return 16;
		case RGB8U:
		case RGB8I:
			return 24;
		case RGBA8U:
		case RGBA8I:
			return 32;
		case DXT1:
			return 4;
		case DXT3:
			return 8;
		case DXT5:
			return 8;
		case ATI1N:
			return 8;
		case ATI2N:
			return 16;
		case BP_FLOAT:
			return 16;
		case BP:
			return 16;
		}
	}

	inline bool isCompressed(gli::image const & Image)
	{
		switch(Image.format())
		{
		default:
			return false;
		case DXT1:
		case DXT3:
		case DXT5:
		case ATI1N:
		case ATI2N:
		case BP_FLOAT:
		case BP:
			return true;
		}
		return false;
	}

	inline format dds2gli_cast(DXGI_FORMAT const & Format)
	{
		format Cast[] = 
		{
			FORMAT_NULL,	//DXGI_FORMAT_UNKNOWN                      = 0,
			RGBA32U,		//DXGI_FORMAT_R32G32B32A32_TYPELESS        = 1,
			RGBA32F,		//DXGI_FORMAT_R32G32B32A32_FLOAT           = 2,
			RGBA32U,		//DXGI_FORMAT_R32G32B32A32_UINT            = 3,
			RGBA32I,		//DXGI_FORMAT_R32G32B32A32_SINT            = 4,
			RGB32U,			//DXGI_FORMAT_R32G32B32_TYPELESS           = 5,
			RGB32F,			//DXGI_FORMAT_R32G32B32_FLOAT              = 6,
			RGB32U,			//DXGI_FORMAT_R32G32B32_UINT               = 7,
			RGB32I,			//DXGI_FORMAT_R32G32B32_SINT               = 8,
			RGBA16U,		//DXGI_FORMAT_R16G16B16A16_TYPELESS        = 9,
			RGBA16F,		//DXGI_FORMAT_R16G16B16A16_FLOAT           = 10,
			RGBA16U,		//DXGI_FORMAT_R16G16B16A16_UNORM           = 11,
			RGBA16I,		//DXGI_FORMAT_R16G16B16A16_UINT            = 12,
			RGBA16I,		//DXGI_FORMAT_R16G16B16A16_SNORM           = 13,
			RGBA16I,		//DXGI_FORMAT_R16G16B16A16_SINT            = 14,
			RG32U,			//DXGI_FORMAT_R32G32_TYPELESS              = 15,
			RG32F,			//DXGI_FORMAT_R32G32_FLOAT                 = 16,
			RG32U,			//DXGI_FORMAT_R32G32_UINT                  = 17,
			RG32I,			//DXGI_FORMAT_R32G32_SINT                  = 18,
			FORMAT_NULL,	//DXGI_FORMAT_R32G8X24_TYPELESS            = 19,
			D32FS8X24,		//DXGI_FORMAT_D32_FLOAT_S8X24_UINT         = 20,
			FORMAT_NULL,	//DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS     = 21,
			FORMAT_NULL,	//DXGI_FORMAT_X32_TYPELESS_G8X24_UINT      = 22,
			RGB10A2,		//DXGI_FORMAT_R10G10B10A2_TYPELESS         = 23,
			RGB10A2,		//DXGI_FORMAT_R10G10B10A2_UNORM            = 24,
			RGB10A2,		//DXGI_FORMAT_R10G10B10A2_UINT             = 25,
			RG11B10F,		//DXGI_FORMAT_R11G11B10_FLOAT              = 26,
			RGBA8U,			//DXGI_FORMAT_R8G8B8A8_TYPELESS            = 27,
			RGBA8U,			//DXGI_FORMAT_R8G8B8A8_UNORM               = 28,
			RGBA8U,			//DXGI_FORMAT_R8G8B8A8_UNORM_SRGB          = 29,
			RGBA8U,			//DXGI_FORMAT_R8G8B8A8_UINT                = 30,
			RGBA8I,			//DXGI_FORMAT_R8G8B8A8_SNORM               = 31,
			RGBA8I,			//DXGI_FORMAT_R8G8B8A8_SINT                = 32,
			RG16U,			//DXGI_FORMAT_R16G16_TYPELESS              = 33,
			RG16F,			//DXGI_FORMAT_R16G16_FLOAT                 = 34,
			RG16U,			//DXGI_FORMAT_R16G16_UNORM                 = 35,
			RG16U,			//DXGI_FORMAT_R16G16_UINT                  = 36,
			RG16I,			//DXGI_FORMAT_R16G16_SNORM                 = 37,
			RG16I,			//DXGI_FORMAT_R16G16_SINT                  = 38,
			R32F,			//DXGI_FORMAT_R32_TYPELESS                 = 39,
			D32F,			//DXGI_FORMAT_D32_FLOAT                    = 40,
			R32F,			//DXGI_FORMAT_R32_FLOAT                    = 41,
			R32U,			//DXGI_FORMAT_R32_UINT                     = 42,
			R32I,			//DXGI_FORMAT_R32_SINT                     = 43,
			FORMAT_NULL,	//DXGI_FORMAT_R24G8_TYPELESS               = 44,
			FORMAT_NULL,	//DXGI_FORMAT_D24_UNORM_S8_UINT            = 45,
			FORMAT_NULL,	//DXGI_FORMAT_R24_UNORM_X8_TYPELESS        = 46,
			FORMAT_NULL,	//DXGI_FORMAT_X24_TYPELESS_G8_UINT         = 47,
			RG8U,			//DXGI_FORMAT_R8G8_TYPELESS                = 48,
			RG8U,			//DXGI_FORMAT_R8G8_UNORM                   = 49,
			RG8U,			//DXGI_FORMAT_R8G8_UINT                    = 50,
			RG8I,			//DXGI_FORMAT_R8G8_SNORM                   = 51,
			RG8I,			//DXGI_FORMAT_R8G8_SINT                    = 52,
			R16U,			//DXGI_FORMAT_R16_TYPELESS                 = 53,
			R16F,			//DXGI_FORMAT_R16_FLOAT                    = 54,
			D16,			//DXGI_FORMAT_D16_UNORM                    = 55,
			R16U,			//DXGI_FORMAT_R16_UNORM                    = 56,
			R16U,			//DXGI_FORMAT_R16_UINT                     = 57,
			R16I,			//DXGI_FORMAT_R16_SNORM                    = 58,
			R16I,			//DXGI_FORMAT_R16_SINT                     = 59,
			R8U,			//DXGI_FORMAT_R8_TYPELESS                  = 60,
			R8U,			//DXGI_FORMAT_R8_UNORM                     = 61,
			R8U,			//DXGI_FORMAT_R8_UINT                      = 62,
			R8I,			//DXGI_FORMAT_R8_SNORM                     = 63,
			R8I,			//DXGI_FORMAT_R8_SINT                      = 64,
			R8U,			//DXGI_FORMAT_A8_UNORM                     = 65,
			FORMAT_NULL,	//DXGI_FORMAT_R1_UNORM                     = 66,
			RGB9E5,			//DXGI_FORMAT_R9G9B9E5_SHAREDEXP           = 67,
			FORMAT_NULL,	//DXGI_FORMAT_R8G8_B8G8_UNORM              = 68,
			FORMAT_NULL,	//DXGI_FORMAT_G8R8_G8B8_UNORM              = 69,
			DXT1,			//DXGI_FORMAT_BC1_TYPELESS                 = 70,
			DXT1,			//DXGI_FORMAT_BC1_UNORM                    = 71,
			DXT1,			//DXGI_FORMAT_BC1_UNORM_SRGB               = 72,
			DXT3,			//DXGI_FORMAT_BC2_TYPELESS                 = 73,
			DXT3,			//DXGI_FORMAT_BC2_UNORM                    = 74,
			DXT3,			//DXGI_FORMAT_BC2_UNORM_SRGB               = 75,
			DXT5,			//DXGI_FORMAT_BC3_TYPELESS                 = 76,
			DXT5,			//DXGI_FORMAT_BC3_UNORM                    = 77,
			DXT5,			//DXGI_FORMAT_BC3_UNORM_SRGB               = 78,
			ATI1N,			//DXGI_FORMAT_BC4_TYPELESS                 = 79,
			ATI1N,			//DXGI_FORMAT_BC4_UNORM                    = 80,
			ATI1N,			//DXGI_FORMAT_BC4_SNORM                    = 81,
			ATI2N,			//DXGI_FORMAT_BC5_TYPELESS                 = 82,
			ATI2N,			//DXGI_FORMAT_BC5_UNORM                    = 83,
			ATI2N,			//DXGI_FORMAT_BC5_SNORM                    = 84,
			FORMAT_NULL,	//DXGI_FORMAT_B5G6R5_UNORM                 = 85,
			FORMAT_NULL,	//DXGI_FORMAT_B5G5R5A1_UNORM               = 86,
			RGBA8U,			//DXGI_FORMAT_B8G8R8A8_UNORM               = 87,
			RGBA8U,			//DXGI_FORMAT_B8G8R8X8_UNORM               = 88,
			FORMAT_NULL,	//DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM   = 89,
			RGBA8U,			//DXGI_FORMAT_B8G8R8A8_TYPELESS            = 90,
			RGBA8U,			//DXGI_FORMAT_B8G8R8A8_UNORM_SRGB          = 91,
			RGBA8U,			//DXGI_FORMAT_B8G8R8X8_TYPELESS            = 92,
			RGBA8U,			//DXGI_FORMAT_B8G8R8X8_UNORM_SRGB          = 93,
			BP_FLOAT,		//DXGI_FORMAT_BC6H_TYPELESS                = 94,
			BP_FLOAT,		//DXGI_FORMAT_BC6H_UF16                    = 95,
			BP_FLOAT,		//DXGI_FORMAT_BC6H_SF16                    = 96,
			BP,				//DXGI_FORMAT_BC7_TYPELESS                 = 97,
			BP,				//DXGI_FORMAT_BC7_UNORM                    = 98,
			BP,				//DXGI_FORMAT_BC7_UNORM_SRGB               = 99,
			R32U			//DXGI_FORMAT_FORCE_UINT                   = 0xffffffffUL 
		};

		return Cast[Format];
	}

}//namespace detail

	template<>
	inline image importFile<DDS10>
	(
		std::string const & Filename
	)
	{
		std::ifstream FileIn(Filename.c_str(), std::ios::in | std::ios::binary);
		if(FileIn.fail())
			return image();

		detail::ddsHeader HeaderDesc;
		detail::ddsHeader10 HeaderDesc10;
		char Magic[4]; 

		//* Read magic number and check if valid .dds file 
		FileIn.read((char*)&Magic, sizeof(Magic));

		assert(strncmp(Magic, "DDS ", 4) == 0);

		// Get the surface descriptor 
		FileIn.read((char*)&HeaderDesc, sizeof(HeaderDesc));
		if(HeaderDesc.format.flags & detail::GLI_DDPF_FOURCC && HeaderDesc.format.fourCC == detail::GLI_FOURCC_DX10)
			FileIn.read((char*)&HeaderDesc10, sizeof(HeaderDesc10));

		detail::DDLoader Loader;
		if(HeaderDesc.format.flags & detail::GLI_DDPF_FOURCC)
		{
			switch(HeaderDesc.format.fourCC)
			{
			case detail::GLI_FOURCC_DX10:
				Loader.DivSize = 0;
				Loader.BlockSize = 0;
				Loader.Format = dds2gli_cast(HeaderDesc10.dxgiFormat);
				break;
			case detail::GLI_FOURCC_DXT1:
				Loader.DivSize = 4;
				Loader.BlockSize = 8;
				Loader.Format = DXT1;
				break;
			case detail::GLI_FOURCC_DXT3:
				Loader.DivSize = 4;
				Loader.BlockSize = 16;
				Loader.Format = DXT3;
				break;
			case detail::GLI_FOURCC_DXT5:
				Loader.DivSize = 4;
				Loader.BlockSize = 16;
				Loader.Format = DXT5;
				break;
			case detail::GLI_FOURCC_R16F:
				Loader.DivSize = 1;
				Loader.BlockSize = 2;
				Loader.Format = R16F;
				break;
			case detail::GLI_FOURCC_G16R16F:
				Loader.DivSize = 1;
				Loader.BlockSize = 4;
				Loader.Format = RG16F;
				break;
			case detail::GLI_FOURCC_A16B16G16R16F:
				Loader.DivSize = 1;
				Loader.BlockSize = 8;
				Loader.Format = RGBA16F;
				break;
			case detail::GLI_FOURCC_R32F:
				Loader.DivSize = 1;
				Loader.BlockSize = 4;
				Loader.Format = R32F;
				break;
			case detail::GLI_FOURCC_G32R32F:
				Loader.DivSize = 1;
				Loader.BlockSize = 8;
				Loader.Format = RG32F;
				break;
			case detail::GLI_FOURCC_A32B32G32R32F:
				Loader.DivSize = 1;
				Loader.BlockSize = 16;
				Loader.Format = RGBA32F;
				break;

			default:
				assert(0);
				return image();
			}
		}
		else if(SurfaceDesc.format.flags & detail::GLI_DDPF_RGB)
		{
			switch(SurfaceDesc.format.bpp)
			{
			case 8:
				Loader.DivSize = 1;
				Loader.BlockSize = 2;
				Loader.Format = R8U;
				break;
			case 16:
				Loader.DivSize = 1;
				Loader.BlockSize = 2;
				Loader.Format = RG8U;
				break;
			case 24:
				Loader.DivSize = 1;
				Loader.BlockSize = 3;
				Loader.Format = RGB8U;
				break;
			case 32:
				Loader.DivSize = 1;
				Loader.BlockSize = 4;
				Loader.Format = RGBA8U;
				break;
			}
		}
		else
		{

		}

		std::size_t Width = HeaderDesc.width;
		std::size_t Height = HeaderDesc.height;

		gli::format Format = Loader.Format;

		std::streamoff Curr = FileIn.tellg();
		FileIn.seekg(0, std::ios_base::end);
		std::streamoff End = FileIn.tellg();
		FileIn.seekg(Curr, std::ios_base::beg);

		std::vector<glm::byte> Data(std::size_t(End - Curr), 0);
		std::size_t Offset = 0;

		FileIn.read((char*)&Data[0], std::streamsize(Data.size()));

		//image Image(glm::min(MipMapCount, Levels));//SurfaceDesc.mipMapLevels);
		std::size_t MipMapCount = (HeaderDesc.flags & detail::GLI_DDSD_MIPMAPCOUNT) ? HeaderDesc.mipMapLevels : 1;
		//if(Loader.Format == DXT1 || Loader.Format == DXT3 || Loader.Format == DXT5) 
		//	MipMapCount -= 2;
		image Image(MipMapCount);
		for(std::size_t Level = 0; Level < Image.levels() && (Width || Height); ++Level)
		{
			Width = glm::max(std::size_t(Width), std::size_t(1));
			Height = glm::max(std::size_t(Height), std::size_t(1));

			std::size_t MipmapSize = 0;
			if(Loader.Format == DXT1 || Loader.Format == DXT3 || Loader.Format == DXT5)
				MipmapSize = ((Width + 3) >> 2) * ((Height + 3) >> 2) * Loader.BlockSize;
			else
				MipmapSize = Width * Height * Loader.BlockSize;
			std::vector<glm::byte> MipmapData(MipmapSize, 0);

			memcpy(&MipmapData[0], &Data[0] + Offset, MipmapSize);

			image::dimensions_type Dimensions(Width, Height, std::size_t(1));
			Image[Level] = image::mipmap(Dimensions, Format, MipmapData);

			Offset += MipmapSize;
			Width >>= 1;
			Height >>= 1;
		}

		return Image;
	}

	template<>
	inline void exportFile<DDS10>
	(
		gli::image const & ImageIn, 
		std::string const & Filename
	)
	{
		std::ofstream FileOut(Filename.c_str(), std::ios::out | std::ios::binary);
		if (!FileOut)
			return;

		gli::image Image = duplicate(ImageIn);

		char const * Magic = "DDS ";
		FileOut.write((char*)Magic, sizeof(char) * 4);

		glm::uint32 Caps = detail::GLI_DDSD_CAPS | detail::GLI_DDSD_HEIGHT | detail::GLI_DDSD_WIDTH | detail::GLI_DDSD_PIXELFORMAT;

		detail::ddsHeader HeaderDesc;
		SurfaceDesc.size = sizeof(detail::ddsHeader);
		SurfaceDesc.flags = Caps | (detail::isCompressed(Image) ? detail::GLI_DDSD_LINEARSIZE : detail::GLI_DDSD_PITCH) | (Image.levels() > 1 ? detail::GLI_DDSD_MIPMAPCOUNT : 0); //659463;
		SurfaceDesc.width = ImageIn[0].dimensions().x;
		SurfaceDesc.height = ImageIn[0].dimensions().y;
		SurfaceDesc.pitch = detail::isCompressed(Image) ? 32 : 32;
		SurfaceDesc.depth = 0;
		SurfaceDesc.mipMapLevels = glm::uint32(Image.levels());
		SurfaceDesc.format.size = sizeof(detail::ddsPixelFormat);
		SurfaceDesc.format.flags = detail::getFormatFlags(Image);
		SurfaceDesc.format.fourCC = GLI_FOURCC_DX10;
		SurfaceDesc.format.bpp = detail::getFormatBPP(Image);
		SurfaceDesc.format.redMask = 0;
		SurfaceDesc.format.greenMask = 0;
		SurfaceDesc.format.blueMask = 0;
		SurfaceDesc.format.alphaMask = 0;
		SurfaceDesc.surfaceFlags = detail::GLI_DDSCAPS_TEXTURE | (Image.levels() > 1 ? detail::GLI_DDSCAPS_MIPMAP : 0);
		SurfaceDesc.cubemapFlags = 0;

		FileOut.write((char*)&SurfaceDesc, sizeof(SurfaceDesc));

		std::size_t Offset = 0;
		std::size_t MipMapCount = (SurfaceDesc.flags & detail::GLI_DDSD_MIPMAPCOUNT) ? SurfaceDesc.mipMapLevels : 1;

		for(std::size_t Level = 0; Level < Image.levels(); ++Level)
		{
			gli::image::dimensions_type Dimension = Image[Level].dimensions();
			Dimension = glm::max(Dimension, gli::image::dimensions_type(1));

			std::streamsize LevelSize = 0;
			if(Image.format() == gli::DXT1 || Image.format() == gli::DXT3 || Image.format() == gli::DXT5)
				LevelSize = ((Dimension.x + 3) >> 2) * ((Dimension.y + 3) >> 2) * detail::getFormatBlockSize(Image);
			else
				LevelSize = Dimension.x * Dimension.y * Image[Level].value_size();
			std::vector<glm::byte> MipmapData(LevelSize, 0);

			FileOut.write((char*)(Image[Level].data() + Offset), LevelSize);

			Offset += LevelSize;
		}

		if(FileOut.fail() || FileOut.bad())
			return;

		FileOut.close ();
	}

}//namespace loader
}//namespace gtx
}//namespace gli