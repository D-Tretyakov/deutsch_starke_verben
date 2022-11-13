#include "MainFrame.hpp"
#include <vector>
#include <string>

#include <chrono>
#include <thread>

#include <random>

MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxString("Starke Verben lernen"), wxDefaultPosition, wxSize(500, 700))
{
    m_Sizer = new wxBoxSizer(wxVERTICAL);

    m_ButtonPanel = new ButtonPanel(this);
    m_TranslationPanel = new TranslationPanel(this);

    m_Sizer->Add(m_TranslationPanel, 1, wxEXPAND | wxALL, 5);
    m_Sizer->Add(m_ButtonPanel, 0, wxEXPAND | wxALL, 5);

    SetSizer(m_Sizer);

    std::vector<std::wstring> words;
    words.push_back(L"слово 1");
    words.push_back(L"слово 2");
    words.push_back(L"слово 3");
    words.push_back(L"слово 4");
    m_ButtonPanel->Refresh(words, 2);

    Center(wxBOTH);
}

void MainFrame::NeedRefresh()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 3);

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);

    std::vector<std::wstring> words;
    words.push_back(L"слово 1");
    words.push_back(L"слово 2");
    words.push_back(L"слово 3");
    words.push_back(L"слово 4");
    m_ButtonPanel->Refresh(words, distrib(gen));
}