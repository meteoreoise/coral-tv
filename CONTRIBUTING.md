# Contributing to CORAL TV

Thanks for your interest in CORAL TV. This project targets real PlayStation 2 hardware, so contributions must respect its memory and performance limits.

## Ground rules

1. **No fake features.** Do not add UI entries, documentation claims or README badges for anything that is not implemented and tested. Use the project status labels (`Planned`, `Implemented`, `Build-tested`, `Emulator-tested`, `Hardware-tested`, `Experimental`) and state exactly how a feature was verified.
2. **No copyrighted content.** Never commit BIOS files, commercial games, leaked SDKs or protected assets. Original homebrew only.
3. **Real APIs only.** Use functions that exist in PS2SDK, gsKit or documented libraries. Check headers and official samples before calling an API; do not invent function names.
4. **One phase at a time.** Keep changes focused. A pull request should implement or fix one thing and leave the build green.
5. **Memory discipline.** Avoid loading every asset at once, avoid allocations inside the render loop, and free resources when leaving a screen.

## Development workflow

```bash
# build
make

# clean rebuild
make rebuild
```

Or with Docker:

```bash
docker run --rm -v "$PWD:/src" -w /src ghcr.io/ps2dev/ps2dev:latest make
```

Before opening a pull request:

- The ELF builds without warnings caused by your change.
- The relevant screen or subsystem was tested in PCSX2, and on hardware when possible.
- Documentation and `CHANGELOG.md` reflect the real status.

## Code style

- C for all runtime code; C++ only with a clear technical reason compatible with PS2SDK.
- Tabs for indentation in `.c` / `.h`, 4-space equivalent.
- Kernel-style braces (opening brace on the next line for functions).
- Prefix public functions with `coral_`; keep internal helpers `static`.
- Avoid dynamic allocation in hot paths; prefer static buffers with explicit bounds.
- No new dependencies without documenting the license in `docs/THIRD_PARTY.md`.

## Commit messages

Use short imperative subjects, for example:

```text
add controller polling for D-pad navigation
fix GS mode detection on PAL consoles
docs: correct build steps for gsKit
```

## Reporting bugs and requesting features

Use the GitHub issue templates. For hardware bugs, always include:

- SCPH model of your console.
- Boot method (FreeMcBoot, uLaunchELF, wLaunchELF, other).
- Whether the issue reproduces in PCSX2.
- Any console output captured through ps2link/ps2client or the emulator log.
