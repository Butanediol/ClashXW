/*
 * Copyright (C) 2020 Richard Yu <yurichard3839@gmail.com>
 *
 * This file is part of ClashXW.
 *
 * ClashXW is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ClashXW is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with ClashXW.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "resource.h"
#include "boost/preprocessor/stringize.hpp"

namespace fs = std::filesystem;
namespace wrl = Microsoft::WRL;
using winrt::Windows::Foundation::IAsyncAction;
using winrt::Windows::Foundation::IAsyncOperation;
using nlohmann::json;
using namespace std::chrono_literals;

HINSTANCE g_hInst;
fs::path g_exePath;
fs::path g_dataPath;
fs::path g_configPath;
std::vector<fs::path> g_configFilesList;
bool g_clashRunning = false;
bool g_clashOnline = false;
std::string g_clashVersion;
HWND g_hWnd;
HWND g_hWndRemoteConfigDlg = nullptr;
IAsyncAction g_processMonitor = nullptr;

enum class BalloonClickAction
{
	None,
	ReloadConfig,
	ShowConsoleWindow
};
BalloonClickAction g_balloonClickAction = BalloonClickAction::None;

constexpr UINT WM_NOTIFYICON = WM_APP + 1;
constexpr UINT WM_RESUMECORO = WM_APP + 2; // wParam=coroutine_handle.address
constexpr UINT WM_CONFIGCHANGEDETECT = WM_APP + 3;

// RemoteConfigDlg
constexpr UINT WM_REFRESHCONFIGS = WM_APP + 1;

constexpr auto CLASHXW_APP_ID = L"com.ysc3839.clashxw";
constexpr auto CLASHXW_MUTEX_NAME = L"Local\\com.ysc3839.clashxw";
constexpr auto CLASHXW_DIR_NAME = L"ClashXW";
constexpr auto CLASHXW_LINK_NAME = L"ClashXW.lnk";
constexpr auto CLASHXW_CONFIG_NAME = L"ClashXW.json";
constexpr auto CLASHXW_USERAGENT = L"ClashXW/" BOOST_PP_STRINGIZE(GIT_BASEVERSION_MAJOR) "." BOOST_PP_STRINGIZE(GIT_BASEVERSION_MINOR) "." BOOST_PP_STRINGIZE(GIT_BASEVERSION_PATCH);
constexpr auto CLASH_CONFIG_DIR_NAME = L"Config";
constexpr auto CLASH_ASSETS_DIR_NAME = L"ClashAssets";
constexpr auto CLASH_DASHBOARD_DIR_NAME = L"Dashboard";
constexpr auto CLASH_DEF_CONFIG_NAME = L"config.yaml";
constexpr auto CLASH_EXE_NAME = L"clash.exe";
constexpr auto CLASH_CTL_ADDR = L"127.0.0.1:9090";
constexpr auto CLASH_CTL_SECRET = L"";

#include "I18n.hpp"
#include "Coroutine.hpp"
#include "Util.hpp"
#include "SysProxy.hpp"
#include "SettingsUtil.hpp"
#include "ClashApi.hpp"
#include "ConfigFileManager.hpp"
#include "MenuUtil.hpp"
#include "ProcessManager.hpp"
#include "DarkMode.hpp"
#include "DialogUtil.hpp"
#include "OSLicensesDlg.hpp"
#include "TaskDialogInput.hpp"
#include "RemoteConfigManager.hpp"
#include "RemoteConfigDlg.hpp"

std::unique_ptr<ClashApi> g_clashApi;

#include "EdgeWebView2.hpp"
