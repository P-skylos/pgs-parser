# This is a very primitive and incomplete parser for the pps subtitle format
the pps format looks like:
|code|meaning|
|---|---|
|CCCCCCCC|1 pixel of color 1<=C<=255|
|00000000 00LLLLLL| 1<=L<=63 pixels of color 0|
|00000000 01LLLLLL LLLLLLLL| 64<=L<=16383 pixels of color 0|
|00000000 10LLLLLL CCCCCCCC|1<=L<=63 pixels of color 1<=C<=255|
|00000000 11LLLLLL LLLLLLLL CCCCCCCC| 64<=L<=16383 pixels of color 0 |
|00000000 00000000| end of line|

the code handles this by more or less simulating a finite automata with a transition for each byte and states as needed.
