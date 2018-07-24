
Debian
====================
This directory contains files used to package stampd/stamp-qt
for Debian-based Linux systems. If you compile stampd/stamp-qt yourself, there are some useful files here.

## stamp: URI support ##


stamp-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install stamp-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your stampqt binary to `/usr/bin`
and the `../../share/pixmaps/stamp128.png` to `/usr/share/pixmaps`

stamp-qt.protocol (KDE)

