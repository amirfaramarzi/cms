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

#ifndef SETTING_HPP
#define SETTING_HPP

#include "common.hpp"
#include "core/core.hpp"

TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Interface)

/*!
 * \brief The SettingData class
 */
struct InterfaceData final
{
    OptionalString title      {};
    OptionalString descr      {};
    OptionalString value      {};
    OptionalString json       {};
    OptionalString defaultVal {};
    OptionalString extra      {};
};

class SettingInterface
{
public:
    SettingInterface(const OptionalString& title,
                     const OptionalString& descr,
                     const OptionalString& value,
                     const OptionalString& json,
                     const OptionalString& defaultVal,
                     const OptionalString& extra);
    SettingInterface();
    ~SettingInterface();

    /*!
     * \brief title is subject of setting option.
     * \returns string.
     */
    OptionalString title();

    /*!
     * \brief descr is description of setting option.
     * \returns string.
     */
    OptionalString descr();

    /*!
     * \brief value is content of option value.
     * \returns string.
     */
    OptionalString value();

    /*!
     * \brief json is content based on json format.
     * \returns string.
     */
    OptionalString json();

    /*!
     * \brief defaultVal will gets default value for option.
     * \returns string.
     */
    OptionalString defaultVal();

    /*!
     * \brief extra will gets extra data from option.
     * \returns string.
     */
    OptionalString extra();

    void setTitle(const std::string& val);
    void setDescr(const std::string& val);
    void setValue(const std::string& val);
    void setJson(const std::string& val);
    void setDefaultVal(const std::string& val);
    void setExtra(const std::string& val);

private:
    InterfaceData* m_interfaceData;
};

struct SettingData final
{
    Scope<Engine>  engine   {};
    VectorString   option   {};
    SettingType    type     {};
    std::string    language {};
};

class Setting
{
public:
    Setting();
    ~Setting();

    std::string getOption(const std::string& var);

    /*!
     * \brief getList function will returns list of setting items.
     * \returns list
     */
    __tegra_no_discard SettingType getList() __tegra_const_noexcept;

    /*!
     * \brief option function gets item as option.
     * \returns list of options.
     */
    VectorString option() const;

    /*!
     * \brief setOption function will sets value into option.
     * \param val as list of string.
     */
    void setOption(const VectorString& val);

    /*!
     * \brief saveList function will sets all data inside the list of setting. Any website changes effects on the list data.
     */
    void saveList() __tegra_const_noexcept;

private:
    SettingData* m_settingData;
};

TEGRA_NAMESPACE_END

#endif  // SETTING_HPP
