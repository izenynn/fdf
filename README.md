# fdf

## Info

Wireframe rasterizer.

- Status: finished
- Result: 125%
- Observations: you can zoom, translate (move) and rotate the wireframe :D

# How to use

## Clone repo and submodules

```sh
git clone --recurse-submodules https://github.com/izenynn/fdf.git
```

## Linux extra steps

- If you are using Linux, firts you will need to install a few dependencies

```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

- Also, give execution permissions to the file `./lib/mlx_linux/configure`

```sh
chmod +x ./lib/mlx_linux/configure
```

## Change window resolution

Open the `Makefile`, go to line 40 and change WIN_H value to you desire windows height, and WIN_W value to the window width :)

- For Full HD example:

```make
CCFLAGS += -D WIN_H=1080 -D WIN_W=1920
```

## Change color palette

A custom palette will be aplied when no colors are present on the map, the color will depend on the z axis, to change this palette, uncomment line 57 - 61 in the `Makefile` and change the color values, example:

```make
DCOLORS =   -D COLOR_1=0x00a0b0     \
            -D COLOR_2=0x4f372d     \
            -D COLOR_3=0xcc2a36     \
            -D COLOR_4=0xeb6841     \
            -D COLOR_5=0xedc951
```

## Compile

- Run `make` (make rules: `all`, `clean`, `fclean` and `re`)

```sh
make all clean
```

- Run `./fdf` with a map as an argument (test maps on the `test_maps` folder)

```sh
./fdf ./test_map/42.fdf
```

## If the program is closing instantly

I do not know for sure if this bug is related with minilibx, linux, or wsl.

This is because of ESC key ghosting. to fix this comment the lines that close the program when ESC key is pressed.

Go to `src/mlx_hook.c` and comment line 25 and 26:

```c
//if (keycode == KEY_ESC)
//	close_win(vars);
```

You will stil be able to exit either closing the window or by pressing CTRL + C on the terminal.

## MAC OS alternative version

If you have any issues on MAC OS, an alternative minilibx is included in the repo, just uncomment the lines 108 and 109, and comment lines 111 and 112 of the `Makefile` :)

- Before

```make
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -D OSX
#	########## SHARED VARS       ##########
	CCFLAGS += -framework OpenGL -framework AppKit
	LDLIBS = -lft -lmlx
#	########## mlx_mms           ##########
#	LMLX_NAME = $(LMLX_NAME_MMS)
#	LMLX_DIR = $(LMLX_DIR_MMS)
#	########## mlx_macos_sierra  ##########
	LMLX_NAME = $(LMLX_NAME_MACOS_SIERRA)
	LMLX_DIR = $(LMLX_DIR_MACOS_SIERRA)
endif
```

- After

```make
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -D OSX
#	########## SHARED VARS       ##########
	CCFLAGS += -framework OpenGL -framework AppKit
	LDLIBS = -lft -lmlx
#	########## mlx_mms           ##########
	LMLX_NAME = $(LMLX_NAME_MMS)
	LMLX_DIR = $(LMLX_DIR_MMS)
#	########## mlx_macos_sierra  ##########
#	LMLX_NAME = $(LMLX_NAME_MACOS_SIERRA)
#	LMLX_DIR = $(LMLX_DIR_MACOS_SIERRA)
endif
```

## Screenshots

![map elem2.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/01-elem2.png)

![map t2.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/02-t2.png)

![map elem-col.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/03-elem-col.png)

![map julia.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/04-julia.png)

![map elem-fract.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/05-elem-fract.png)

# Useful links

### Minilibx documentation:

- [documentation](https://qst0.github.io/ft_libgfx/man_mlx.html) (by [qst0](https://github.com/qst0))

- [documentation and guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) (by [harm-smits](https://github.com/harm-smits))

- [minilibx images guide](https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html) (by [Gontjarow](https://github.com/Gontjarow))

- [minilibx images examples](https://github.com/keuhdall/images_example) (by [keuhdall](https://github.com/keuhdall))

- [fdf mini wiki](https://github.com/VBrazhnik/FdF/wiki) (by [VBrazhnik](https://github.com/VBrazhnik/FdF/wiki))

### Minilibx for linux:

- [minilibx for linux](https://github.com/42Paris/minilibx-linux)

#
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/you-didnt-ask-for-this.svg)](https://forthebadge.com)
