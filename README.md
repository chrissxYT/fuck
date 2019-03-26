# fuck
Tools for dealing with brainfuck, asmfuck and binfuck.
|asmfuck|c             |brainfuck|binfuck|
|-------|--------------|---------|-------|
|inc    |t[tp]++       |+        |0      |
|dec    |t[tp]--       |-        |1      |
|tsl    |tp--          |<        |2      |
|tsr    |tp++          |>        |3      |
|sjp    |while(t[tp]) {|[        |4      |
|jpb    |}             |]        |5      |
|rac    |getc()        |,        |6      |
|wac    |putc(t[tp])   |.        |7      |
