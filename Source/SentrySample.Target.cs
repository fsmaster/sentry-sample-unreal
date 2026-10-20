using UnrealBuildTool;

public class SentrySampleTarget : TargetRules
{
	public SentrySampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("SentrySample");
	}
}
