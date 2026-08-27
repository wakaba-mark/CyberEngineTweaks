# Cyber Engine Tweaks 简体中文版

[![最新版本](https://img.shields.io/github/v/release/wakaba-mark/CyberEngineTweaks?label=%E6%9C%80%E6%96%B0%E7%89%88%E6%9C%AC)](https://github.com/wakaba-mark/CyberEngineTweaks/releases/latest)
[![下载量](https://img.shields.io/github/downloads/wakaba-mark/CyberEngineTweaks/total?label=%E4%B8%8B%E8%BD%BD%E9%87%8F)](https://github.com/wakaba-mark/CyberEngineTweaks/releases)
[![MIT License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Discord](https://img.shields.io/discord/717692382849663036.svg?label=Discord&logo=discord&logoColor=ffffff&color=7389D8&labelColor=6A7EC2)](https://discord.gg/Epkq79kd96)

> [!IMPORTANT]
> 这是基于 [Cyber Engine Tweaks 官方项目](https://github.com/maximegmd/CyberEngineTweaks)制作的**非官方简体中文专用版本**，与官方开发团队没有隶属关系。项目保留 CET 的功能和 Mod 兼容性，仅对 CET 自有界面、提示与部分日志进行本地化。

## 项目介绍

**Cyber Engine Tweaks（CET）** 是《赛博朋克 2077》的脚本与 Mod 框架。它允许 Mod 作者通过 [Lua](https://www.lua.org/) 调用游戏内部脚本功能，并使用 [Dear ImGui](https://github.com/ocornut/imgui) 为 Mod 创建图形界面。

CET 自带控制台、按键绑定管理、设置页面、游戏日志和 TweakDB 编辑器，也提供多项可独立启用或关闭的游戏补丁。部分补丁修改后需要重启游戏才会生效。

本仓库在官方 CET 基础上提供完整的简体中文使用体验，适合希望直接使用中文界面、又不想额外安装语言补丁的玩家。

### 本版本的汉化范围

- CET 主界面、工具栏和首次启动设置；
- 控制台、按键绑定、设置页面和游戏日志；
- TweakDB 编辑器及其常用操作提示；
- 通知、错误提示、未保存更改弹窗和部分运行日志；
- 默认加载 Noto Sans SC 简体中文字体；
- 使用 GB2312 字形范围，覆盖 6763 个简体汉字及常用符号；
- 保留稳定的 ImGui 控件标识，避免汉化影响窗口布局和配置状态。

本版本不会翻译游戏本体文本，也不会自动翻译第三方 Mod 自己提供的界面和消息。Lua API、函数名、TweakDB 类型名及其他必须保持兼容的技术标识仍使用原文。

## 下载与安装

请从本仓库的 [Releases 页面](https://github.com/wakaba-mark/CyberEngineTweaks/releases/latest)下载名称中带有 `zh-CN` 的发行版 ZIP，不要下载 GitHub 自动生成的 `Source code` 源码压缩包。

安装步骤：

1. 按照官方要求安装 [RED4ext](https://github.com/WopsS/RED4ext)；
2. 下载本项目最新的简体中文发行版 ZIP；
3. 将 ZIP 中的 `bin` 文件夹解压到《赛博朋克 2077》游戏根目录；
4. 如系统询问是否合并目录或覆盖文件，请确认；
5. 首次进入游戏后，按照中文提示设置 CET 界面开关快捷键。

典型的游戏安装目录示例：

```text
C:\Program Files (x86)\Steam\steamapps\common\Cyberpunk 2077
```

安装完成后，CET 的主要文件应位于：

```text
Cyberpunk 2077\bin\x64\plugins\cyber_engine_tweaks
```

> [!NOTE]
> 安装新版前建议备份自己的 CET 配置和 Mod。遇到问题时，可先暂时移出第三方 Mod，以区分 CET 本体问题与 Mod 兼容问题。

## 主要功能

- Lua 脚本与 Mod 运行环境；
- Dear ImGui 图形界面支持；
- Lua 控制台；
- CET 与 Mod 按键绑定管理；
- TweakDB 记录、查询和属性编辑；
- 游戏日志查看；
- 可配置的游戏补丁；
- 面向 Mod 作者的调试选项。

### 游戏补丁

| 补丁 | 说明 |
| :-- | :-- |
| AMD SMT | 为未能从 CDPR 官方补丁中获得性能提升的 AMD CPU 调整 SMT 行为 |
| 移除行人与交通 | 移除大部分行人和道路交通 |
| 禁用异步计算 | 禁用异步计算，可能提升 Nvidia 10 系等较旧显卡的性能 |
| 禁用时间抗锯齿 | 禁用抗锯齿；通常不建议开启 |
| 跳过开始菜单 | 跳过要求按空格键继续的开始菜单 |
| 跳过开场动画 | 禁用游戏启动时播放的徽标动画 |
| 禁用暗角 | 禁用屏幕边缘的暗角效果 |
| 禁用越界传送 | 允许玩家进入正常边界之外的区域 |
| 禁用 Windows 7 垂直同步 | 在 Windows 7 上禁用垂直同步，以绕过 60 FPS 限制 |

### Mod 开发选项

| 选项 | 说明 |
| :-- | :-- |
| 显示 ImGui 诊断窗口 | 显示 ImGui 内部诊断信息，便于排查 Mod 界面问题 |
| 移除失效的按键绑定 | 移除属于未加载 Mod 的按键绑定 |
| 启用 ImGui 断言 | 启用 ImGui 断言，适合在发布 Mod 前检查界面错误 |
| 调试菜单 | 启用游戏内调试菜单 |
| 导出游戏选项 | 将全部游戏选项写入 CET 主日志 |

## 使用与开发资料

- [CET 官方 Wiki](https://wiki.redmodding.org/cyber-engine-tweaks/)
- [官方 Mod 示例](https://github.com/WolvenKit/cet-examples)
- [Proton 环境安装说明](https://wiki.redmodding.org/cyber-engine-tweaks/getting-started/installing/untitled)
- [本地构建说明](BUILD.md)
- [CET 官方仓库](https://github.com/maximegmd/CyberEngineTweaks)

本仓库使用 GitHub Actions 在 Windows 云端构建。普通用户只需要下载 Releases 中已经编译好的 ZIP，不需要安装 Visual Studio、xmake 或其他开发工具。

## 问题反馈

提交问题时，请尽量提供：

- 游戏版本和 CET 简体中文版版本；
- 问题出现前执行的操作；
- 是否安装了第三方 CET Mod；
- `cyber_engine_tweaks.log` 中与问题相关的内容；
- 如果是显示问题，请说明具体页面和无法正常显示的文字。

如果问题也能在官方英文版 CET 中复现，请优先查阅官方 Wiki 和官方仓库的问题记录。与本项目汉化、中文字体或简体中文发行包有关的问题，可以在本仓库反馈。

## 参与贡献

欢迎改进译文、修正文档或报告遗漏。修改代码时请遵循项目现有代码风格，不要提交来源不明或许可证与 MIT 不兼容的代码。

本仓库是独立维护的简体中文版本，不会自动向 CET 官方仓库提交 Pull Request。希望参与 CET 核心功能开发时，请前往[官方仓库](https://github.com/maximegmd/CyberEngineTweaks)。

## 支持官方项目

如果 CET 对你有帮助，可以通过以下方式支持原开发团队：

- [Patreon](https://www.patreon.com/tiltedphoques)
- Bitcoin：`bc1q0neujk5e8v8sc3934ajn8z8zav7hl6557fjj54`
- Bitcoin Cash：`qps5ze9p8fxmu4rszyxwy3g0ctlmrhvc3uqq0fzsnl`
- Dogecoin：`DMoReR33D87D6rYeUkyQb2BsEHJTqfBFva`
- Ethereum：`0x7Cd23BE1C507Da85ABF0B05c7A3C03e6d3d0233B`

## 许可证

本项目沿用 Cyber Engine Tweaks 的 [MIT License](LICENSE)。
