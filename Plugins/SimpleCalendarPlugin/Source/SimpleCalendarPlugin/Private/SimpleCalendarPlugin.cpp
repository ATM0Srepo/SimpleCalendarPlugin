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
}

void FSimpleCalendarPluginModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSimpleCalendarPluginModule, SimpleCalendarPlugin)