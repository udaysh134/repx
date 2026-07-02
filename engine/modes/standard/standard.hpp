#pragma once

#include <string>


class Standard {
    public:
        class Credential {
            private:
                struct Context {
                    std::string salt;
                    std::string hash;
                };
            
            
            public:
                struct Create {
                    Context forStandard(std::string password);
                };
            
                struct Authenticate {
                    bool forStandard(std::string password, std::string salt, std::string hash);
                };
        };
};