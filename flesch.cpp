#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

char c;
char previous_char; // used to find syllables
char space = ' ';
char enter = '\n';
int char_count = 0;
float spa_count =0.0;// space count
float e_count =0.0; // enter count
float v_count=0.0; // vowel count
float nv_count=0.0; // not a vowel count
float sen_count=0.0; // sentence count
float syllable_count=0.0; //syllable count
float dipthong_count=0.0;
float index=0.0;

bool was_a_vowel = false;
bool is_a_vowel = false;
bool first_pass = true;
string test; // mostly for testing, mostly
string filename;


void space_count(){ //aka word counting

if (c == ' '){ spa_count++;}
}

void enter_count(){

if (c == '\n'){ e_count++;}	
}

void sentence_count(){//aka sentence counting
		if (c == '!' || c == '?' || c== ';' || c== ':' || c== '.'){ sen_count++;}
}
bool check_if_is_vovel(char c){ //aka vovel counting
	if (c=='a' || c=='A' || c=='e' || c=='E' || c=='u' || c=='U' || c=='i' || c=='I' || c=='o' || c=='O' || c=='y' || c=='Y'){is_a_vowel=true;}
	else {is_a_vowel=false;}
	return is_a_vowel;
}
/*bool check_if_was_a_vowel(char c){//aka diphtong counting
	if (c=='a' || c=='A' || c=='e' || c=='E' || c=='u' || c=='U' || c=='i' || c=='I' || c=='o' || c=='O'){was_a_vowel=true;}
	else {was_a_vowel==false;}
 return was_a_vowel;
}*/

int main(){
	cout << '\n';
	cout << endl;
	cout << "***********************************************" << endl;
	cout << "*  FReSC -Flesch Readibility Score Calculator *" << endl;
	cout << "***********************************************" << endl;
	cout << endl;


	cout << "Enter the name of the file to check: ";
	getline(cin, filename);	
	cout << endl;

	cout << previous_char;

	ifstream in_file;
	in_file.open(filename.c_str());
	

	

	if (in_file.fail()){cout << "Error. Unable to open the file." << endl ;return -1;}//check for failure after input
	
	while (in_file.get(c)){
		
		if (first_pass==true){
			if (c==' '){spa_count++; first_pass=false;}
		}
			//checks if it is a first pass ( used to check if first char is a space to properly count sentences)

		char_count++; // count all characters
		space_count();// count spaces( words ) 
		sentence_count(); //count sentences

		if ((c == '!' || c == '?' || c== ';' || c== ':' || c== '.')
		    &(previous_char == '!' || previous_char == '?' || previous_char== ';' || previous_char== ':' || previous_char== '.')){
			sen_count--;
		    }// if clause that should ignore multiple exclamation point in god damn it!!!!



		// the four lines below were used for testing to ensure that chars were flagged
		/*cout << endl;              
		cout << char_count << endl;
		cout << "previous char: " << previous_char << endl;
		cout << "current char: "  << c;*/ 
	

		if (check_if_is_vovel(c)==true ){ v_count++; was_a_vowel=true;} 
  		

		
		if (was_a_vowel==true){
		if (check_if_is_vovel(c)==true &&  (check_if_is_vovel(previous_char)==true)){ dipthong_count++; was_a_vowel=false;
								
		/*cout <<   "    <Diphtong count: " << dipthong_count << endl */;
		}}
		if ( (previous_char=='e'|| previous_char=='E') && (c==' ' || c=='.')){cout << "<< last e : " << endl; v_count--;}



previous_char=c;
is_a_vowel=false;

	}

	syllable_count = v_count - dipthong_count;

 // the lines below were used for testing to ensure calculated numbers were correct
 /*cout << endl;
   cout << "Vovel count is: ";
   cout << v_count << endl;
   cout << endl;
   cout << "Diphtong count is:" << dipthong_count << endl;
   cout << "Syllable count is: " << syllable_count << endl;
   cout << "Word count is: " << spa_count<< endl; 
   cout << "Sentece count: " << sen_count << endl;*/

   if ( syllable_count < spa_count ){syllable_count=spa_count;}

  float test1;
  test1 = syllable_count/spa_count;
  float test2;
  test = spa_count/sen_count;

   //cout << test1 << " " << test2 << endl;//the lines was used for testing

  index =  206.835-84.6*(test1) - 1.015 * (test2);

cout << "Flesch-Kincaid readability for this file is: " << index << endl;
cout << endl;

 //206.835 - 1.015 {total words}/{total sentences}- 84.6 {total syllables}/{total words} 
 
return 0;
}
