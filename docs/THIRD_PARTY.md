# Third-party components

CORAL TV original code is MIT licensed. The build depends on the following external components; they are **not** vendored in this repository.

| Component | Use | License |
|---|---|---|
| [PS2SDK](https://github.com/ps2dev/ps2sdk) | PS2 runtime libraries, startup code, build templates | Academic Free License 2.0 |
| [gsKit](https://github.com/ps2dev/gsKit) | Graphics synthesizer toolkit (drawing, DMA) | Academic Free License 2.0 |
| [ps2dev toolchain](https://github.com/ps2dev/ps2dev) | MIPS cross-compiler (GCC 15.2.0) | GPL with GCC runtime exception (build-time only) |

## Notes

- The `ps2dev` Docker image bundles PS2SDK and gsKit; they are fetched at build time, not redistributed here.
- The 5×7 bitmap font in `src/graphics/text.c` was authored for this project. No third-party font files are included.
- No BIOS, commercial game, SDK dump or copyrighted asset is included in this repository. Users must supply their own BIOS to run an emulator.
- Before adding any new library, document its source, version and license in this file and confirm the license is compatible with MIT distribution.
