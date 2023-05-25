# Cub3D
This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.

## Features 💯

- Compact & Portable
- Fast Rendering Algorithm
- Clean Source Code
- Dynamic Resolution
- Adaptive and Fun Maps

## Keybinds ⌨️

| Command | Description |
| --- | --- |
| `W` | Move Forward |
| `A` | Move Left |
| `S` | Move Backward |
| `D` | Move Right |
| `LEFT ARROW` | Rotate Left |
| `RIGHT ARROW` | Rotate Right |

## How to Use:

First you have to clone this repository into your local machine:

`$> git clone https://github.com/haytham10/Cub3D.git`

Then use the included Makefile to compile the required files:

`$> make all`

After that you can simply run the game with a map of your choice as an argument:

`$> ./Cub3D map1.cub`

## Preview 🎮

<img src="https://github.com/haytham10/Cub3D/blob/master/preview/1.png">

<img src="https://github.com/haytham10/Cub3D/blob/master/preview/2.png">

<img src="https://github.com/haytham10/Cub3D/blob/master/preview/3.png">

<img src="https://github.com/haytham10/Cub3D/blob/master/preview/4.png">

## Map Assetes 🧭

- A Valid Map file must have a 4 texture paths to the diffrent wall directions:

`NO ./textures/2.xpm`  
`SO ./textures/3.xpm`  
`WE ./textures/7.xpm`  
`EA ./textures/6.xpm`

- Floor and Ceiling Colors should be present in an RGB format:

`F 255,227,171`  
`C 16,142,210`

- Finally a Valid Map should contain only 1 Player spawn Position `N, W, E, or S` and should be surrounded by walls (`1` or ` `), `0` is for empty space:  

`111111`  
`100101`  
`101001`  
`1100N1`  
`111111`  

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Authors

- [@Haytham](https://www.github.com/haytham10)
- [@Amal](https://github.com/amalsenhaji)
