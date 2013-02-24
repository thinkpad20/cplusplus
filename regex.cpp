#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string input;
	regex integer("(\\+|-)?[[:digit:]]+");
	//As long as the input is correct ask for another number
	while(true)
	{
		cout<<"Give me an integer!"<<endl;
		cin>>input;
		//Exit when the user inputs q
		if(input=="q")
			break;
		if(regex_match(input,integer))
			cout<<"integer"<<endl;
		else
		{
			cout<<"Invalid input"<<endl;
		}
	}
}

/*What possesses the North Korean government to be such assholes.
What people say about me when I'm not around. The good stuff, and the bad.
To what extent human nature is inherent, and to what extent it's shaped by surroundings and intent.
Why art matters so much.
Why anything matters at all.
How most statements accepted as true at some point rely on axiomatic assumptions, and whether this affects their validity.
The problem of a finite existence.
What I'm going to have for dinner.

You're educated (note, this does not require some arbitrary degree, 
it simply means that you are a learner, you see education as its own 
good, and you can challenge me intellectually). You can hold your own 
at a dinner party full of opinionated bourgeois intellectuals, if need 
be. You have questions you want to ask and questions you want to answer. 
You have secrets you want to tell someone, but not anyone. You're mature, 
confident, attractive, interested in something serious but not afraid of 
it not working out. You're sexy and you know it. The idea of getting 
drunk and belting out "Stars" from Les Mis sounds like fun.
*/

