using UnrealBuildTool;

public class SentrySample : ModuleRules
{
	public SentrySample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "Sentry" });
	}
}
