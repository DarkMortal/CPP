# C++ Revision Files
  ## [Watch this video about Structure Padding in C++](https://youtu.be/aROgtACPjjg)
  ## [Watch this video about Header Guards](https://youtu.be/wRq8pxJEpfc)
  ## [Watch this video about Array decay](https://youtu.be/hsUivWegqYU)
  ## [Sieve of Eratosthenes](https://youtu.be/nDPo9hsDNvU)
  ## [Havel Hakimi Theorem](https://youtu.be/DdCxNvULI-c)

   ### 1. Order of passing arguments to a function matters a lot <br>
   We can't pass any non-default parameters after a default parameter in C and C++
   > WRONG <br>
 ```
 void arr(int a=10,int b)
 ```
   > CORRECT <br>
 ```
 void arr(int a=10,int b=0)
```
<p align="center">OR</p>

```
void arr(int b,int a=10)
```
