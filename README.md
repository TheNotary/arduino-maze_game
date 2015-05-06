# MazeGame

Maze Game is a game where you move a pixel around an 8x8 grid.  Maybe it hooks into an LCD display and allows you to search and fight stuff.  

## Installation

Download this repo with git.  

```
$ git clone https://github.com/BackupSelfyBot/maze_game
```

Connect your Arduino Uno and flash it using platformio:

    $ platformio run

## Parts

* [8x8 LED Matrix](https://www.adafruit.com/products/902)
* [LCD Plate](https://www.adafruit.com/products/1115)

#### MCUs
* [Arduino Uno](https://127.0.0.1)

## Wiring

TODO: Drop a link to a picture of your wiring here or something.  Maybe fritzing.  

## Device Operation

Use the LCD plate buttons to navigate the green pixel through the maze of yellow pixels.  Watch out for red pixels, cause they like to fight!


## Contributing

1. Fork it ( https://github.com/[my-github-username]/maze_game/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
