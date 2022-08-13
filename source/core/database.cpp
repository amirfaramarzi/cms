#include "database.hpp"
#include "core/core.hpp"
#include "core/config.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;

TEGRA_NAMESPACE_BEGIN(Tegra::Database)

Manager::Manager(const StructManager& structManager)
{
    m_structManager = new StructManager(structManager);
    setTypes(m_structManager->types);
    setDb(m_structManager->database);
}

Manager::~Manager()
{
    __tegra_safe_delete(m_structManager);
}

void Manager::setTypes(Database::DriverTypes type)
{
    m_structManager->types = type;
}

Database::DriverTypes Manager::types()
{
    return m_structManager->types;
}

std::string getRdbmsType()
{
  //ToDo...
}

DatabaseList Manager::db() const
{
    return m_structManager->database;
}

void Manager::setUsername(const std::string& username)
{
    if(!username.empty()) m_structManager->username = username;
}

std::optional<std::string> Manager::username() const
{
    if (!m_structManager->username.empty()) {
        return m_structManager->username;
    } else {
        return std::nullopt;
    }
}

void Manager::setPassword(const std::string& pass)
{
    if(!m_structManager->passworod.empty()) m_structManager->passworod = pass;
}

std::optional<std::string> Manager::password() const
{
    if (!m_structManager->passworod.empty()) {
        return m_structManager->passworod;
    } else {
        return std::nullopt;
    }
}

void Manager::setDb(const std::vector<std::string>& db)
{
    if(!m_structManager->database.empty()) m_structManager->database = db;
}

void Manager::setPath(const std::string& path)
{
    if(!m_structManager->path.empty()) m_structManager->path = path;
}

std::optional<std::string> Manager::path() const
{
    if (!m_structManager->path.empty()) {
        return m_structManager->path;
    } else {
        return std::nullopt;
    }
}

void Manager::createDatabase()
{


}

void Manager::removeDatabase()
{

}

void Manager::backupDatabase(Database::DriverTypes type, const DatabaseList& db, const std::string& path, const std::string& u)
{

}

void Manager::createTables(Database::DriverTypes type)
{

}

void Manager::removeTables(Database::DriverTypes type)
{

}

void Manager::insertTables(Database::DriverTypes type)
{

}

void Manager::resetAllTables(Database::DriverTypes type)
{


}

void Manager::resetTable(Database::DriverTypes type, const std::string& tableName)
{

}

const TableList& Manager::tables() const
{
    return m_structManager->tables;
}

void Manager::setTables(const TableList& newTables)
{
    m_structManager->tables = newTables;
}

void Connection::connect()
{
    std::string rdbms{}, dbName{}, dbUsername{}, dbPassword{}, dbCharset{}, dbHost{}, tablePrefix{};

    std::vector<std::string> driverType{};

    unsigned int dbPort{__tegra_zero};

    Scope<Configuration> config(new Configuration(ConfigType::File));
    config->init(SectionType::SystemCore);

    auto getConf = Configuration::GET["database"];

    for(const auto& c : getConf) {

        if(isset(BOOLCOMBINER(c,"status"))) {

            driverType.push_back(STRCOMBINER(c, "rdbms"));

            for(const auto& d : driverType) {
                rdbms = d;
            }

            dbHost          =   STRCOMBINER(c, "host");
            dbName          =   STRCOMBINER(c, "name");
            dbUsername      =   STRCOMBINER(c, "username");
            dbPassword      =   STRCOMBINER(c, "password");
            dbPort          =   INTCOMBINER(c, "port");
        }
    }

    try {
        APPLICATION_DB_RUN(rdbms, dbHost, dbPort, dbName, dbUsername, dbPassword);
    }
    catch (const SqlException& e)
    {
        if(DeveloperMode::IsEnable) {
            eLogger::Log("Database Error: " + FROM_TEGRA_STRING(e.base().what()), eLogger::LoggerType::Critical);
        }
    }
}

bool Connection::isConnected() __tegra_noexcept
{
    bool res {false};
    auto dbc = AppFramework::application().getDbClient();
    if (isset(dbc->hasAvailableConnections()) && true)
    {
        if(DeveloperMode::IsEnable)
            eLogger::Log("Database Connected!", eLogger::LoggerType::Info);
        res = true;
    } else {
        if(DeveloperMode::IsEnable)
            eLogger::Log("Database Connection Error: " + FROM_TEGRA_STRING("There is a problem connecting to the database, please check your settings!"), eLogger::LoggerType::Critical);
        res = false;
    }
    return res;
}


TEGRA_NAMESPACE_END
