#include "language.hpp"
#include "core/core.hpp"

#if defined(PLATFORM_MAC) && !defined(PLATFORM_MOBILE)
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <mach-o/dyld.h>
#include <IOKit/IOKitLib.h>
#include <ApplicationServices/ApplicationServices.h>
#include <ImageIO/ImageIO.h>
#elif defined(PLATFORM_MAC) && defined(PLATFORM_MOBILE)
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <mach-o/dyld.h>
#include <IOKit/IOKitLib.h>
#include <ApplicationServices/ApplicationServices.h>
#include <ImageIO/ImageIO.h>
#elif defined(PLATFORM_LINUX)
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#elif defined(PLATFORM_FREEBSD)
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#elif defined(PLATFORM_WINDOWS)
#include <Windows.h>
#include <Iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#elif defined (PLATFORM_ANDROID)
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#endif

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;

TEGRA_NAMESPACE_BEGIN(Tegra::Multilangual)

std::string LanguagePath::getExecutablePath() {
#if defined(PLATFORM_MOBILE) && defined(PLATFORM_ANDROID)
    std::string res = {"assets:/"};
#elif defined(PLATFORM_MOBILE) && defined(PLATFORM_IOS)
    std::string res = {"/"};
#elif defined(PLATFORM_MAC)
    std::string res = {"/"};
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        std::string v = path;
        res = v.substr(0, v.find_last_of("\\/")) + "/";
    }
#elif defined(PLATFORM_LINUX)
    std::string res = {"/"};
    char path[1024];
    uint32_t size = sizeof(path);
    if (readlink(path, &size) == 0) {
        std::string v = path;
        res = v.substr(0, v.find_last_of("\\/")) + "/";
    }
#elif defined(PLATFORM_WINDOWS)
    std::string res = {"/"};
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    res = std::string(buffer).substr(0, pos);
#elif defined(PLATFORM_FREEBSD)
    std::string res = {"/"};
    res = "FreeBSD does not support yet!"
#elif defined(PLATFORM_SOLARIS)
    std::string res = {"/"};
    res = "Solaris does not support yet!"
#endif
    return res;
}

bool LanguagePath::exists(const std::string& file) {
    struct stat buffer;
    return (stat (file.c_str(), &buffer) == 0);
}

/*! Implementation of language support */
Language::Language()
{
    ///TODO... this section is under development :) this is a simple concept.
    ///Everything must be dynamic from db and configs file.
}

Language::~Language()
{
    
}


void Language::registerAll(const LanguageType& data)
{
    m_get = data;
}

LanguageType Language::get() const noexcept
{
    return m_get;
}

void Language::registerLanguage(const Types::CodeType& code)
{
    m_languageSupport = code;
}

CodeType Language::languageSupport()
{
    return m_languageSupport;
}

void Language::registerSections(const Types::SectionType& sec)
{
    m_sections = sec;
}

CodeType Language::sections()
{
    return m_sections;
}

std::string Language::getLanguageCode()
{

}

std::string Language::getLanguage()
{

}

TEGRA_NAMESPACE_END
