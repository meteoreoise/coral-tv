# Testing CORAL TV

Every feature must be reported with one of the project status labels. Do not upgrade a label without evidence.

| Label | Meaning |
|---|---|
| `Planned` | Designed, not implemented. |
| `Implemented` | Code exists and links, but no runtime verification yet. |
| `Build-tested` | Builds into a valid ELF with a recorded toolchain. |
| `Emulator-tested` | Runs correctly in a specific emulator version. |
| `Hardware-tested` | Runs on a specific PS2 model and boot method. |
| `Experimental` | Works partially or only under narrow conditions. |

## 1. Build verification

```bash
docker run --rm -v "$PWD:/src" -w /src ghcr.io/ps2dev/ps2dev:latest \
  sh -c "apk add --no-cache make >/dev/null && make"
```

Check the output is a little-endian 32-bit MIPS ELF:

```bash
docker run --rm -v "$PWD:/src" -w /src ghcr.io/ps2dev/ps2dev:latest \
  sh -c "mips64r5900el-ps2-elf-readelf -h coral-tv.elf | head -12"
```

Expected: `Class: ELF32`, `Machine: MIPS R3000`, `Flags: ... 5900 ...`.

## 2. Emulator testing (PCSX2)

Requirements: PCSX2 2.x (or recent 1.7 nightly) and a BIOS image you legally own.

1. Start PCSX2 and configure your BIOS.
2. `System → Boot ELF...` and select `coral-tv.elf`.
3. Observe the screen and the emulator console output.

Expected result for `v0.1.0-dev`:

- Dark background (`#0E0E12`) with a coral bar at the top.
- `CORAL TV` wordmark centered, "CORAL" in coral and "TV" in white.
- Subtitle `PLAYSTATION 2 HOMEBREW LAUNCHER`.
- A `SYSTEM READY` pill and a footer with `PHASE 1 - BOOTABLE ELF` and `V0.1.0-DEV`.
- Log lines in the console beginning with `[CORAL]`.

Record the PCSX2 version and renderer used (Vulkan / OpenGL / software).

## 3. Hardware testing

Requirements: a PS2 with a working homebrew boot method (FreeMcBoot, uLaunchELF, wLaunchELF, ps2link...).

1. Copy `coral-tv.elf` to a supported device (USB mass storage or memory card).
2. Launch the ELF through your boot method.
3. Check display mode, aspect ratio and text readability from TV distance.
4. Record any difference from the emulator result.

Always record:

- SCPH model (e.g. SCPH-90004).
- Video region/mode (NTSC / PAL).
- Boot method and storage device.
- Whether the console keeps running or hangs.

## 4. Reporting results

Use the bug report template and include the exact status label that matches your evidence. Example:

```text
Feature: Phase 1 Home screen
Status: Emulator-tested
Environment: PCSX2 2.2.0, Vulkan, NTSC BIOS
Result: screen renders as expected; console log shows GS screen 640x448
```

## 5. Test log

| Date | Scope | Environment | Result |
|---|---|---|---|
| 2026-11-13 | Build | ps2dev image, GCC 15.2.0 | Valid ELF produced, no warnings |
| 2026-11-13 | Build (CI) | GitHub Actions run 43332246006 | Success, `coral-tv-elf` artifact uploaded |
| — | PCSX2 | — | Not tested yet |
| — | Hardware | — | Not tested yet |
