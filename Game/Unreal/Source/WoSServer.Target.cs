// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
using System;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class WoSServerTarget : TargetRules
{
    public WoSServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("WoS");
    }
}
