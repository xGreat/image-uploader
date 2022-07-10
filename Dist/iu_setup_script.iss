﻿; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!
#include "../Source/VersionInfo.h"

;#expr Exec(SourcePath + "signcode.bat")
#define MyAppName "Image Uploader"
#define MyAppVersion IU_APP_VER
#define MyAppPublisher "Sergey Svistunov"
#define MyAppURL "https://svistunov.dev/imageuploader"
#define MyAppExeName "Image Uploader.exe"
;#include ReadReg(HKEY_LOCAL_MACHINE,'Software\Sherlock Software\InnoTools\Downloader','ScriptPath','')
#include "it_download.iss"


[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{24F211C6-2732-4564-B602-CDA2DE2A13FC}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppVerName=Image Uploader {#MyAppVersion} Build {#IU_BUILD_NUMBER}
UninstallDisplayName=Image Uploader {#MyAppVersion}
VersionInfoVersion={#IU_APP_VER_CLEAN}.{#IU_BUILD_NUMBER}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
OutputDir=output\
OutputBaseFilename=image-uploader-{#IU_APP_VER}-build-{#IU_BUILD_NUMBER}-setup
Compression=lzma/max 
SolidCompression=yes
;SignTool=zenden2k
CloseApplications=yes
CloseApplicationsFilter=*.exe

[Languages]
Name: "en"; MessagesFile: "compiler:Default.isl"
Name: "ru"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "hr"; MessagesFile: "Languages\Croatian.isl"
Name: "ro"; MessagesFile: "Languages\Romanian.isl"
Name: "fa"; MessagesFile: "Languages\Farsi.isl"
Name: "sr"; MessagesFile: "Languages\SerbianCyrillic.isl"
Name: "sv"; MessagesFile: "Languages\Swedish.isl"
Name: "tr"; MessagesFile: "compiler:Languages\Turkish.isl"
Name: "ko"; MessagesFile: "Languages\Korean.isl"
Name: "hu"; MessagesFile: "Languages\Hungarian.isl"
Name: "uk"; MessagesFile: "compiler:Languages\Ukrainian.isl"
Name: "ar"; MessagesFile: "Languages\Arabic.isl"
[CustomMessages]
InstallFFmpeg=Install FFmpeg library (better video formats support)
Additional=Additional
ru.InstallFFmpeg=Установить библиотеку FFmpeg для лучшей поддержки форматов видео
ru.Additional=Дополнительно
[Registry]
Root: HKLM; Subkey: "Software\Zenden.ws\Image Uploader"; ValueType: string; ValueName: "DataPath"; ValueData: "{code:GetDataFolder}\Image Uploader\"; 
;Tasks: common;  ;
;Root: HKCU; Subkey: "Software\Zenden.ws\Image Uploader"; ValueType: string; ValueName: "DataPath"; ValueData: "{code:GetDataFolder}\Image Uploader"; Tasks: installuser; 

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:Additional}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:Additional}"; Flags: unchecked; OnlyBelowVersion: 0,6.1
Name: "installffmpeg"; Description: "{cm:InstallFFmpeg}"; GroupDescription: "{cm:Additional}"; Flags: unchecked 
;Name: common; Description: All users; GroupDescription: Install for:; Flags: exclusive
;Name: installuser; Description: The current user only; GroupDescription: Install for:; Flags: exclusive unchecked
[Dirs]
Name: "{code:GetDataFolder}\Image Uploader"; Permissions: users-modify
Name: "{code:GetDataFolder}\Image Uploader\Thumbnails"; Permissions: users-modify
Name: "{code:GetDataFolder}\Image Uploader\Servers"; Permissions: users-modify
Name: "{code:GetDataFolder}\Image Uploader\Scripts"; Permissions: users-modify
Name: "{code:GetDataFolder}\Image Uploader\Favicons"; Permissions: users-modify
Name: "{code:GetDataFolder}\Image Uploader\Update"; Permissions: users-modify
[Files]
Source: "..\Build\Gui\Release\Image Uploader.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\Build\Gui\Release\curl-ca-bundle.crt"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\Lang\*.lng"; Excludes: "default.*"; DestDir: "{app}\Lang"; Flags: ignoreversion
Source: "..\Lang\English.lng.src"; DestDir: "{app}\Lang"; Flags: ignoreversion
Source: "..\Modules\*"; DestDir: "{app}\Modules"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\Docs\*"; DestDir: "{app}\Docs"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\Data\servers.xml"; DestDir: "{code:GetDataFolder}\Image Uploader\"; Flags: ignoreversion
Source: "..\Data\servers.xsd"; DestDir: "{code:GetDataFolder}\Image Uploader\"; Flags: ignoreversion
Source: "..\Data\template.txt"; DestDir: "{code:GetDataFolder}\Image Uploader\"; Flags: ignoreversion
Source: "..\Data\templates.xml"; DestDir: "{code:GetDataFolder}\Image Uploader\"; Flags: ignoreversion
Source: "..\Data\Favicons\*.ico"; DestDir: "{code:GetDataFolder}\Image Uploader\Favicons"; Flags: ignoreversion
Source: "..\Data\Scripts\*.nut"; DestDir: "{code:GetDataFolder}\Image Uploader\Scripts"; Flags: ignoreversion  
Source: "..\Data\Scripts\Utils\*.nut"; DestDir: "{code:GetDataFolder}\Image Uploader\Scripts\Utils"; Flags: ignoreversion  
Source: "..\Data\Scripts\UploadFilters\*.nut"; DestDir: "{code:GetDataFolder}\Image Uploader\Scripts\UploadFilters"; Flags: ignoreversion  
Source: "..\Data\Scripts\Lang\*.json"; DestDir: "{code:GetDataFolder}\Image Uploader\Scripts\Lang"; Flags: ignoreversion
Source: "..\Data\Update\iu_core.xml"; DestDir: "{code:GetDataFolder}\Image Uploader\Update"; Flags: ignoreversion
Source: "..\Data\Update\iu_serversinfo.xml"; DestDir: "{code:GetDataFolder}\Image Uploader\Update"; Flags: ignoreversion
Source: "..\Data\Thumbnails\*.*"; DestDir: "{code:GetDataFolder}\Image Uploader\Thumbnails"; Flags: ignoreversion
Source: "..\Data\Utils\*"; DestDir: "{code:GetDataFolder}\Image Uploader\Utils"; Flags: ignoreversion

;Flags: deleteafterinstall
;Source: "..\Data\Servers\*.xml"; DestDir: "{code:GetDataFolder}\Image Uploader\Servers"; Flags: ignoreversion
Source: "{app}\ExplorerIntegration64.dll"; DestDir: "{app}"; DestName: "ExplorerIntegration64.dll.old"; Flags: external skipifsourcedoesntexist
Source: "{app}\ExplorerIntegration.dll"; DestDir: "{app}"; DestName: "ExplorerIntegration.dll.old"; Flags: external skipifsourcedoesntexist
Source: "..\Source\ShellExt\Build\Release optimized\ExplorerIntegration.dll";DestDir: "{app}";
Source: "..\Source\ShellExt\Build\Release optimized\ExplorerIntegration64.dll";DestDir: "{app}";

Source: "..\Build\Gui\Release\av*.dll"; DestDir: "{app}"; Flags: ignoreversion; Tasks: installffmpeg;
Source: "..\Build\Gui\Release\sw*.dll"; DestDir: "{app}"; Flags: ignoreversion; Tasks: installffmpeg;


; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}";

Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}";
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon;
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon;
[Run]
Filename: "{app}\{#MyAppExeName}"; Parameters: "/afterinstall /language={language} {code:GetAdditionalRunParameters}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent

[UninstallRun]
Filename: "{app}\image uploader.exe"; Parameters: "/uninstall"; Flags: runascurrentuser

[UninstallDelete]
Type: files; Name: "{app}\av*.dll"
Type: files; Name: "{app}\sw*.dll"
Type: files; Name: "{app}\*.old"
Type: files; Name: "{code:GetDataFolder}\Image Uploader\Update\*.xml"
Type: files; Name: "{code:GetDataFolder}\Image Uploader\Favicons\*"
Type: files; Name: "{code:GetDataFolder}\Image Uploader\Scripts\*"

[Code]
function GetDataFolder(Param: String): String;
begin
       Result := ExpandConstant('{commonappdata}')
      
end;

function GetIconFileName(Param: String): String;
begin
    Result := ExpandConstant('{app}') + '\Image Uploader.exe'; 
end;

function GetAdditionalRunParameters(Param: String): String;
begin
    Result := '';
end;

function LoadLibraryA(lpLibFileName: PAnsiChar): THandle;
external 'LoadLibraryA@kernel32.dll stdcall';
function GetProcAddress(Module: THandle; ProcName: PAnsiChar): Longword;
external 'GetProcAddress@kernel32.dll stdcall';

function IsWine: boolean;
var  LibHandle  : THandle;
begin
  LibHandle := LoadLibraryA('ntdll.dll');
  Result:= GetProcAddress(LibHandle, 'wine_get_version')<> 0;
end;

procedure  InitializeWizard;
 var BtnImage: TBitmapImage;
  WelcomePage: TWizardPage; 
   BtnPanel: TPanel; 
begin
     ITD_Init;
     ITD_SetOption('UI_AllowContinue','1');
     ITD_DownloadAfter(wpReady);
end;

function PrepareToInstall(var NeedsRestart: Boolean): String;
begin
 
end;

procedure CurPageChanged(CurPageID: Integer);
  var Version: TWindowsVersion;
begin
      if CurPageID = wpReady then begin
      ITD_ClearFiles;
    GetWindowsVersionEx(Version);
   if (Version.NTPlatform and
     (Version.Major = 5) 
     and (Version.Minor <1 )) or IsWine()  
     then
  begin

    ITD_AddFile('http://dl.bintray.com/zenden/zenden-image-uploader/gdiplus.dll', expandconstant('{tmp}\gdiplus.dll'));
    //http://dl.bintray.com/zenden/zenden-image-uploader/ffmpeg-1.2.12.zip
  
  end;


end;
end;


procedure CurStepChanged(CurStep: TSetupStep);
   var Version: TWindowsVersion;
  ResultCode: integer;
  Cmd: String;
begin

 if CurStep=ssPostInstall then begin
 GetWindowsVersionEx(Version);
   if (Version.NTPlatform and
     (Version.Major = 5) 
     and (Version.Minor <1 ) ) or  IsWine()   
     then
  begin
  filecopy(expandconstant('{tmp}\gdiplus.dll'),expandconstant('{app}\gdiplus.dll'),false);
  end;


    if IsWine then
    RegWriteStringValue(HKEY_CURRENT_USER, 'Software\Wine\DllOverrides',
    'gdiplus', 'native, builtin');
 end;
end;
