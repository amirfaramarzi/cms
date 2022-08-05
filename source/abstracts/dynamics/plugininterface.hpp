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

#ifndef PLUGIN_INTERFACE_ABSTRACT_HPP
#define PLUGIN_INTERFACE_ABSTRACT_HPP

#include "common.hpp"
#include "plugin.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

using NameList      =   std::vector<std::string>;
using PluginList    =   std::vector<PluginInfo>;
using ErrorString   =   std::vector<std::string>;

/*!
 * \brief The PluginInterfaceData class
 */
struct PluginInterfaceData final
{
public:
    NameList    nameList    {};     ///< List of plugins name.
    PluginList  pluginList  {};     ///< List of plugins by info.
    ErrorString errors      {};     ///< List of errors.
};

class __tegra_export AbstractPluginInterface
{
public:
    //Return a static instance of this class
    static AbstractPluginInterface& instance();

    /*!
     * \brief addDetail function sets all information of plugins.
     * \param plist is type of PluginList [std::vector<PluginDetail>]
     */
    __tegra_virtual void addDetail(const PluginList& plist) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief addName function sets name of plugins.
     * \param name of plugin.
     */
    __tegra_virtual void addName(const std::string& name) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief setError function sets message of error inside plugins.
     * \param var is message of error.
     */
    __tegra_virtual void setError(const std::string& var) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getDetail function gets detail from plugins.
     * \returns list of detail such as name, version and etc.
     */
    __tegra_no_discard_virtual const PluginList& getDetail() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getNames function gets name of plugins.
     * \returns list of plugin.
     */
    __tegra_no_discard_virtual const NameList& getNames() __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief getErrors function gets list of errors.
     * \returns list of errors as string [ErrorString : std::vector<std::string>].
     */
    __tegra_no_discard_virtual const ErrorString& getErrors() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPluginInterface)
    PluginInterfaceData*  m_pluginInterfaceData;
};


TEGRA_NAMESPACE_END

#endif  // PLUGIN_INTERFACE_ABSTRACT_HPP
