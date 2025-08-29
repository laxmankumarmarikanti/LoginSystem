#ifndef AUTH_H
#define AUTH_H

#include <string>

std::string sha256(const std::string &str);
void registerUser(const std::string &dbPath);
bool loginUser(const std::string &dbPath);

#endif
