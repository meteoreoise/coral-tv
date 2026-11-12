# Building CORAL TV

CORAL TV is a PlayStation 2 Emotion Engine program (`coral-tv.elf`). It needs the [PS2SDK](https://github.com/ps2dev/ps2sdk) toolchain and [gsKit](https://github.com/ps2dev/gsKit).

Verified toolchain (last successful build):

- ps2dev Docker image digest `sha256:bc2eb0ddcf3c83f8697d3b7da2a654dacaae4c862322b712884858d20daf74dc`
- `mips64r5900el-ps2-elf-gcc (GCC) 15.2.0`

## Option A — Docker (recommended)

Docker Desktop is enough; no local cross-compiler is required.

```bash
docker run --rm \
  -v "$PWD:/src" \
  -w /src \
  ghcr.io/ps2dev/ps2dev:latest \
  sh -c "apk add --no-cache make >/dev/null && make"
```

PowerShell:

```powershell
docker run --rm -v "${PWD}:/src" -w /src ghcr.io/ps2dev/ps2dev:latest sh -c "apk add --no-cache make >/dev/null && make"
```

Why `apk add make`: the `ps2dev` image ships the toolchain, PS2SDK and gsKit, but not GNU Make.

Output: `coral-tv.elf` in the repository root, stripped, ready to boot.

Other targets:

```bash
docker run --rm -v "$PWD:/src" -w /src ghcr.io/ps2dev/ps2dev:latest \
  sh -c "apk add --no-cache make >/dev/null && make clean"
```

## Option B — local toolchain

1. Install the ps2dev toolchain + PS2SDK by following the official instructions: <https://ps2dev.github.io/>.
2. Make sure `PS2SDK` points to the SDK root and `mips64r5900el-ps2-elf-gcc` is on your `PATH`.
3. Install gsKit:

   - If your setup already provides `$PS2DEV/gsKit` (as the Docker image does), export `GSKIT=$PS2DEV/gsKit`.
   - Otherwise build gsKit from source:

     ```bash
     git clone https://github.com/ps2dev/gsKit.git
     make -C gsKit
     make -C gsKit install    # installs headers/libs into $PS2SDK/ports
     ```

4. Build:

   ```bash
   make
   ```

   The Makefile uses `$GSKIT` when set, and falls back to `$PS2SDK/ports` otherwise.

## Makefile targets

| Target | Action |
|---|---|
| `make` | Compile and link `coral-tv.elf`, then strip it |
| `make clean` | Remove the ELF and object files |
| `make rebuild` | `clean` followed by `all` |

## Troubleshooting

| Symptom | Cause / fix |
|---|---|
| `mips64r5900el-ps2-elf-gcc: not found` | Toolchain not installed or not on `PATH`. Use the Docker option or source the ps2dev environment. |
| `fatal error: gsKit.h: No such file or directory` | gsKit not found. Check `ls "$GSKIT/include/gsKit.h"` or install gsKit into `$PS2SDK/ports`. |
| `Makefile.pref: No such file or directory` | PS2SDK installation is incomplete (sample makefiles missing). Reinstall PS2SDK. |
| `make: not found` inside the container | Run `apk add --no-cache make` first. |
| Git Bash rewrites container paths | Prefix the command with `MSYS_NO_PATHCONV=1` or use a Windows-style path (`C:/...`). |
| Permission errors on mounted volume (Linux) | The container runs as root; build outputs may become root-owned. Use `sudo chown -R "$USER" .` afterwards or run Docker with `--user "$(id -u):$(id -g)"`. |
