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
   /**Tokenize the string from "ifconfig" command output **/
   char* tokenReturnData = returnData;
   seperateString = strtok(tokenReturnData, "\n");
	while (seperateString) {
    		printf("Token: %s\n", seperateString);
    		seperateString = strtok(NULL, " ");
   	}
   
}


pclose(fp);
return 0;
}
