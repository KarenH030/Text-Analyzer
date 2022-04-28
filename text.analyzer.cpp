// Text Analyzer


/* Program that reads text from text file and analyze it. Specifically it should count and print:
 1#  the number of words
 2#  the number of letters
 3#  the number of sentences
 4#  the most used letter in text and its count
 5#  the most used word in text and its count   */


#include <iostream>
#include <cstring>
#include <fstream>



int main()
{
        std::ifstream fin;
        std::string file ;
        do{
                std::cout << "enter your file name : " ;
                std::cin >> file ;
                fin.open(file);
        }
        while(!fin.is_open());


        int words_count = -1 ;
        int letter_count = 0 ;
        int sentence_count = 0 ;
        char most_used_letter ;
        int most_letter_count = 0;
        std::string most_used_word;
        int most_word_count = 0 ;

        
	while(!fin.eof())
        {
		std::string word;
                fin >> word ;
                if(word.size() == 1 && !((word[0] > 64 && word[0] < 91) || (word[0] > 96 && word[0] < 123 ))){
                	words_count--;
                }
                words_count++ ;

        }
        
        fin.close() ;


        fin.open(file);	
        while(!fin.eof()){
		char ch ;
                ch = fin.get();
                if( (ch > 64 && ch < 91) || ( ch > 96 && ch < 123) ){
                	letter_count++ ;
                }
        }
 
       	fin.close() ;


        fin.open(file) ;
	{	
                std::string sentence ;
                while(getline(fin,sentence))
                {
                        for(int i = 0 ; i < sentence.size() ; i++)
                                if((sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!') && (sentence[i + 1] == ' ' or sentence[i + 1] == fin.eof() ))
                                        sentence_count++ ;
                }
        }

        fin.close();
        if(words_count && !sentence_count)
                sentence_count = 1 ;


	
	std::ifstream fin2;
        fin.open(file);
	while(!fin.eof()){
		int count = 0;
		char ch = fin.get();
		if( (ch > 64 && ch < 91) || ( ch > 96 && ch < 123) ){
			fin2.open(file);
			if(ch > 96 && ch < 123)
                                ch -= 32;
			while(!fin2.eof()){

				char ch1 = fin2.get();
				if(ch1 > 96 && ch1 < 123)
					 ch1 -= 32;
			      	if(ch == ch1)
				count++;
			}
			fin2.close();
			if(count > most_letter_count){
                        most_letter_count = count ;
                        most_used_letter = ch ;
			}
		}
			
	}

	fin.close();



	fin.open(file);
	while(!fin.eof()){
		int count = 0;
		std::string str;
		fin >> str ;
		for(int i = 0 ; i < str.length() ; i++ ){
			if(str[i] > 64 && str[i] < 91)
				str[i] +=32 ;
		}
		fin2.open(file);
		while(!fin2.eof())
		{
			std::string str1;
			fin2 >> str1;
			for(int i = 0 ; i < str.length() ; i++ ){
                        	if(str1[i] > 64 && str1[i] < 91)
                                str1[i] +=32 ;
	                }
			if((str[0] > 64 && str[0] < 91) || (str[0] > 96 && str[0] < 123 )){
				if(str == str1)
					count++;
			}
			
		}
		fin2.close();
		if(count > most_word_count)
		{
			most_word_count = count ;
			most_used_word = str;
		}
		

	}

	fin.close();


	std::cout <<" the number of words is  : " << words_count << std::endl ;
	std::cout << " the number of letters is : " << letter_count << std::endl ;
	std::cout << " the number of sentences is : " << sentence_count << std::endl ;
	std::cout << " The most used letter is  " << most_used_letter <<" and its used "<<most_letter_count << " times" << std::endl ;
	if(most_word_count == 1)
		std::cout << "There is no word that is used more then ones" << std::endl;
	else
		std::cout << "The most used word is " << most_used_word <<" and its used " << most_word_count << " times"<<std::endl;



}





































