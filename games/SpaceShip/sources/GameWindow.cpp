#include "GameWindow.hpp"
#include "SFML/Window/Window.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/System/String.hpp"

namespace SpaceShipGame
{
    struct GameWindow::Implementation
    {
        unsigned int m_Width;
        unsigned int m_Height;
        const char* m_Title;

        sf::Window m_HwWindow;

        Implementation(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle);
        ~Implementation();
    };

    GameWindow::Implementation::Implementation(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle)
        : m_Width(InWidth)
        , m_Height(InHeight)
        , m_Title(InTitle)
    {

        const auto HwWindowTitle = sf::String{ m_Title };
        const auto HWVideoMode = sf::VideoMode{ sf::Vector2u{ m_Width, m_Height } };
        m_HwWindow.create(HWVideoMode, HwWindowTitle);
    }

    GameWindow::Implementation::~Implementation() = default;

    GameWindow::GameWindow()
        : m_Implementation(nullptr)
    {

    }

    GameWindow::~GameWindow() = default;

    bool GameWindow::Create(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle)
    {
        if (m_Implementation)
        {
            return true;
        }
        
        try
        {
            m_Implementation = MakeShared<Implementation>(InWidth, InHeight, InTitle);
        }
        catch(...)
        {
            return false;
        }
        
        return true;
    }

    InputEvent GameWindow::PollEvent()
    {
        InputEvent Event;

        sf::Event HwEvent = m_Implementation->m_HwWindow.pollEvent();

        if (HwEvent.is<sf::Event::Closed>())
        {
            Event.SetType(InputEvent::Type::Exit);
        }

        return Event;
    }

    void GameWindow::Close()
    {
        m_Implementation->m_HwWindow.close();
    }
}