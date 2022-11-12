cmake_minimum_required(VERSION 3.24.1)

project(StarkeVerben)

set(wxWidgets_DIR "../modulation_sim/wxWidget/wx_install/lib/cmake/wxWidgets")
find_package(wxWidgets 3.2 COMPONENTS core base REQUIRED CONFIG)

# Include the wxWidgets use file to initialize various settings
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

include_directories("GUI")

set(GUI_SOURCES
    GUI/ButtonPanel/ChoiceButton/ChoiceButton.cpp
    GUI/ButtonPanel/ButtonPanel.cpp
    GUI/TranslationPanel/TranslationPanel.cpp
    GUI/MainFrame.cpp
)

set(SRC_FILES
    ${GUI_SOURCES}
    main.cpp
)

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
# Set Windows resources file
if(WIN32)
    set(wxWidgets_RC "../modulation_sim/wxWidget/wx_install/include/wx/msw/wx.rc")
    target_sources(${PROJECT_NAME} PRIVATE ${wxWidgets_RC})
endif()