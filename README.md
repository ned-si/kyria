# kyria

My QMK keymap for the [splitkb Kyria](https://splitkb.com/products/kyria-pcb-kit) rev1 with Elite-C controllers.

It is cloned inside my
[qmk-userspace](https://github.com/ned-si/qmk-userspace) checkout, at
`keyboards/splitkb/kyria/keymaps/nedsi` (git-ignored there, so the userspace always
builds whatever this clone has checked out).

It uses the shared code in `users/nedsi`: layer enum, row macros, custom keycodes,
tap dances. The gaming row macros and the gaming toggle on the NAV layer are
defined in `keymap.c`, since the shared code no longer has them.

## Build and flash

From a machine set up as described in the qmk-userspace README:

```sh
qmk compile -kb splitkb/kyria/rev1/base -km nedsi
qmk flash   -kb splitkb/kyria/rev1/base -km nedsi
```

Both halves take the same firmware; flash each one. Bootloader: double-tap the
reset button, or `QK_BOOT` (the Q position on the MISC layer).
