#include <iostream>
#include <string>
#include <vector>      // C++ vectors (good replacement for arrays in most cases)
#include <fstream>     // C++ streams are used for reading/writing files, etc.
#include <sstream>
#include <algorithm>

using namespace std;

class Chatbot
{
    public:
    
    int index;
    
    string response;
    

    Chatbot(string var1)
    {
        response = var1;
    }

    string get_reply()
    {
        return response;
    }
    

     void tell(string input)
    {
        string raison; //reasons but in french for when the user describes why they like anime
        vector<string> answer
        {
           
        };
        
        vector<string> greeting 
        {
            "Hello indeed. Do you have any questions?", "Hi wandering user! Do you have any questions?", "Greetings program traverser. How can I help you today?"
        };
        
        vector<string> feeling 
        {
            "I am alright, how about you?", "I feel great! How about you?", "Not to well but I'm a bot so here I am. But how about you?", "I am good. How about you?", "You can't ask a bot about it's feelings and expect an actual answer. But how about you?"
        };
            
        vector<string> anime 
        {
            "Oregairu", "Re:Zero", "Tower of God", "Hunter x Hunter", "Erased"
        };
          
        vector<string> websites
        {
            "Animeultima", "kissanime", "crunchyroll", "animeflix", "9anime"
        };
        
        vector<string> affirmations
        {
            "Yes you should!", "Honestly, why not?", "Give it one try at least", "if you have the time, here are some reccomendations"
        };
        
        vector<string> convincing
        {
            "Because you can?", "It's literally 24 minutes out of your day", "It's shorter then you attention span in class"
        };
        
        vector<string> reasons
        {
            "Because it is amazing.", "It has nice visuals", "It can rekindle your childhood", "Because the good ones actually give solid life lessons"
        };
        
        vector<string> introduction
        {
            "I am a chatbot designed to give anime recommendations.", "Well, I am the anime chat bot who recommends anime."
        };
        
        vector<string> statement
        {
            "How come ", "...but why? What's the reason ", "In what way "
        };
        
        vector<string> confirmation
        {
            "Okay, that's understandable since everyone has their own taste. But try it out at least once", "If you're that determined then there's not much to do. Can I still give you a recommendation"
        };
        
        vector<string> description
        {
            "https://en.wikipedia.org/wiki/Anime", "You can google it", "They are basically animated episodes that are in japanese"
        };
        
        vector<string> likedanime
        {
            "Great!, what do you like about it?", "Ah, a person of culture! What makes it good to you?"
        };
        
        string list; //list of anime from user
        stringstream splits(input);
        string wordbyword;
        char space = ' ';
        string name;
        
        while(getline(splits, wordbyword, space))
        {
            answer.push_back(wordbyword);

        }
        
        for(index = 0; index < answer.size(); index++)
        {

            
            if(find(answer.begin(), answer.end(), "Hello") != answer.end() )
            {
                response = greeting[rand() % 3];
                
            }
            
            else if(find(answer.begin(), answer.end(), "Hi") != answer.end() )
            {
                response = greeting[rand() % 3];
                
            }
            
            else if(find(answer.begin(), answer.end(), "No") != answer.end() )
            {
                response = greeting[rand() % 3];
                
            }

            else if(find(answer.begin(), answer.end(), "Nope") != answer.end() )
            {
                response = greeting[rand() % 3];
                
            }

            else if(find(answer.begin(), answer.end(), "Who") != answer.end() )
            {
                response = introduction[rand() % 2];
                
            }

            else if(find(answer.begin(), answer.end(), "What") != answer.end() )
            {
                response = description[rand() % 3];
            }
            
            else if(find(answer.begin(), answer.end(), "What?") != answer.end() )
            {
                response = description[rand() % 3];
            }
      
            
             else if(find(answer.begin(), answer.end(), "joke") != answer.end() )
            {
                response = "This program.";
            }
    
            else if(find(answer.begin(), answer.end(), "reason") != answer.end() )
            {
                response = reasons[rand() % 3];
            }
            
            else if(find(answer.begin(), answer.end(), "Why would") != answer.end() )
            {
                response = convincing[rand() % 3];
            }
            
            else if(find(answer.begin(), answer.end(), "should") != answer.end() )
            {
                response = affirmations[rand() % 3];
            }
            
            else if(find(answer.begin(), answer.end(), "sure") != answer.end() )
            {
                response = "Okay, try viewing " + anime[rand() % 5] + " on " + websites[rand() % 5];
            }
            
            else if(find(answer.begin(), answer.end(), "recommendation") != answer.end() )
            {
                response = "Of course, try watching " + anime[rand() % 5] + " on " + websites[rand() % 5];
            }
            
            else if(find(answer.begin(), answer.end(), "another recommendation") != answer.end() )
            {
                response = "Okay, try viewing " + anime[rand() % 5] + " on " + websites[rand() % 5];
            }
            
            else if(find(answer.begin(), answer.end(), "where") != answer.end() )
            {
                response = " On " + websites[rand() % 5];
            }
            
            else if(find(answer.begin(), answer.end(), "hate") != answer.end() )
            {
                response =  statement[rand() % 3] + input;
            }
            
            else if(find(answer.begin(), answer.end(), "just") != answer.end() )
            {
                response = confirmation[rand() % 2];
            }
            else if(find(answer.begin(), answer.end(), "like") != answer.end() )
            {
                response = "You mean love?";
            }
            else if(find(answer.begin(), answer.end(), "love") != answer.end() )
            {
                response = likedanime[rand() % 2];
                
                while(getline(splits, raison, space))
                {
                    answer.push_back(raison);
                }
            
            }
            else if(find(answer.begin(), answer.end(), "seen") != answer.end() )
            {
                response = input + " no, but I'll consider it just in case .";
            }
            else if(find(answer.begin(), answer.end(), "it's") != answer.end() )
            {
                response = input + " indeed! Can you list some anime for my collection? (prompt: Here)";
            
            }
                 else if(find(answer.begin(), answer.end(), "Here") != answer.end() )
            {
                while(getline(splits, wordbyword, space))
                {
                    anime.push_back(wordbyword);
                }
                response = "Great it has been added!";
            
            }
            
            
            else if(find(answer.begin(), answer.end(), "sorry") != answer.end() )
            {
                response = "no problem, keep the questions coming as long as they're anime show related.";
                
            }
            else if(find(answer.begin(), answer.end(), "oops") != answer.end() )
            {
                response = "no worries, ask me something else related to anime.";
                
            }
            
            else
            {
                response = "I don't understand, but you should find out for yourself";
            }
            
            
            while(input.find(" me") != string::npos)
            {
                input.replace(input.find("me"), 2, "you");
                response = statement[rand() % 3] + input + "?";
            }
            
            while(input.find("I") != string::npos)
            {
                input.replace(input.find("I"), 1, "you");
                response = statement[rand() % 3] + input + "?";
            }
            
                //answer[0] == "You";

        }
    
        
    }
    
    string get_name()
    {
        return "Chatbot";
    }

};
