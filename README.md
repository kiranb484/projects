# Personal Projects Collection

This repository contains various projects I've worked on in my free time for learning and entertainment purposes. Some are written in Python while others were created for educational purposes. Below is a guide for each project:

## 1. Break Blocks
A classic arcade-style block-breaking game. Control a paddle at the bottom of the screen to bounce a ball and break blocks. Test your reflexes and aim to clear all blocks!
```bash
python break_blocks.py
```
Controls:
- Use left and right arrow keys to move the paddle
- Press ESC key to exit the game

## 2. Image Snapshot
A real-time image capture tool that uses your computer's camera. Perfect for taking quick snapshots and testing computer vision applications.
```bash
python image_snapshot.py
```
Controls:
- Camera feed will start automatically
- Press ESC key to exit the program

## 3. Snake Game
Classic snake game where you control a snake that grows longer as it eats food. Navigate carefully to avoid collisions!
```bash
python snake_game.py
```
Controls:
- Use arrow keys to control snake's direction
- Press ESC key to exit the game
- Game ends automatically if snake collides with itself

## 4. STL Projects
A utility for working with STL (STereoLithography) files, commonly used in 3D printing and CAD applications.
```bash
python stl_project.py
```

## 5. Tower of Hanoi
An implementation of the classic Tower of Hanoi puzzle. Move a stack of disks from one rod to another, following specific rules:
- Only one disk can be moved at a time
- Each move consists of taking the upper disk from one stack and placing it on top of another stack
- No larger disk may be placed on top of a smaller disk
```bash
python tower_of_hanoi.py
```

## 6. Verilog Projects
A collection of Verilog hardware description language projects including:
- Full Adder implementation
- Ripple Carry Adder
- Sum and Carry logic
- Example test implementations

To run the simulations:
```bash
cd verilog
./run_sim.sh <testbench_file>
```
Example usage:
```bash
./run_sim.sh full_adder_test.v    # Run full adder testbench
./run_sim.sh ripple_adder_tb.v    # Run ripple adder testbench
```

## Requirements
- Python 3.x
- Required libraries (install via pip):
  - OpenCV (for Image Snapshot)
  - Pygame (for Snake Game and Break Blocks)
  - NumPy (for STL processing)
- For Verilog Projects:
  - Icarus Verilog (iverilog) - Install with:
    ```bash
    brew install icarus-verilog
    ```
  - GTKWave - Install with:
    ```bash
    brew install --HEAD randomplum/gtkwave/gtkwave
    ```

## Setup
1. Clone the repository
2. Make sure Python is installed on your system
3. Install required dependencies
4. Navigate to the project directory
5. Run the desired program using the commands listed above

## Note
All programs are interactive and will provide additional instructions during runtime.