#include "MainFrame.hpp"
#include <vector>
#include <string>

#include <chrono>
#include <thread>

#include <random>

MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxString("Starke Verben lernen"), wxDefaultPosition, wxSize(500, 700)),
      m_DataProvider(L"starke_verben.csv")
{
    m_Sizer = new wxBoxSizer(wxVERTICAL);

    m_ButtonPanel = new ButtonPanel(this);
    m_TranslationPanel = new TranslationPanel(this);

    m_Sizer->Add(m_TranslationPanel, 1, wxEXPAND | wxALL, 5);
    m_Sizer->Add(m_ButtonPanel, 0, wxEXPAND | wxALL, 5);

    SetSizer(m_Sizer);

    MakeQuestion();

    Center(wxBOTH);
}

void MainFrame::NeedRefresh()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);

    MakeQuestion();
}

void MainFrame::MakeQuestion()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 3);
    const int answer_pos = distrib(gen);

    const auto entries = m_DataProvider.Get(4);
    std::wstring translation = entries[answer_pos].first;

    std::vector<std::wstring> verbs;
    for (const auto& entry : entries)
        verbs.push_back(entry.second);

    m_ButtonPanel->Refresh(verbs, answer_pos);
    m_TranslationPanel->SetText(translation);
}