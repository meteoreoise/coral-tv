# CORAL TV

<p align="center">
  <img src="assets/logo/banner.svg" alt="CORAL TV — PlayStation 2 Homebrew Launcher" width="760">
</p>

<p align="center">
  <a href="https://github.com/meteoreoise/coral-tv/actions/workflows/build.yml"><img src="https://github.com/meteoreoise/coral-tv/actions/workflows/build.yml/badge.svg" alt="Build status"></a>
  <img src="https://img.shields.io/badge/platform-PlayStation%202-00439C" alt="Platform: PlayStation 2">
  <img src="https://img.shields.io/badge/version-0.1.0--dev-FF7F50" alt="Version 0.1.0-dev">
  <a href="LICENSE"><img src="https://img.shields.io/badge/license-MIT-2ea44f" alt="License: MIT"></a>
</p>

## Overview

**CORAL TV** is an open-source homebrew launcher that turns a **PlayStation 2 Slim** into a living-room entertainment hub with a Smart TV inspired interface, fully controllable with a DualShock 2.

It is **not** Android and it does **not** run APK files. It is a native ELF application built on **PS2SDK** and **gsKit**, designed around the real limits of PS2 hardware: 32MB of main memory and the Emotion Engine.

> **Honesty first:** every feature is reported with its real status. Nothing is advertised as supported before it has been tested on an emulator or real hardware.

## Current status

| Area | Status |
|---|---|
| PS2SDK + gsKit project build | **Build-tested** (Docker / GitHub Actions) |
| Phase 1 — bootable ELF and initial Home screen | **Implemented** + **Build-tested** |
| PCSX2 testing | Not tested yet |
| Real PS2 hardware testing | Not tested yet |
| Apps / Games / Media / Files / Settings | **Planned** |

Status labels: `Planned` — `Implemented` — `Build-tested` — `Emulator-tested` — `Hardware-tested` — `Experimental`.

## What works today (v0.1.0-dev)

- `coral-tv.elf` builds against PS2SDK + gsKit.
- DMA and GS initialisation with automatic display mode detection.
- Initial Home screen: dark background, CORAL TV wordmark, coral accent, system status and version footer.
- Built-in 5×7 bitmap font (no external font assets), keeping memory use minimal.
- Small console logger for boot diagnostics.

## Requirements

- **Docker Desktop** (easiest) or a manual PS2SDK + gsKit installation.
- Target hardware: PS2 Slim (SCPH-7xxxx / 9xxxx) with a homebrew boot method.
- For testing: PCSX2 (requires a BIOS you own) or real hardware.

## Quick build

```bash
docker run --rm -v "$PWD:/src" -w /src ghcr.io/ps2dev/ps2dev:latest make
```

Output: `coral-tv.elf` in the repository root. Manual build details: [docs/BUILD.md](docs/BUILD.md).

## Running

In PCSX2:

1. Start PCSX2 with your own BIOS.
2. `System → Boot ELF...` and select `coral-tv.elf`.
3. The CORAL TV screen should appear.

On real hardware: copy `coral-tv.elf` to USB or a memory card, then launch it with uLaunchELF / wLaunchELF. Record your SCPH model and boot method in [docs/TESTING.md](docs/TESTING.md).

## Repository layout

```text
.
├── src/
│   ├── main.c              # entry point and Home screen
│   ├── core/logger.c       # minimal logger
│   └── graphics/           # renderer + 5×7 font
├── include/coral/          # public headers
├── assets/logo/            # repository branding (not loaded on PS2)
├── docs/                   # build, testing, roadmap, specification
├── .github/workflows/      # automated ELF build
├── Makefile
└── LICENSE
```

## Roadmap

Development follows the phases in [docs/ROADMAP.md](docs/ROADMAP.md): graphics → input → sections → ELF launcher → file manager → media and settings → stable release.

## Contributing

Read [CONTRIBUTING.md](CONTRIBUTING.md). The most important rule: do not claim a feature works before it is built and tested, and report its test status accurately.

## License and disclaimer

CORAL TV source code is licensed under [MIT](LICENSE). The project depends on [PS2SDK](https://github.com/ps2dev/ps2sdk) and [gsKit](https://github.com/ps2dev/gsKit) (AFL-2.0) — see [docs/THIRD_PARTY.md](docs/THIRD_PARTY.md).

This project is not affiliated with Sony Interactive Entertainment. The repository contains no BIOS, commercial games or copyrighted content, and does not modify original system files.

<p align="center">
  <a href="README.md">← التوثيق بالعربية</a>
</p>
