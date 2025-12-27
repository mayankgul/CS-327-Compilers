# CS-327-Compilers

You can use these materials to get started for building your own compiler.
Two sample language processors (source code + binary) designed by me are available here.
- **Pro** (```pro```): Scanner, Parser, Analyzer of sentences expressed in Propositional Logic.
- **language_processor** (```sm```): Scanner, Parser, Analyzer of sentences expressing arithmetic operations in ```bash```.

Lab Assignments will be linked, i.e., built upon the previous one, and should be performed in groups of size at most three. Each group will develop a compiler for a custom language of their choice, or a subset of any popular programming language. Compilation phases collectively implemented (spanning across all four lab assignments) need not be exhaustive.

## Our Compilation Pipeline
(Character stream) --> ***Front-end*** --> Intermediate Representation (IR) --> ***Back-end*** --> (Target machine code)

### Illustration
```z = x + y * 32``` (Character stream)

***Front-end***
- Lexical Analyzer
  
  ```<id,1> <=> <id,2> <+> <id,3> <*> <32>```
- Syntax Analyzer

  ```
             =
           /   \     
      <id,1>    +
              /   \
           <id,2>  *
                 /   \
              <id,3>  32

  ```
- Semantic Analyzer

  ```
             =
           /   \     
      <id,1>    +
              /   \
          <id,2> (inttofloat)
                      |
                      *
                    /   \
                 <id,3>  32

  ```
- Intermediate Code Generator

  ```
  t1 = id3 * 32
  t2 = inttofloat(t1)
  t3 = id2 + t2
  id1 = t3
  ```
  
***Back-end***
- Machine-Independent Code Optimizer

  ```
  t1 = id3 * 32
  t2 = inttofloat(t1)
  id1 = id2 + t2
  ```
- Code Generator [AT&T syntax to be followed in ```gas```](https://en.wikibooks.org/wiki/X86_Assembly/GNU_assembly_syntax)

  ```
  LD R3, id3
  MUL R3, R3, #32
  ITOF R2, R3
  LDF R1, id2
  ADDF R1, R1, R2
  STF id1, R1
  ```
- Machine-Dependent Code Optimizer [AT&T syntax to be followed in ```gas```](https://en.wikibooks.org/wiki/X86_Assembly/GNU_assembly_syntax)


  ```
  LD R3, id3
  SHL R3, #5
  ITOF R2, R3
  LDF R1, id2
  ADDF R1, R1, R2
  STF id1, R1
  ```

Software Tools to be used: [```lex```](https://en.wikipedia.org/wiki/Lex_(software)), [```yacc```](https://en.wikipedia.org/wiki/Yacc), [```gcc```](https://en.wikipedia.org/wiki/GNU_Compiler_Collection), [```gas```](https://en.wikipedia.org/wiki/GNU_Assembler), and other relevant tools as and when necessary.

### Acknowledgements
[Rupesh Nasre.](https://www.cse.iitm.ac.in/~rupesh)
