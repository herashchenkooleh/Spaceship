#include "ssg/GameWindow.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window/WindowEnums.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/System/String.hpp"

namespace ssg
{
    struct GameWindow::Implementation
    {
        unsigned int m_Width;
        unsigned int m_Height;
        const char* m_Title;

        sf::RenderWindow m_HwWindow;

        Implementation(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle);
        ~Implementation();
    };

    GameWindow::Implementation::Implementation(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle)
        : m_Width(InWidth)
        , m_Height(InHeight)
        , m_Title(InTitle)
    {

        const auto HwWindowTitle = sf::String{ m_Title };
        const auto HWVideoMode = sf::VideoMode::getDesktopMode();
        m_HwWindow.create(HWVideoMode, HwWindowTitle, sf::Style::Default, sf::State::Fullscreen);
        m_HwWindow.setFramerateLimit(60.0f);
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

        bool IsAltF4Pressed = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LSystem)));
        if (HwEvent.is<sf::Event::Closed>() || IsAltF4Pressed)
        {
            Event.SetType(InputEvent::Type::Exit);
        }

        if (HwEvent.is<sf::Event::KeyPressed>())
        {
            Event.SetType(InputEvent::Type::KeyPressed);
            Event.SetKey(static_cast<InputEvent::Key>(HwEvent.getIf<sf::Event::KeyPressed>()->code));
        }

        if (HwEvent.is<sf::Event::KeyReleased>())
        {
            Event.SetType(InputEvent::Type::KeyReleased);
            Event.SetKey(static_cast<InputEvent::Key>(HwEvent.getIf<sf::Event::KeyReleased>()->code));
        }

        if (HwEvent.is<sf::Event::MouseMoved>())
        {
            sf::Vector2f WorldMousePosition = { (float)HwEvent.getIf<sf::Event::MouseMoved>()->position.x, (float)HwEvent.getIf<sf::Event::MouseMoved>()->position.y };
            Event.SetType(InputEvent::Type::MouseMove);
            Event.SetMousePosition({ WorldMousePosition.x, WorldMousePosition.y });
        }

        return Event;
    }

    void GameWindow::Close()
    {
        m_Implementation->m_HwWindow.close();
    }

    GameWindow::RenderTargetHandle GameWindow::GetRenderTarget() const
    {
        return reinterpret_cast<void*>(&m_Implementation->m_HwWindow);
    }

    Vector2D GameWindow::GetSize() const
    {
        decltype(auto) HWSize = m_Implementation->m_HwWindow.getSize();
        return Vector2D{ static_cast<float>(HWSize.x), static_cast<float>(HWSize.y) };
    }
}