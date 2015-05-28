#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<map>


using namespace std;
map<char,int> hashmap;


void find_indexes(string pattern,string text,unsigned int encoded_value)
{
	if(pattern.size()>text.size())return ;	// if pattern size is greater than given text then return
	
	int window_size=pattern.size();		// store the size of pattern string to create an imaginary window
	
	unsigned int current_enc_val=1;		// temporary value to find the current encoded value
	
	for(int j=0;j<window_size;j++)
	{
		current_enc_val*=hashmap[text[j]];     // find the encoded value of first window
	}
	
	if(current_enc_val==encoded_value)
		cout<<"0 ";							// print the index 0 if encide values match
	
	
	
	for(int i=window_size;i<text.size();i++)	// interate over remaining characters in text
	{
		current_enc_val/=hashmap[text[i-window_size]];		// remove the character which should not be in the current window
		current_enc_val*=hashmap[text[i]];					// compute the new encoded value
		if(current_enc_val==encoded_value)
			cout<<i-window_size+1<<endl;					// print the start index of the anagram sub string in text
		
	}
}

int main()
{
	// assign a unique prime to each character, limited it to alphabets a-z to just show the logic.
	hashmap['a']=3;
	hashmap['b']=5;
	hashmap['c']=7;
	hashmap['d']=11;
	hashmap['e']=13;
	hashmap['f']=17;
	hashmap['g']=19;
	hashmap['h']=23;
	hashmap['i']=29;
	hashmap['j']=31;
	hashmap['k']=37;
	hashmap['l']=41;
	hashmap['m']=43;
	hashmap['n']=47;
	hashmap['o']=53;
	hashmap['p']=59;
	hashmap['q']=61;
	hashmap['r']=71;
	hashmap['s']=73;
	hashmap['t']=79;
	hashmap['u']=83;
	hashmap['v']=89;
	hashmap['w']=97;
	hashmap['x']=101;
	hashmap['y']=103;
	hashmap['z']=107;
	 
	string pattern,text;
	
	cin>>pattern; //input the pattern ex: "abcd"
	cin>>text;	  //  input the text ex:"abdcadad"
	
	unsigned int encoded_value=1;
	
	for(int i=0;i<pattern.size();i++)
	{
		encoded_value *=hashmap[pattern[i]]; //product of all prime numbers assigned to characters of the pattern.
	}
	
	find_indexes(pattern,text,encoded_value); // function to print the start indexes of the anagram of pattern sub string in the given text
	
	return 0;
}
