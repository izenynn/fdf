# fdf

## Info

Wireframe rasterizer.

- Status: finished
- Result: n/a
- Observations: you can transform (move), zoom and rotate the wireframe :D

## Screenshots

![map t2.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/01-t2.png)
![map elem-col.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/02-elem-col.png)
![map julia.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/03-julia.png)
![map elem-fract.fdf screenshot](https://github.com/izenynn/fdf/blob/main/screenshots/04-elem-fract.png)

## How to use

### Clone the repo and submodules

```sh
git clone --recurse-submodules https://github.com/izenynn/fdf.git
```

### Dependencies (Linux)

- If you are using Linux, firts you will need to install a few packages

```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Change window resolution

Open the `Makefile`, go to line 40 and change WIN_H value to you desire windows height, and WIN_W value to the window width :)

### Compile

- Just run `make`

```sh
make
```

- Run `./fdf` with a map as an argument (test maps on the `test_maps` folder)

```sh
./fdf ./test_map/42.fdf
```

### MAC OS alternative version

If you have any issues on MAC OS, an alternative minilibx is included in the repo, just uncomment the lines 98 and 99, and comment lines 101 and 102 of the `Makefile` :)

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

##
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/you-didnt-ask-for-this.svg)](https://forthebadge.com)
