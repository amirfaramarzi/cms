#include "dictionary.hpp"
#include "core/core.hpp"
#include "core/logger.hpp"

TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra::Translation)

LanguageTemplate::LanguageTemplate(const LanguageStruct& rhs)
{
    m_languageStruct = new LanguageStruct(rhs);
}
LanguageTemplate::~LanguageTemplate()
{
    __tegra_safe_delete(m_languageStruct);
}

std::string LanguageTemplate::wordKey() __tegra_const_noexcept
{
    if(!m_languageStruct->m_wordKey.empty()) {
        return m_languageStruct->m_wordKey;
    } else {
        return "unknown key";
    }
}

std::string LanguageTemplate::module() __tegra_const_noexcept
{
    return m_languageStruct->m_module;
}

std::string LanguageTemplate::defaultValue() __tegra_const_noexcept
{
    if(!m_languageStruct->m_defaultValue.empty()) {
        return m_languageStruct->m_defaultValue;
    } else {
        Log("there is no default value of key [" + wordKey() + "]", LoggerType::Warning);
        return "there is no default value of key [" + wordKey() + "]";
    }
}

std::string LanguageTemplate::customValue() __tegra_const_noexcept {
    if(!m_languageStruct->m_customValue.empty()) {
        return m_languageStruct->m_customValue;
    } else {
        return "there is no custom value of key [" + wordKey() + "]";
        Log("here is no custom value of key [" + wordKey() + "]", LoggerType::Warning);
    }
}

TEGRA_NAMESPACE_END
