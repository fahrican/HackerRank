/*
We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>

tag1~value  
tag1.tag2~name

You are given source code in HRML format consisting of N lines. You have to answer Q queries. Each query asks you to print the value of the attribute specified. Print "Not Found!" if there isn't any such attribute.


Input Format
The first line consists of two space separated integers, N and Q. N specifies the number of liens in the HRML soure program. Q specifies the number of queres.

The following N lines consist of either an opening tag with zero or more attributes or a closing tag.

Q queries follow. Each query consists of string that references an attribute in the source program.


Constraints
1 <= N <= 20
1 <= Q <= 20

Each line in the source program contains, at max, 200 characters.
Every reference to the attributes in the A queries contains at max 200 characters.
All tag names are unique.

<tag-name attribute1-name = "value1" attribute2-name = "value2" ... >

The closing tags follow the format:

< /tag-name > 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

int main(){
    short n,q;
    std::unordered_map<std::string,std::string> hashtable;
    std::cin >> n >> q;

    // HDML source
    for(int i=0; i<n; i++){
        std::string input,temp;
        std::cin.ignore();
        getline(std::cin,input);
        std::stringstream stream(input);
        
        while(getline(stream,temp,' ')){
            std::string key_tag;
            std::string key_attr;
            std::string attr_value; 
            if(temp[0]=='<'){
                if(temp[1]=='/'){
                    (key_tag.find('.')) ? (key_tag.erase(key_tag.rfind('.'),key_tag.length()-1)) : key_tag="";
                }else{
                    (key_tag.empty()) ? (key_tag=temp.substr(1)) : (key_tag+="."+temp.substr(1));
                }
                std::cout<<"KEY TAG: "<<key_tag<<std::endl;
            }else{
                //Handle attribute assignment
            }
        }
    }
    
    // Queries
    for(int i=0; i<q; i++){
    }
}