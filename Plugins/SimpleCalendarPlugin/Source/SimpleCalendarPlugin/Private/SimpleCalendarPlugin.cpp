// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleCalendarPlugin.h"

#define LOCTEXT_NAMESPACE "FSimpleCalendarPluginModule"

void FSimpleCalendarPluginModule::StartupModule()
{
    // Define the path to the flag file
    FString FlagFilePath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("CalendarTaskAPI_Ran.txt"));

    // Check if the flag file already exists
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FlagFilePath))
    {
        // Path to the executable
        FString ExePath = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("SimpleCalendarPlugin/ThirdParty/CalendarTaskAPI/Binaries/api.exe"));

        // Check if the executable exists before running it
        if (FPaths::FileExists(ExePath))
        {
            // Launch the executable
            FPlatformProcess::CreateProc(*ExePath, nullptr, true, false, false, nullptr, 0, nullptr, nullptr);

            // Create the flag file to indicate the executable has run
            FFileHelper::SaveStringToFile(TEXT("Ran"), *FlagFilePath);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Executable not found at %s"), *ExePath);
        }
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