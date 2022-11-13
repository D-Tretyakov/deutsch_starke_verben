#include <string>
#include <utility>
#include <vector>

class DataProvider
{
    using Entry = std::pair<std::wstring, std::wstring>;
    using Entries = std::vector<Entry>;

public:
    DataProvider(std::wstring file_path);
    Entries Get(int num);

private:
    void Load();

    std::wstring m_FilePath;
    Entries m_Data;
};