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

//! Fixed width integer types (since C++11)
//! Signed integer type
using s8  = std::uint8_t;
using s16 = std::uint16_t;
using s32 = std::uint32_t;
using s64 = std::uint64_t;

//! Fastest Signed integer type
using sf8  = std::int_fast8_t;
using sf16 = std::int_fast16_t;
using sf32 = std::int_fast32_t;
using sf64 = std::int_fast64_t;

//! Smallest Signed integer type
using slf8  = std::int_least8_t;
using slf16 = std::int_least16_t;
using slf32 = std::int_least32_t;
using slf64 = std::int_least64_t;

using imax = std::intmax_t; //! maximum-width signed integer type.
using iptr = std::intptr_t; //! signed integer type capable of holding a pointer to void.

//! UnSigned integer type
using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

//! Fastest UnSigned integer type
using uf8  = std::uint_fast8_t;
using uf16 = std::uint_fast16_t;
using uf32 = std::uint_fast32_t;
using uf64 = std::uint_fast64_t;

//! Smallest UnSigned integer type
using ulf8  = std::uint_least8_t;
using ulf16 = std::uint_least16_t;
using ulf32 = std::uint_least32_t;
using ulf64 = std::uint_least64_t;

using umax = std::uintmax_t; //! maximum-width unsigned integer type
using uptr = std::uintptr_t; //! unsigned integer type capable of holding a pointer to void.

using VariantTypes      = std::map<std::string, std::variant<std::string, std::string_view, int, double, bool>>;
using MapList           = std::pair<std::string, std::map<std::string, std::string>>;
using MapVector         = std::pair<std::string, std::vector<std::string>>;
using IteratorConfig    = std::map<std::string, std::string>::iterator;
using LanguageType      = std::map<std::string, std::string>;
using MetaList          = std::map<std::string, std::string>;
using ResourceType      = std::map<std::string, std::string>;
using ConfigType        = std::map<std::string, std::string>;
using MapString         = std::map<std::string, std::string>;
using PairString        = std::pair<std::string, std::string>;
using SettingType       = std::map<int, std::string>;
using VectorString      = std::vector<std::string>;
using SectionType       = std::vector<std::string>;
using CodeType          = std::vector<std::string>;
using OptionalString    = std::optional<std::string>;
using OptionalNumeric   = std::optional<int>;
using OptionalBool      = std::optional<bool>;
using TableNames        = std::vector<std::string>;
using QueryType         = std::vector<std::string>;
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
using IfStreamer        = std::ifstream;
using StringStream      = std::stringstream;

}

#endif // PROJECT_TYPES_HPP
