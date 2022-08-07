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

#ifndef TEGRA_TRANSLATOR_HPP
#define TEGRA_TRANSLATOR_HPP

#include "dictionary.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE FileSystem  = std::filesystem;
TEGRA_USING     JSonPointer = std::unique_ptr<JSon>;

TEGRA_NAMESPACE_BEGIN(Tegra::Translation)

TEGRA_USING LSMap                 =   Map<std::string, Map<std::string, LanguageTemplate>>;
TEGRA_USING MForLanguageTemplate  =   Map<std::string, LanguageTemplate>;
TEGRA_USING LanguageList          =   std::vector<std::string>;
TEGRA_USING LanguageFile          =   std::vector<std::string>;
TEGRA_USING LanguageMap           =   Map<std::string, LSMap>;
TEGRA_USING LanguageSheet         =   Map<std::string, MForLanguageTemplate>;
TEGRA_USING LanguagePair          =   Pair<std::string, LanguageTemplate>;
TEGRA_USING LanguageTemp          =   Map<std::string, LanguageTemplate>;


class LanguageTemplate;

struct TranslatorStruct final
{
    bool           isRtl            {};
    LanguageFile   file             {};
    std::string    parseMessage     {};
    LanguageList   language         {};
    std::string    symbol           {};
    std::string    currency         {};
    std::string    callingCode      {};
    std::string    callingCodeByUri {};
    std::string    drivingSide      {};
    std::string    iso3166Code      {};
    std::string    internetTld      {};
};

class __tegra_export Translator
{
public:
    Translator();
    ~Translator();

    __tegra_no_discard bool init() __tegra_noexcept;

    __tegra_no_discard bool initExternal(const std::vector<std::string>& file) __tegra_noexcept;

    __tegra_static_constexpr auto translations = "translations";

    /** @var string System Language */
    __tegra_inline_static_constexpr std::string_view file = "en_US.json";

    /** @var string view of basic language */
    __tegra_inline_static std::string_view basicLang = {"en_US"};

    /*!
     * \brief existFile checks file.
     * \param file
     * \returns true if file exists.
     */
    __tegra_no_discard bool existFile(const std::string& file) __tegra_const_noexcept;

    /*!
     * \brief isMultiLanguage
     * \returns true if system supports multi language.
     */
    __tegra_no_discard bool isMultiLanguage() __tegra_const_noexcept;
    /*!
     * \brief isValid checks json file!
     * \returns true if json format is valid.
     */
    __tegra_no_discard bool isValid() __tegra_noexcept;

    /*!
     * \brief hasError checks any error from json structure.
     * \returns true if error exists.
     */
    __tegra_no_discard bool hasError() __tegra_const_noexcept;

    std::string defaultLanguage() __tegra_const_noexcept;

    /*!
     * \brief errorMessage
     * \return
     */
    __tegra_no_discard std::string errorMessage() __tegra_const_noexcept;

    /*!
     * \brief Language::hasString checks for the existence of [shee][lang][key].
     * \param sheet name of your selected sheet.
     * \param lang code of the language structure. e.g: en_US, or fa_IR.
     * \param key word_key of the `myword` structure. e.g: error, warning.
     * \returns true value if correct.
     */
    __tegra_no_discard bool hasString(const std::string& lang,
                                      const std::string& sheet,
                                      const std::string& key) __tegra_const_noexcept;
    /*!
     * \brief list gets all language name.
     * \returns list of language by name.
     */
    __tegra_no_discard LanguageList list() __tegra_noexcept;

    /*!
     * \brief listByCode
     * \return
     */
    __tegra_no_discard LanguageList listByCode() __tegra_noexcept;

    /*!
     * \brief isRtl
     * \return
     */
    __tegra_no_discard bool isRtl(const std::string& code) __tegra_noexcept;

    /*!
     * \brief symbol
     * \param code
     * \return
     */
    __tegra_no_discard std::string symbol(const std::string& code) __tegra_noexcept;

    /*!
     * \brief currency
     * \param code
     * \return
     */
    __tegra_no_discard std::string currency(const std::string& code) __tegra_noexcept;

    /*!
     * \brief callingCode
     * \param code
     * \return
     */
    __tegra_no_discard std::string callingCode(const std::string& code) __tegra_noexcept;

    /*!
     * \brief callingCodeByUri
     * \param code
     * \return
     */
    __tegra_no_discard std::string callingCodeByUri(const std::string& code) __tegra_noexcept;

    /*!
     * \brief drivingSide
     * \param code
     * \return
     */
    __tegra_no_discard std::string drivingSide(const std::string& code) __tegra_noexcept;

    /*!
     * \brief iso3166Code
     * \param code
     * \return
     */
    __tegra_no_discard std::string iso3166Code(const std::string& code) __tegra_noexcept;

    /*!
     * \brief internetTld
     * \param code
     * \return
     */
    __tegra_no_discard std::string internetTld(const std::string& code) __tegra_noexcept;

    /*!
     * \brief listByTitle gets all language by native name.
     * \returns title by native name as string.
     */
    __tegra_no_discard LanguageList listByTitle() __tegra_noexcept;

    /*!
     * \brief getFile function contains the filename and path.
     * \returns string for filename.
     */
    __tegra_no_discard LanguageFile getFile() __tegra_const_noexcept;

    /*!
     * \brief setFile function sets file to parsing.
     * \param file as string path and name.
     */
    void setFile(const LanguageFile& file) __tegra_noexcept;

    /*!
     * \brief wordProcess function process the parsing of words inside json file
     * structure.
     */
    void wordProcess() noexcept;

    /*!
     * \brief parse function will parse the JSON file.
     */
    __tegra_no_discard bool parse() __tegra_noexcept;

    /*!
     * \brief parseExternal function is suitable for external device structure such as mobile android and ios storage.
     * \param data gets data list.
     * \return as bool.
     */
    __tegra_no_discard bool parseExternal(const std::vector<std::string>& data) __tegra_noexcept;

    /*!
     * \brief parseMessage function prints message of parsing status.
     */
    void parseMessage() noexcept;

    /*!
     * \brief translate function will translate data based on selected sheet, key and language.
     * \param lang is data based on language file.
     * \param sheet is sheet name.
     * \param key is sheet key.
     * \return as translated data.
     */
    __tegra_no_discard LanguageTemplate translate(
        const std::string& lang,
        const std::string& sheet,
        const std::string& key
        );


    /*!
     * \brief data function will gets all language data from one sheet.
     * \param sheet is sheet name.
     * \return collection of one sheet.
     */
    __tegra_no_discard DictonaryType data(const std::string& sheet) __tegra_noexcept;

protected:
    JSonPointer       jsonParser; //JSon Parser

    LanguageList      m_list;
    LanguageList      m_list_title;
    bool              m_multi_language = {true};
    bool              m_hasError;
    std::string       m_errorMessage = {"Unknown"};
    DicType           m_data;
    LanguageMap       wordMap;
    LanguageTemplate  m_template;
    std::string       m_defaultLanguage;

private:
    TranslatorStruct* m_translatorStruct;

};

TEGRA_NAMESPACE_END

#endif // TEGRA_TRANSLATOR_HPP
