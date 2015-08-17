#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
FILE *fp;
char returnData[128];
char* seperateString;
fp = popen("/sbin/ifconfig eth0", "r");
while (fgets(returnData, 128, fp) != NULL)
{

   printf("%s\n" returnData); //Display "ifconfig" command output
   
}


pclose(fp);
return 0;
}
