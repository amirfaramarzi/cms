#include "template.hpp"
#include "core/core.hpp"
#include "core/config.hpp"
#include "core/logger.hpp"

#include <map>

TEGRA_NAMESPACE_BEGIN(Tegra::CMS)


Template::Template()
{
  //ToDo...
}

Template::~Template()
{
  //ToDo...
}

bool Template::fileExist(const std::string& file)
{
    bool file_status;
    try {
        file_status = std::filesystem::exists(file);
    } catch (const std::system_error& e)
    {
        if(isset(DeveloperMode::IsEnable))
        {
            eLogger::Log("Template\t" + FROM_TEGRA_STRING(file) + "\twas not found!", eLogger::LoggerType::Info);
            eLogger::Log(e.what(), eLogger::LoggerType::Critical);
        }
    }
    if(const auto it = isset(file_status); it == true)
    {
        return true;
    } else {
        return false;
    }
    return false;
}

std::string Template::theme() const
{
    std::string t{};
    switch (utype)
    {
    //!Administrator Template
    case UserType::Admin:
        t = "/" + Source + "/" + Admin + "/";
        break;
        //!User Template
    case UserType::User:
        t = "/" + Source + "/" + User + "/";
        break;
        //!Moderator Template
    case UserType::Moder:
        t = "/" + Source + "/" + Moder + "/";
        break;
        //!Guest Template
    case UserType::Guest:
        t = "/" + Source + "/" + User + "/";
        break;
    default:
        break;
    }
    return t;
}

std::string Template::font() const
{
    return "fonts";
}
std::string Template::css() const
{
    return "css";
}
std::string Template::script() const
{
    return "js";
}

LoadListTemplate::LoadListTemplate(const std::string &l, const std::string &p)
{
  //ToDo...
}

LoadListTemplate::~LoadListTemplate()
{
  //ToDo...
}

void LoadListTemplate::setTitle(const std::string& val)
{
    m_title = val;
}

void LoadListTemplate::setDescription(const std::string& val)
{
    m_description = val;
}

void LoadListTemplate::setSiteSeprator(const std::string& val)
{
    m_siteSeprator = val;
}

void LoadListTemplate::setFullSiteTitle(const std::string& val)
{
    m_fullSiteTitle = val;
}

std::optional<std::string> LoadListTemplate::title() const
{
    if (isset(m_title)) {
        return m_title;
    } else {
        return std::nullopt;
    }
}

std::optional<std::string> LoadListTemplate::description() const
{
    if (isset(m_description)) {
        return m_description;
    } else {
        return std::nullopt;
    }
}

std::optional<std::string> LoadListTemplate::siteSeprator() const
{
    if (isset(m_siteSeprator)) {
        return m_siteSeprator;
    } else {
        return std::nullopt;
    }
}

std::optional<std::string> LoadListTemplate::fullSiteTitle() const
{
    if (isset(m_fullSiteTitle)) {
        return m_fullSiteTitle;
    } else {
        return std::nullopt;
    }
}

TEGRA_NAMESPACE_END
