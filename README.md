# Pac-Man Game

This Pac-Man game is a project developed as part of a college assignment. It is implemented in C++ using the SFML (Simple and Fast Multimedia Library) graphic library. 
The game follows the classic Pac-Man gameplay, where the player controls Pac-Man to eat all the dots while avoiding ghosts.

## Features

- Classic Pac-Man gameplay: Control Pac-Man to navigate through a maze and eat all the dots.
- Ghost AI: The ghosts in the game have their own AI patterns to chase and evade Pac-Man.
- Power pellets: Pac-Man can eat power pellets to temporarily gain the ability to eat ghosts.
- Score tracking: The game keeps track of the player's score based on eating dots and ghosts.
- Levels: The game includes multiple levels with increasing difficulty.
- Bonus fruits: Bonus fruits appear in the maze for additional points.

## Requirements

- C++ compiler (supporting C++11 or later)
- SFML library (version X.X.X)

## Installation

1. Clone the repository or download the source code files.
2. Make sure you have SFML installed on your system. If not, visit the SFML website (link) for installation instructions.
3. Compile the source code using your preferred C++ compiler with SFML linked.
4. Run the executable file generated after compilation.

## Controls

- Arrow keys: Control the movement of Pac-Man in the maze.

## Design Patterns

The project utilizes the following design patterns:

1. State Pattern: The State pattern is used to manage the different states of the game, such as the main menu, gameplay, and game over screens. Each state is implemented as a separate class that encapsulates the behavior and logic associated with that state.

2. Double Dispatch: The Double Dispatch pattern is used to handle collisions between different game entities, such as Pac-Man and ghosts. It allows dynamic resolution of the collision based on the types of the colliding entities. This pattern improves extensibility and flexibility when adding new types of entities in the game.

## Future Enhancements

- Add additional levels and mazes.
- Implement more challenging AI patterns for the ghosts.
- Introduce power-ups or special abilities for Pac-Man.
- Improve game graphics and sound effects.
- Implement a high-score leaderboard.
