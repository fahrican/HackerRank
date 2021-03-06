#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

void readHDML(int n, std::unordered_map<std::string,std::string> &hash);
void processTag(std::string source_tag, std::string &master_tag);

int main(){
    int n,q;
    std::cin >> n >> q; 
    std::cin.ignore();

    // Hashtable containg tag names and attributes
    // Key = <tagName>~<attribute>
    // Value = <attributevalue>
    std::unordered_map < std::string, std::string > hashtable;

    // Read HDML source
    readHDML(n, hashtable);

    // Print HDML queries
    for(int i=0; i<q; i++){
        std::string query;
        getline(std::cin,query);
        if(hashtable[query].empty()){
            std::cout << "Not Found!" << std::endl;
        }else{
            std::cout << hashtable[query] << std::endl;
        }
    }

    return 0;
}

void readHDML(int n, std::unordered_map<std::string,std::string> &hash){
    std::string source, temp;
    std::string tag, attribute, value;
    
    for(int i=0; i<n; i++){
        bool att_val_flag = true; // True = attribute, false = value

        getline(std::cin,source);
        std::stringstream sourcestream(source);

        while(getline(sourcestream,temp,' ')){
            if(temp[0]=='<'){ // Tag
                processTag(temp,tag);
            }else{
                if(temp=="=") continue; // Don't process =
                if(att_val_flag){
                    attribute=temp;
                    att_val_flag=false;
                }else{
                    (temp[temp.length()-1]=='>') ? (temp=temp.substr(1,temp.length()-3)) : (temp=temp.substr(1,temp.length()-2)); // Remove leading/trailing characters
                    hash[tag+"~"+attribute]=temp;
                    att_val_flag=true;
                }
            }
        }
    }
}

void processTag(std::string source_tag, std::string &master_tag){
    if(source_tag[1]=='/'){
        if(master_tag.rfind(".")==std::string::npos){
            master_tag.clear();
        }else{
            master_tag.erase(master_tag.rfind("."));
        }
    }else{
        if(source_tag[source_tag.length()-1]=='>') source_tag.erase(source_tag.length()-1);
        if(master_tag.empty()){
            master_tag = source_tag.substr(1);
        }else{
            master_tag.append("." + source_tag.substr(1));
        }
    }
}
