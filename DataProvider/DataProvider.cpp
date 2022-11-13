#include "DataProvider.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <codecvt>

namespace
{
    std::wstring ExtractTranslation(std::vector<std::wstring>& words)
    {
        std::wstring translation;
        if (words.size() == 5)
        {
            translation = words.back();
            words.pop_back();
        }
        else
        {
            auto last = words.rbegin();
            translation = *(last + 1) + L"," + *last;
            translation = translation.substr(1, translation.size() - 2);
            words.pop_back();
            words.pop_back();
        }
        return translation;
    }
}

DataProvider::DataProvider(std::wstring file_path)
    : m_FilePath(file_path)
{
    Load();
}

void DataProvider::Load()
{
    std::wifstream file(m_FilePath.c_str());

    if (!file.is_open())
        throw std::runtime_error("Could not open file!");

    file.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

    std::wstring line;
    while (std::getline(file, line))
    {
        std::wistringstream iss(line);

        std::vector<std::wstring> verb_forms;

        std::wstring word;
        while (std::getline(iss, word, L','))
            verb_forms.push_back(word);

        std::wstring translation = ExtractTranslation(verb_forms);

        std::wostringstream joined_verbs;
        //exclude second verb form as unimportant
        joined_verbs << verb_forms[0] << ", " << verb_forms[2] << ", " << verb_forms[3];

        m_Data.push_back(
            {translation, joined_verbs.str()}
        );
    }

}

DataProvider::Entries DataProvider::Get(int num)
{
    DataProvider::Entries result;
    
    std::sample(
        m_Data.begin(),
        m_Data.end(),
        std::back_inserter(result),
        num,
        std::mt19937{std::random_device{}()}
    );

    return result;
}