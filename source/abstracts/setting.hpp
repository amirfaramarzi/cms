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

#ifndef SETTING_ABSTRACT_HPP
#define SETTING_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The ServiceType enum
 * \details Users and customers will have different options. For this purpose, it is necessary to have this structure.
 */
__tegra_enum_class ServiceType : u8
{
    Default       =   0x1,  ///< These types of options are available for all purposes and types of users.
    Customized    =   0x2,  ///< These types of options are only available for specific purposes or dedicated development.
    Premium       =   0x3   ///< These types of options are only available for premium users.
};

__tegra_enum_class Status : u8
{
    Disabled    =   0x0,  ///< Disabled.
    Hidden      =   0x1,  ///< Hidden.
    Active      =   0x2   ///< Active.
};

#if defined(ENABLE_SAFE_ONLY)
TEGRA_USING ValueType = std::variant<std::string, bool, s64, u64>;   ///<In this section we will cover data types for value of options.
#else
struct ValueType __tegra_final
{
    std::string AsString;           ///< String type.
    bool        AsBoolean;          ///< Boolean type.
    s64         AsSignedInteger;    ///< Integer with signed.
    u64         AsUnsignedInteger;  ///< Integer with unsigned.
};
#endif


/*!
 * \brief The SettingData class
 */
struct OptionData __tegra_final
{
    OptionalString      title      {};   ///< Title of setting option.
    OptionalString      descr      {};   ///< Description of setting option.
    Optional<ValueType> value      {};   ///< Value of setting option.
    OptionalJson        json       {};   ///< JSon of setting option.
    OptionalString      defaultVal {};   ///< Default value of setting option.
    OptionalString      extra      {};   ///< Extra value of setting option.
    Optional<Status>    status     {};   ///< Status value of setting option.
    OptionalNumeric     startGroup {};   ///< Group index value of option.
    ServiceType         service    {};   ///< Service type for option.
};

class __tegra_export AbstractSetting
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractSetting)

    /*!
     * \brief title is subject of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString title() __tegra_const = __tegra_zero;

    /*!
     * \brief descr is description of setting option.
     * \returns string.
     */
    __tegra_virtual OptionalString descr() __tegra_const = __tegra_zero;

    /*!
     * \brief value is content of option value.
     * \returns as ValueType.
     */
    __tegra_virtual Optional<ValueType> value() __tegra_const = __tegra_zero;

    /*!
     * \brief json is content based on json format.
     * \returns string.
     */
    __tegra_virtual OptionalString json() __tegra_const = __tegra_zero;

    /*!
     * \brief defaultVal will gets default value for option.
     * \returns string.
     */
    __tegra_virtual OptionalString defaultVal() __tegra_const = __tegra_zero;

    /*!
     * \brief extra will gets extra data from option.
     * \returns string.
     */
    __tegra_virtual OptionalString extra() __tegra_const = __tegra_zero;

    /*!
     * \brief status will gets status value from option.
     * \returns one of the Status.
     */
    __tegra_virtual Optional<Status> status() __tegra_const = __tegra_zero;

    /*!
     * \brief startGroup will gets index of group id.
     * \returns id as integer.
     */
    __tegra_virtual OptionalNumeric startGroup() __tegra_const = __tegra_zero;

    /*!
     * \brief It is necessary to receive a list of all the options in the settings in a part of the system.
     * \returns string of items list.
     */
    __tegra_virtual VectorString getByList() __tegra_const = __tegra_zero;

    /*!
     * \brief SetTitle inserts data for the option's title.
     * \param opt is a string type for inserting values into the function.
     */
    __tegra_virtual void setTitle(const std::string& opt) = __tegra_zero;

    /*!
     * \brief setDescr inserts data for the option's description.
     * \param opt is a string type for inserting values into the function.
     */
    __tegra_virtual void setDescr(const std::string& opt) = __tegra_zero;

    /*!
     * \brief setValue inserts data for the option's value.
     * \param opt is a ValueType for inserting values into the function.
     */
    __tegra_virtual void setValue(const ValueType& opt) = __tegra_zero;

    /*!
     * \brief setJson inserts data for the option's json.
     * \param opt is a json type for inserting values into the function.
     */
    __tegra_virtual void setJson(const JSon& opt) = __tegra_zero;

    /*!
     * \brief setDefaultValue inserts data for the option's default value.
     * \param opt is a string type for inserting values into the function.
     */
    __tegra_virtual void setDefaultValue(const std::string& opt) = __tegra_zero;

    /*!
     * \brief setStatus will change option's status.
     * \param opt is a Status type for change the option status.
     */
    __tegra_virtual void setStatus(const Optional<Status> opt) = __tegra_zero;

    /*!
     * \brief setStartGroup will sets option's group index.
     * \param index is number of group id.
     */
    __tegra_virtual void setStartGroup(const int index) = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractSetting)
};

TEGRA_NAMESPACE_END

#endif  // SETTING_ABSTRACT_HPP
