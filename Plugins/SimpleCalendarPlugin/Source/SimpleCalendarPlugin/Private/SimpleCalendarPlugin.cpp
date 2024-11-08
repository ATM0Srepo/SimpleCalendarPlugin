// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleCalendarPlugin.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FSimpleCalendarPluginModule"

void FSimpleCalendarPluginModule::StartupModule()
{
    FString FlagFilePath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("CalendarTaskAPI_Ran.txt"));

    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FlagFilePath))
    {
        FString PluginDir = IPluginManager::Get().FindPlugin(TEXT("SimpleCalendarPlugin"))->GetBaseDir();
        FString BinariesPath = FPaths::Combine(*PluginDir, TEXT("ThirdParty/CalendarTaskAPI/Binaries/app.exe"));
        FPlatformProcess::CreateProc(*BinariesPath, nullptr, true, true, true, nullptr, 0, nullptr, nullptr);
        FFileHelper::SaveStringToFile(TEXT("Ran"), *FlagFilePath);

    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Executable already ran. Skipping execution."));
    }
}

void FSimpleCalendarPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSimpleCalendarPluginModule, SimpleCalendarPlugin)