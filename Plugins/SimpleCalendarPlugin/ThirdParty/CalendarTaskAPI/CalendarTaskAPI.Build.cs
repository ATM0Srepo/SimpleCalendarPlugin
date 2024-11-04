using UnrealBuildTool;
using System.IO;

public class CalendarTaskAPI : ModuleRules
{
    public CalendarTaskAPI(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        string CalendarTaskAPIDir = Path.Combine(ModuleDirectory, "Binaries");

        RuntimeDependencies.Add(Path.Combine(CalendarTaskAPIDir, "api.exe"));

        PublicDefinitions.Add("WITH_CALENDAR_TASK_API=1");
        PublicIncludePaths.Add(CalendarTaskAPIDir);
    }
}
