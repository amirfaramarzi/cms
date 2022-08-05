#ifndef COMMON_HPP
#define COMMON_HPP

/*!
 * MIT License
 *
 * Copyright (c) 2021 Kambiz Asadzadeh
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


/*!
 * C++20 introduces modules, a modern solution for componentization of C++ libraries and programs.
 * A module is a set of source code files that are compiled independently of the translation units that import them.
 * Modules eliminate or greatly reduce many of the problems associated with the use of header files, and also potentially reduce compilation times.
 * Macros, preprocessor directives, and non-exported names declared in a module are not visible and therefore have no effect on the compilation of the translation unit that imports the module.
 * You can import modules in any order without concern for macro redefinitions. Declarations in the importing translation unit do not participate in overload resolution or name lookup in the imported module.
 * After a module is compiled once, the results are stored in a binary file that describes all the exported types, functions and templates. That file can be processed much faster than a header file, and can be reused by the compiler every place where the module is imported in a project.
 *
!*/

#include "utilities/preprocessor.hpp"
#include "utilities/featuretest.hpp"
#include "utilities/types.hpp"

#ifdef USE_LATEST_STANDARD
////TODO use module...
#else
///!
#endif

#if defined(CXX_STANDARD_20)
#ifdef __has_cpp_attribute
#  if __has_cpp_attribute(__cpp_modules)
#   pragma message("Your project is based on modern solution for componentization of C++ libraries and programs.")
#  endif
#else
#   pragma message("Your project is based on classic precompiled-header system. [enable module technique in C++]")
#endif
#endif

#if __cplusplus > 201703
#ifdef __has_include
#  if __has_include("precompiled/pch.hpp")
#    include "precompiled/pch.hpp"
#  else
#     pragma message("Your project is based on classic precompiled-header system.")
#  endif
#endif
#else
# include "precompiled/pch.hpp"
#endif

namespace Tegra {

namespace CMS {

struct LANGUAGE_SHEET final {
  static constexpr auto GLOBAL      = "global";
  static constexpr auto EXCEPTION   = "exceptions";
};

struct CONFIG final {
  static constexpr std::string_view FULL_NAME = "Tegra CMS";
  static constexpr std::string_view FULL_VERSION = "0.5";
  static constexpr std::string_view RELEASE_MODE = "alpha";
  static constexpr std::string_view RELEASE_NUMBER = "2.0";
  static constexpr std::string_view DEVELOPER = "Kambiz Asadzadeh";
  static constexpr std::string_view FRAMEWORK_CONFIG_FILE = "config.json";
  static constexpr std::string_view CMS_CONFIG_FILE = "config/system-config.json";
  static constexpr std::string_view CMS_TABLES_FILE = "config/system-tables.json";
  static constexpr std::string_view CMS_TABLES_PREFIX = "teg_";
  static constexpr std::string_view CMS_TABLES_VALUE_STRUCT = "_l";
  static constexpr std::string_view CMS_TABLES_TABLE_UNICODE = "utf-8";
  static constexpr std::string_view CMS_TABLES_COOKIE_PREFIX = "tegra_";
  static constexpr std::string_view TRANSLATION_FILE = "translations/contents.json";

  static constexpr std::string_view OFFICIAL_WEB = "http://kambizasadzadeh.com";
  static constexpr std::string_view OFFICIAL_EMAIL = "info@kambizasadzadeh.com";
};

struct STATICS final {

  //!INDEX
  static constexpr std::string_view INDEX_PATH        = "{}";
  static constexpr std::string_view INDEX_PATH_SCOPE  = "";

  //!ADMIN
  static constexpr std::string_view ADMIN_PATH        = "dashboard";
  static constexpr std::string_view ADMIN_PATH_SCOPE  = "dashboard/";

  //!INSTALLER
  static constexpr std::string_view INSTALL_PATH                = "install";
  static constexpr std::string_view INSTALL_PATH_SCOPE          = "install/";
  static constexpr std::string_view INSTALL_INIT_PATH           = "install/init";
  static constexpr std::string_view INSTALL_INIT_PATH_SCOPE     = "install/init/";
  static constexpr std::string_view INSTALL_DATABASE_PATH       = "install/database";
  static constexpr std::string_view INSTALL_DATABASE_PATH_SCOPE = "install/database/";
  static constexpr std::string_view INSTALL_FINALIZE_PATH       = "install/finalize";
  static constexpr std::string_view INSTALL_FINALIZE_PATH_SCOPE = "install/finalize/";
  static constexpr std::string_view INSTALL_COMPLETE_PATH       = "install/complete";
  static constexpr std::string_view INSTALL_COMPLETE_PATH_SCOPE = "install/complete/";
};

}


#undef TEGRA_COPYRIGHT
#define TEGRA_COPYRIGHT "<!-- ]]></script> -->Copyright © 2022 <a class=\"nav-link d-inline-block p-0\" href=\"https://kambizasadzadeh.com\" rel=\"noopener\" target=\"_blank\">Tegra CMS</a> <!-- Tegra CMS Team -->"

#define STLLIB_STANDARD             0x0
#define STLLIB_TECHNICAL_REPORT     0x1
#define STLLIB_EXPERIMENTAL         0x2
#define STLLIB_BOOST                0x3
#define STLLIB_NETWORKING_ERROR "We don't even have access to networking TS."
#define STLLIB_SYSTEM_ERROR "We don't even have access to system TS."
#define BOOST_ASIO_NO_DEPRECATED

//! Compiler Predefined Variables.

#define __tegra_null_str ""
#define __tegra_space " "
#define __tegra_zero 0
#define __tegra_newline "\n"
#define __tegra_compiler_counter __COUNTER__
#define __tegra_compiler_line __LINE__
#define __tegra_compiler_file __FILE__
#define __tegra_compiler_function __FUNCTION__
#define __tegra_compiler_pretty_function __PRETTY_FUNCTION__
#define __tegra_compiled_date __DATE__
#define __tegra_compiler_time __TIME__

#define __tegra_has_include __has_include
#define __tegra_charset "utf-8"
#define __tegra_unknown "unknown"

template<typename T>
using Function = std::function<T>;

template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
  return std::make_unique<T>(std::forward<Args>(args)...);
}

#define TEGRA_SCOPE_POINTER(Class, alias, param) std::unique_ptr<Class>alias(new Class(param));

template<typename T>
using Ref = std::shared_ptr<T>;

#define TEGRA_REF_SHARED_POINTER(Class, alias, param) std::shared_ptr<Class>alias(new Class(param));

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
  return std::make_shared<T>(std::forward<Args>(args)...);
}

#define __tegra_safe_instance(object, Class) \
object = new Class();\

#define __tegra_safe_delete(object) \
if(object!=nullptr)                 \
{ delete object;}                   \
object = nullptr;                   \

#define __tegra_abort abort();

#define TEGRA_BRACE_BEGIN {
#define TEGRA_BRACE_END }
#define TEGRA_USING_NAMESPACE using namespace
#define TEGRA_NAMESPACE_BEGIN(x) namespace x {
#define TEGRA_ANONYMOUS_NAMESPACE_BEGIN namespace {
#define TEGRA_NAMESPACE_END }
#define TEGRA_USING using
#define TEGRA_NAMESPACE namespace

/*
 * C++11 keywords and expressions
 */
#ifdef TEGRA_COMPILER_NULLPTR
# define __tegra_nullptr         nullptr
#else
# define __tegra_nullptr         NULL
#endif

# define __tegra_override override
# define __tegra_final final

# define __tegra_const const
# define __tegra_const_noexcept const noexcept
# define __tegra_noexcept noexcept
# define __tegra_noexcept_expr(x) noexcept(x)
# define __tegra_constexpr_virtual virtual constexpr
# define __tegra_constexpr constexpr
# define __tegra_static_constexpr static constexpr
# define __tegra_static_constexpr static constexpr
# define __tegra_inline_static_constexpr inline static constexpr
# define __tegra_inline_static_const inline static const
# define __tegra_inline_static inline static

#define __tegra_pure_const_noexcept const noexcept = 0

#define __tegra_no_return [[noreturn]]

#define __tegra_no_discard [[nodiscard]]
#define __tegra_no_discard_message(x) [[nodiscard(x)]]

#define __tegra_maybe_unused [[maybe_unused]]

#define __tegra_virtual virtual

#define FROM_TEGRA_STRING(x) std::string(x)
#define TO_TEGRA_STRING(x) std::to_string(x)

#define TEGRA_TRANSLATOR(key, value) engine->translator->translate(engine->getLanguage(), key, value).defaultValue()

#define TEGRA_RUNTIME_FORMAT(content, ...) fmt::format(fmt::runtime(content), __VA_ARGS__)

#define TEGRA_COMPILETIME_FORMAT(content, ...) fmt::format(content, __VA_ARGS__)

#define TEGRA_PAGE_URL_REGEN(x) regen_url(x, 2)

#define BOOLCOMBINER(v1, v2) v1[v2].asBool()
#define STRCOMBINER(v1, v2) v1[v2].asString()
#define INTCOMBINER(v1, v2) v1[v2].asInt()
#define DBLCOMBINER(v1, v2) v1[v2].asDouble()
#define FLTCOMBINER(v1, v2) v1[v2].asFloat()

#define APPLICATION_DB_RUN(rdbms, dbHost, dbPort, dbName, dbUsername, dbPassword) AppFramework::application().createDbClient(FROM_TEGRA_STRING(rdbms), dbHost, dbPort, dbName, dbUsername, dbPassword).run();

//! EXPORTS & EXTRA
#if defined(__WINNT) || defined(__WINNT__) || defined(WIN32) || \
defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) ||    \
    defined(WIN64) || defined(_WIN64) || defined(__WIN64) ||    \
    defined(__WIN64__)
//! Microsoft Windows
#define __tegra_export __declspec(dllexport)
#define __tegra_import __declspec(dllimport)
#elif defined(__GNUC__)
//! Define for Unix base OS such as: Linux, macOS, FreeBSD, etc...
#define __tegra_export __attribute__((visibility("default")))
#define __tegra_import __attribute__((visibility("default")))
#define __tegra_hidden __attribute__((visibility("hidden")))
#else
//  do nothing and hope for the best?
#define __tegra_export
#define __tegra_import
#pragma warning Unknown dynamic link import / export semantics.
#endif

#define TEGRA_HAS_INCLUDE __has_include
#define TEGRA_ENABLE_SHARED_FROM(x) std::enable_shared_from_this<x>

#define TEGRA_MOVE(x) std::move(x)

#define eprintf(format, ...) fprintf (stderr, format, __VA_ARGS__)

#define SCOPE :
#define SCOPE_LEFT (
#define SCOPE_RIGHT )
#define SCOPE_ENDS {}

#define TEGRA_QUERY(...) #__VA_ARGS__

#define TEGRA_DEFAULT_OCTORS_WITHOUT_IMPL(Class) \
    Class() = default;\
    ~Class() = default;

#define TEGRA_DEFAULT_INTERFACE_OCTORS_WITHOUT_IMPL(Class) \
Class() = default;\
    virtual ~Class() = default;

#define TEGRA_DEFAULT_OCTORS(Class) \
Class();\
    ~Class();

#define TEGRA_DEFAULT_OCTORS_IMPL(Class)\
Class::Class(){}\
    Class::~Class(){}\

#define TEGRA_DEFAULT_INTERFACE_OCTORS(Class) \
Class();\
    virtual ~Class();

#define TEGRA_DEFAULT_INTERFACE_OCTORS_IMPL(Class)\
Class::Class() {}\
    Class::~Class(){}\

#define __tegra_enum enum
#define __tegra_enum_class enum class

#define __tegra_shared_ptr(Class) \
std::shared_ptr<Class>

#define __tegra_classic_ptr(Class, object) \
Class* object;\

/*!
 * \brief This struct represents a non-copyable object.
 */
struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable(NonCopyable const&) = delete;
    NonCopyable& operator=(NonCopyable const&) = delete;
};

/*!
 * \brief This struct represents a non-movable object.
 */
struct NonMovable
{
    NonMovable() = default;
    NonMovable(NonMovable&&) = delete;
    NonMovable& operator=(NonMovable&&) = delete;
};

/*!
 * \brief This struct represents a non-copyable or non-movable object.
 */
struct NonMovableOrCopyable : private NonCopyable, NonMovable
{
    NonMovableOrCopyable() = default;
};

//!Macro version of non-copyable.
#define TEGRA_DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;

//!Macro version of non-movable.

#define TEGRA_DISABLE_MOVE(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;

//!Macro version of non-copyable and non-movable.
#define TEGRA_DISABLE_COPY_MOVE(Class) \
    TEGRA_DISABLE_COPY(Class) \
    TEGRA_DISABLE_MOVE(Class)
}

#include "prestructure.hpp"

#endif // COMMON_HPP
