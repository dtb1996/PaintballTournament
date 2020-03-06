// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Paintball_BellefeuilEditorTarget : TargetRules
{
	public Paintball_BellefeuilEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Paintball_Bellefeuil");
	}
}
