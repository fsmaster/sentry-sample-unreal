using UnrealBuildTool;

public class SentrySampleEditorTarget : TargetRules
{
	public SentrySampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("SentrySample");
	}
}
