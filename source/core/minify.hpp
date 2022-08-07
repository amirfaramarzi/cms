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

#ifndef MINIFY_HPP
#define MINIFY_HPP

#include "common.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra)

struct MinifyStruct final
{
    /** @var string Path to a directory on the server */
    std::string path{};

    /** @var string HTTP directory path */
    std::string http{};
};

/*!
 * \brief JS and CSS obfuscator minifier
 */
class Minify
{
public:
    Minify();
    Minify(const Minify& rhsMinify) = delete;
    Minify(Minify&& rhsMinify) noexcept = delete;
    Minify& operator=(const Minify& rhsMinify) = delete;
    Minify& operator=(Minify&& rhsMinify) noexcept = delete;
    ~Minify();

    /** Obfuscation css handler
     * @param array source Files to be compressed
     * @param string dest The file where you want to put the result
     */
    void cssGenerator(const std::vector<std::string>& source, const std::string& dest);

    /** Javascript obfuscator
     * @param string|array source Files to be compressed
     * @returns string Path to compressed file for HTTP access
     */

    std::string script(const std::vector<std::string>& source);

    /** Obfuscation js handler
     * @param array source Files to be compressed
     * @param string dest The file where you want to put the result
     */
    void scriptGenerator(const std::string& source, const std::string& dest);

    /** Create a cache for arbitrary files (compressed css, javascript, images, etc.)
     * @param string file Name of the file where the result will be stored
     * @param string|array List of source files for which fileMtime will be checked (last modification time of the file)
     * @param callback generator Cache generator, the method will receive 2 variables as input: source and the full path to the file where the result should be saved.
     * @returns string */
    void getFile(const std::string& file,const std::vector<std::string>& source, const std::string& generator);

    /** Generate a relative path to navigate from one directory to another
     * @param string a Path to the first directory
     * @param string b Path to second directory
     * @returns string For example: ../../aa/bb/cc
     */
    std::string shortPathTo(const std::string& a, const std::string& b);

private:
    MinifyStruct* m_minifyStruct;

};

TEGRA_NAMESPACE_END

#endif  // MINIFY_HPP
