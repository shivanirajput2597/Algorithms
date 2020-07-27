#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *str , char delim)
{
	//string and a single chaarcter acts as a delimniter
	//static input pointer 
	//this input will point to "today" if str is not NULL
	static char *input = NULL;
	if(str != NULL){
		//we are making the first call
		input = str;
	}
	
	//base case-afetr the final token has been returned 
	//to stop this while loop
	if(input == NULL)
	{
		return NULL;
	}
	
	//start extracting tokens and store in a dynamic array
	//beacuse we want this mempory to 
	//exist even after function call is over
	char *output = new char[strlen(input)+1];
	
	int i=0;
	for(;input[i] != '\0';i++){
		if(input[i] != delim)
		{
		
		output[i] = input[i];
	}
	else
	{
		output[i] = '\0';
		input+= i+1;
		return output;
	}
	}
	//corner case (last case wheer there is no delim)
	output[i] ='\0';
	input = NULL;
	return output;
}




int main(){
	char s[100]="Todayu is a rainy day";
	char *ptr = mystrtok(s,' ');
	
	cout<<ptr<<endl;
	
	while(ptr != NULL)
	{
		ptr = mystrtok(NULL , ' ');
		cout<<ptr<<endl;
		
	}
	return 0;
}
