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

#ifndef PLUGIN_MANAGER_ABSTRACT_HPP
#define PLUGIN_MANAGER_ABSTRACT_HPP

#include "common.hpp"
#include "plugin.hpp"
#include "plugininterface.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

// Define the prototype for a function that should exist in the lib
// that is used to create and return the plugin type in the lib.

TEGRA_POINTER_TO_AN_OBJECT(AbstractPlugin, fnCreatePlugin)

// Destroys the plugin type from the lib before the library is unloaded.
using fnDestroyPlugin = TEGRA_POINTER_TO_A_FUNCTION;

using PluginMap  =  std::map<std::string, AbstractPlugin*>;

using LibraryMap =  std::map<std::string, void*>;

/*!
 * \brief The PluginManagerData class
 */
class PluginManagerData final
{
public:
    PluginMap   plugins {};
    LibraryMap  libs    {};
};

/*!
 * \brief The AbstractPluginManager class
 */
class __tegra_export AbstractPluginManager
{
public:
    static AbstractPluginManager& instance();

    /*!
     * \brief load function loads the plugin and returns true if the plugin was loaded successfully; otherwise returns false.
     * \param plugin is plugin name.
     * \returns plugin.
     */
    __tegra_no_discard_virtual AbstractPlugin* load(const std::string& plugin) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief unload function unloads the plugin and returns true if the plugin could be unloaded; otherwise returns false.
     * \param plugin
     */
    __tegra_virtual void unload(AbstractPlugin*& plugin) __tegra_const_noexcept = __tegra_zero;

    /*!
     * \brief isLoaded function returns true if the plugin is loaded; otherwise returns false.
     * \return bolean of status.
     */
    __tegra_no_discard_virtual bool isLoaded() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPluginManager)
    PluginManagerData* m_pluginManagerData;
    bool m_status = {false};
};

TEGRA_NAMESPACE_END

#endif  // PLUGIN_MANAGER_ABSTRACT_HPP
