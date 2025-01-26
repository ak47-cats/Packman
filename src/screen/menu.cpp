#include "menu.hpp"

ButtonInterface::ButtonInterface(std::string name, std::function<void ()> Callback): name(name),
                                                                                     Callback(Callback) {}

ftxui::Element Menu::Render() {
    return (buttons->Render() | ftxui::flex);
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