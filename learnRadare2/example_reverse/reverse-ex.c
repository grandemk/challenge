#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define KEY "KFFSE_XHKYOKXOHOFEDM^E_Y"

int
checkkey(char *key)
{

   char *p = key;
   
   for (; *p; p++) 
      *p ^= 42; 
   
   if (!strcmp(key,KEY)) 
      return 1;
   return 0;
}

int
foo(char *data)
{
   printf("foo\n");
   return 0;
}

int
bar(char *data)
{
   printf("bar\n");
   return 0;
}

int 
foobar(char *data)
{

   foo(data);
   return 0;
}

int
main(void)
{

   char buf[512];
   int n, ret;
   int (*f)(char *);

   //memset(buf, 0, sizeof(buf));

   printf("Are you feeling lucky today? ");
   fflush(stdout);

   (void)read(0, buf, sizeof(buf)-1);
   n = strlen(buf);
   if (buf[n-1] == '\n')
      buf[n-1] = 0;
 
   switch (buf[0]) {
         
      case 0x41:
         f = &foo;
         break;
      case 0x42:
         f = &checkkey;
         break;
      case 0x43:
         f = &foobar;
         break;
      default:
      loop:
         goto *&&loop;
   }

   ret = f(buf+1);
   if (ret)
      printf("[+] WooT!: %s\n", buf+1);
   else
      printf("[-] Nope.\n");

   exit(ret);
}
