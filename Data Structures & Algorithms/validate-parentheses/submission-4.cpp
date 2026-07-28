class Solution {
public:
    bool isValid(string s) {

        std::unordered_map<char, char> pairings = {
        {'{' , '}'},
        {'[' , ']'},
        {'(' , ')'}
    };

    std::stack<char> container;


    for(char& character : s){

        if(pairings.find(character) != pairings.end()){
            container.push(character);
        }

        else if(!container.empty() && pairings[container.top()] == character){

            container.pop();
        }

        else{
            container.push(character);
        }

    }
    

    if(container.empty()){

        return true;
    }

    return false;

        
    }
};
