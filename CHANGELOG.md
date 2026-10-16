# Changelog

This document records the version release notes of the project.

## v2.1.2

- Fixed crash on Android 15 caused by decrementing the display token refcount twice in `getDisplayState`.
- No longer cache the display token returned by `GetDisplayInfo()` to avoid reusing a private `sp<>` object across calls.

## v2.1.1

- Compatible with the new `SurfaceComposerClient::mirrorSurface` symbol signature on Android 16.
- Mirrored Surfaces are now released correctly by LayerStack to avoid leftover references after cleanup.
- Fixed landscape size and touch-coordinate issues caused by using the long edge as height when creating a Surface.
- Added mutex protection for mirror creation, destruction, and cache access.

## v2.1.0

- Upgraded to the C++17 standard.
- Added a new Surface cleanup function.
- Fixed Surface re-creation issues.
- Added screen-capture protection.
- Fixed capture-card display glitches.
- Fixed screen rotation on Android 15.
- Fixed resolution offset issues.

## v2.0.0

- Based on the original AndroidSurfaceImgui project.
- Supports Android 5.0-16.0.
- Provides basic ImGui rendering.
