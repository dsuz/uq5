

using UnrealBuildTool;
using System.Collections.Generic;

public class UQ5EditorTarget : TargetRules
{
	public UQ5EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V6;

		ExtraModuleNames.AddRange( new string[] { "UQ5" } );
	}
}
