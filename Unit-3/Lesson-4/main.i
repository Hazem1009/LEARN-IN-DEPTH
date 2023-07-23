# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"







void main()
{

 *((*volatile unsigned long) 0x400FE108) =0x20;



 volatile unsigned int i=0;
 for(i=0;i<200;i++);


 *((*volatile unsigned long) 0x40025400) |=(1<<3);

 *((*volatile unsigned long) 0x4002551C) |=(1<<3);

 while(1)
 {



  *((*volatile unsigned long) 0x400253FC)|=(1<<3);
  for(i=0;i<10000;i++);


  *((*volatile unsigned long) 0x400253FC)&=~(1<<3);
  for(i=0;i<10000;i++);
 }
}
