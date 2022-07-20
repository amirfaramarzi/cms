#ifndef PROJECT_TYPES_HPP
#define PROJECT_TYPES_HPP

#include "precompiled/pch.hpp" //get some header.

namespace Tegra::Types {

using schar        = signed char;
using uchar        = unsigned char;
using ushort       = unsigned short;
using uint         = unsigned int;
using ulong        = unsigned long;
using ullong       = unsigned long long;
using llong        = long long;

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using s8  = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

#if __APPLE__
using uptr = std::uint64_t;
#else
using uptr = std::uintptr_t;
#endif


using VariantTypes      = std::map<std::string, std::variant<std::string, std::string_view, int, double, bool>>;
using MapList           = std::pair<std::string, std::map<std::string, std::string>>;
using MapVector         = std::pair<std::string, std::vector<std::string>>;
using IteratorConfig    = std::map<std::string, std::string>::iterator;
using MapString         = std::pair<std::string, std::string>;
using LanguageType      = std::map<std::string, std::string>;
using MetaList          = std::map<std::string, std::string>;
using ResourceType      = std::map<std::string, std::string>;
using ConfigType        = std::map<std::string, std::string>;
using SettingType       = std::map<int, std::string>;
using VectorString      = std::vector<std::string>;
using SectionType       = std::vector<std::string>;
using CodeType          = std::vector<std::string>;
using OptionalString    = std::optional<std::string>;
using TableNames        = std::vector<std::string>;
using SheetType         = std::vector<std::string>;
using TranslateType     = std::string;


template<typename T1, typename T2> using Map      = std::map<T1, T2>;
template<typename T1, typename T2> using MultiMap = std::multimap<T1, T2>;
template<typename T1, typename T2> using Pair     = std::pair<T1, T2>;

template<typename T> using Vector        = std::vector<T>;
template<typename T> using Optional      = std::optional<T>;
template<typename T> using Variant       = std::variant<T>;

using Function          = std::function<void(void)>;
using PackagedTask      = std::packaged_task<void(void)>;
using MultiThreadVector = std::vector<std::thread>;
using StringStream      = std::basic_stringstream<char>;
using String            = std::string;
using if_streamer       = std::ifstream;
using string_stream     = std::stringstream;

}

#endif // PROJECT_TYPES_HPP
