# Changelog

All notable changes to CORAL TV are documented in this file.
The format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and the project adheres to [Semantic Versioning](https://semver.org/).

## [Unreleased]

### Added

- PS2SDK + gsKit project skeleton that builds a valid `coral-tv.elf`.
- Boot path: DMA/GIF channel initialisation, gsKit global and screen setup with auto-detected display mode.
- Phase 1 Home screen: dark background, coral accent bar, CORAL TV wordmark, boot status pill, version and phase footer.
- Built-in 5×7 bitmap text renderer (uppercase mapping, integer scaling) with no external font files.
- Minimal logger writing to the PS2 console.
- GitHub Actions workflow that builds the ELF inside the `ps2dev/ps2dev` Docker image.
- Arabic and English README, build/testing/roadmap/third-party documentation, issue and PR templates.

### Known limitations

- Not yet tested on PCSX2 or real hardware.
- Static screen only: no controller input, navigation or exit handling yet.
- Arabic text rendering is not implemented.

## [0.1.0] - 2026-11-13

- Initial public repository based on the project specification.
