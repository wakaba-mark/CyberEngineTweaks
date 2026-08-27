#pragma once

namespace Text
{
inline constexpr char ProductName[] = "Cyber Engine Tweaks";
inline constexpr char MainWindow[] = "Cyber Engine Tweaks 简体中文版###Cyber Engine Tweaks";
inline constexpr char OverlayBindNotification[] = "CET 界面快捷键：%s";

inline constexpr char Console[] = "控制台###Console";
inline constexpr char Bindings[] = "按键绑定###Bindings";
inline constexpr char BindingsTitle[] = "按键绑定";
inline constexpr char Settings[] = "设置###Settings";
inline constexpr char SettingsTitle[] = "设置";
inline constexpr char TweakDBEditor[] = "TweakDB 编辑器###TweakDB Editor";
inline constexpr char GameLog[] = "游戏日志###Game Log";
inline constexpr char ImGuiDebug[] = "ImGui 调试###ImGui Debug";
inline constexpr char ImGuiStyleEditor[] = "Dear ImGui 样式编辑器###Dear ImGui Style Editor";
inline constexpr char ReloadAllMods[] = "重新加载所有 Mod###Reload all mods";

inline constexpr char Save[] = "保存###Save";
inline constexpr char Load[] = "加载###Load";
inline constexpr char Defaults[] = "恢复默认值###Defaults";
inline constexpr char ResetChanges[] = "撤销更改###Reset changes";
inline constexpr char Cancel[] = "取消###Cancel";
inline constexpr char Search[] = "搜索";
inline constexpr char Regex[] = "正则表达式###Regex";

inline constexpr char UnsavedChanges[] = "未保存的更改";
inline constexpr char UnsavedChangesFor[] = "{} - 未保存的更改";
inline constexpr char UnsavedChangesNotice[] = "你有尚未保存的更改。";
inline constexpr char UnsavedChangesQuestion[] = "要应用这些更改，还是放弃更改？";
inline constexpr char Apply[] = "应用###Apply";
inline constexpr char Discard[] = "放弃###Discard";

inline constexpr char ClearOutput[] = "清空输出###Clear output";
inline constexpr char AutoScroll[] = "自动滚动###Auto-scroll";
inline constexpr char CommandFailed[] = "命令执行失败，请检查输入内容。";
inline constexpr char LuaVMNotReady[] = "命令未执行：Lua 虚拟机尚未初始化，请稍后再试。";
inline constexpr char LuaVMReady[] = "Lua 虚拟机初始化完成。";
inline constexpr char ModsReloaded[] = "已重新加载所有 Mod。";

namespace GameOptions
{
inline constexpr char NotFound[] = "找不到游戏选项“{}/{}”。";
inline constexpr char ReadBooleanFailed[] = "无法读取游戏选项“{}/{}”：该选项可能不是布尔值。";
inline constexpr char ReadIntegerFailed[] = "无法读取游戏选项“{}/{}”：该选项可能不是整数或颜色值。";
inline constexpr char ReadFloatFailed[] = "无法读取游戏选项“{}/{}”：该选项可能不是浮点数。";
inline constexpr char SetStringUnsupported[] = "无法设置游戏选项“{}/{}”：目前不支持设置字符串选项。";
inline constexpr char SetFailed[] = "无法设置游戏选项“{}/{}”：选项数据不可用。";
inline constexpr char SetBooleanFailed[] = "无法设置游戏选项“{}/{}”：该选项不是布尔值。";
inline constexpr char SetIntegerFailed[] = "无法设置游戏选项“{}/{}”：该选项不是整数。";
inline constexpr char SetFloatFailed[] = "无法设置游戏选项“{}/{}”：该选项不是浮点数。";
inline constexpr char Dumped[] = "已将 {} 个游戏选项写入 cyber_engine_tweaks.log。";
inline constexpr char Found[] = "找到 {} 个游戏选项。";
} // namespace GameOptions

namespace Mods
{
inline constexpr char ReservedName[] = "已忽略使用保留名称的 Mod：“{}”。请重命名该 Mod 后重试。";
inline constexpr char InvalidDirectory[] = "无法访问 Mod 目录：“{}”。请检查目录是否存在且有权访问。";
inline constexpr char MissingEntryPoint[] = "已忽略缺少 init.lua 的 Mod：“{}”。请检查 Mod 是否安装完整。";
inline constexpr char Loaded[] = "Mod {} 已加载：“{}”。";
inline constexpr char LoadFailed[] = "Mod {} 加载失败：“{}”。请检查控制台中的错误详情。";
} // namespace Mods

inline constexpr char OverlayKey[] = "界面开关快捷键";
inline constexpr char OverlayKeyDescription[] = "使用此快捷键打开或关闭 CET 界面。";
inline constexpr char FirstTimeSetup[] = "CET 首次设置###CET First Time Setup";
inline constexpr char FirstTimeBindPrompt[] = "请设置一个用于打开或关闭 CET 界面的快捷键组合。";
inline constexpr char FirstTimeBindLimit[] = "快捷键组合最多可以包含 4 个按键。";
inline constexpr char TooltipUnavailable[] = "暂时无法显示此说明，请稍后再试。";
inline constexpr char Binding[] = "正在录入…###Binding...";
inline constexpr char UnbindTooltip[] = "取消勾选即可解除此按键绑定。";
inline constexpr char Hotkeys[] = "快捷键";
inline constexpr char HotkeysTooltip[] = "按下并松开所分配的按键组合后触发。每项最多可以绑定 4 个按键。";
inline constexpr char Inputs[] = "输入键";
inline constexpr char InputsTooltip[] = "按下和松开按键时分别响应。每项只能绑定一个按键。";

namespace SettingsPage
{
inline constexpr char Patches[] = "功能补丁###Patches";
inline constexpr char Development[] = "CET 开发设置###CET Development Settings";
inline constexpr char DisableAsyncCompute[] = "禁用异步计算";
inline constexpr char DisableAsyncComputeTooltip[] = "禁用异步计算；可能提升 Nvidia 10 系等较旧显卡的性能。重启游戏后生效。";
inline constexpr char DisableAntialiasing[] = "禁用抗锯齿";
inline constexpr char DisableAntialiasingTooltip[] = "完全禁用抗锯齿。重启游戏后生效。";
inline constexpr char DisableVignette[] = "禁用暗角";
inline constexpr char DisableVignetteTooltip[] = "禁用屏幕边缘的暗角效果。重启游戏后生效。";
inline constexpr char DisableBoundaryTeleport[] = "禁用越界传送";
inline constexpr char DisableBoundaryTeleportTooltip[] = "允许玩家进入正常边界之外的区域。重启游戏后生效。";
inline constexpr char DisableVSync[] = "禁用垂直同步（仅 Windows 7）";
inline constexpr char DisableVSyncTooltip[] = "在 Windows 7 上禁用垂直同步，以绕过 60 FPS 限制。重启游戏后生效。";
inline constexpr char RemoveDeadBindings[] = "移除失效的按键绑定";
inline constexpr char RemoveDeadBindingsTooltip[] = "移除已不再有效的全部按键绑定；排查 Mod 问题时可以暂时关闭。";
inline constexpr char EnableImGuiAssertions[] = "启用 ImGui 断言";
inline constexpr char EnableImGuiAssertionsTooltip[] = "启用全部 ImGui 断言，并将断言写入触发方的日志。适合排查 ImGui 问题或在发布 Mod 前检查问题。";
inline constexpr char DumpGameOptions[] = "导出游戏选项";
inline constexpr char DumpGameOptionsTooltip[] = "将全部游戏选项写入 CET 主日志。重启游戏后生效。";
inline constexpr char EnableJIT[] = "为 Lua 启用 JIT";
inline constexpr char EnableJITTooltip[] = "启用 Lua 虚拟机的 JIT 编译器，可显著提高部分 Mod 的运行速度。如果遇到问题，可关闭此项进行排查。重启游戏后生效。";
} // namespace SettingsPage

namespace TweakDB
{
inline constexpr char NotInitialized[] = "TweakDB 尚未初始化。";
inline constexpr char RebuildingCache[] = "正在重建缓存…";
inline constexpr char Records[] = "记录###Records";
inline constexpr char Queries[] = "查询###Queries";
inline constexpr char Flats[] = "属性###Flats";
inline constexpr char Advanced[] = "高级###Advanced";
inline constexpr char RecordNotFound[] = "找不到该记录。";
inline constexpr char FlatNotFound[] = "找不到该属性。";
inline constexpr char NamedFlatNotFound[] = "在 TweakDB 中找不到“%s”。";
inline constexpr char UnsupportedType[] = "不支持的类型：%s";
inline constexpr char ArrayItems[] = "[%s] %u 项";
inline constexpr char Clear[] = "清空###clear";
inline constexpr char Edit[] = "编辑###edit";
inline constexpr char ArrayCancel[] = "取消###cancel";
inline constexpr char ArraySave[] = "保存###save";
inline constexpr char AddNew[] = "新增###add new";
inline constexpr char Roll[] = "横滚";
inline constexpr char Pitch[] = "俯仰";
inline constexpr char Yaw[] = "偏航";
inline constexpr char ColorUnsupported[] = "暂不支持编辑“Color”类型";
inline constexpr char LocalizationKey[] = "这是一个本地化文本键。";
inline constexpr char ExpectedValues[] = "游戏要求此处使用特定值。";
inline constexpr char GroupingDepth[] = "“属性”分组深度###'Flats' Grouping depth";
inline constexpr char DropdownHeight[] = "下拉列表高度###ComboBox dropdown height";
inline constexpr char RefreshAll[] = "全部刷新###Refresh all";
inline constexpr char RecordName[] = "记录名称###Record name";
inline constexpr char DeleteRecord[] = "删除记录###Delete Record";
inline constexpr char RecordType[] = "要创建的记录类型###Record type to create";
inline constexpr char CreateRecord[] = "创建记录###Create record";
inline constexpr char RecordToClone[] = "要克隆的记录###Record to clone";
inline constexpr char CloneRecord[] = "克隆记录###Clone record";
inline constexpr char Success[] = "操作成功。";
inline constexpr char Failure[] = "操作失败，请打开控制台查看详情。";
} // namespace TweakDB

namespace Toast
{
inline constexpr char Success[] = "成功";
inline constexpr char Warning[] = "警告";
inline constexpr char Error[] = "错误";
inline constexpr char Info[] = "信息";
} // namespace Toast
} // namespace Text
