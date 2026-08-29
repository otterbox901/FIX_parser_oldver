//
// Created by alex on 2026-08-28.
//

#ifndef UNTITLED_DECODER_H
#define UNTITLED_DECODER_H
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


std::string decoder(std::vector<char>& buffer, std::unordered_map<std::string, std::string> tags,
                    std::unordered_map<std::string, std::string> message, std::string& incomplete_message)
{
    std::string key;
    std::string value;
    bool add_to= true;

    for (char& c : incomplete_message) {
        if (c== 0x01) {
            if (key== "35") {
                std::cout<<message[value]<<'message \n';
                key.clear();
                value.clear();
                add_to= true;
            }
            else {
                std::cout<<tags[key]<<value<<'\n';
            }
        }
        else if (c== 0x3D) add_to= false;
        else {
            if (add_to) {
                key.push_back(c);
            }
            else value.push_back(c);
        }
    }

    for (char& c : buffer) {
        if (c== 0x01) {
            if (key== "35") {
                std::cout<<message[value]<<" message \n";
                key.clear();
                value.clear();
                add_to= true;
            }
            else {
                std::cout<<tags[key]<<value<<'\n';
                key.clear();
                value.clear();
                add_to= true;
            }
        }
        else if (c== 0x3D) add_to= false;
        else {
            if (add_to) {
                key.push_back(c);
            }
            else value.push_back(c);
        }
    }
    if (add_to) return key;
    return key+"="+value;
}


#endif //UNTITLED_DECODER_H
