
/***************************************************************
 * Name:      encoding.h
 * Purpose:   Defines Nerve Gear Character Encodings
 * Author:    GPBeta ()
 * Created:   2014-10-22
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_ENCODING_H
#define NVG_ENCODING_H

namespace NERvGear {

/// \declns{NERvGear::ENCODING}
namespace ENCODING {

#ifndef SIZEOF_WCHAR_T
#define SIZEOF_WCHAR_T 2
#endif // SIZEOF_WCHAR_T

// from wx's fontenc.h

/// Predefined encodings.
enum TYPE {
    SYSTEM = -1,     //!< system default
    DEFAULT,         //!< current default encoding

    // ISO8859 standard defines a number of single-byte charsets
    ISO8859_1,       //!< West European (Latin1)
    ISO8859_2,       //!< Central and East European (Latin2)
    ISO8859_3,       //!< Esperanto (Latin3)
    ISO8859_4,       //!< Baltic (old) (Latin4)
    ISO8859_5,       //!< Cyrillic
    ISO8859_6,       //!< Arabic
    ISO8859_7,       //!< Greek
    ISO8859_8,       //!< Hebrew
    ISO8859_9,       //!< Turkish (Latin5)
    ISO8859_10,      //!< Variation of Latin4 (Latin6)
    ISO8859_11,      //!< Thai

	 /// Doesn't exist currently, but put it here anyhow to make all ISO8859 consecutive numbers.
    ISO8859_12,


    ISO8859_13,      //!< Baltic (Latin7)
    ISO8859_14,      //!< Latin8
    ISO8859_15,      //!< Latin9 (a.k.a. Latin0, includes euro)
    ISO8859_MAX,

    // Cyrillic charset soup (see http://czyborra.com/charsets/cyrillic.html)
    KOI8,            //!< KOI8 Russian
    KOI8_U,          //!< KOI8 Ukrainian
    ALTERNATIVE,     //!< same as MS-DOS CP866
    BULGARIAN,       //!< used under Linux in Bulgaria

    // what would we do without Microsoft? They have their own encodings
        // for DOS
    CP437,           //!< original MS-DOS codepage
    CP850,           //!< CP437 merged with Latin1
    CP852,           //!< CP437 merged with Latin2
    CP855,           //!< another cyrillic encoding
    CP866,           //!< and another one
        // and for Windows
    CP874,           //!< WinThai
    CP932,           //!< Japanese (shift-JIS)
    CP936,           //!< Chinese simplified (GB)
    CP949,           //!< Korean (Hangul charset, a.k.a. EUC-KR)
    CP950,           //!< Chinese (traditional - Big5)
    CP1250,          //!< WinLatin2
    CP1251,          //!< WinCyrillic
    CP1252,          //!< WinLatin1
    CP1253,          //!< WinGreek (8859-7)
    CP1254,          //!< WinTurkish
    CP1255,          //!< WinHebrew
    CP1256,          //!< WinArabic
    CP1257,          //!< WinBaltic (same as Latin 7)
    CP1258,          //!< WinVietnamese
    CP1361,          //!< Johab Korean character set.
    CP12_MAX,

    UTF7,            //!< UTF-7 Unicode encoding
    UTF8,            //!< UTF-8 Unicode encoding
    EUC_JP,          //!< Extended Unix Codepage for Japanese
    UTF16BE,         //!< UTF-16 Big Endian Unicode encoding
    UTF16LE,         //!< UTF-16 Little Endian Unicode encoding
    UTF32BE,         //!< UTF-32 Big Endian Unicode encoding
    UTF32LE,         //!< UTF-32 Little Endian Unicode encoding
	
	// the standard mac encodings
    MACROMAN,        
    MACJAPANESE,
    MACCHINESETRAD,
    MACKOREAN,
    MACARABIC,
    MACHEBREW,
    MACGREEK,
    MACCYRILLIC,
    MACDEVANAGARI,
    MACGURMUKHI,
    MACGUJARATI,
    MACORIYA,
    MACBENGALI,
    MACTAMIL,
    MACTELUGU,
    MACKANNADA,
    MACMALAJALAM,
    MACSINHALESE,
    MACBURMESE,
    MACKHMER,
    MACTHAI,
    MACLAOTIAN,
    MACGEORGIAN,
    MACARMENIAN,
    MACCHINESESIMP,
    MACTIBETAN,
    MACMONGOLIAN,
    MACETHIOPIC,
    MACCENTRALEUR,
    MACVIATNAMESE,
    MACARABICEXT,
    MACSYMBOL,
    MACDINGBATS,
    MACTURKISH,
    MACCROATIAN,
    MACICELANDIC,
    MACROMANIAN,
    MACCELTIC,
    MACGAELIC,
    MACKEYBOARD,

    // more CJK encodings (for historical reasons some are already declared above)
    ISO2022_JP,      //!< ISO-2022-JP JIS encoding

    MAX,             // highest enumerated encoding value

    MACMIN = MACROMAN,
    MACMAX = MACKEYBOARD,

    // aliases for endian-dependent UTF encodings
#ifdef WORDS_BIGENDIAN
    UTF16 = UTF16BE,  //!< native UTF-16
    UTF32 = UTF32BE,  //!< native UTF-32
#else // WORDS_BIGENDIAN
    UTF16 = UTF16LE,  //!< native UTF-16
    UTF32 = UTF32LE,  //!< native UTF-32
#endif // WORDS_BIGENDIAN

    // alias for the native Unicode encoding on this platform
    // (this is used by wxEncodingConverter and wxUTFFile only for now)
#if SIZEOF_WCHAR_T == 2
    UNICODE16 = UTF16,
#else // SIZEOF_WCHAR_T == 4
    UNICODE32 = UTF32,
#endif

    // alternative names for Far Eastern encodings
        // Chinese
    GB2312 = CP936, //!< Simplified Chinese
    BIG5 = CP950,   //!< Traditional Chinese

        // Japanese (see http://zsigri.tripod.com/fontboard/cjk/jis.html)
    SHIFT_JIS = CP932, //!< Shift JIS

        // Korean (CP 949 not actually the same but close enough)
    EUC_KR = CP949,
    JOHAB = CP1361,

        // Vietnamese
    VIETNAMESE = CP1258
};

}

}

#endif // NVG_ENCODING_H
