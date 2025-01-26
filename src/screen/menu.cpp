#include "menu.hpp"

ButtonInterface::ButtonInterface(std::string name, std::function<void ()> Callback): name(name),
                                                                                     Callback(Callback) {}

void Menu::SetRendering() {
    rendering = ftxui::Renderer(this->buttons, [&] {
            return ftxui::vbox({
                ftxui::text(name),
                ftxui::separator(),  
                this->buttons->Render() | ftxui::flex,
                }) |
                ftxui::flex | ftxui::border;
        });
}

ftxui::Component Menu::Rendering() {
    return rendering;
}

ftxui::ButtonOption DefaultStyle() {
    auto option = ftxui::ButtonOption::Animated();
    option.transform = [](const ftxui::EntryState& s) {
        auto element = ftxui::text(s.label);
        if (s.focused) {
            element |= ftxui::bold;
        }
        return element | ftxui::center | ftxui::borderEmpty | ftxui::flex;
    };
    return option;
}