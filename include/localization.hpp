#ifndef LOCALIZATION_HPP
#define LOCALIZATION_HPP

// 本地化模块：所有 UI 文案的标识符定义。
// 通过 Nexus API 的 Localization::Set 注册多语言字符串，
// 运行时用 Localization::Translate 取得当前 Nexus 界面语言对应的文本，
// 从而实现"跟随 Nexus 语言"（Nexus 用中文则显示中文，用英文则显示英文）。

// 标识符统一前缀，避免与其他插件冲突
#define AL_NS "NexusAppLauncher_"

// ---- 选项区文案 ----
#define AL_OPT_KILL_ON_CLOSE AL_NS "Opt_KillProcessesOnClose"
#define AL_OPT_START_HEADER AL_NS "Opt_StartProgramsHeader"
#define AL_OPT_EXIT_HEADER AL_NS "Opt_ExitProgramsHeader"
#define AL_OPT_ADD_HEADER AL_NS "Opt_AddProgramHeader"
#define AL_OPT_OPEN_PICKER AL_NS "Opt_OpenFilePicker"
#define AL_OPT_START_ON_EXIT AL_NS "Opt_StartProgramOnExit"
#define AL_OPT_START_ON_GAME_EXIT AL_NS "Opt_StartOnGameExit"

// ---- 编辑/新增程序的输入项标签 ----
#define AL_LBL_PROGRAM_PATH AL_NS "Lbl_ProgramPath"
#define AL_LBL_WORKING_DIR AL_NS "Lbl_ProgramWorkingDirectory"
#define AL_LBL_ARGUMENTS AL_NS "Lbl_ProgramArguments"

// ---- 按钮 ----
#define AL_BTN_CONFIRM AL_NS "Btn_Confirm"
#define AL_BTN_CANCEL AL_NS "Btn_Cancel"
#define AL_BTN_EDIT AL_NS "Btn_Edit"
#define AL_BTN_DELETE AL_NS "Btn_Delete"
#define AL_BTN_ADD AL_NS "Btn_AddProgram"

// ---- 列表展示文本（含格式占位符 %s） ----
#define AL_TXT_WORKING_DIR AL_NS "Txt_WorkingDirectoryLabel"
#define AL_TXT_ARGUMENTS AL_NS "Txt_ArgumentsLabel"

// ---- 提示 / 报错 ----
#define AL_TIP_PATH_NOT_EXIST AL_NS "Tip_PathDoesNotExist"
#define AL_TIP_REMOVE_PROGRAM AL_NS "Tip_RemoveProgram"
#define AL_ERR_NOT_EXECUTABLE AL_NS "Err_MustBeExecutable"

// 注册所有语言的文案，应在 addon_load 时调用一次
void register_localization();

#endif // LOCALIZATION_HPP
