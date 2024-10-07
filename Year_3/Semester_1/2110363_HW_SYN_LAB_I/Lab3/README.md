# LAB 3
## Objective
- Implement Debouncing Single Pulser for every input
- countup/countdown single pulsed switches (-1, +1, -10, +10, -100, +100, -1000)
- set/reset button (=0000, =9999)
- Show on seven segment display

## Method
- Input handler ([Input Buffer](Source/Inputbuffer.v)).
    - Use 2 [D-FlipFlops](Source/DFF.v) for Metastability (sync DFF).
    - Connect the signal from 2nd Flipflop to [Deboucer](Source/Deboucer.v) (literally a 20 bits counter DFF)
    - Use the signal from Deboucer as a input of [Single Pulser](Source/Single_Pulser.v)
- [BCD](Source/BCD.v)
    - add/substract for each digit
      - must return carry/borrow
- Misc.
  - [SevenSegment](Source/SevenSegment.v) and [Encoder](Source/Encoder.v) from previous lab.
- [Main](Source/Main.v)
    - For every inputs must be passed by InputBuffer module.
    - `add_signal`, `sub_signal` is enable if a **switch is pushed** or **have carry/borrow** from the previous digit.