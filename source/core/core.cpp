#include "core.hpp"
#include "logger.hpp"

TEGRA_USING_NAMESPACE Tegra::eLogger;

TEGRA_NAMESPACE_BEGIN(Tegra::CMS)

Exception::Exception(const Reason& reason, const std::string& message)
{
    m_exceptionData = new ExceptionData();
    std::string eMessage{};
    switch (reason) {
    case Reason::Core:
        eMessage=":[Core]:";
        break;
    case Reason::Framework:
        eMessage=":[Framework]:";
        break;
    case Reason::IO:
        eMessage=":[IO]:";
        break;
    case Reason::User:
        eMessage=":[User]:";
        break;
    case Reason::System:
        eMessage=":[System]:";
        break;
    case Reason::Other:
        eMessage=":[Other]:";
        break;
    default:
        break;
    }
    m_exceptionData->message = message;
}

Exception::~Exception()
{
    if(m_exceptionData != nullptr) {
        delete m_exceptionData;
    }
    m_exceptionData = nullptr;
};

const char* Exception::what() const throw()
{
    return m_exceptionData->message.c_str();
}

void Termination::terminate(TerminateType terminateType)
{
    switch (terminateType) {
    case TerminateType::Unknown:
        std::abort();
        Log("The system has been terminated for [Unknown] reason!", LoggerType::Info);
        ///ToDo for more details...
        break;
    case TerminateType::UnexpectedError:
        Log("The system has been terminated for [UnexpectedError] reason!", LoggerType::Info);
        std::abort();
        ///ToDo for more details...
        break;
    case TerminateType::Violation:
        Log("The system has been terminated for [Violation] reason!", LoggerType::Info);
        std::abort();
        ///ToDo for more details...
        break;
    default:
        break;
    }
}

std::string Engine::copyright() __tegra_noexcept
{
#if defined(TEGRA_COPYRIGHT)
    return TEGRA_COPYRIGHT;
#else
  // TODO... add output for html template.
    Termination t;
    t.terminate(TerminateType::Violation);
#endif
}

std::string command(const std::string& cmd) {
    // Support Unix base.
    std::string c = cmd;
    std::string data;
    FILE *stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    c.append(" 2>&1");
#ifdef PLATFORM_WINDOWS
    stream = _popen(c.c_str(), "r");
#else
    stream = popen(c.c_str(), "r");
#endif
    if (stream)
    {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != nullptr)
                data.append(buffer);
#ifdef PLATFORM_WINDOWS
        _pclose(stream);
#else
        pclose(stream);
#endif
    }
    return data;
}

std::string convertStream(std::stringstream const& data) __tegra_noexcept
{
  //ToDo...
}

std::string Engine::htmlEntityDecode(const std::string& content)
{
  //ToDo...
}

bool Engine::findSubString(const std::vector<std::string>& list, const std::string& search)
{
  //ToDo...
}

void Engine::findAndReplaceContent(std::string& data, std::string toSearch, std::string replaceStr)
{
  //ToDo...
}

void Engine::findAndReplaceLink(std::string& data, std::string toSearch, std::string replaceUrl)
{
  //ToDo...
}

std::string Engine::linkConvertor(const std::string& uri)
{
  //ToDo...
}

std::vector<std::string> Engine::filteredQueryFields(VectorString& fields)
{
  //ToDo...
}

std::string Engine::tablePrefix()
{
  //ToDo...
}

std::string Engine::tableUnicode()
{
  //ToDo...
}

std::string Engine::mixedTablePrefix(const std::string& p, const std::string& t)
{
  //ToDo...
}

std::string Engine::table(std::string_view tableName, TableType tableType)
{
  //ToDo...
}

VectorString Engine::tableFilter(const std::vector<std::string>& tables, TableType tableType)
{
  //ToDo...
}

std::string Engine::fullReplacer(const std::string& content, const MapString& map)
{
    std::string rawContent = content;
    // Get the first occurrence
    size_t pos;
    for(const auto& r : map) {
        pos = rawContent.find(r.first);
        // Repeat till end is reached
        while( pos != std::string::npos)
        {
            // Replace this occurrence of Sub String
            rawContent.replace(pos, r.first.size(), r.second);
            // Get the next occurrence from the current position
            pos = rawContent.find(r.first, pos + r.first.size());
        }
    }
    return rawContent;
}

void Engine::setLanguage(const std::string& l)
{
  //ToDo...
}

std::string Engine::getLanguage()
{
  //ToDo...
}

std::map <std::string, std::string> Engine::langs()
{
  //ToDo...
}

std::map <std::string, std::string> Engine::langsByPath(const std::string& path)
{
  //ToDo...
}

std::string Engine::reducePath(const std::string& path)
{
  //ToDo...
}

std::string Engine::removeDashes(const std::string& src) __tegra_const_noexcept {
    std::string command = src;
    command.erase(std::remove(command.begin(), command.end(), '/'), command.end());
    return command;
}

bool Engine::initialize() __tegra_const_noexcept
{
  //ToDo...
}

std::string Engine::defaultLanguage()
{
  //ToDo...
}

std::string Engine::join(const std::vector<std::string>& strings,  const SepratorType& sep, const SepratorStyle& sepStyle) __tegra_noexcept
{
    std::string delim{__tegra_null_str};
    switch (sep) {
    case SepratorType::Comma:
        delim=",";
        break;
    case SepratorType::Dash:
        delim="-";
        break;
    case SepratorType::Slash:
        delim="/";
        break;
    case SepratorType::BackSlash:
        delim="\\";
        break;
    case SepratorType::Dot:
        delim=".";
        break;
    case SepratorType::Equal:
        delim="=";
        break;
    case SepratorType::Quote:
        delim="'";
        break;
    case SepratorType::Apostrophe:
        delim="'";
        break;
    case SepratorType::Grave:
        delim="`";
        break;
    case SepratorType::DoubleQuote:
        delim="\"";
        break;
    case SepratorType::Colon:
        delim=":";
        break;
    case SepratorType::SemiColon:
        delim=";";
        break;
    case SepratorType::Brvbar:
        delim="¦";
            break;
    case SepratorType::Lt:
        delim="<";
        break;
    case SepratorType::Gt:
        delim=">";
        break;
    case SepratorType::Percent:
        delim="%";
        break;
    case SepratorType::And:
        delim="&";
        break;
    case SepratorType::Sharp:
        delim="#";
        break;
    case SepratorType::Dollar:
        delim="$";
        break;
    case SepratorType::Atsign:
        delim="@";
        break;
    case SepratorType::Sim:
        delim="~";
        break;
    case SepratorType::Question:
        delim="?";
        break;
    case SepratorType::Exclamation:
        delim="!";
        break;
    case SepratorType::Hat:
        delim="^";
        break;
    case SepratorType::LeftCurlyBracket:
        delim="[";
        break;
    case SepratorType::RightCurlyBracket:
        delim="]";
        break;
    case SepratorType::LeftSquareBracket:
        delim="{";
        break;
    case SepratorType::RightSquareBracket:
        delim="}";
        break;
    case SepratorType::LeftRoundBracket:
        delim="(";
        break;
    case SepratorType::RightRoundBracket:
        delim=")";
        break;
    default:
        delim=",";
        break;
    }

    switch (sepStyle) {
    case SepratorStyle::WithSpace:
        delim.append(" ");
        break;
    case SepratorStyle::Mixed:
        delim.append("");
        break;
    default:
        break;
    }

    const auto res = std::accumulate(
        strings.begin(), strings.end(),
        std::string(),[&delim, sepStyle](const std::string& x, const std::string& y)
        {
            return x.empty() ? y : x + delim + y;
        });

    return res;
}

void Engine::elementErase(std::string& content) noexcept
{
    try {
        std::erase_if(content, [](const char c) {
            return c == '`' or c == '/' or c =='\\' or c == '~' or c == '?'
                   or c == '|' or c == '(' or c == ')' or c == '[' or c == ']'
                   or c == '{' or c == '}' or c == '-';
        });
    }
    catch(const Exception& e) {
        if(DeveloperMode::IsEnable) {
            Log(FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
        }
    }
}

std::string Engine::whiteSpaceReduce(std::string& input) noexcept
{
    try {
        if(!input.empty()) {
            input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        }
    }
    catch(const Exception& e) {
        if(DeveloperMode::IsEnable) {
            Log(FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
        }
    }
    return input;
}

std::string Engine::whiteSpaceLeading(std::string& input) noexcept
{
    try {
        if(!input.empty()) {
            while (std::isspace(*input.begin())) {
                input.erase(input.begin());
            }
        }
    }
    catch(const Exception& e) {
        if(DeveloperMode::IsEnable) {
            Log(FROM_TEGRA_STRING(e.what()), eLogger::LoggerType::Critical);
        }
    }
    return input;
}


TEGRA_NAMESPACE_END
