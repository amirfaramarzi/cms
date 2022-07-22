/*!
 * MIT License
 *
 * Copyright (c) 2022 Kambiz Asadzadeh
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

#ifndef TEGRA_CORE_HPP
#define TEGRA_CORE_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::CMS)

/*!
 * @brief The DeveloperMode is for enable or disable system debuging information.
 */
struct DeveloperMode {
#if defined(BUILD_DEBUG_MODE) || defined(ENABLE_DEVELOPER_MODE)
    inline static bool IsEnable = true;
#else
    inline static bool IsEnable = false;
#endif
};

template <typename T>
/*!
 * @brief isset checks if the variable has no value.
 * @returns true if it has value
 */
[[nodiscard("Checks if the variable has no value.")]]
static auto isset(T t) noexcept(true) {
    if (const auto it = t; it != T {})
        // on success
        return true;
    else
        // on false...
        return false;
}

/*!
 * @brief check if these two are equal
 */
template <typename T1, typename T2>
__tegra_no_discard constexpr bool equals(T1 const& first, T2 const& second) __tegra_noexcept
{
    return first == second;
}

/*!
 * @brief Invokes the command processor to execute a command.
 * @param cmd holds the commands for function.
 * @returns data from terminal.
 */
__tegra_maybe_unused std::string command(const std::string& cm);

/*!
 * @brief Maybe we need to convert stringstream to standard string.
 * @param data as stringstream content.
 * @returns as std::string output.
 */
__tegra_no_discard std::string convertStream(std::stringstream const& data) __tegra_noexcept;

/*!
 * @brief regen url by length fro, the first
 */
template <typename T1, typename T2>
__tegra_no_discard std::string_view regenUrl(T1 const& url, T2 const len) __tegra_noexcept
{
    if(!url.empty)
        return url.substr(len);
}

/*!
 * @brief The StorageType enum
 */
enum class StorageType : u8
{
    Empty           =   0x0,
    File            =   0x1,
    MemoryCard      =   0x2,
    Hdd             =   0x3,
    Ssd             =   0x4,
    Cache           =   0x5,
    Database        =   0x6,
    Network         =   0x7
};

enum class UserMode : u8
{
    Guest           =   0x0,
    User            =   0x1,
    Master          =   0x2,
    Customized      =   0x3
};

enum class SyncDevice : u8
{
    Unknown         =   0x0,
    WebOnly         =   0x1,
    Mobile          =   0x2,
    Desktop         =   0x3,
    CrossPlatform   =   0x4
};

enum class HostType : u8
{
    Unknown     =   0x0,
    Windows     =   0x1,
    MacOS       =   0x2,
    Linux       =   0x3
};

enum class SystemStatus : u8
{
    Unknown     =   0x0,
    Installed   =   0x1,
    Open        =   0x2,
    Closed      =   0x3,
    Running     =   0x4,
    Suspend     =   0x5
};

enum class Service : u8
{
    Local       =   0x0,
    Installed   =   0x1,
    Closed      =   0x2,
    Running     =   0x3
};

enum class ApiModel : u8
{
    Unknown,
    JSON,
    XML,
    GRAPHQL
};

enum class TerminateType : u8
{
    Unknown,
    Violation,
    UnexpectedError
};

struct Termination
{
    /*!
     * @brief It is sometimes necessary to force the system in runtime.
     * @param terminateType is based on reasons for action.
     */
    void terminate(TerminateType terminateType);
};

/*!
 * @brief The ExceptionMode enum
 */
enum class ExceptionMode : u8 { Default, StlException, TegraException };

struct ExceptionData
{
    std::string message {}; //default message
    std::string file    {};
    uint line           {};
    std::string func    {};
    std::string info    {};
};

class Exception : public std::exception
{
public:
    enum Reason : u8
    {
        Core,
        Framework,
        IO,
        User,
        System,
        Other
    };

    Exception(const Reason& reason, const std::string& message);
    virtual ~Exception();
    virtual const char* what() const throw();
private:
    ExceptionData* m_exceptionData;
};

struct BootParameter
{
    std::time_t initTime;
    std::string saveState;
    std::optional<s32> stateIndex;
    std::optional<bool> fastBoot;
    std::optional<HostType> hostType;
    std::optional<StorageType> storageType;
    std::optional<UserMode> userMode;
    std::optional<SyncDevice> syncDevice;
    std::optional<SystemStatus> systemStatus;
};

/*!
 * @brief The Engine class
 */
class Engine {
public:
    Engine() = default;
    Engine(const Engine& rhsEngine) = delete;
    Engine(Engine&& rhsEngine) noexcept = delete;
    Engine& operator=(const Engine& rhsEngine) = delete;
    Engine& operator=(Engine&& rhsEngine) noexcept = delete;
    ~Engine()=default;

    /*!
     * System copyrights.
     * @brief Please do not delete or modify them, unless, of course, you have a little respect for the developers.
     * @returns output as static copyright by system.
     */
    __tegra_no_discard static std::string copyright() __tegra_noexcept;

    /*!
     * @brief Convert HTML entities to their corresponding characters.
     * @param The input string.
     * @returns output as string.
     */
    static std::string htmlEntityDecode(const std::string& content);

    /*!
     * @brief String find is used to find the first occurrence of sub-string in the specified string being called upon.
     * @param list contains of strings.
     * @param search is for searching as key.
     * @returns true if the desired content is found and replaced.
     */
    bool findSubString(const std::vector<std::string>& list, const std::string& search);

    /*!
     * @brief Replace all occurrences of a sub string with new string of data.
     * @param data is a full content.
     * @param toSearch is target.
     * @param replaceStr is string for replace with toSearch.
     */
    void findAndReplaceContent(std::string& data, std::string toSearch, std::string replaceStr);

    /*!
     * @brief Replace all links of a sub string with new link.
     * @param data is a full content.
     * @param toSearch is target.
     * @param replaceUrl is string for replace with toSearch.
     */
    void findAndReplaceLink(std::string& data, std::string toSearch, std::string replaceUrl);

    /*!
     * @brief Some links have symptoms that need to be corrected, this function can provide it.
     * @param uri for example [page_one+1] ~ should be page-page1
     * @returns string type of fixed link.
     */
    std::string linkConvertor(const std::string& uri);

    /*!
     * @brief There are some differences in the fields of queries for some drivers that we can filter them with this function.
     * @param fields is list of the fields.
     * @returns as filtered list of fields.
     */
    std::vector<std::string> filteredQueryFields(VectorString& fields);

    /*!
     * @brief The SepratorType enum
     */
    enum class SepratorType : u8
    {
        Comma,
        Dash,
        Slash,
        BackSlash,
        Dot,
        Equal,
        UnderLine,
        Quote,
        DoubleQuote,
        Apostrophe,
        Grave,
        Colon,
        SemiColon,
        Brvbar,
        Lt,
        Gt,
        Percent,
        And,
        Hat,
        Dollar,
        Question,
        Sim,
        Atsign,
        Sharp,
        Exclamation,
        LeftRoundBracket,
        RightRoundBracket,
        LeftSquareBracket,
        RightSquareBracket,
        LeftCurlyBracket,
        RightCurlyBracket
    };

    /*!
     * @brief The SepratorStyle enum
     */
    enum class SepratorStyle : u8 { WithSpace, Mixed };

    /*!
     * @brief initialize starter!
     * @returns returns true if the system starts successfully.
     */
    __tegra_no_discard bool initialize() __tegra_const_noexcept;

    /*!
     * @brief join function will implode a vector of strings into a comma-separated.
     * @param strings are list of strings.
     * @param sep is character of seprator.
     * @param sepStyle is style of seprator.
     * @returns as string of result.
     */
    __tegra_no_discard std::string join(const VectorString& strings, const SepratorType& sep, const SepratorStyle& sepStyle) __tegra_noexcept;

    /*!
     * \brief elementErase function will removes certain characters from a string.
     * \param content is the main content of string.
     */
    void elementErase(std::string& content) __tegra_noexcept;

    /*!
     * \brief whiteSpaceLeading function will Reduce multiple whitespaces to a single white space.
     * \param input as string.
     * \return final content output after reducing single white space.
     */
    __tegra_no_discard std::string whiteSpaceReduce(std::string& input) __tegra_noexcept;

    /*!
     * \brief whiteSpaceLeading function will removes leading whitespace from content.
     * \param input as string.
     * \return final content output after leading white spaces.
     */
    __tegra_no_discard std::string whiteSpaceLeading(std::string& input) __tegra_noexcept;

    // Declared and defined in database section.
    enum class TableType : u8;

    /*!
     * @brief  It may help to distinguish between tables and views depending on what your naming convention is.
     * @returns string name of prefix.
     */
    static std::string tablePrefix();

    /**
     * Table unicode base.
     * @brief   It may help to distinguish between tables and views depending on what your naming convention is.
     * @returns  string unicode of unicode.
     */
    static std::string tableUnicode();

    /**
     * @brief   It may help to mixing table prefixes for more details.
     * @returns  string final table name after mixed.
     */
    static std::string mixedTablePrefix(const std::string& p, const std::string& t);

    /**
     * @brief   It may help to mixing table prefixes for more details.
     * @returns  string final table name after mixed.
     */
    static std::string table(std::string_view tableName, TableType tableType);

    /**
     * @brief It may help to filter tables.
     * @returns as tables.
     */
    VectorString tableFilter(const VectorString& tables, TableType tableType);

    /*!
     * @brief Sometimes we need to remove dashes from the uri or content based data.
     * @param src is a content source.
     * @returns string of final output.
     */
    __tegra_no_discard std::string removeDashes(const std::string& src) __tegra_const_noexcept;

    /*!
     * @brief We need to get current language based on your selected translator value on page.
     * @returns string for name of language that is used.
     */
    static std::string defaultLanguage();

    /*!
     * @brief Before displaying the contents of the pages, we need to replace some characters.
     * @param content as raw content.
     * @param map as data for replacing.
     * @returns content as string.
     */
    std::string fullReplacer(const std::string& content, const MapString& map);

    /*!
     * @brief setLanguage function sets language from user.
     * @param l as language string.
     */
    void setLanguage(const std::string& l);

    /*!
     * @brief getLanguage function will returns language name as string.
     * @returns string.
     */
    std::string getLanguage();

    /*!
     * @brief A URI is an identifier of a specific resource. Like a page, or book, or a document.
     * @returns uri.
     */
    std::vector <std::string> langUri;

    /*!
     * @brief array Languages available on the system
     * @returns map of languages.
     */
    std::map <std::string, std::string> langs();

    /*!
     * @brief array getting language by path
     * @returns map of languages based on their path.
     */
    std::map <std::string, std::string> langsByPath(const std::string& path);

    /*!
     * @brief Path reducing function.
     * @returns string of reduced path.
     */
    std::string reducePath(const std::string& path);

    /*!
     * @brief Language list as a member.
     * @returns unique pointer of languages list.
     */
    std::unique_ptr<MapString> langList;

    /*!
     * @brief Services name.
     * @returns string services name.
     */
    std::vector <std::string> services;

    /*!
     * @brief Recommended container for module settings.
     * @returns array of modules.
     */
    std::vector <std::string> module;

};


TEGRA_NAMESPACE_END

#endif // CORE_HPP
