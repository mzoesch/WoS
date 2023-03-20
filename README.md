# **WoS**

## IM:

- VS: DeveloperEditor -> Win64

## Fix Bug:

- Platform 'arm64' referenced in the project file 'UE5' cannot be found.
- Platform 'x64' referenced in the project file 'UE5' cannot be found.
- Platform 'arm64' referenced in the project file 'WoS' cannot be found.
  <br />
  -> .vs/\* <br />
  -> Intermediate/\*

- ABP_DefaultCharacter -> x/y but not z -> Calc like UAC_CharacterMovementController::CalcDirMoveStraight

# Input

## Action Mappings

- PlayerCameraFPP:
  - MouseWheelUp
- PlayerCameraTPP:
  - MouseWheelDown
- PlayerCameraTPPDecreaseSpringArmLength:
  - MouseWheelUp
- PlayerCameraTPPIncreaseSpringArmLength:
  - MouseWheelDown
- PlayerCameraTPPRotate:
  - LeftAlt
- PlayerFootJump:
  - Space
- PlayerFootRun:
  - LeftShift
- OpenDebugMenu:
  - F3
    <br />
    <br />

## Axis Mappings

- PlayerCameraPitch:
  - MouseY [-1,1]
- PlayerCameraYaw:
  - MouseX [-1,1]
- PlayerFootMoveForward:
  - +1 : w
  - -1 : s
- PlayerFootMoveRight:
  - +1 : d
  - -1 : a
    <br />
    <br />

# Default Values

## DefaultPawn

### Movement

- Walking Speed: 300 cm/h (~ km/h); {Normal human walking Speed: 140 cm/h (~5 km/h)}
- Running Speed: 900 cm/h (~ km/h); {Normal human running Speed: 359 cm/h (~12.9 km/h))}
- Crouching Speed : 150 cm/h (~ km/h)
  <br />
  <br />

### Debug

Debug standard text size: 10 dpi
<br />
<br />

# DefaultEngine.ini

- NetServerMaxTickRate=64
  <br />
  <br />

# Script Structure

> Source

- WoS.Target.cs
- WoSEditor.Target.cs
- WoSServer.Target.cs
- > WoS
  - WoS.h
  - WoS.cpp
  - > PlayerRT
    - > Movement
      - AC_CharacterMovementController.h
