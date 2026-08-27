#include <stdafx.h>

#include "Settings.h"

#include <CET.h>

#include <Utils.h>

Settings::Settings(Options& aOptions, LuaVM& aVm)
    : Widget(Text::Settings)
    , m_options(aOptions)
    , m_vm(aVm)
{
    Load();
}

WidgetResult Settings::OnPopup()
{
    const auto ret = UnsavedChangesPopup(Text::SettingsTitle, m_openChangesModal, m_madeChanges, [this] { Save(); }, [this] { Load(); });
    m_madeChanges = ret == TChangedCBResult::CHANGED;
    m_popupResult = ret;

    return m_madeChanges ? WidgetResult::ENABLED : WidgetResult::DISABLED;
}

WidgetResult Settings::OnDisable()
{
    if (m_enabled)
    {
        if (m_popupResult == TChangedCBResult::CANCEL)
        {
            m_popupResult = TChangedCBResult::APPLY;
            return WidgetResult::CANCEL;
        }

        if (m_madeChanges)
        {
            m_drawPopup = true;
            return WidgetResult::ENABLED;
        }

        m_enabled = false;
    }

    return m_enabled ? WidgetResult::ENABLED : WidgetResult::DISABLED;
}

void Settings::OnUpdate()
{
    const auto frameSize = ImVec2(ImGui::GetContentRegionAvail().x, -(ImGui::GetFrameHeight() + ImGui::GetStyle().ItemSpacing.y + ImGui::GetStyle().FramePadding.y + 2.0f));
    if (ImGui::BeginChild(ImGui::GetID("Settings"), frameSize))
    {
        m_madeChanges = false;
        if (ImGui::CollapsingHeader(Text::SettingsPage::Patches, ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::TreePush("##PATCHES");
            if (ImGui::BeginTable("##SETTINGS_PATCHES", 2, ImGuiTableFlags_Sortable | ImGuiTableFlags_SizingStretchSame, ImVec2(-ImGui::GetStyle().IndentSpacing, 0)))
            {
                const auto& patchesSettings = m_options.Patches;
                UpdateAndDrawSetting(
                    Text::SettingsPage::DisableAsyncCompute, Text::SettingsPage::DisableAsyncComputeTooltip, m_patches.AsyncCompute, patchesSettings.AsyncCompute);
                UpdateAndDrawSetting(
                    Text::SettingsPage::DisableAntialiasing, Text::SettingsPage::DisableAntialiasingTooltip, m_patches.Antialiasing, patchesSettings.Antialiasing);
                UpdateAndDrawSetting(
                    Text::SettingsPage::DisableVignette, Text::SettingsPage::DisableVignetteTooltip, m_patches.DisableVignette, patchesSettings.DisableVignette);
                UpdateAndDrawSetting(
                    Text::SettingsPage::DisableBoundaryTeleport, Text::SettingsPage::DisableBoundaryTeleportTooltip, m_patches.DisableBoundaryTeleport,
                    patchesSettings.DisableBoundaryTeleport);
                UpdateAndDrawSetting(
                    Text::SettingsPage::DisableVSync, Text::SettingsPage::DisableVSyncTooltip, m_patches.DisableWin7Vsync, patchesSettings.DisableWin7Vsync);
                
                ImGui::EndTable();
            }
            ImGui::TreePop();
        }
        if (ImGui::CollapsingHeader(Text::SettingsPage::Development, ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::TreePush("##DEV");
            if (ImGui::BeginTable("##SETTINGS_DEV", 2, ImGuiTableFlags_Sortable | ImGuiTableFlags_SizingStretchSame, ImVec2(-ImGui::GetStyle().IndentSpacing, 0)))
            {
                const auto& developerSettings = m_options.Developer;
                UpdateAndDrawSetting(
                    Text::SettingsPage::RemoveDeadBindings, Text::SettingsPage::RemoveDeadBindingsTooltip, m_developer.RemoveDeadBindings,
                    developerSettings.RemoveDeadBindings);
                UpdateAndDrawSetting(
                    Text::SettingsPage::EnableImGuiAssertions, Text::SettingsPage::EnableImGuiAssertionsTooltip, m_developer.EnableImGuiAssertions,
                    developerSettings.EnableImGuiAssertions);
                UpdateAndDrawSetting(
                    Text::SettingsPage::DumpGameOptions, Text::SettingsPage::DumpGameOptionsTooltip, m_developer.DumpGameOptions, developerSettings.DumpGameOptions);
                UpdateAndDrawSetting(
                    Text::SettingsPage::EnableJIT, Text::SettingsPage::EnableJITTooltip, m_developer.EnableJIT, developerSettings.EnableJIT);

                ImGui::EndTable();
            }
            ImGui::TreePop();
        }
    }
    ImGui::EndChild();

    ImGui::Separator();

    const auto itemWidth = GetAlignedItemWidth(3);
    if (ImGui::Button(Text::Load, ImVec2(itemWidth, 0)))
        Load();
    ImGui::SameLine();
    if (ImGui::Button(Text::Save, ImVec2(itemWidth, 0)))
        Save();
    ImGui::SameLine();
    if (ImGui::Button(Text::Defaults, ImVec2(itemWidth, 0)))
        ResetToDefaults();
}

void Settings::Load()
{
    m_options.Load();

    m_patches = m_options.Patches;
    m_developer = m_options.Developer;
}

void Settings::Save() const
{
    m_options.Patches = m_patches;
    m_options.Developer = m_developer;

    m_options.Save();
}

void Settings::ResetToDefaults()
{
    m_options.ResetToDefaults();

    m_patches = m_options.Patches;
    m_developer = m_options.Developer;
}

void Settings::UpdateAndDrawSetting(const std::string& acLabel, const std::string& acTooltip, bool& aCurrent, const bool& acSaved)
{
    ImGui::TableNextRow();
    ImGui::TableNextColumn();

    ImVec4 curTextColor = ImGui::GetStyleColorVec4(ImGuiCol_Text);
    if (aCurrent != acSaved)
        curTextColor = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

    ImGui::AlignTextToFramePadding();

    ImGui::PushStyleColor(ImGuiCol_Text, curTextColor);

    ImGui::PushID(&acLabel);
    ImGui::TextUnformatted(acLabel.c_str());
    ImGui::PopID();

    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled) && !acTooltip.empty())
        ImGui::SetTooltip("%s", acTooltip.c_str());

    ImGui::TableNextColumn();

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (ImGui::GetContentRegionAvail().x - ImGui::GetFrameHeight()) / 2);
    ImGui::Checkbox(("##" + acLabel).c_str(), &aCurrent);
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
        ImGui::SetTooltip("%s", acTooltip.c_str());

    ImGui::PopStyleColor();

    m_madeChanges |= aCurrent != acSaved;
}
