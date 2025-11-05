#include "../../../include/client/ChatUI/chatbox.hpp"
using namespace std;

ChatBoxUI::ChatBoxUI(const char* partner_name, ImGuiIO& io) : io(io)
{
    this->partner_name = partner_name;
    init();
}

ChatBoxUI::~ChatBoxUI()
{
    large_font = nullptr;
    delete large_font;
}

void ChatBoxUI::init()
{
    io.Fonts->AddFontDefault();
    large_font = io.Fonts->AddFontFromFileTTF(FONT_PATH, 32);
    med_font = io.Fonts->AddFontFromFileTTF(FONT_PATH, 12);
}

void ChatBoxUI::draw()
{
    ImGui::Begin("CHAT HERE");
    ImVec2 window_size = ImGui::GetWindowSize();
    ImVec2 text_size = ImGui::CalcTextSize(this->partner_name);
    ImGui::SetCursorPosX((window_size.x - text_size.x) * 0.5f);
    ImGui::PushFont(large_font);
    ImGui::Text("%s", partner_name);
    ImGui::PopFont();

    ImGui::PushFont(med_font);
    ImGui::Text("Enter your message: ");
    ImGui::PopFont();
    ImGui::SameLine();
    ImGui::InputText(" ", this->inputTextBuffer, sizeof(inputTextBuffer));
    ImGui::SameLine();
    auto send_button = ImGui::Button("Send");
    if(send_button)
    {
        std::cout << "You sent a message" << std::endl;
    }
    if(inputTextBuffer[0] != NULL)
        std::cout << "null shit man" << std::endl;
    ImGui::End();
}