# CORAL TV Roadmap

The project is built one phase at a time. A phase is only marked complete when its features carry the appropriate test status (`Build-tested`, `Emulator-tested`, `Hardware-tested`).

| # | Phase | Status |
|---|---|---|
| 1 | Bootable ELF | Implemented, Build-tested |
| 2 | Graphics foundation | Planned |
| 3 | Controller input | Planned |
| 4 | Main UI sections | Planned |
| 5 | Apps and ELF launcher | Planned |
| 6 | Storage and file manager | Planned |
| 7 | Media center and settings | Planned |
| 8 | Stable release | Planned |

## Phase 1 — Bootable ELF

- [x] PS2SDK + gsKit build integrated through a Makefile.
- [x] DMA/GIF initialisation and gsKit screen setup.
- [x] Static Home screen with CORAL TV branding and version footer.
- [x] GitHub Actions build producing `coral-tv.elf`.
- [ ] Verified in PCSX2.
- [ ] Verified on real hardware.

## Phase 2 — Graphics foundation

- [ ] Theme module (coral palette, contrast rules, safe-area constants).
- [ ] Widget layer: cards, list rows, focus frame, scrollbar.
- [ ] Icon loading with a small texture cache and explicit eviction.
- [ ] Lightweight transitions that do not allocate per frame.
- [ ] Asset pipeline limited to sizes the GS can display without scaling artifacts.

## Phase 3 — Controller input

- [ ] Poll DualShock 2 through PS2SDK pad APIs.
- [ ] Edge detection (press once), repeat delay and repeat rate.
- [ ] Focus movement through the UI graph.
- [ ] Confirm/back/cancel semantics matching the documented button map.
- [ ] Controller presence and button map shown in Settings.

## Phase 4 — Main UI sections

- [ ] Home with sections: Apps, Games, Media, Files, Settings.
- [ ] Navigation bar and focus management across sections.
- [ ] Empty states and error messages for every section.
- [ ] Last-used programs list, persisted safely.

## Phase 5 — Apps and ELF launcher

- [ ] Application registry with validated paths.
- [ ] Add, edit, reorder and delete shortcuts (without deleting the target file).
- [ ] Confirm before launching an ELF.
- [ ] Handle missing/invalid ELF and document the return-to-launcher behavior.

## Phase 6 — Storage and file manager

- [ ] Detect the storage devices PS2SDK actually exposes (USB, memory card).
- [ ] Browse directories with sizes/dates when available.
- [ ] Copy, move and rename with clear failure reporting.
- [ ] Confirmed delete only; never format automatically.

## Phase 7 — Media center and settings

- [ ] Evaluate available media libraries and licenses.
- [ ] Add only formats proven to decode on hardware.
- [ ] Persist theme, language and control settings.
- [ ] Arabic text rendering only after real glyph shaping tests.
- [ ] Stability and memory tests.

## Phase 8 — Stable release

- [ ] Test across several SCPH models and boot methods.
- [ ] Document tested hardware and boot methods.
- [ ] Fix known bugs and publish release notes with build artifacts.
