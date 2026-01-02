

using UnrealBuildTool;
using System.Collections.Generic;

public class UQ5Target : TargetRules
{
	public UQ5Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		//DefaultBuildSettings = BuildSettingsVersion.V6;
		DefaultBuildSettings = BuildSettingsVersion.Latest;

		ExtraModuleNames.AddRange( new string[] { "UQ5" } );
	}
}
