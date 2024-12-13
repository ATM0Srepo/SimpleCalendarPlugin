// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleCalendarPlugin.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"                 
#include "HAL/PlatformFilemanager.h" 
#include "HAL/PlatformProcess.h"  
#include "Misc/FileHelper.h"

#define LOCTEXT_NAMESPACE "FSimpleCalendarPluginModule"

void FSimpleCalendarPluginModule::StartupModule()
{
    FString PluginDir = IPluginManager::Get().FindPlugin(TEXT("SimpleCalendarPlugin"))->GetBaseDir();
    FString BinariesPath = FPaths::Combine(*PluginDir, TEXT("ThirdParty/CalendarTaskAPI/Binaries/app.exe"));
    FPlatformProcess::CreateProc(*BinariesPath, nullptr, true, true, true, nullptr, 0, nullptr, nullptr);
}

void FSimpleCalendarPluginModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSimpleCalendarPluginModule, SimpleCalendarPlugin)