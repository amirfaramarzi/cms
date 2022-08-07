/*!
 * MIT License
 *
 * Copyright (c) 2022 The Genyleap. All rights reserved.
 * Copyright (c) 2022 Kambiz Asadzadeh.
 *
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

#ifndef HTML_HPP
#define HTML_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::CMS)

/*!
 * \class Html
 * \brief Primitives html library
 */
class Html
{
public:
    Html() = default;
    ~Html() = default;

    /*!
     * \brief Processing a string to safely use it as a tag parameter value
     * \param string s => Data
     * \param int mode => Mode of operations:
     * - 0 The text is run through htmlspecialchars, so we edit the string in
     * the form in which we received it.
     * - 1 The text is removed first through htmlspecialchars_decode, and then
     * through htmlspecialchars.
     * - 2 In the text, only <and> are replaced by&  lt; and&  gt; respectively.
     * - 3 Edit HTML viewed by the user.
     * \param string ch => Encoding
     * \return string
     */
    __tegra_no_discard static std::string ParamValue(const std::string& s, ss8 mode,
                                                     const std::string& ch) __tegra_noexcept_expr(true);

    /*!
     * \brief Converting an associative array to tag parameters
     * \param array a Collection array with parameters parameter name =>
     * parameter value \return string
     */
    __tegra_no_discard static std::string TagParams(const std::vector<std::string>& a) __tegra_noexcept_expr(true);

    /*!
     * \brief Easily realign text to components with text alignment classes.
     * \param array a Collection array with parameters parameter name =>
     * parameter value \return string
     */
    __tegra_no_discard static std::string Label(const std::string& value,
                                                const std::vector<std::string>& extra) __tegra_noexcept_expr(true);

    /*!
     * \brief Easily realign text to components with text alignment classes.
     * \param array a Collection array with parameters parameter name =>
     * parameter value \return string
     */
    __tegra_no_discard static std::string Text(const std::string& name,
                                               const std::string& value,
                                               const std::vector<std::string>& extra) __tegra_noexcept_expr(true);

    /*!
     * \brief Generation <input> type defaults to text
     * \param string name => Name
     * \param string | ss8 | null value => Value.
     * \param std::vector extra => Collection array of additional parameters
     * \param ss8 mode => Value output method, details are described in the
     * ParamValue method \return string
     */
    __tegra_no_discard static std::string Input(const std::string& name,
                                                const std::string& title,
                                                const std::string& description,
                                                const std::string& value,
                                                const std::vector<std::string>& extra, ss8 mode) __tegra_noexcept_expr(true);

    /*!
     * \brief Generation <textarea> type defaults to rich text
     * \param string name => Name
     * \param string | ss8 | null value => Value.
     * \param std::vector extra => Collection array of additional parameters
     * \param ss8 mode => Value output method, details are described in the
     * ParamValue method \return string
     */
    __tegra_no_discard static std::string TextArea(const std::string& name,
                                                   const std::string& value,
                                                   const std::vector<std::string>& extra, ss8 mode) __tegra_noexcept_expr(true);

    /*!
     * \brief Generation <checkbox> type for select status.
     * \param string name => Name
     * \param bool checked => flag.
     * \param std::vector extra => Collection array of additional parameters
     * \return string
     */
    __tegra_no_discard static std::string Check(const std::string& name, bool checked,
                                                const std::string& text,
                                                const std::vector<std::string>&  extra) __tegra_noexcept_expr(true);

    /*!
     * \brief Generation Buttons type.
     * \param string value The inscription on the button (value)
     * \param string type Button type: submit, button, reset
     * \param std::vector extra => Collection array of additional parameters
     * \param ss8 mode Value output method, details are described in the
     * ParamValue method. \return string
     */
    __tegra_no_discard static std::string Button(const std::string& name,
                                                 const std::string& value, std::string type,
                                                 const std::string& text,
                                                 const std::vector<std::string>&  extra) __tegra_noexcept_expr(true);

    /*!
     * \brief Generation of <input type = "radio"/>
     * \param string | false name => Name
     * \param string value | ss8 value
     * \param bool checked | flag
     * \param std::vector extra => Collection array of additional parameters
     * \param ss8 mode Value output method, details are described in the
     * ParamValue method. \return string
     */
    __tegra_no_discard static std::string Radio(const std::string& name,
                                                const std::string& value, bool checked,
                                                const std::string& text,
                                                const std::vector<std::string>&  extra) __tegra_noexcept_expr(true);

    /*!
     * \brief Generate <option> for Select
     * \param string name => Name select
     * \param string options List of options
     * \param bool selected Checked Flag
     * \param std::vector extra => Collection array of additional parameters
     * \param ss8 mode Value output method , details are described in the ParamValue method
     * \return string
     */
    __tegra_no_discard static std::string Option(const std::string& view,
                                                 const std::string& value, bool selected,
                                                 const std::string& name,
                                                 const std::vector<std::string>&  extra, ss8 mode) __tegra_noexcept_expr(true);

    /*!
     * \brief Single select <select> generation
     * \param string name => Name select
     * \param string options List of options
     * \param bool checked | flag
     * \param std::vector extra => Collection array of additional parameters
     * \return string
     */
    __tegra_no_discard static std::string Select(const std::string& name,
                                                 const std::vector<std::string>&  options,
                                                 const std::vector<std::string>&  extra) __tegra_noexcept_expr(true);


    __tegra_no_discard static std::string Switch(const std::string& name,
                                                 const std::string& title,
                                                 const std::string& description,
                                                 const std::vector<std::string>&  options,
                                                 const std::vector<std::string>&  extra) __tegra_noexcept_expr(true);


    __tegra_no_discard static std::string Card(const std::string& name,
                                               const std::string& title,
                                               const std::vector<std::string>& options,
                                               const std::vector<std::string>& extra,
                                               const std::vector<std::string>& item) __tegra_noexcept_expr(true);

    __tegra_no_discard static std::string Table(const std::string& name,
                                                const std::string& title,
                                                const std::vector<std::string>& options,
                                                const std::vector<std::string>& extra,
                                                const std::vector<std::string>& header,
                                                const std::vector<std::string>& item) __tegra_noexcept_expr(true);

};

TEGRA_NAMESPACE_END

#endif // HTML_HPP
