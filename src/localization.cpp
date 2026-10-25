#include "localization.hpp"
#include <globals.hpp>
#include <nexus/Nexus.h>

// 在 Nexus 中注册本插件的所有 UI 文案。
// Nexus 的 Localization::Translate 会把标识符翻译成"当前激活的语言"，
// 若该语言没有对应译文，则返回标识符原样（所以必须注册英文作为兜底，
// 且标识符本身设计成可读的英文短语作为最后防线）。
//
// 参数说明：Localization::Set(标识符, 语言代码, 译文)
// 语言代码与 Nexus 官方语言包一致："cn"=简体中文, "en"=English, 还有 tw/kr/jp/de...
// 本仓库当前仅提供 cn/en 两套（原插件只有英文界面，故 en 即原文）。

void register_localization()
{
    if (api == nullptr) {
        return; // 尚未就绪，跳过注册
    }

    // ---------- English (fallback / 原文) ----------
    const char *en = "en";
    api->Localization.Set(AL_OPT_KILL_ON_CLOSE, en, "Kill Processes On Close");
    api->Localization.Set(AL_OPT_START_HEADER, en, "Programs to start on game start");
    api->Localization.Set(AL_OPT_EXIT_HEADER, en, "Programs to start on game close");
    api->Localization.Set(AL_OPT_ADD_HEADER, en, "Add program");
    api->Localization.Set(AL_OPT_OPEN_PICKER, en, "Open File Picker");
    api->Localization.Set(AL_OPT_START_ON_EXIT, en, "Start program on game close");
    api->Localization.Set(AL_OPT_START_ON_GAME_EXIT, en, "Start on game exit");

    api->Localization.Set(AL_LBL_PROGRAM_PATH, en, "Program Path");
    api->Localization.Set(AL_LBL_WORKING_DIR, en, "Program Working Directory");
    api->Localization.Set(AL_LBL_ARGUMENTS, en, "Program Arguments");

    api->Localization.Set(AL_BTN_CONFIRM, en, "Confirm");
    api->Localization.Set(AL_BTN_CANCEL, en, "Cancel");
    api->Localization.Set(AL_BTN_EDIT, en, "Edit");
    api->Localization.Set(AL_BTN_DELETE, en, "Delete");
    api->Localization.Set(AL_BTN_ADD, en, "Add program");

    api->Localization.Set(AL_TXT_WORKING_DIR, en, "working dir: %s");
    api->Localization.Set(AL_TXT_ARGUMENTS, en, "arguments: %s");

    api->Localization.Set(AL_TIP_PATH_NOT_EXIST, en, "Path does not exist.");
    api->Localization.Set(
        AL_TIP_REMOVE_PROGRAM, en,
        "Remove program from list and kills it if kill processes on close is enabled.");
    api->Localization.Set(AL_ERR_NOT_EXECUTABLE, en,
                          "Path must lead to an executable file. (.exe)");

    // ---------- 简体中文 ----------
    const char *cn = "cn";
    api->Localization.Set(AL_OPT_KILL_ON_CLOSE, cn, "关闭游戏时结束进程");
    api->Localization.Set(AL_OPT_START_HEADER, cn, "游戏启动时启动的程序");
    api->Localization.Set(AL_OPT_EXIT_HEADER, cn, "游戏关闭时启动的程序");
    api->Localization.Set(AL_OPT_ADD_HEADER, cn, "添加程序");
    api->Localization.Set(AL_OPT_OPEN_PICKER, cn, "打开文件选择器");
    api->Localization.Set(AL_OPT_START_ON_EXIT, cn, "游戏关闭时启动程序");
    api->Localization.Set(AL_OPT_START_ON_GAME_EXIT, cn, "游戏退出时启动");

    api->Localization.Set(AL_LBL_PROGRAM_PATH, cn, "程序路径");
    api->Localization.Set(AL_LBL_WORKING_DIR, cn, "程序工作目录");
    api->Localization.Set(AL_LBL_ARGUMENTS, cn, "程序启动参数");

    api->Localization.Set(AL_BTN_CONFIRM, cn, "确认");
    api->Localization.Set(AL_BTN_CANCEL, cn, "取消");
    api->Localization.Set(AL_BTN_EDIT, cn, "编辑");
    api->Localization.Set(AL_BTN_DELETE, cn, "删除");
    api->Localization.Set(AL_BTN_ADD, cn, "添加程序");

    api->Localization.Set(AL_TXT_WORKING_DIR, cn, "工作目录：%s");
    api->Localization.Set(AL_TXT_ARGUMENTS, cn, "启动参数：%s");

    api->Localization.Set(AL_TIP_PATH_NOT_EXIST, cn, "路径不存在。");
    api->Localization.Set(AL_TIP_REMOVE_PROGRAM, cn,
                          "从列表中移除该程序；若启用了“关闭游戏时结束进程”，将同时结束该进程。");
    api->Localization.Set(AL_ERR_NOT_EXECUTABLE, cn,
                          "路径必须指向可执行文件（.exe）。");
}
