/*!
 * @file        plugin.hpp
 * @brief       This file is part of the Tegra CMS.
 * @details     Plugin interface for system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/cms/blob/main/LICENSE.md
 *
 */

#ifndef PLUGIN_ABSTRACT_HPP
#define PLUGIN_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The PluginType enum
 */
__tegra_enum_class PluginType : u8
{
    Index,      //!For global user service.
    Admin,      //!For administrator service.
    Root,       //!For root service.
    System,     //!For system service.
    Cron,       //!For cron job service.
    Core,       //!For cms core service.
    Theme,      //!For cms template.
    Default,    //!For default global service.
    Custom      //!For custom global service.
};

/*!
 * \brief The PermissionType enum
 */
__tegra_enum_class PermissionType
{
    ReadOnly,
    EditableOnly,
    Restricted,
    FullAccess,
    ByService
};

/*!
 * \brief The PluginInfo class
 */
struct PluginInfo __tegra_final
{
    Optional<u32>               codeName        {}; ///< A unique code for plugin.
    OptionalString              name            {}; ///< A name for plugin.
    OptionalString              description     {}; ///< A description for explanation plugin.
    OptionalString              compiledDate    {}; ///< Compiled date for plugin.
    Optional<SystemLicense>     license         {}; ///< License type for plugin.
    PluginType                  pluginType      {}; ///< The type of plugin.
    Optional<SemanticVersion>   version         {}; ///< Version of plugin.
    OptionalString              author          {}; ///< Author of plugin.
    OptionalString              url             {}; ///< Url of plugin.
};

/*!
 * \brief The AbstractBaseClass class
 */
class __tegra_export AbstractPlugin
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPlugin)

    /*!
     * \brief getCodeName function returns a unique code of plugin.
     * \returns a code as unique type.
     */
    __tegra_no_discard_virtual OptionalString getCodeName()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getName function returns name of plugin.
     * \returns a name as string.
     */
    __tegra_no_discard_virtual OptionalString getName()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getDescription function returns description of plugin.
     * \returns a description about plugin as string.
     */
    __tegra_no_discard_virtual OptionalString getDescription()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getCompiledDate function returns date of plugin's compile date.
     * \returns a name as string.
     */
    __tegra_no_discard_virtual OptionalString getCompiledDate()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getLicense function returns license of plugin.
     * \returns a license as SystemLicense.
     */
    __tegra_no_discard_virtual Optional<SystemLicense> getLicense()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getPluginType function returns type of plugin.
     * \returns a type as PluginType.
     */
    __tegra_no_discard_virtual Optional<PluginType> getPluginType()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getVersion function returns version of plugin.
     * \returns a version as SemanticVersion.
     */
    __tegra_no_discard_virtual Optional<SemanticVersion> getVersion()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getAuthor function returns author of plugin.
     * \returns a name as string.
     */
    __tegra_no_discard_virtual OptionalString getAuthor()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getUrl function returns url of plugin.
     * \returns a url as string.
     */
    __tegra_no_discard_virtual OptionalString getUrl()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief run is action function for plugins.
     */
    __tegra_virtual void run()  __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief runAsTemplate is action function for plugins based on template.
     * \param val is a parameter as multi type support.
     */
    template <typename... Args>
    auto runAsTemplate(const auto& val)
    {
        return val;
    }

protected:
    PluginInfo* m_pluginInfo;
    friend class AbstractPluginManager;
    void setCodeName(const Optional<u32>& codename);
    void setName(const OptionalString& name);
    void setDescription(const OptionalString& desc);
    void setCompiledDate(const OptionalString& compiledDate);
    void setLicense(const Optional<SystemLicense>& licese);
    void setPluginType(const PluginType pluginType);
    void setVersion(const Optional<SemanticVersion>& version);
    void setAuthor(const OptionalString& author);
    void setUrl(const OptionalString& url);

private:
    TEGRA_DISABLE_COPY(AbstractPlugin)
};

TEGRA_NAMESPACE_END

#endif  // PLUGIN_ABSTRACT_HPP
