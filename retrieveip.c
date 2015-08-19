#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fp; //use to open the sbin/ifconfig file
	char returnData[128]; //Data from ifconfig
	char* seperateString; //String use to store the result of string tokenizer
	fp = popen("/sbin/ifconfig eth0", "r"); //Run the command of "ifconfig eth0"
	int foundIp = 0; //To identify is there any IP address of the running PC, 0 = no IP, 1 = got IP

	/**Retrieve the data from fp to string returnData**/
	while (fgets(returnData, 128, fp) != NULL)
	{
	   /**Check whethere the machine got IP address or not**/
	   if(strstr(returnData,"inet addr") != NULL){
		foundIp = 1; //foundIp set to 1 to indicate there is an IP address in this machine

		/**Tokenize the string from "ifconfig" command output **/
		//returnData is stored into a new string to prevent lost of data
		char* tokenReturnData = returnData;
		seperateString = strtok(tokenReturnData, ":");
		//The actual location where the IP address will locate
		int counterToGetIP = 0;
		while (seperateString) {	
			//IP is at second location, after the delimiter ":"
			if(counterToGetIP == 1){
	  			printf("Your IP address: %s\n", seperateString);
				break;
			}//if
		seperateString = strtok(NULL, " "); //Update the loop counter
		counterToGetIP ++; //Update the counter
		}//while
	   break; //No need to get others data since we already have the IP addresss
	   }//if
	}//while

	//If no IP address found, display the error
	if(!foundIp){
	    printf("No IP address found\n");
	}
	
	//Close the file
	pclose(fp);
	return 0;
}
